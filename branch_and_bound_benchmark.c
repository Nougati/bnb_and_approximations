/*****************************************************************************
 *  branch_and_bound_benchmark.c                                             *
 *   Implements a series of benchmarks on instances of KP for my B&B algo    *
 *   Input parameters will decide how this algorithm will function           *
 *   Input parameters to me made:                                            *
 t the program currently does:
  It expects input
    <file> <benchmark set> <memory limit> <timeout> <file_out>
  If benchmark set is
    "tiny_n"
      for n=50
        runs instances 1-9 w/ coeff 1000-10000000

  It does WS, TB and 
What I want it to do:
  Fail if the out file is not a csv
  It needs to be more flexible:
    should be able to specify any subset to benchmark
  Be able to go into instance types
  

Some refactoring thoughts:
  Can I just run the benchmark as a function and assign a value to n, running the benchmark?

void benchmark(char *n_set, char *coefficient_set, char *instance_set, char *branching_stategies)
benchmark_instance(instance_type, problem_no, timeout, allocation_limit)
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
#include "bench_extern.h"
#include "branch_and_bound.h"
#include "pisinger_reader.h"

void benchmark(char *n_set, char *coefficient_set, char *instance_set, char *branching_strategies);
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
      printf("Format: %s <benchmark set> <memory limit> <timeout> <file out>\n"
             "where benchmark_set can be\n\ttiny_n\n\tsmall_n\n\tmidlow_n\n\t"
             "medium_n\n\tmidhigh_n\n\tbig_n\n\thuge_n\n\tmassive_n\nand memor"
             "y_limit can be\n\ta positve integer number of bytes to cap alloc"
             "ation to\n\tor -1 if no limit.\nand timeout can be\n\ta positi"
             "ve integer number of seconds to limit computation to\n\tor -1 if"
             "time is to be unbounded.\n", argv[0]);
  if(argc != 5)
  {
    printf("Format: %s <benchmark set> <memory limit> <timeout> <file out>\n"
           "Type \"%s help\" for info on input options.\n", argv[0], argv[0]);
    exit(-1);
  }

  /* Convert memory_limit to integer */
  int memory_allocation_limit = atoi(argv[2]);

  /* Convert timeout to integer */
  int timeout = atoi(argv[3]);

  char file_name_holder[30];
  const char *instance_types_1[] = { "1", "2", "3", "4", "5", "6", "9"};
  const char *coefficient_types[] = {"1000", "10000", "100000", "1000000", 
                                     "10000000"};
  const char *instance_types_2[] = {"11", "12", "13", "14", "15", "16"};

  /* Problem variables */
  double epsilon = 0.0;
  FILE *logging_stream  = stdout;
  FILE *benchmark_stream = fopen(argv[4],"a");
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int branching_strategy = TRUNCATION_BRANCHING;
  int seed = 0;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;

  fprintf(benchmark_stream, "File name, problem #, runtime, memory allocated\n");
  /* Then if tiny_n */
  if (strcmp("tiny_n", argv[1]) == 0)
  {
    /* Run for n=50 */
    n = 50;

    /* Compute for each instance type, and coefficient type */
    for(int i = 0; i < 7; i++)
    {
      printf("Running for instance %d.\n", i);
      for(int j = 0; j < 5; j++)    
      {
        printf("\tRunning for coefficient type %d\n", j);
        snprintf(file_name_holder, 30, "knapPI_%s_%d_%s.csv", 
                 instance_types_1[i], n, coefficient_types[j]);
        for(int k = 1; k <= 100; k++)
        {
          printf("\t\tRunning for problem %d\n", k);
          pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, file_name_holder, k);
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

          fprintf(benchmark_stream, "%s, %d, %s, %s\n", file_name_holder, k, stringified_time, 
                  stringified_memory);
        }
      }
    }
    /* TODO Run all the 'hard' instances for this n */
  }
  /* Else if small_n */
  if (strcmp("small_n", argv[4]) == 0)
  {
    /* Run for n=100 */
    /* Log to file_out */
  }
  /* Else if midlow_n */
  if (strcmp("midlow_n", argv[4]) == 0)
  {
    /* Run for n=200 */
    /* Log to file_out */
  }
  /* Else if medium_n */
  if (strcmp("medium_n", argv[4]) == 0)
  {
    /* Run for n=500 */
    /* Log to file_out */
  }
  /* Else if midhigh_n */
  if (strcmp("midhigh_n", argv[4]) == 0)
  {
    /* Run for n=1000 */
    /* Log to file_out */
  }
  /* Else if big_n */
  if (strcmp("big_n", argv[4]) == 0)
  {
    /* Run for n=2000 */
    /* Log to file_out */
  }
  /* Else if huge_n */
  if (strcmp("huge_n", argv[4]) == 0)
  {
    /* Run for n=5000 */
    /* Log to file_out */
  }
  /* Else if massive_n */
  if (strcmp("massive_n", argv[4]) == 0)
  {
    /* Run for n=10000 */
    /* Log to file_out */
  }

  return 0;
}

void benchmark(int memory_allocation_limit, int timeout, char *n_set, 
               char *coefficient_set, char *instance_set, 
               char *branching_strategies)
{
  /* Parameterisations to enumerate through */
  char file_name_holder[30];
  const char *instance_types_1[] = { "1", "2", "3", "4", "5", "6", "9"};
  const char *coefficient_types[] = {"1000", "10000", "100000", "1000000", 
                                     "10000000"};
  const char *instance_types_2[] = {"11", "12", "13", "14", "15", "16"};
  const char *n_types[] = {"50", "100", "200", "500", "1000", "2000", "5000", "10000"}

  /* Filetype enumeration begin */
  /* For each branching_strategy */
  for(int i = 0; i < 3; i++)
  {
    /* For each instance */
    for(int j = 0; j < 7; j++)
    {
      /* For each n */
      for(int k = 0; k < 8; k++)
      {
        /* For each coefficient type */
        for(int l = 0; l < 5; l++)
        {
          /* For each problem instance */
          for(int m = 0; m <= 100; m++)
          {
            /* Prepare filename */

            /* Run the benchmark */
                        
          }
        }
      }
    }
  }
}

void benchmark_instance(char *instance_name, int problem_no, int timeout, 
                        int allocation_limit, FILE *benchmark_stream)
{
  /* Problem variables */
  double epsilon = 0.0;
  FILE *logging_stream  = stdout;
  FILE *benchmark_stream = fopen(argv[4],"a");
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int branching_strategy = TRUNCATION_BRANCHING;
  int seed = 0;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;

  pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, file_name_holder, k);
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

  fprintf(benchmark_stream, "%s, %d, %s, %s\n", file_name_holder, k, stringified_time, 
          stringified_memory);
}
