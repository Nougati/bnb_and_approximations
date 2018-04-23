/*****************************************************************************
 *  branch_and_bound_benchmark.c                                             *
 *   Implements a series of benchmarks on instances of KP for my B&B algo    *
 *   Input parameters will decide how this algorithm will function           *
 *   Input parameters to me made:                                            *
 *  argv[0] : filename                                                       *
 *  argv[1] : memory limit                                                   *
 *  argv[2] : timeout                                                        *
 *  argv[3] : file out                                                       *
 *  argv[4] : DP types                                                       *
 *  argv[5] : branching strategy                                             *
 *  argv[6] : instance set                                                   *
 *  argv[7] : n set                                                          *
 *  argv[8] : coefficient set                                                *
 *  argv[9] : problem subset                                                 *
 *                                                                           *
 *  TODO Timeout does not work!                                              *
 *  TODO Wizard!                                                             *
 *  TODO Move all the defines into a header file                             *
 *                                                                           *
 *****************************************************************************/
#define INCLUDE_FPTAS
#define TESTING
#define nP 1
#define SIMPLE_SUM 2
#define RATIO_BOUND 3
#define BINARY_SOL 1
#define VARIABLE_ON 2
#define VARIABLE_UNCONSTRAINED 1
#define VARIABLE_OFF 0
#define LINEAR_ENUM_BRANCHING 0
#define RANDOM_BRANCHING 1
#define TRUNCATION_BRANCHING 2
#define TRUE 1
#define FALSE 0
#define NO_LOGGING 0 
#define PARTIAL_LOGGING 1
#define FULL_LOGGING 2
#define FILE_LOGGING 3
#define MEMORY_EXCEEDED 1
#define TIMEOUT 2
#define VASIRANI 0
#define WILLIAMSON_SHMOY 1
#define SMART_DP 2
#define INDEX_NOTATION 0
#define BINARY_NOTATION 1
#define HYPER_TRIVIAL_BOUND 1
#define TRIVIAL_BOUND 2
#define NODE_OVERFLOW 1500000

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <string.h>
#include "branch_and_bound_benchmark.h"
#include "bench_extern.h"
#include "branch_and_bound.h"
#include "pisinger_reader.h"

/* If memory has been exceeded, bytes_allocated will be -1 (so we write "memory
     exceeeded to log" */
/* If time has been exceeded, start_time will be -1 */

