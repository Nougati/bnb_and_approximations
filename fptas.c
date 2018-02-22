/**fptas2.c********************************************************************
 * TODO                                                                       *
 *  - Go over code to more easily support Williamson and Shmoy's DP too       *
 *  - Set up iterative FPTAS                                                  *
 *                                                                            *
 *  Really big epsilons:                                                      *
 *    Basically for epsilon >= 1, the lower bound guarantee relative to OPT   *
 *    goes to 0. P lower bounds OPT, but P decreases in the truncated profits,*
 *    so its guarantees decrease too.                                         *
 *                                                                            *
 ******************************************************************************/

#include <stdio.h>
#include <math.h>
#include <assert.h> 
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define VASIRANI 0
#define WILLIAMSON_SHMOY 1
#define INDEX_NOTATION 0
#define BINARY_NOTATION 1
#define HYPER_TRIVIAL_BOUND 1
#define TRIVIAL_BOUND 2
#define TRUE 1
#define VARIABLE_ON 2
#define VARIABLE_UNCONSTRAINED 1
#define VARIABLE_OFF 0


#define typename(x) _Generic((x),        /* Get the name of a type */             \
                                                                                  \
        _Bool: "_Bool",                  unsigned char: "unsigned char",          \
         char: "char",                     signed char: "signed char",            \
    short int: "short int",         unsigned short int: "unsigned short int",     \
          int: "int",                     unsigned int: "unsigned int",           \
     long int: "long int",           unsigned long int: "unsigned long int",      \
long long int: "long long int", unsigned long long int: "unsigned long long int", \
        float: "float",                         double: "double",                 \
  long double: "long double",                   char *: "pointer to char",        \
       void *: "pointer to void",                int *: "pointer to int",         \
      default: "other")
/*
#define min(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a < _b ? _a : _b; })
*/
/* Function Prototypes */
struct problem_item
{
  int weight;
  int profit;
};


struct solution_pair 
{
  int weight;
  int profit;
  struct solution_pair *next;
  /* Begin tentative changes */  
  int solution_array[];
  /* End tentative changes */ 
};

int williamson_shmoys_DP(struct problem_item items[], int capacity, int n, 
                         int *solution_array);
void push(struct solution_pair** head_ref, int new_weight, int new_profit, 
          int n);
void remove_dominated_pairs(struct solution_pair** head_ref);
void merge_sort(struct solution_pair** head_ref);
struct solution_pair* sorted_merge(struct solution_pair* a, 
                                   struct solution_pair* b);
void front_back_split(struct solution_pair* source, 
                      struct solution_pair** front_ref, 
                      struct solution_pair** back_ref);
void print_list(struct solution_pair* node);

void DP(const int problem_profits[],
        const int problem_weights[],
        const int x[],
        int sol[],
        const int n,
        const int capacity,
        const int z,
        const int sol_flag,
        const int bounding_method,
        const char *problem_file);

int DP_p_upper_bound(const int problem_profits[],
                     const int n,
                     const int P,
                     const int bounding_method);

void pisinger_reader(int *n, int *c, int *z, int **p, int **w, int **x,
                     char *problem_file, int problem_no);

void FPTAS(double eps, 
           int *profits,
           int *weights,
           int *x,
           int *sol_prime,
           const int n,
           int capacity,
           const int z,
           const int sol_flag,
           const int bounding_method,
           const char *problem_file,
           double *K,
           int *profits_prime,
           const int DP_method,
           const int *variable_statuses);

int DP_max_profit(const int problem_profits[],
                  const int n);

float define_K(double eps,
               int P,
               int n);

void make_profit_primes(int *profits,
                        int *profits_prime,
                        double K,
                        int n,
                        const int *active_nodes);

void DP_fill_in_base_cases(const int width,
                           const int n,
                           int ** DP_table, //int DP_table[][width],
                           const int problem_profits[],
                           const int problem_weights[]);

void DP_fill_in_general_cases(const int width,
                              const int n,
                              int ** DP_table, //int DP_table[][width],
                              const int problem_profits[],
                              const int problem_weights[]);

int derive_pinf(const int problem_weights[],
                const int n);

int DP_find_best_solution(const int width,
                          const int n,
                          int ** DP_table, //const int DP_table[][width],
                          const int capacity,
                          const int my_pinf);

int DP_derive_solution_set(int n,
                           const int width,
                           int **, //const int DP_table[][width],
                           const int problem_profits[],
                           int solution[],
                           int p,
                           const int sol_flag);

