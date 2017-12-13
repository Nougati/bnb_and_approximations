/* ~~fptas2.c~~
 * MAJOR WORK IN PROGRESS LOL
 * TODO
 *  - Make sure that my Kprofit(S') output is definitely what I think it is.
 * Pushing from home!
 */

#include <stdio.h>
#include <math.h>
#include <assert.h> 
#include <stdlib.h>
#include <string.h>
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

#define min(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a < _b ? _a : _b; })

/* Function Prototypes */
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
void pisinger_reader(int *n,
                     int *c,
                     int *z,
                     int **p,
                     int **w,
                     int **x,
                     char *problem_file);

void FPTAS(float eps, 
           int *profits,
           int *weights,
           int *x,
           int *sol_prime,
           const int n,
           const int capacity,
           const int z,
           const int sol_flag,
           const int bounding_method,
           const char *problem_file,
           float *K,
           int *profits_prime);

int DP_max_profit(const int problem_profits[],
                  const int n);

float define_K(float eps,
               int P,
               int n);

void make_profit_primes(int *profits,
                        int *profits_prime,
                        float K,
                        int n);
void DP_fill_in_base_cases(const int width,
                           const int n,
                           int DP_table[][width],
                           const int problem_profits[],
                           const int problem_weights[]);
void DP_fill_in_general_cases(const int width,
                              const int n,
                              int DP_table[][width],
                              const int problem_profits[],
                              const int problem_weights[]);
int derive_pinf(const int problem_weights[],
                const int n);

int DP_find_best_solution(const int width,
                          const int n,
                          const int DP_table[][width],
                          const int capacity,
                          const int my_pinf);
int DP_derive_solution_set(int n,
                           const int width,
                           const int DP_table[][width],
                           const int problem_profits[],
                           int solution[],
                           int p,
                           const int sol_flag);
int p_upper_bound_aux(const int problem_profits[],
                      const int n);
/* End Function Prototypes */


int main(){
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
   *                  "knapPI_11_10000_1000.csv" <- Hard instance (Won't compute)
   *                  "knapPI_16_1000_1000.csv" <- Hard
   * Some things to note:
   *   As eps approaches 0, FPTAS's lower bound approaches true solution
   *   As eps approaches 1, FPTAS's lower bound approaches (1-eps)OPT
   *    ... I think
   */
  /* Declarations */
  float eps, K;
  char *problem_file;
  int *profits, *weights, *x, *profit_primes;
  int n, capacity, z, sol_flag, bounding_method;

  /* Initialisations */
  eps = 1.0;
  problem_file = "./problems/knapPI_3_1000_10000000.csv";

  pisinger_reader(&n,
                  &capacity,
                  &z,
                  &profits,
                  &weights,
                  &x,
                  problem_file);
  sol_flag = 1;
  int sol_prime[n];
  for (int i=0; i < n; i++) sol_prime[i] = 0;
  bounding_method = 2;
  profit_primes = (int *) malloc(n * sizeof(*profit_primes));
  /* Begin Debug 
  printf("DEBUG n: %d\nDEBUG c: %d\nDEBUG z: %d\n", n, capacity, z);
  /* End Debug */

  /* Run the FPTAS...
     I want to give to FPTAS to update:
       profit_prime: the FPTAS's guess on profit
       sol_prime: the FPTAS's guess on sol (already malloc'd)
       a K so I can get the rescaled profits on choice.. Just in case!
  */ 
  FPTAS(eps,
        profits,
        weights,
        x,
        sol_prime, // sol prime
        n,
        capacity,
        z,
        sol_flag,
        bounding_method,
        problem_file,
        &K,  // out parameter
        profit_primes); // out parameter 

  /* Derive profit'(S') */
  float profit_primes_i_times_K; 
  for(int i=0; i<n; i++){
    profit_primes_i_times_K = profit_primes[i]*K;
    profit_primes[i] = profit_primes_i_times_K;
  }
  int kprofitprimeSprime = 0;
  int profitSprime = 0;
  for(int i=0; i<n; i++){
    if (sol_prime[i] == 1){ 
      kprofitprimeSprime += profit_primes[i];
      profitSprime += profits[i];
    }
  }

  /*End debug*/
  /* Print profit results */
  printf("profit(O): %d\nprofit(S'): %d\nKprofit'(S'): %d\n", z, profitSprime, kprofitprimeSprime);

  printf("Deviation from optimal: %s%f.\n", "%", (1 - ((float)z/(float)profitSprime)) *100);

  free(profit_primes);
  return 0;
}

void FPTAS(float eps, 
           int *profits,
           int *weights,
           int *x,
           int *sol_prime,
           const int n,
           const int capacity,
           const int z,
           const int sol_flag,
           const int bounding_method,
           const char *problem_file,
           float *K,
           int *profits_prime){
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

  /* Declarations */
  int P;
  
  /* Initialisations */
  P = DP_max_profit(profits,
                    n);
  *K = define_K(eps, P, n);
  make_profit_primes(profits, profits_prime, *K, n); 
  /*BEGIN DEBUG: Transition from profits to profits' 
  for(int i = 0; i < n; i++) printf("profit[%d]: %d\t-> %d\n", i, profits[i], profits_prime[i]);
  /*END DEBUG*/
  /* Now with amended profits list "profit_primes," solve the DP */
  DP(profits_prime,
     weights,
     x,
     sol_prime,
     n,
     capacity,
     z, 
     sol_flag,
     bounding_method,
     problem_file);

  /* Solution should be in sol_prime */
  /* Nothing else done in this place? */
}

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
  int (*DP_table)[p_upper_bound] = malloc(sizeof(*DP_table) * (n+1));
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
}
/**** END DP ****/
 