int main(int argc, char *argv[])
{
  /* branch_and_bound_benchmark.c main()
   * Argv should be of the form
   *  [file, benchmark_set, memory_limit, timeout, file_out]
   * where
   *  benchmark_set can be "tiny_n", "small_n", "midlow_n", "medium_n", 
   *                        "midhigh_n", "big_n", "huge_n", "massive_n", "all"
   *                        Which all correspond to different n values.
   *
   *  memory_limit is string version of the max amount bytes
   *  timeout is a string of the number of seconds allowed
   * and
   *  if memory_limit or timeout takes the value -1, then we do not worry.
   * */

  /* First verify the given arguments */
  if(argc == 2)
  {
    if (strcmp("help", argv[1]) == 0)
    {
      printf("To run this benchmark, there are two ways:\n\t1. Input \"%s -w\" t"
             "o run the instance set customisation wizard.\n\t2. Input \"%s <mem"
             "ory limit> <timeout> <file out> <DP types> <branching strategy set"
             "> <instance set> <n set> <coefficient set> <problem subset> <hard "
             "instance set> <hard n set>\n", argv[0], argv[0]);
      printf("By using the wizard, you can choose all the parameters from questi"
             "on prompts. Following the wizard will give you an input if you wan"
             "t to run that specific configuration again.\n");
      printf("The format for each is:\n"
               "\t branching strats: a string of three bits\n"
               "\t\t Where each respective bit is linear enum, random, then trun"
               "cation branching\n"
             "DP type is first flag VV, second flag WS.\n"
             "Instances, n category, and coefficients have each index in the str"
             "ing as flags for the respective type in ascending order. (1st is 5"
             "0 for n, 2nd is 100, etc).\n"
             "This differs from problen instance where you simply specify, for s"
             "ome input n, the first n problems in a problem file. For example, "
             "for input 1, only the first problem of each file will be run.\n");
      printf("Data formats of inputs:\n");
      printf("Memory limit (bytes):\tint\ntimeout (seconds):\tint\nfile out:\t\tchar "
             "array (any length)\nDP Types:\t\t2 bits\nbranching strategies:\t3 bits"
             "\ninstance set:\t\t7 bits\nn set:\t\t\t8 bits\ncoefficient set:\t5 bits\npr"
             "oblem subset:\t\tinteger in range [1,100]\n<hard instance set:\t6 bit"
             "s\nhard n set:\t\t9 bits\n");
      exit(-1);
    }
    else if(strcmp("-w", argv[1]) == 0)
    {
      printf("Wizard!\n");
      exit(-1);
    }
  } 


  if(argc != 12)
  {
    printf("This application takes either 2 or 12 arguments.\n");
    printf("Format: \"%s <memory limit> <timeout> <file out> <DP set> <branchi"
           "ng strategy set> <instance set> <n set> <coefficient set> <problem"
           " subset> <hard instance set> <hard n set>\"\nor\n \"%s -w\" for w"
           "izard\n Type \"%s help\" for info on input options.\n", argv[0], 
           argv[0], argv[0]);
    printf("i.e. %s int int char[] char[2] char[3] char[7] char[8] char[5] in"
           "t char[6] char[9]\n", argv[0]);
    exit(-1);
  }

  /* TODO validate inputs 
   *  Probably just run a function with each argv in it 
   *  So at this point we assume that all the args are great */  
  
  int memory_allocation_limit = atoi(argv[1]);
  int timeout = atoi(argv[2]);
  FILE *file_out = fopen(argv[3],"a");

  /* Copy DP types string */
  char DP_set[2];
  strncpy(DP_set, argv[4], sizeof(DP_set));
  DP_set[2] = '\0';

  /* Copy branching set string */
  char branching_set[BRANCH_STRAT_NO_OF_OPTIONS];
  strncpy(branching_set, argv[5], sizeof(branching_set));
  branching_set[BRANCH_STRAT_NO_OF_OPTIONS] = '\0';

  /* Copy instance set string*/
  char instance_set[7];
  strncpy(instance_set, argv[6], sizeof(instance_set));  
  instance_set[7] = '\0';
  
  /* Copy n_set string */
  char n_set[8];
  strncpy(n_set, argv[7], sizeof(n_set));
  instance_set[8] = '\0';

  /* Copy coefficient set string */
  char coefficient_set[5];
  strncpy(coefficient_set, argv[8], sizeof(coefficient_set));
  coefficient_set[5] = '\0';

  int problem_subset = atoi(argv[9]);  

  /* Copy hard instance set string*/
  char hard_instance_set[6];
  strncpy(hard_instance_set, argv[10], sizeof(hard_instance_set));
  hard_instance_set[6] = '\0';
  
  /* Copy hard_n_set string */
  char hard_n_set[9];
  strncpy(hard_n_set, argv[11], sizeof(hard_n_set));
  hard_n_set[9] = '\0';

  printf("Memory allocation limit: %d\nTimeout: %d\nDP_Set: %s\nBranching set: %s\nInstance set:%s\n n_set: %s\nCoefficient set: %s\nProblem subset: %d\nhard_instance_set: %s\nhard_n_set: %s\n", memory_allocation_limit, timeout, DP_set, branching_set, instance_set, n_set, coefficient_set, problem_subset, hard_instance_set, hard_n_set);

  benchmark(memory_allocation_limit, timeout, DP_set, n_set, coefficient_set, 
            instance_set, branching_set, file_out, problem_subset,
            hard_instance_set, hard_n_set);

  return 0;
}

