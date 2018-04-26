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
 *  argv[10] : hard instance set                                             *
 *  argv[11] : hard n set                                                    *
 *                                                                           *
 *  TODO Wizard: validate inputs                                             *
 *  TODO Validate CLArgs inpus                                               *
 *  TODO Run benchmark via wizard                                            *
 *  TODO Make sure the wizard returns the generated input                    *
 *                                                                           *
 *****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <string.h>
#include "branch_and_bound_benchmark.h"
#include "bench_extern.h"
#include "branch_and_bound.h"
#include "fptas.h"
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
      /* TODO lol wizard */
      printf("Wizard!\n");

      printf("Please enter the limit on memory allocation (bytes):\n");
      int memory_allocation_limit;
      scanf("%d", &memory_allocation_limit);

      printf("Please enter the limit on run-time (seconds):\n");
      int timeout;
      scanf("%d", &timeout); 
  
      char input_str[100];
      /* Prompt user for DP types */
      char DP_types[] = "00";  
      printf("Enter the DP types you want to toggle (of vv or ws), and input 0 when done.\n");
      do{
        scanf("%s", input_str);
        if(strcmp(input_str,"vv")==0) DP_types[0] = ( DP_types[0] == '0' ? '1' : '0' );
        else if(strcmp(input_str,"ws")==0) DP_types[1] = ( DP_types[1] == '0' ? '1' : '0' );
        printf("DP_types: %s\n", DP_types);
        /* TODO Make sure they pick something! */
      }while(strncmp(input_str, "0", 1) != 0);

      /* Prompt user for branching strats */
      char branch_strats[] = "000";
      printf("Enter the branch strategies you want to toggle (of le, rb, tb)\n");
      do{
        scanf("%s", input_str);
        if(strcmp(input_str,"le")==0) branch_strats[0] = ( branch_strats[0] == '0' ? '1' : '0' );
        else if(strcmp(input_str,"rb")==0) branch_strats[1] = ( branch_strats[1] == '0' ? '1' : '0' );
        else if(strcmp(input_str,"tb")==0) branch_strats[2] = ( branch_strats[2] == '0' ? '1' : '0' );
        printf("branch_strats: %s\n", branch_strats);
        /* Make sure they pick something! */
      }while(strncmp(input_str, "0", 1) != 0);
      
      /* Prompt user for Instance set */
      char instance_set[] = "0000000";
      printf("Enter the instance types you want to toggle (1-6 and 9)\n");
      do{
        scanf("%s", input_str);
        if(strcmp(input_str,"1")==0) instance_set[0] = ( instance_set[0] == '0' ? '1' : '0' );
        else if(strcmp(input_str,"2")==0) instance_set[1] = ( instance_set[1] == '0' ? '1' : '0' );
        else if(strcmp(input_str,"3")==0) instance_set[2] = ( instance_set[2] == '0' ? '1' : '0' );
        else if(strcmp(input_str,"4")==0) instance_set[3] = ( instance_set[3] == '0' ? '1' : '0' );
        else if(strcmp(input_str,"5")==0) instance_set[4] = ( instance_set[4] == '0' ? '1' : '0' );
        else if(strcmp(input_str,"6")==0) instance_set[5] = ( instance_set[5] == '0' ? '1' : '0' );
        else if(strcmp(input_str,"9")==0) instance_set[6] = ( instance_set[6] == '0' ? '1' : '0' );
        printf("instance_set: %s\n", instance_set);
      }while(strncmp(input_str, "0", 1) != 0);

      /* Prompt user for n set */
      char n_set[] = "00000000";
      printf("Enter the n-types you want to toggle (50, 100, 200, 500, 1000, 2000, 5000, 10000)\n");
      do{
        scanf("%s", input_str);
        if(strcmp(input_str,"50")==0) n_set[0] = ( n_set[0] == '0' ? '1' : '0' );
        else if(strcmp(input_str,"100")==0) n_set[1] = ( n_set[1] == '0' ? '1' : '0' );
        else if(strcmp(input_str,"200")==0) n_set[2] = ( n_set[2] == '0' ? '1' : '0' );
        else if(strcmp(input_str,"500")==0) n_set[3] = ( n_set[3] == '0' ? '1' : '0' );
        else if(strcmp(input_str,"1000")==0) n_set[4] = ( n_set[4] == '0' ? '1' : '0' );
        else if(strcmp(input_str,"2000")==0) n_set[5] = ( n_set[5] == '0' ? '1' : '0' );
        else if(strcmp(input_str,"5000")==0) n_set[6] = ( n_set[6] == '0' ? '1' : '0' );
        else if(strcmp(input_str,"10000")==0) n_set[7] = ( n_set[7] == '0' ? '1' : '0' );
        printf("n_set: %s\n", n_set);
      }while(strncmp(input_str, "0", 1) != 0);

      /* Prompt user for coefficient set */
      char coefficient_set[] = "00000";
      printf("Enter the coefficient types you want to toggle (of 1000, 10000, 100000, 1000000, 10000000)\n");
      do{
        scanf("%s", input_str);
        if(strcmp(input_str,"1000")==0) coefficient_set[0] = ( coefficient_set[0] == '0' ? '1' : '0' );
        else if(strcmp(input_str,"10000")==0) coefficient_set[1] = ( coefficient_set[1] == '0' ? '1' : '0' );
        else if(strcmp(input_str,"100000")==0) coefficient_set[2] = ( coefficient_set[2] == '0' ? '1' : '0' );
        else if(strcmp(input_str,"1000000")==0) coefficient_set[3] = ( coefficient_set[3] == '0' ? '1' : '0' );
        else if(strcmp(input_str,"10000000")==0) coefficient_set[4] = ( coefficient_set[4] == '0' ? '1' : '0' );
        printf("coefficient_set: %s\n", coefficient_set);
      }while(strncmp(input_str, "0", 1) != 0);

      /* Prompt user for problem subset */
      int problem_subset = 0;
      printf("Enter the first n problems you want to compute of an instance type\n");
      do{
        scanf("%s", input_str);
        /* Make sure they pick a reasonable number! */
      }while(problem_subset >= 1 && problem_subset <= 100);

      /* Prompt user for hard instance set */
      char hard_instance_set[] = "000000";
      printf("Enter the hard instance types you want to toggle (of 11-16)\n");
      do{
        scanf("%s", input_str);
        if(strcmp(input_str,"11")==0) hard_instance_set[0] = ( hard_instance_set[0] == '0' ? '1' : '0' );
        else if(strcmp(input_str,"12")==0) hard_instance_set[1] = ( hard_instance_set[1] == '0' ? '1' : '0' );
        else if(strcmp(input_str,"13")==0) hard_instance_set[2] = ( hard_instance_set[2] == '0' ? '1' : '0' );
        else if(strcmp(input_str,"14")==0) hard_instance_set[3] = ( hard_instance_set[3] == '0' ? '1' : '0' );
        else if(strcmp(input_str,"15")==0) hard_instance_set[4] = ( hard_instance_set[4] == '0' ? '1' : '0' );
        else if(strcmp(input_str,"16")==0) hard_instance_set[5] = ( hard_instance_set[5] == '0' ? '1' : '0' );
        printf("hard_instance_set: %s\n", hard_instance_set);
        /* TODO Make sure they pick something if they didn't before! */
      }while(strncmp(input_str, "0", 1) != 0);

      /* Prompt user for hard n set*/
      char hard_n_set[] = "000000000";
      printf("Enter the hard n types you want to toggle (20, 50, 100, 200, 500, 1000, 2000, 5000, 10000\n");
      do{
        scanf("%s", input_str);
        if(strcmp(input_str,"20")==0) hard_n_set[0] = ( hard_n_set[0] == '0' ? '1' : '0' );
        else if(strcmp(input_str,"50")==0) hard_n_set[1] = ( hard_n_set[1] == '0' ? '1' : '0' );
        else if(strcmp(input_str,"100")==0) hard_n_set[2] = ( hard_n_set[2] == '0' ? '1' : '0' );
        else if(strcmp(input_str,"200")==0) hard_n_set[3] = ( hard_n_set[3] == '0' ? '1' : '0' );
        else if(strcmp(input_str,"500")==0) hard_n_set[4] = ( hard_n_set[4] == '0' ? '1' : '0' );
        else if(strcmp(input_str,"1000")==0) hard_n_set[5] = ( hard_n_set[5] == '0' ? '1' : '0' );
        else if(strcmp(input_str,"2000")==0) hard_n_set[6] = ( hard_n_set[6] == '0' ? '1' : '0' );
        else if(strcmp(input_str,"5000")==0) hard_n_set[7] = ( hard_n_set[7] == '0' ? '1' : '0' );
        else if(strcmp(input_str,"10000")==0) hard_n_set[8] = ( hard_n_set[8] == '0' ? '1' : '0' );
        printf("hard_n_set: %s\n", hard_n_set);
        /* TODO Make sure they pick something if they didn't before! */
      }while(strncmp(input_str, "0", 1) != 0);

      /*TODO Run benchmark with these*/
      
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

  int problem_subset = atoi(argv[9]);  

  printf("Memory allocation limit: %s\n"
         "Timeout: %s\n"
         "DP_Set: %s\n"
         "Branching set: %s\n"
         "Instance set: %s\n"
         "n_set: %s\n"
         "Coefficient set: %s\n"
         "Problem subset: %s\n"
         "hard_instance_set: %s\n"
         "hard_n_set: %s\n", 
         argv[1], argv[2], argv[4], argv[5], argv[6],
         argv[7], argv[8], argv[9], argv[10], argv[11]);

  benchmark(memory_allocation_limit, timeout, argv[4], argv[7], argv[8], 
            argv[6], argv[5], file_out, problem_subset,
            argv[10], argv[11]);

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

  fprintf(benchmark_stream, "File name, DP method, branching strategy, problem #, runtime, memory allocate"
                            "d, node count, ave. time per node\n");

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
  double average_time_per_node;
  if (t == -1.0)
  {
    strcpy(stringified_time, "TIMEOUT");
    average_time_per_node = 0.0;
  }
  else
  {
    clock_t elapsed = clock() - t;
    double time_taken = ((double) elapsed)/CLOCKS_PER_SEC;
    sprintf(stringified_time, "%lf", time_taken);
    average_time_per_node = time_taken/(double)number_of_nodes;
  }
  char stringified_memory[30];
  if(bytes_allocated == -1)
    strcpy(stringified_memory, "MEMORY LIMITED EXCEEDED");
  else
    sprintf(stringified_memory, "%d", bytes_allocated);

  char *DP_str_arr[] = {"Vazirani", "Williamson Shmoy"}; 
  char *branching_strats[] = {"Linear Enum", "Random", "Truncation"};

  fprintf(benchmark_stream, "%s, %s, %s, %d, %s, %s, %d, %lf\n", file_name_holder,
         DP_str_arr[DP_method], branching_strats[branching_strategy], problem_no, stringified_time, 
         stringified_memory, number_of_nodes, average_time_per_node);
}