int DP_max_profit(const int problem_profits[],
                  const int n){
  /*
    Description:
      Finds the highest profit in the array of item profits
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
    case 1: upper_bound = n*P; break;
    case 2: upper_bound = p_upper_bound_aux(problem_profits, n); break;
    default: printf("Hmmm... What bounding method was that?\n");
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
                           int DP_table[][width],
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
                              int DP_table[][width],
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
        DP_table[i][p] = min(a,b);
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

  */

  int my_pinf = 1;
  for(int i = 0; i < n; i++){
    my_pinf += problem_weights[i];
  }
  return my_pinf;
}

int DP_find_best_solution(const int width,
                          const int n,
                          const int DP_table[][width],
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
                           const int DP_table[][width],
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
      This doesn't work on certain instances :/
  */

  int s_index = 0;
  while ((p > 0)&&(n > 0)){
    if (DP_table[n-2][p] > DP_table[n-1][p]){
      // then we had item n and the solution at A[n-1][p-profit(n)]
      if(sol_flag == 0) solution[s_index] = (n-1);
      else solution[n-2] = 1;
      s_index += 1;
      n -= 1;
      p -= problem_profits[n-1]; // remember table n corresponds to profit n-1
    }else{
      // A[n-1][p] must be the same as A[n][p]
      if (sol_flag != 0) solution[n-2] = 0;
      n -= 1;
    }
  }
 return s_index;
}


float define_K(float eps, int P, int n){
  /* Description: 
   *   Defines real valued scaling factor K
   */
  
  // assert eps > 0
  assert(eps > 0);
  assert(eps <= 1);  

  float K = (eps*P)/n;
  // define K

  return K;
  // return K
}


void make_profit_primes(int *profits, int *profits_prime, float K, int n){
 /* 
  * Description: 
  *  Derives the adjusted profits set profits', which is made by scaling every
  *   profit down by 1/K and flooring the result.
  * Inputs:
  *
  * Postconditions:
  */
  
  for(int i=0; i < n; i++){
    profits_prime[i] = floor(profits[i]/K);
  }
}


void pisinger_reader(int *n, int *c, int *z, int **p, int **w, int **x, char *problem_file){
  /* 
   * Description:
   *   Reads pisinger's csv knapsack instances into arrays. This does not work 
   *    on his automatically generated instances.
   * Inputs:
   *
   * Notes:
   * 
   */
  FILE *fp;
  char str[256];
  char * pch;

  fp = fopen(problem_file, "r");

  /* Get n */
  if (fp == NULL) exit(EXIT_FAILURE);
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


