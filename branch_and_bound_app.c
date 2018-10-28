/* Preprocessor definitions */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "branch_and_bound_app.h"
#include "branch_and_bound.h"
#include "fptas.h"
#include "bench_extern.h"
#include "pisinger_reader.h"

#ifndef MAIN
#define MAIN
int main(int argc, char *argv[]) {
  /* Dynamic Input variable support */
  int n, capacity;
  long z;
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
           "rithm, else input an eps > 0.\nDualbound type:\n\t0 : a priori bou"
           "nd\n\t1 : bound with just nK\n\t2 : a posteriori nK - ω\n\t3 : rou"
           "nded up profits.\n");
    exit(0);
  }

  /* Catch unexpected argument vector */
  if(argc != 8 && argc != 9)
  { 
    printf("Format:\n %s <filename> <problem_no> <DP> <logging rule> <epsilon>"
           " <dualbound> <branching strategy>\n", argv[0]);
    printf("or\n %s <filename> <problem_no> <DP> <logging rule> <epsilon> <dua"
           "lbound> -rb <seed>\n", argv[0]);
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

  /* Dual bound type */
  int dualbound_type = atoi(argv[6]);
  if(dualbound_type < APRIORI_DUAL || dualbound_type > LINEAR_PROG_DUAL)
  {
    printf("Unrecognised dual bound code specified! Exiting...\n");
    exit(-1);
  }

  /* Designate branching strategy variable */
  int branching_strategy;
  time_t seed;
  if(strcmp(argv[7], "-rb") == 0)
  {
    branching_strategy = RANDOM_BRANCHING;
    if (argc != 9)
    {
      printf("Please define a seed!\n For random branching after the -rb flag,"
             " or input \"auto\"\n to allow the program to generate one based "
             "on time(NULL).\n");
      exit(-1);
    }
    if (strcmp(argv[8], "auto") == 0)
      seed = time(NULL);
    else seed = (time_t) atoi(argv[3]);
  }
  else if(strcmp(argv[7], "-le") == 0)
  {
    branching_strategy = LINEAR_ENUM_BRANCHING;
    seed = 0;
  }
  else if(strcmp(argv[7], "-tb") == 0)
  {
    branching_strategy = TRUNCATION_BRANCHING;
    seed = 0;
  }
  else
  {
    printf("Branching strategy flag not recognised!\n");
    exit(-1);
  }
  
  /* Read problem */
  strcpy(problem_file, argv[1]);
  pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, problem_file,
                  problem_no);

  /* Output variables */
  long z_out = 0;
  int number_of_nodes = -1;
  int sol_out[n];

  /* Turn off limits */
  int memory_allocation_limit = -1;
  int timeout = -1;

  char str_DP_method[50];
  char str_dualbound_type[50];
  char str_branching_strategy[50];

  /* Prepare info variables */
  if(DP_method == VASIRANI) 
    strcpy(str_DP_method, "Vasirani's DP algorithm");
  else if(DP_method == WILLIAMSON_SHMOY) 
    strcpy(str_DP_method, "Williamson Shmoy's DP algorithm");
  else if(DP_method == SMART_DP) 
  {
    strcpy(str_DP_method, "SMART DYNAMIC PROGRAMING!!!!!!!11!1");
    exit(-1);
  }
  if(dualbound_type==APRIORI_DUAL)
    strcpy(str_dualbound_type, "A priori dual bound");
  else if(dualbound_type==APOSTERIORI_DUAL_PLUS_NK)
    strcpy(str_dualbound_type, "Plus nK dual bound");
  else if(dualbound_type==APOSTERIORI_DUAL_NK_MINUS_OMEGA)
    strcpy(str_dualbound_type, "Plus nK - ω dual bound");
  else if(dualbound_type==APOSTERIORI_DUAL_ROUNDUP)
    strcpy(str_dualbound_type, "Rounded up profits dual bound");
  else if(dualbound_type==LINEAR_PROG_DUAL)
  {
    strcpy(str_dualbound_type, "Linear programming dual bound");
    strcpy(str_branching_strategy, "Fractional branching (this is forced for LP)");

  }
  if(dualbound_type != LINEAR_PROG_DUAL)
  {
    if(branching_strategy == LINEAR_ENUM_BRANCHING)
      strcpy(str_branching_strategy, "Linear search enumeration branching");
    else if(branching_strategy == RANDOM_BRANCHING)
      strcpy(str_branching_strategy, "Random variable branching");
    else if(branching_strategy == TRUNCATION_BRANCHING)
      strcpy(str_branching_strategy, "Truncation branching");
  }
  printf("Problem specification: \n\tProblem #%d of %s"
         "\n\tDP method: %s"
         "\n\tEpsilon: %f"
         "\n\tDualbound type: %s"
         "\n\tBranching strategy: %s\n", problem_no, problem_file, 
          str_DP_method, epsilon==0 ? 0.002 : epsilon, str_dualbound_type, str_branching_strategy);

  /* Start timer */
  clock_t t = clock();

  /* Solve the problem */
  branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, problem_file, branching_strategy,
                                seed, DP_method, logging_rule, logging_stream, 
                                epsilon, &number_of_nodes, 
                                memory_allocation_limit, &t, timeout, 
                                dualbound_type);


  /* Stop timer */
  t = clock() - t;
  double time_taken = ((double)t)/CLOCKS_PER_SEC;

  /* Print results */
  if(branching_strategy == RANDOM_BRANCHING) printf("Seed: %ld\n", seed);
  printf("Results:\n\t%ld/%ld (%s)\n\ttime taken: %lf\n\tBytes allocated: %lld\n" , z_out,
         z, z_out == z ? "Pass!" : "Failure!", time_taken, bytes_allocated);
  printf("\tNo of nodes: %d\n", number_of_nodes);

  /* Clean up */  
  free(profits);
  free(weights);
  free(x);

  fclose(logging_stream);
  return 0;
}
#endif