void benchmark(int memory_allocation_limit, int timeout, char *DP_set, 
               char *n_set, char *coefficient_set, char *instance_set, 
               char *branching_strategies, FILE *benchmark_stream, 
               int problem_subset, char *hard_instance_set, char *hard_n_set)
{
  /* Parameterisations to enumerate through */
  char file_name_holder[30];
  const char *instance_types_1[] = { "1", "2", "3", "4", "5", "6", "9" };
  const char *coefficient_types[] = {"1000", "10000", "100000", "1000000", 
                                     "10000000"};
  const char *n_types[] = {"50", "100", "200", "500", "1000", "2000", "5000",
                           "10000"};
  /* Second instance types */
  const char *instance_types_2[] = {"11", "12", "13", "14", "15", "16"};
  const char *n_types_2[] = {"20", "50", "100", "200", "500", "1000", "2000",
                             "5000", "10000"}; 

  fprintf(benchmark_stream, "File name, problem #, runtime, memory allocate"
                            "d\n");

  /* Filetype enumeration begin */
  /* For each DP method */
  for(int DP_method = VASIRANI; DP_method <= WILLIAMSON_SHMOY; DP_method++)
  {
    if(strncmp(&DP_set[DP_method],"0", 1)==0)
      continue;  

    /* For each branching_strategy */
    for(int branching_strategy = LINEAR_ENUM_BRANCHING; 
        branching_strategy <= TRUNCATION_BRANCHING;
        branching_strategy++)
    {
      if(strncmp(&branching_strategies[branching_strategy],"0", 1)==0)
        continue;  

      /* For each instance type*/
      for(int j = 0; j < 7; j++)
      {
        if(strncmp(&instance_set[j],"0", 1)==0)
          continue;

        /* For each n (easy instances) */
        for(int k = 0; k < 8; k++)
        {
          if(strncmp(&n_set[k],"0", 1)==0)
            continue;

          /* For each coefficient type */
          for(int l = 0; l < 5; l++)
          {
            if(strncmp(&coefficient_set[l],"0", 1)==0)
              continue;

            /* For each problem instance */
            for(int m = 1; m <= problem_subset; m++)
            {
              snprintf(file_name_holder, 30, "knapPI_%s_%s_%s.csv", 
                       instance_types_1[j], n_types[k], coefficient_types[l]);
            
              /* Run the benchmark */
              printf("%s\n", file_name_holder);
              benchmark_instance(file_name_holder, m, timeout, DP_method,
                                memory_allocation_limit, benchmark_stream,
                                branching_strategy);
            }
          }
        }
      }
      /* For each instance type (hard)*/
      for(int j = 0; j < 6; j++)
      {
        if(strncmp(&hard_instance_set[j],"0", 1)==0)
          continue;

        /* For each n (hard instances) */
        for(int k = 0; k < 9; k++)
        {
          if(strncmp(&hard_n_set[k],"0", 1)==0)
            continue;
          /* For each problem instance */
          for(int m = 1; m <= problem_subset; m++)
          {
            snprintf(file_name_holder, 30, "knapPI_%s_%s_1000.csv", 
                     instance_types_2[j], n_types_2[k]);

            /* Run the benchmark */
            printf("%s\n", file_name_holder);
            benchmark_instance(file_name_holder, m, timeout, DP_method,
                              memory_allocation_limit, benchmark_stream,
                              branching_strategy);
          }
        }
      }
    }
  }
}

void benchmark_instance(char *file_name_holder, int problem_no, int timeout, 
                        int DP_method, int memory_allocation_limit,
                        FILE *benchmark_stream, int branching_strategy)
{
  /* Problem variables */
  double epsilon = 0.0;
  FILE *logging_stream  = stdout;
  int logging_rule = NO_LOGGING;
  int seed = 0;
  if(branching_strategy == RANDOM_BRANCHING)
  {
    seed = time(NULL);
  }
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;

  pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, file_name_holder,
                  problem_no);
  int sol_out[n];
  clock_t t = clock();
  branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, 
                                &z_out, sol_out, n, file_name_holder,
                                branching_strategy, seed, DP_method, 
                                logging_rule, logging_stream, epsilon,
                                &number_of_nodes, 
                                memory_allocation_limit, &t, timeout);

  char stringified_time[30];
  if (t == -1.0)
    strcpy(stringified_time, "TIMEOUT");
  else
  {
    clock_t elapsed = clock() - t;
    double time_taken = ((double) elapsed)/CLOCKS_PER_SEC;
    sprintf(stringified_time, "%lf", time_taken);
  }
  char stringified_memory[30];
  if(bytes_allocated == -1)
    strcpy(stringified_memory, "MEMORY LIMITED EXCEEDED");
  else
    sprintf(stringified_memory, "%d", bytes_allocated);

  fprintf(benchmark_stream, "%s, %d, %s, %s\n", file_name_holder, problem_no, 
          stringified_time, stringified_memory);
}
