#include <stdio.h>
#include <math.h>
#include <assert.h> 
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "fptas.h"
#include "pisinger_reader.h"

int main(int argc, char *argv[]){
  /* 
   * Description:
   *   This is the main function that tries to use FPTAS as a blackbox
   *
   *     eps -------------->|¯¯¯¯¯¯¯| 
   *     profits ---------->|       |
   *     weights ---------->|       |
   *     x ---------------->|       |
   *     sol_prime -------->|       |-----> sol_prime (updated)
   *     n ---------------->|       |
   *     capacity --------->| FPTAS |
   *     z ---------------->|       |
   *     sol_flag --------->|       |-----> profit_primes (updated)
   *     bounding_method -->|       |
   *     problem_flie ----->|       |
   *     K ---------------->|       |
   *     profit_primes ---->|_______|
   * 
   * Some things to note:
   *   As eps approaches 0, FPTAS's lower bound approaches true solution
   *   As eps approaches 1, FPTAS's lower bound approaches (1-eps)OPT
   *    ... I think
   */

  double eps, K;
  char problem_file[100];
  char output_file[100];
  int *profits, *weights, *x, *profit_primes, *turned_on_variables;
  int n, capacity, z, sol_flag, bounding_method, DP_method;
  int all_instances = 0;
  int output_flag = 0;
  FILE *fp_out;

  /* Command line argument "help" */
  if ((argc == 2)&&(strcmp(argv[1],"help") == 0))
  {
    printf("Usage:\n\t%s <filename> <DP solver> <epsilon> <instance number> <l"
           "ogging rule>\n\tFilename options:"
           "\n\t\tNothing yet!\n\tDP Solver Flags:\n\t\t-v : Vasirani\n\t\t-ws"
           " : Williamson and Shmoy's DP\n\tEpsilon\n\t\tWhatever you like! We"
           "ll, not really, it has to be nonnegative\n\tInstance number:\n\t\t"
           " An integer in the range 1 to 100 inclusive.\n\t\t.. or \"all\" to"
           " read all of the file.\n\t Logging rule:\n\t\t Use \"none\" to not"
           " log anything, otherwise \"filename.csv\" to specify an output fil"
           "e.", argv[0]);
    exit(-1);
  }
  if (argc != 6)
  {
    printf("Usage: %s <filename> <DP solver> <epsilon> <instance number> <logg"
           "ing_rule>\n Type \"%s help\" for info.\n", argv[0], argv[0]);
    exit(-1);
  }
  sscanf(argv[3], "%lf", &eps);
  strcpy(problem_file, argv[1]);

  /* If argv[5] doesn't want output */
  if(strcmp(argv[5], "none")!=0) 
  {
    output_flag = TRUE; 
    strcpy(output_file, argv[5]);
    fp_out = fopen(output_file, "a");
    fprintf(fp_out, "epsilon, problem_file, instance no, runtime, profit(S'), "
                    "z, deviation\n");
  }

  /* Set up iterative FPTAS */
  int problem_number, iter_start, iter_end;

  /* If the user specified all instances to be run */
  if(strcmp(argv[4],"all") == 0)
  {
    all_instances = TRUE;
    iter_start = 1;
    iter_end = 100;
  }else
  {
    iter_start = atoi(argv[4]);
    iter_end = iter_start + 1;
  }
  if(output_flag) printf("Computing");
  
  for(int i = iter_start; i < iter_end; i++)
  {
    /* Parameters have been read in, now read in the problem file */
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, problem_file, i);

    /* This is just for the B&B */
    int active_nodes[n];
    for (int i = 0; i < n; i++) active_nodes[i] = 1;

    sol_flag = BINARY_NOTATION;
    int sol_prime[n];
    for (int i=0; i < n; i++) sol_prime[i] = 0;
    bounding_method = TRIVIAL_BOUND;  
    profit_primes = (int *) malloc(n * sizeof(*profit_primes));
 
    /*Timer Segment Start*/
    clock_t t;
    t = clock();
    /*Timer Segment End*/

    /* Choose DP method and run the FPTAS */
    if(strcmp(argv[2],"-v") == 0)
    {
      DP_method = VASIRANI;
      FPTAS(eps, profits, weights, x, sol_prime, n, capacity, z, sol_flag,
            bounding_method, problem_file, &K, profit_primes, DP_method, 
            active_nodes); 
    }
    else if (strcmp(argv[2],"-ws")==0)
    {
      DP_method = WILLIAMSON_SHMOY;
      FPTAS(eps, profits, weights, x, sol_prime, n, capacity, z, sol_flag,
            bounding_method, problem_file, &K, profit_primes, DP_method,
            active_nodes); 
    }
    else
    {
      printf("Unrecognised flag. Type \"%s help\" for options. Exiting...\n", 
             argv[0]);
      exit(-1);
    }
  
    /*Timer Segment Start*/
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    /*Timer Segment End*/

    /* FPTAS solved a scaled down one. We need to scale profit_primes[i] up by
     *  K for it to be useful */
    float profit_primes_i_times_K; 
    for(int i=0; i<n; i++)
    {
      profit_primes_i_times_K = profit_primes[i]*K;
      profit_primes[i] = profit_primes_i_times_K;
    }
    int kprofitprimeSprime = 0;
    int profitSprime = 0;

    /* Then, for each item in S', we derive Kprofit'(S') and profit(S')*/
    for(int i=0; i<n; i++){
      if (sol_prime[i] == 1){ 
        kprofitprimeSprime += profit_primes[i];
        profitSprime += profits[i];
      }
    }

    /* Output results */
    if(output_flag == TRUE)
    {
      fprintf(fp_out, "%f, %s, %d, %f, %d, %d, %f%s\n", eps, problem_file, i, 
              time_taken, profitSprime, z, 
              (1-((float)profitSprime/(float)z))*100, "%");
      fclose(fp_out);
    }
    else
    {
      printf("%d/%d, epsilon: %f\ttime_taken:  %f\tdeviation: %s%f\n",
             profitSprime, z, eps, time_taken, "%",
             (1-((float)profitSprime/(float)z))*100);
    }

    /* Clean up */
    free(profit_primes);
    free(profits);
    free(weights);
    free(x);
    printf(".");
  }
  if(output_flag) printf(" Done!\n");
  
  return 0;
}