int p_upper_bound_aux(const int problem_profits[],
                      const int n);
/* End Function Prototypes */

#ifndef TESTING
#ifndef INCLUDE_FPTAS
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
   *     Input files: "knapPI_1_50_1000.csv"
   *                  "small_instance"
   *                  "knapPI_1_100_1000.csv"
   *                  "knapPI_1_1000_1000.csv"
   *                  "knapPI_11_1000_1000.csv" <- Hard
   *                  "knapPI_11_10000_1000.csv" <- Hard instance
   *                  "knapPI_16_1000_1000.csv" <- Hard
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
    if(output_flag == TRUE){
      fprintf(fp_out, "%f, %s, %d, %f, %d, %d, %f%s\n", eps, problem_file, i, 
              time_taken, profitSprime, z, 
              (1-((float)profitSprime/(float)z))*100, "%");
      fclose(fp_out);
    }else{
     printf("%d/%d, epsilon: %f\ttime_taken:  %f\tdeviation: %s%f\n", profitSprime, z, eps, time_taken,
            "%", (1-((float)profitSprime/(float)z))*100);
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
#endif
#endif

void FPTAS(double eps, 
           int *profits,
           int *weights,
           int *x,
           int *sol_prime,
           const int n,
           int capacity,
           const int z,
           const int sol_flag,
           const int bounding_method,
           const char *problem_file,
           double *K,
           int *profits_prime,
           const int DP_method,
           const int *variable_statuses){
  /* Description
   *  Recreates the FPTAS for the 0,1 KP as described by V. Vasirani in his
   *   chapter on Knapsack in Approximation Algorithms.
   * Inputs
   *  eps - the epsilon value representing the level of approximation on the
   *        result. A lower epsilon value will indicate less error and thus 
   *        worse performance in terms of time. Epsilon is a positive real 
   *        number no greater than 1.
   *  profits - The input profit array
   *  weights - The input weight array
   *  x - The input problem optimal solution binary representation
   *  sol_prime - The array for the approximate solution S' to be stored. This 
   *   It is by definition the optimal solution to the KP problem with profits 
   *   described by profits_prime. For our purposes it'll stored as a bitstr.
   *  n - the number of items in the problem
   *  capacity - the capacity of the knapsack as specified by the problem
   *  sol_flag - a flag which should always be 1 (binary).
   *  bounding_method - a flag which should always be 2 (simple sum)
   *  problem_file - just the string of the problem file
   *  K - the husk where we store the K value determined by this algo.
   */
  int P = DP_max_profit(profits, n);

  /* Define K */
  *K = define_K(eps, P, n);

  /* Derive adjusted profits (and trivialise constrained nodes 0) */
  make_profit_primes(profits, profits_prime, *K, n, variable_statuses); 


  /* Adjust capacity according to nodes constrained to be in */
  for (int i = 0; i < n; i++)
    if (variable_statuses[i] == VARIABLE_ON)
      capacity -= weights[i];

  /* Now with amended profits list "profit_primes," solve the DP */
  if (DP_method == VASIRANI)
  {
    DP(profits_prime, weights, x, sol_prime, n, capacity, z, sol_flag, 
       bounding_method, problem_file);
  }
  else if (DP_method == WILLIAMSON_SHMOY)
  {
    /* Make problem item struct array */
    struct problem_item items_prime[n];
    for(int i = 0;  i < n; i++)
    {
      items_prime[i].weight = weights[i];
      items_prime[i].profit = profits_prime[i];
    }
    int result = williamson_shmoys_DP(items_prime, capacity, n, sol_prime);
    /* sol_prime analysis is done outside for some reason */
  }
  /* Solution should be in sol_prime */
}

/* vasirani_dp.c begin */
void DP(const int problem_profits[], // profit primes?
        const int problem_weights[],
        const int x[],
        int sol[],
        const int n,
        const int capacity,
        const int z,
        const int sol_flag,
        const int bounding_method,
        const char *problem_file){
  /*
    Description:
      Carries out DP to compute the optimal solution for knapsack,
       given profits and weights.
    Inputs:
      problem_profits (int *) array start
      problem_weights (int *) array start
      sol (int *) array start - the output array
      n - the number of items in the array
    Postconditions:
      The array S will be totally filled out
    Notes:
      Indexing for this will be confuuusing
  */

  // Find max profit item
  int max_profit = DP_max_profit(problem_profits,
                                 n);

  // Find upper bound on p for DP
  int p_upper_bound = DP_p_upper_bound(problem_profits,
                                       n,
                                       max_profit,
                                       bounding_method);
  // Define DP table (n+1)*(nP)
  //int (*DP_table)[p_upper_bound] = malloc(sizeof(*DP_table) * (n+1));
  int **DP_table = (int **) malloc(sizeof(int *) * (n+1));
  DP_table[0] = (int *)malloc(sizeof(int) * p_upper_bound * (n+1));
  for(int i = 0; i < (n+1); i++)
    DP_table[i] = (*DP_table + p_upper_bound * i);

  printf("DP table is %d * %d\n", (n+1),  p_upper_bound);
  // Compute base cases

  DP_fill_in_base_cases(p_upper_bound,
                        n+1,
                        DP_table,
                        problem_profits,
                        problem_weights);

  // Compute general cases
  DP_fill_in_general_cases(p_upper_bound,
                           n+1,
                           DP_table,
                           problem_profits,
                           problem_weights);
  int my_pinf = derive_pinf(problem_weights, n);

  int p = DP_find_best_solution(p_upper_bound,
                                n+1,
                                DP_table,
                                capacity,
                                my_pinf);

  int n_solutions = DP_derive_solution_set(n+1,
                                           p_upper_bound,
                                           DP_table,
                                           problem_profits,
                                           sol,
                                           p,
                                           sol_flag);
  free(DP_table);
  free(DP_table[0]);
}

int DP_max_profit(const int problem_profits[],
                  const int n){
  /*
    Description:
      Finds the highest profit in the array of item profits. In terms of Vasirani's notation
       this is P. 
    Inputs:
      problem_profits - the profit array
      n - the number of objects
    Outputs:
      max - the value of the highest profit item.
  */
  int max = 0;
  for(int i = 0; i < n; i++){
    if (max < problem_profits[i]){
      max = problem_profits[i];
    }
  }
  return max;
}

int DP_p_upper_bound(const int problem_profits[],
                     const int n,
                     const int P,
                     const int bounding_method){
  /*
    Description:
      Derives the upper bound for the DP table, based on the bounding
       method specified.
    Inputs:
      problem_profts[] - the profit array
      n - the number of objects
      P - the highest profit among every item in the set
  */
  int upper_bound;

  switch (bounding_method){
    case HYPER_TRIVIAL_BOUND: upper_bound = n*P; break;
    case TRIVIAL_BOUND: upper_bound = p_upper_bound_aux(problem_profits, n); break;
    default: printf("Invalid bounding method! Exiting...\n");
    exit(-1);
  }

  return upper_bound;
}

int p_upper_bound_aux(const int problem_profits[],
                      const int n){
  /*
    Description:
      An auxiliary function used to calculate the intelligent trivial
       upper bound on the profit.
    Inputs:
      problem_profits[] -  the profit array
      n - the number of objects
    Outputs:
      total - the sum of all the item profits
    Notes:
      There's a funny story behind this function.
  */

  int total=0;

  for(int i=0; i < n; i++){
    total += problem_profits[i];
  }
  return total;
}

void DP_fill_in_base_cases(const int width,
                           const int n,
                           int ** DP_table, //int DP_table[][width],
                           const int problem_profits[],
                           const int problem_weights[]){
  /*
    Description:
      Fills in the base cases for the DP. In Vasirani's terminology this
       is every A(1,p) for every p between 0 and width.
    Inputs:
      width - the upper bound on the width of the table
      n - the number of rows. Remember this is passed in as n+1 to account
           for the 0th row of the table. As a result derive_pinf passes n-1
      DP_table - the two dimensional array to calculate the DP in
    Preconditions:
      The space for the table must be allocated
    Postconditions:
      The first row should indicate the minimum size solutions for the
      specified solution subset. Also, impossible solutions will be
       represented by infinity
    Notes:
      The rows of the table is expected to represent the number of items
       included. The columns of the table is expected to represent the
       maximum profit achievable.
      Also worth mentioning:
       A(i,p) = A[i][p]
      Another thing: I couldn't use the in built pinf because it was a double
       being stored in an int array. Instead I've defined my_pinf, which is a
       simple upper bound on the problem_weight of any solution represented by
       the sum of all the items in problem_weights + 1.
       This has led to the definition of the function derive_pinf.
  */

  int my_pinf = derive_pinf(problem_weights, n-1);
  // Go over the first column with 0's
  for(int i = 0; i < n; i++){
     DP_table[i][0] = 0;
  }

  // Go over the first row with infinities
  for(int i = 1; i < width; i++){
    DP_table[0][i] = my_pinf;
  }
}

void DP_fill_in_general_cases(const int width,
                              const int n,
                              int ** DP_table, //int DP_table[][width],
                              const int problem_profits[],
                              const int problem_weights[]){
  /*
    Description:
      Fills in the fields of the DP table which are defined by the
       general recurrence.
      Specifically fields A[1][nP] to A[n][nP] (using Vasirani's definition)
    Inputs:
      width - the upper bound on p, the max allowable profit for the given
               subproblem.
      n - the number of items and also the number of rows in the DP table
      DP_table - the n*width table which will store our solution.
      problem_profits - an array of all the problem profits
      problem_weights - an array of all the problem weights
    Preconditions:
      The base cases must be filled in for this general algorithm to return
       a reasonable result. For our purposes, the base cases include the cases
       where profit is 0 and where items = 0
    Postconditions:
      Hopefully a completed DP table which will, within it, contain the optimal
       solution to the 0,1 Knapsack.
    Notes:
      Serious consideration: the problem_profits are 0-indexed, as are the problem
       weights.
      As a result the field A[1][1] is actually the solution which considers the
       combination of problem_profits[0] and problem_weights[0].
      This means when designing this, it is *crucial* to account for this semantic
       indexing issue.
  */

  int a, b;
  for (int p = 1; p < width; p++){
    for (int i = 1; i < n; i++){
      if (problem_profits[i-1] <= p){
        a = DP_table[i-1][p];
        b = problem_weights[i-1] + DP_table[i-1][(p-problem_profits[i-1])];
        //DP_table[i][p] = min(a,b);
        DP_table[i][p] = ((a < b) ? a : b);
      }else DP_table[i][p] = DP_table[i-1][p];
    }
  }
}

int derive_pinf(const int problem_weights[],
                const int n){
  /*
    Description:
      Sums up all the item weights to obtain a trivial upper bound on the weight
      of any given solution.
    Input:
      problem_weights - a 1D array of the problem's weight values.
    Output:
      my_pinf - my version of positive infinity.
    Notes:
      This is a purely symbolic representation of infinity that adds a single linear
       pass of the weight set to the run time.
  */

  int my_pinf = 1;
  for(int i = 0; i < n; i++){
    my_pinf += problem_weights[i];
  }
  return my_pinf;
}

int DP_find_best_solution(const int width,
                          const int n,
                          int ** DP_table, //const int DP_table[][width],
                          const int capacity,
                          const int my_pinf){
  /*
    Description:
      Given a completed DP_table, find max(p | A(n,p) <= Capacity)
    Inputs:
      width - the width of the tables
      n - the height of the table (also the number of items)
      DP_table - the dynamic programming 2d array
      problem_profits - the input problem's associated item profits
      problem_weights - the input problem's associated item weights
      capacity - the input problem's knapsack capacity
      my_pinf - the input problem's trivial upper bound on weight
    Preconditions:
      DP_table must be completed, both in basis and in general case, for us
       to derive an optimal solution.
    Outputs:
      p - the max(p | A(n,p) <= Capacity)
    Notes:
      This is simply the profit of the optimal solution, nothing else.
      In order to derive the item set, more analysis needs to be done.
  */

  int p= -1;
  for(int i = width-1; i >= 0; i--){
    if (DP_table[n-1][i] != my_pinf){
      if (DP_table[n-1][i] <= capacity){
        p = i;
        break;
      }
    }
  }
  return p;
}

int DP_derive_solution_set(int n,
                           const int width,
                           int ** DP_table, //const int DP_table[][width],
                           const int problem_profits[],
                           int solution[],
                           int p,
                           const int sol_flag){

  /*
    Description:
      Given a completed DP_table, derive the indices of the items of the optimal set.
    Inputs:
      n - the number of rows in the Dynamic Programming table
      DP_table - the 2d array representing the constituent subproblems of the DP
      solution - the output array; it will simply hold the indices of the items that
       are included in the optimal solution.
      p - the profit of the optimal solution
      sol_flag - if 0, index notation, if 1, 0/1 notation
    Postconditions:
      solution will be filled out
    Notes:
      
  */

  int s_index = 0;
  while ((p > 0)&&(n > 0)){
    if (DP_table[n-2][p] > DP_table[n-1][p]){
      // then we had item n and the solution at A[n-1][p-profit(n)]
      if(sol_flag == INDEX_NOTATION) solution[s_index] = (n-1);
      else solution[n-2] = 1;
      s_index += 1;
      n -= 1;
      p -= problem_profits[n-1]; // remember table n corresponds to profit n-1
    }else{
      // A[n-1][p] must be the same as A[n][p]
      if (sol_flag != INDEX_NOTATION) solution[n-2] = 0;
      n -= 1;
    }
  }
 return s_index;
}
/* vasirani_dp.c end */

/* williamson_shmoy_dp.c begin */

int williamson_shmoys_DP(struct problem_item items[], int capacity, int n,
                         int *solution_array)
{
 /***william_shmoys_DP********************************************************
  *  Description: Implements the dynamic programming algorithm for the       *
  *               knapsack problem as described by Williamson and Shmoys.    *
  *  Inputs:                                                                 *
  *    struct problem_item items[]                                           *
  *      An array of all the items in the problem instance, built from       *
  *      reading and encoding an input file. Each item struct has profit     * 
  *      and weight members.                                                 *
  *    int capacity                                                          *
  *      The capacity as described by the problem statement                  *
  *  Outputs:                                                                *
  *    int w                                                                 *
  *      the max weight of a tuple in the list at the end of the algorithm   *
  *  Notes:                                                                  *
  *                                                                          *
  ****************************************************************************/

  /* Base case */
  struct solution_pair* head = NULL;
  struct solution_pair* current; 
  push(&head, 0, 0, n);
  /* ASSUMPTION MADE: the 0'th item will feasibly fit! */
  push(&head, items[0].weight, items[0].profit, n);
  head->solution_array[0] = 1;

  /* General case */
  for(int j=1; j < n; j++)
  {
    current = head;
    while(current != NULL)
    {
      /* Only add if we can feasibly add it */
      int possible_weight = current->weight + items[j].weight;
      if (possible_weight <= capacity)
      {
        /* Put new partial solution on the head */
        push(&head, possible_weight, current->profit + items[j].profit, n);
        /* Copy the partial solution array  */
        for (int i=0; i <= j; i++)
          head->solution_array[i] = current->solution_array[i];
        /* Distinguish it from the others */
        head->solution_array[j] = 1;
      }
      current = current->next;
    }
    remove_dominated_pairs(&head);
  }

  /* return max ((t,w) in A max) w*/
  current = head;
  struct solution_pair* best_pair;
  int max_profit = -1;
  while (current != NULL)
  {
    if (current->profit > max_profit)
      max_profit = current->profit;
      best_pair = current;
    current = current->next;  
  }

  /* Assuming solution_array has been malloc'd already */
  for(int i=0; i < n; i++)
  {
    solution_array[i] = best_pair->solution_array[i];
  }


  /* Clean up */
  current = head;
  while (current != NULL)
  {
    current = current->next;
    free(head);
    head = current;
  }
  /* TODO Find out if we need to clena up individual struct arrays */

  return max_profit;
}

void push(struct solution_pair** head_ref, int new_weight, int new_profit,
          int n)
{
 /***push*********************************************************************
  *  Description:                                                            *
  *    Given a pointer to a solution_pair structure pointer (the head of a   *
  *    linked list of such structures), link a new structure into the list   *
  *    with given weight new_weight and profit new_profit.                   *
  *  Postconditions:                                                         *
  *    This will put the new structure at the top of the list.               *
  *  Notes:                                                                  *
  *    This is taken from the geeksforgeeks linked list mergesort article    *
  *    This needs n in order to dynamically allocate enough space for the    *
  *    struct member solution_array                                          * 
  ****************************************************************************/
  /* Allocate memory for the new solution pair 
  struct solution_pair* new_solution_pair = 
    (struct solution_pair*) malloc(sizeof(struct solution_pair) + n * sizeof(int));
  */
  /*Tentative start*/
  /*Start temp white-out*/
  struct solution_pair* new_solution_pair =
     (struct solution_pair*)calloc(sizeof(struct solution_pair) + n, sizeof(int));
  /*End*/


  if (new_solution_pair)
  {
    struct solution_pair const temp_pair =
      {.weight = new_weight, .profit = new_profit, .next=(*head_ref)};
     memcpy(new_solution_pair, &temp_pair, sizeof(struct solution_pair));
    
  }

  /*Tentative end*/

  /* Define new pair's data */
  new_solution_pair->weight = new_weight;
  new_solution_pair->profit = new_profit;

  /* Connect pair to the head of the list */
  new_solution_pair->next = (*head_ref);

  
  /* TENTATIVE Initialise the array to 0's*/
  for(int i = 0; i < n; i++)
    *(new_solution_pair->solution_array+i) = 0;
 
  /* Set the new node to be the new head of the list */
  (*head_ref) = new_solution_pair;
}

void remove_dominated_pairs(struct solution_pair** head_ref)
{
 /***remove_dominated_pairs documentation*************************************
  *  Description:                                                            *
  *    Removes the dominated pairs within a linked list of solution_pairs by *
  *    a two phase approach consistening of a merge sort on each of the      * 
  *    weights and a series of iteratively shortening comparisons based on   *
  *    the profits.                                                          *
  *  Inputs:                                                                 *
  *    struct solution_pair** headRef                                        *
  *      Double pointer to the head of the linked list to allow for          *
  *      reallocation of the head, should it be dominated                    * 
  *  Postconditions:                                                         *
  *    Linked list will have entirely non-dominated pairs.                   *
  *  Notes:                                                                  *
  *    Has function dependencies in merge sort and all of its constituent    *
  *    functions                                                             *
  *    This function assumes that the (0,0) tuple will always be in an input.*
  *    As such, the case where the linked list is of length 0 is not         *
  *    addressed. The algorithm seems resilient enough to cover length=1     *
  *    with its general case.                                                *
  ****************************************************************************/

  /* Merge sort the list by weight */
  merge_sort(head_ref);

  struct solution_pair* current = (*head_ref)->next;
  struct solution_pair* previous = *head_ref;

  /* Filtration algorithm */
  while (current != NULL)
  {
    if (previous->profit >= current->profit)
    {
      current = current->next;
      free(previous->next);
      previous->next = current;
    }
    else
    {
      current = current->next;
      previous = previous->next;
    }
  }
}

void merge_sort(struct solution_pair** head_ref)
{
 /* merge_sort: my adapation for solution pairs as originally described by    *
  *             geeks for geeks.                                              *
  *             This is strictly designed for linked lists                    *
  *             This algorithm is said to have complexity O(nlogn)            */
  struct solution_pair* head = *head_ref;
  struct solution_pair* a;
  struct solution_pair* b;

  /* Bases: length 0 or 1 */
  if ((head == NULL) || (head->next == NULL))
    return;

  /* Split head into 'a' and 'b' sublists */
  front_back_split(head, &a, &b);

  /* Recursively sort the sublists */
  merge_sort(&a);
  merge_sort(&b);

  /* Merge the two lists of this scope together */
  *head_ref = sorted_merge(a, b);
}

struct solution_pair* sorted_merge(struct solution_pair* a, 
                                   struct solution_pair* b)
{
  struct solution_pair* result = NULL;
  
  /* Base cases */
  if (a == NULL) return (b);
  else if (b == NULL) return (a);

  /* Pick the lower of either a or b, and recur */
  if (a->weight <= b->weight)
  {
    /* Corner case: if they're equal weighted, put the one with the higher 
       profit first. This simplifies the cases we have to consider within
       the filtration step of dominated pair removal */
    if (a->weight == b->weight)
    {
      if (a->profit > b->profit) 
      {
        result = a;
        result->next = sorted_merge(a->next, b);
      }
      else 
      {
        result = b;
        result->next = sorted_merge(a, b->next);
      }
    }
    /* Otherwise just merge as normal */
    else
    {
      result = a;
      result->next = sorted_merge(a->next, b);
    }
  }
  else
  {
    result = b;
    result->next = sorted_merge(a, b->next);
  }
  return(result);
}

void front_back_split(struct solution_pair* source, 
                      struct solution_pair** front_ref, 
                      struct solution_pair** back_ref)
{
  struct solution_pair* fast;
  struct solution_pair* slow;
  if (source == NULL || source->next == NULL)
  {
    /* Length < 2 cases */
    *front_ref = source;
    *back_ref = NULL; 
  }
  else
  {
    slow = source;
    fast = source->next;

    /* Advance 'fast' by two nodes, and advance 'slow' by one */
    while (fast != NULL)
    {
      fast = fast->next;
      if (fast != NULL)
      {
        slow = slow->next;
        fast = fast->next;
      }
    }
    /* 'slow' is before the midpoint in the list, so split it at that point */
    *front_ref = source;
    *back_ref = slow->next;
    slow->next = NULL;
  }
}

void print_list(struct solution_pair* node)
{
  while(node!=NULL)
  {
    printf("%d ", node->profit);
    node = node->next;
  }
}


/* williamson_shmoy_dp.c end */

float define_K(double eps, int P, int n){
  /* Description: 
   *   Defines real valued scaling factor K. K is epsP/n. As eps approaches 0, K does too.  
   *    As eps approaches 1, K approaches P/n. As eps exceeds 1, K scales progressively larger
   *    than the n-way split of P.
   * Inputs: 
   *  
   * Output:
   *  
   * Notes:
   *  Epsilon can indeed exceed 1 as soon as epsilon hits 1 the lower bound guarantee on the
   *   profit with respect to OPT drops completely and is bounded trivially by 0. As a result,
   *   a stronger lower bound would be P at this point, however there is no guarantee on how
   *   this adjusted P will look. It may well be positive but with increasing epsilon values 
   *   it would seem that P's would be crushed to a low point. 
   */
  
  // assert eps > 0
  assert(eps > 0);
  //assert(eps <= 1); TODO TURN THIS BACK ON???  

  double K = (eps*P)/n;
  // define K

  return K;
  // return K
}

void make_profit_primes(int profits[], int profits_prime[], double K, int n,
                        const int *variable_statuses){
 /* 
  * Description: 
  *  Derives the adjusted profits set profits', which is made by scaling every
  *   profit down by 1/K and flooring the result.
  * Inputs:
  *
  * Postconditions:
  *  
  * Notes:
  *  As eps increases, K increases, and so the profit' of each item will get scaled further
  *   and further downwards. Since P is the max, it will be scaled to 1 for eps = 1 TODO
  *   explain this better
  *   
  */
  
  for(int i=0; i < n; i++)
  {
    if(variable_statuses[i] == VARIABLE_UNCONSTRAINED)
    {
      double scaled_profit = profits[i]/K;
      profits_prime[i] = floor(scaled_profit);
    }
    else
      profits_prime[i] = VARIABLE_OFF; // We just make the item dominated
  }
}
/*

void pisinger_reader(int *n, int *c, int *z, int **p, int **w, int **x, char *problem_file){ 
  /* 
   * Description:
   *   Reads pisinger's csv knapsack instances into arrays. This does not work 
   *    on his automatically generated instances.
   * Inputs:
   *
   * Notes:
   * 
   *
  FILE *fp;
  char str[256];
  char * pch;

  fp = fopen(problem_file, "r");

  /* Get n *
  if (fp == NULL) 
  {
    printf("Problem opening the file!\n");
    exit(EXIT_FAILURE);
  }
  while (fgets(str, sizeof(str), fp)){
    if (str[0] == 'n'){
      pch = strtok(str, " ");
      pch = strtok(NULL, " ");
      *n = atoi(pch);
      break;
    }
  }

  int *tmp_p = (int *)malloc(*n * sizeof(*tmp_p));
  int *tmp_w = (int *)malloc(*n * sizeof(*tmp_w));
  int *tmp_x = (int *)malloc(*n * sizeof(*tmp_x));

  int counter=0;
  if (fp == NULL) exit(EXIT_FAILURE);
  while ((fgets(str, sizeof(str), fp))&&(counter<*n)){

  if(str[0] == 'c'){
      pch = strtok(str, " ");
      pch = strtok(NULL, " ");
      *c = atoi(pch);
  }else if (str[0] == 'z'){
      pch = strtok(str, " ");   
      pch = strtok(NULL, " ");
      *z = atoi(pch);
  }else if (!((str[0] == 'n')
            ||(str[0] == 'z')
            ||(str[0] == 'k')
            ||(str[0] == 't'))){

      pch = strtok(str, ",");
      pch = strtok(NULL, ",");

      tmp_p[counter] = atoi(pch);

      pch = strtok(NULL, ",");

      tmp_w[counter] = atoi(pch);

      pch = strtok(NULL, ",");

      tmp_x[counter] = atoi(pch);

      counter += 1;

    }
  }
  fclose(fp);

  *p = tmp_p;
  *w = tmp_w;
  *x = tmp_x;
}
*/

void pisinger_reader(int *n, int *c, int *z, int **p, int **w, int **x, 
                     char *problem_file, int problem_number)
{ 
  /* 
   * Description:
   *   Reads pisinger's csv knapsack instances into arrays. This does not work 
   *    on his automatically generated instances.
   * Inputs:
   *
   * Notes:
   *   This has been edited to support dynamic allocation error catching.  
   */
  /* Make sure the reader was given a valid problem index */
  if (problem_number <= 0 || problem_number > 100)
  {
    printf("Bad problem number. Exiting...\n");
    exit(EXIT_FAILURE);
  }
  FILE *fp;
  char str[256];
  char * pch;
  char problem_number_str[100];

  /* Get data about the instance itself
   * TODO Get this supporting instance types of more than one digit */
  int coefficient_size;
  sscanf(problem_file, "knapPI_%*d_%d_%d.csv", n, &coefficient_size);
  int ndigits = floor(log10(abs(*n)))+1;
  int cdigits = floor(log10(abs(coefficient_size)))+1;
  int pnodigits = floor(log10(abs(problem_number)))+1;

  /* From this, we deduce the length of the instance name */
  int instance_name_width = 11+ndigits+cdigits+pnodigits;

  /* Problem number needs to be concatenated onto char array instance_name */
  /* So, we convert it to a string. */
  sprintf(problem_number_str, "%d", problem_number);

  /* Create the instance name of form knapPI_<instance>_<n>_<coeff>_<pno>*/
  char instance_name[50];
  strncpy(instance_name, problem_file, instance_name_width-pnodigits-1);
  //strcat(instance_name, "_");
  instance_name[instance_name_width-pnodigits-1] = '_';
  instance_name[instance_name_width-pnodigits] = '\0';
  strcat(instance_name, problem_number_str);

  /* Open file */
  char path[80];
  strcpy(path, "./problems/");
  strcat(path, problem_file);
  fp = fopen(path, "r");
  if (fp == NULL)
  {
    printf("Unable to open file. Exiting...\n");
    exit(EXIT_FAILURE);
  }

  /* Find instance in file */
  while(strncmp(fgets(str, sizeof(str), fp), instance_name, instance_name_width) != 0)
    ;

  /* Extract n */
  while (fgets(str, sizeof(str), fp)){
    if (str[0] == 'n'){
      pch = strtok(str, " ");
      pch = strtok(NULL, " ");
      *n = atoi(pch);
      break;
    }
  }

  /* Allocate profits array */
  int *tmp_p;
  if((tmp_p = (int *)malloc(*n * sizeof(*tmp_p)))==NULL)
  {  //tperror("Error allocating space for profits\n");
    fprintf(stderr, "Cannot malloc tmp_x!\n");
    exit(1);
  }

  /* Allocate weights array */
  int *tmp_w;
  if((tmp_w = (int *)malloc(*n * sizeof(*tmp_w)))==NULL)
  {  //perror("Error allocating space for weights\n");
    fprintf(stderr, "Cannot malloc tmp_x!\n");
    exit(1);
  }

  /* Allocate solution array x */
  int *tmp_x;
  if ((tmp_x = (int *)malloc(*n * sizeof(*tmp_x)))==NULL)
  {  //perror("Error allocating space for solution\n");
    fprintf(stderr, "Cannot malloc tmp_x!\n");
    exit(1);
  }

  int counter=0;
  if (fp == NULL) exit(EXIT_FAILURE);

  /* Read in all the values into the arrays */
  while ((fgets(str, sizeof(str), fp))&&(counter<*n)){
    if(str[0] == 'c'){
        pch = strtok(str, " ");
        pch = strtok(NULL, " ");
        *c = atoi(pch);
    }else if (str[0] == 'z'){
        pch = strtok(str, " ");   
        pch = strtok(NULL, " ");
        *z = atoi(pch);
    }else if (!((str[0] == 'n')
              ||(str[0] == 'z')
              ||(str[0] == 'k')
              ||(str[0] == 't'))){

        pch = strtok(str, ",");
        pch = strtok(NULL, ",");

        tmp_p[counter] = atoi(pch);

        pch = strtok(NULL, ",");

        tmp_w[counter] = atoi(pch);

        pch = strtok(NULL, ",");

        tmp_x[counter] = atoi(pch);

        counter += 1;

    }
  }
  fclose(fp);

  *p = tmp_p;
  *w = tmp_w;
  *x = tmp_x;
}

