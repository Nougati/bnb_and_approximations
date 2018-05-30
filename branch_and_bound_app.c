/* Preprocessor definitions */
#define INCLUDE_FPTAS
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
#define NODE_OVERFLOW 1500000

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "branch_and_bound.h"
#include "bench_extern.h"
#include "pisinger_reader.h"
#include "fptas.h"

int main(int argc, char *argv[]) {
  /* Dynamic Input variable support */
  int n, capacity, z;
  int *profits, *weights, *x;
  char problem_file[100];

  /* Command line args support */
  if(argc == 2 && (strcmp(argv[1], "help") == 0))
  {
    printf("Branch strategy flags:\n\t-rb: random branching\n\t-le: linear enu"
           "meration\n\t-tb: truncation branching \nDP Options:\n\t-ws: force "
           "Williamson & Shmoy's DP\n\t-vv: force Vasirani's DP\n\t-smart: let"
           " the program decide.\n\tLogging rule:\n\t-off: do not log anything"
           ".\n\t-console_some: log the big actions of the program to console."
           "\n\t-console_all: log basically all actions to console\n\t<filenam"
           "e>: specify a file to write to.\nEpsilon:\n\t0 to leave it to algo"
           "rithm, else input an eps > 0.\n");
    exit(0);
  }
  if(argc != 7 && argc != 8)
  { 
    printf("Format:\n %s <filename> <problem_no> <DP> <logging rule> <epsilon> <branching strategy>\n", argv[0]);
    printf("or\n %s <filename> <problem_no> <DP> <logging rule> <epsilon> -rb <seed>\n", argv[0]);
    exit(0);
  }
  
  int problem_no = atoi(argv[2]);

  /* Specify DP method */
  int DP_method = -1;
  if(strcmp(argv[3], "-ws") == 0)
    DP_method = WILLIAMSON_SHMOY;
  else if (strcmp(argv[3], "-vv") == 0)
    DP_method = VASIRANI;
  else if (strcmp(argv[3], "-smart") == 0)
    DP_method = SMART_DP; 
  else
  {
    printf("Unrecognised DP flag!\nExiting...\n");
    exit(-1);
  }
  
  /* Specify logging */
  int logging_rule = -1;
  FILE * logging_stream;
  if(strcmp(argv[4], "-off") == 0)
  {  
    logging_rule = NO_LOGGING;
    logging_stream = NULL;
  }
  else if(strcmp(argv[4], "-console_some") == 0)
  {
    logging_rule = PARTIAL_LOGGING;
    logging_stream = stdout;
  }
  else if(strcmp(argv[4], "-console_all") == 0)
  { 
    logging_rule = FULL_LOGGING; 
    logging_stream = stdout;
  }
  else
  {
    logging_rule = FULL_LOGGING;
    logging_stream = fopen(argv[4], "a");
  }

  /* Epsilon choice */
  double epsilon = 0.02;
  sscanf(argv[5], "%lf", &epsilon);

  /* Designate branching strategy variable */
  int branching_strategy;
  time_t seed;
  if(strcmp(argv[6], "-rb") == 0)
  {
    branching_strategy = RANDOM_BRANCHING;
    if (argc != 8)
    {
      printf("Please define a seed!\n For random branching after the -rb flag,"
             " or input \"auto\"\n to allow the program to generate one based "
             "on time(NULL).\n");
      exit(-1);
    }
    if (strcmp(argv[7], "auto") == 0)
      seed = time(NULL);
    else seed = (time_t) atoi(argv[3]);
  }
  else if(strcmp(argv[6], "-le") == 0)
  {
    branching_strategy = LINEAR_ENUM_BRANCHING;
    seed = 0;
  }
  else if(strcmp(argv[6], "-tb") == 0)
  {
    branching_strategy = TRUNCATION_BRANCHING;
    seed = 0;
  }
  else
  {
    printf("Branching strategy flag not recognised!\n");
    exit(-1);
  }
  
  strcpy(problem_file, argv[1]);

  /* Read problem */
  pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, problem_file,
                  problem_no);

  /* Output variables */
  int z_out = 0;
  int number_of_nodes = -1;
  int sol_out[n];

  /* Turn off limits */
  int memory_allocation_limit = -1;
  int timeout = -1;

  /* Start timer */
  clock_t t = clock();

  /* Solve the problem */
  branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, problem_file, branching_strategy,
                                seed, DP_method, logging_rule, logging_stream, 
                                epsilon, &number_of_nodes, 
                                memory_allocation_limit, &t, timeout);

  /* Stop timer */
  t = clock() - t;
  double time_taken = ((double)t)/CLOCKS_PER_SEC;

  printf("No of nodes: %d\n", number_of_nodes);

  if(branching_strategy == RANDOM_BRANCHING) printf("Seed: %ld\n", seed);

  printf("Answer: %d/%d (%s), time taken: %lf\nBytes allocated: %d\n" , z_out,
         z, z_out == z ? "Pass!" : "Failure!", time_taken, bytes_allocated);

  /* Clean up */  
  free(profits);
  free(weights);
  free(x);

  fclose(logging_stream);
  return 0;
}

