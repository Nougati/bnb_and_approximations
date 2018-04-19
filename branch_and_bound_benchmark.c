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
 *****************************************************************************/
/* TODO sort out all this shit */
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
    if (strcmp("help", argv[1]) == 0)
    {
      printf("To run this benchmark, there are two ways:\n\t1. Input \"%s -w\" t"
             "o run the instance set customisation wizard.\n\t2. Input \"%s <mem"
             "ory limit> <timeout> <file out> <DP types> <branching strategy set"
             "> <instance set> <n set> <coefficient set> <problem subset>\n",
             arg[0], arg[0]);
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
      exit(-1);
    }

  if(strcmp("-w", argv[1] == 0))
  {
    printf("Wizard!\n");
    exit(-1);
  }

  if(argc != 5)
  {
    printf("Format: \"%s <memory limit> <timeout> <file out> <branching strategy"           " set> <instance set> <n set> <coefficient set> <problem subset>\"\no"           "r\n \"%s -w\" for wizard\n Type \"%s help\" for info on input option"           "s.\n", argv[0], argv[0]);
    exit(-1);
  }

  /* TODO validate inputs 
   *  Probably just run a function with each argv in it 
   *  So at this point we assume that all the args are great */  
  
  int memory_allocation_limit = atoi(argv[1]);
  int timeout = atoi(argv[2]);
  FILE *file_out = fopen(argv[3],"a");

  /* Copy DP types string */
  char DP_set[2 + 1];
  strncpy(DP_set, argv[4], sizeof(DP_set));
  DP_set[3] = '\0';

  /* Copy branching set string */
  char branching_set[BRANCH_STRAT_NO_OF_OPTIONS + 1];
  strncpy(branching_set, argv[5], sizeof(branching_set));
  branching_set[BRANCH_STRAT_NO_OF_OPTIONS + 1] = '\0';

  /* Copy instance set string*/
  char instance_set[13 + 1];
  strncpy(instance_set, argv[6], sizeof(instance_set));  
  instance_set[14] = '\0';
  
  /* Copy n_set string */
  char n_set[8 + 1];
  strncpy(n_set, argv[7], sizeof(instance_set));
  instance_set[9] = '\0';

  /* Copy coefficient set string */
  char coefficient_set[5 + 1];
  strncpy(coefficient_set, argv[8], sizeof(coefficient_set));
  coefficient_set[6] = '\0';

  int problem_subset = atoi(argv[9]);  

  benchmark(memory_allocation_limit, time_out, DP_set, n_set, coefficient_set, 
            instance_set, DPs, branching_strategies, benchmark_stream, 
            problem_subset);

  return 0;
}

void benchmark(int memory_allocation_limit, int timeout, char *DP_set, 
               char *n_set, char *coefficient_set, char *instance_set, 
               char *branching_strategies, FILE *benchmark_stream, 
               int problem_subset)
{
  /* Parameterisations to enumerate through */
  char file_name_holder[30];
  const char *instance_types_1[] = { "1", "2", "3", "4", "5", "6", "9"};
  const char *coefficient_types[] = {"1000", "10000", "100000", "1000000", 
                                     "10000000"};
  const char *instance_types_2[] = {"11", "12", "13", "14", "15", "16"};
  const char *n_types[] = {"50", "100", "200", "500", "1000", "2000", "5000",
                           "10000"};

  fprintf(benchmark_stream, "File name, problem #, runtime, memory allocate"
                            "d\n");

  /* Filetype enumeration begin */
  /* TODO change iterators to their respective names (h -> DP_method)*/
  /* For each DP method */
  for(int h = 0; h < 2; h++)
  {
    /* TODO if this DP's index is off, go to next iteration*/
    /* For each branching_strategy */
    for(int i = 0; i < 3; i++)
    {
      /* TODO if this branching strat's index is off, go to next iteration*/
      /* For each instance type*/
      for(int j = 0; j < 7; j++)
      {
        /* TODO if this instance type's index is off, go to next iteration*/
        /* For each n */
        for(int k = 0; k < 8; k++)
        {
          /* TODO if this n's index is off, go to next iteration*/
          /* For each coefficient type */
          for(int l = 0; l < 5; l++)
          {
            /* TODO if this coefficient's index is off, go to next iteration*/
            /* For each problem instance */
            for(int m = 0; m <= problem_subset; m++)
            {
              /* TODO Prepare filename */
              /* Run the benchmark */
              benchmark_instance(file_name_holder, m, timeout, DP_method,
                                memory_allocation_limit, benchmark_stream,
                                branching_strategy);
            }
          }
        }
      }
    }
  }
}

void benchmark_instance(char *instance_name, int problem_no, int timeout, 
                        int DP_method, int allocation_limit,                                             FILE *benchmark_stream, int branching_strategy)
{
  /* Problem variables */
  double epsilon = 0.0;
  FILE *logging_stream  = stdout;
  int logging_rule = NO_LOGGING;
  /*TODO randomly generate seed*/
  int seed = 0;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;

  pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, file_name_holder,
                  k);
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

  fprintf(benchmark_stream, "%s, %d, %s, %s\n", file_name_holder, k, 
          stringified_time, stringified_memory);
}
