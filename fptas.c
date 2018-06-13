/**fptas.c*********************************************************************
 *                                                                            *
 *  Really big epsilons:                                                      *
 *    Basically for epsilon >= 1, the lower bound guarantee relative to OPT   *
 *    goes to 0. P lower bounds OPT, but P decreases in the truncated profits,*
 *    so its guarantees decrease too.                                         *
 *                                                                            *
 ******************************************************************************/

#include <math.h>
#include <assert.h> 
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "fptas.h"
#include "bench_extern.h"
#include "pisinger_reader.h"
#include "branch_and_bound.h"


/* Preprocessor definitions */

/* That generic thingo */
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


Dynamic_Array *times_per_node;

/* FPTAS Functions */
/* FPTAS core function */
void FPTAS(double eps, int *profits, int *weights, int *x, int *sol_prime,
           const int n, int capacity, const int z, const int sol_flag,
           const int bounding_method, const char *problem_file, double *K,
           int *profits_prime, const int DP_method,
           const int *variable_statuses, const int dualbound_type){
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
  make_profit_primes(profits, profits_prime, *K, n, variable_statuses, dualbound_type);

  /* Symbolic profits (just for the computation) */
  int symbolic_profits_prime[n];
  for (int i = 0; i < n; i++) symbolic_profits_prime[i] = 0;
  make_symbolic_profit_primes(profits, symbolic_profits_prime, *K, n, 
                              variable_statuses, dualbound_type);

  /* Adjust capacity according to nodes constrained to be in */
  for (int i = 0; i < n; i++)
    if (variable_statuses[i] == VARIABLE_ON)
      capacity -= weights[i];
  for (int i = 0; i < n; i++) sol_prime[i] = 0;

  /* Feasibility check */
  if (capacity >= 0)
  {
    /* Now with amended profits list "profit_primes," solve the DP */
    /*... With Vazirani's DP */
    if (DP_method == VASIRANI)
    {
      #ifdef BENCHMARKING
      clock_t start_time = clock();
      #endif

      DP(symbolic_profits_prime, weights, x, sol_prime, n, capacity, z, 
         sol_flag, bounding_method, problem_file);

      #ifdef BENCHMARKING
      clock_t elapsed = clock() - start_time;
      double time_taken = ((double)elapsed)/CLOCKS_PER_SEC;
      append_to_dynamic_array(times_per_node, time_taken);
      #endif
    }

    /*... or Williamson and Shmoys. */
    else if (DP_method == WILLIAMSON_SHMOY)
    {
      /* Make problem item struct array */
      struct problem_item items_prime[n];
      for(int i = 0;  i < n; i++)
      {
        items_prime[i].weight = weights[i];
        items_prime[i].profit = symbolic_profits_prime[i];
      }
      #ifdef BENCHMARKING
      clock_t start_time = clock();
      #endif

      int result = williamson_shmoys_DP(items_prime, capacity, n, sol_prime);

      #ifdef BENCHMARKING
      clock_t elapsed = clock() - start_time;
      double time_taken = ((double)elapsed)/CLOCKS_PER_SEC;
      append_to_dynamic_array(times_per_node, time_taken);
      #endif
    }

    /* Force any variables on if necessary */
    for(int i = 0; i < n; i++) 
      if(variable_statuses[i] == VARIABLE_ON)
        sol_prime[i] = 1;
    /* Solution should be in sol_prime */
  }
}

/* FPTAS: Define K */
float define_K(double eps, int P, int n){
  /* Description: 
   *   Defines real valued scaling factor K. K is epsP/n. As eps approaches 0,
   *   K does too. As eps approaches 1, K approaches P/n. As eps exceeds 1, K 
   *   scales progressively larger than the n-way split of P.
   * Notes:
   *  Epsilon can indeed exceed 1 as soon as epsilon hits 1 the lower bound
   *  guarantee on the profit with respect to OPT drops completely and is 
   *  bounded trivially by 0. As a result, a stronger lower bound would be P at
   *  this point, however there is no guarantee on how this adjusted P will look. 
   *  It may well be positive but with increasing epsilon values it would seem 
`  *  that P's would be crushed to a low point. 
   */
  assert(eps > 0);
  double K = (eps*P)/n;
  return K;
}

/* FPTAS: Make profit primes */
void make_profit_primes(int profits[], int profits_prime[], double K, int n,
                        const int *variable_statuses, const int dualbound_type)
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
  *   and further downwards. Since P is the max, it will be scaled to 1 for eps = 1 
  */
{
  switch(dualbound_type)
  {
    /* Case: we need to round up */
    case APOSTERIORI_DUAL_ROUNDUP :
      if(K > 1)
        for(int i=0; i < n; i++)
        {
            double scaled_profit = profits[i]/K;
            profits_prime[i] = ceil(scaled_profit);
        }
      /* If K < 1, then profits would be inflated, so we simply solve exactly */
      else
        for(int i = 0; i < n; i++)
          profits_prime[i] = profits[i];
      break;
    /* For all other dual bounds, we round down */
    default :
      if(K > 1)
        for(int i=0; i < n; i++)
        {
            double scaled_profit = profits[i]/K;
            profits_prime[i] = floor(scaled_profit);
        }
      /* If K < 1, then profits would be inflated, so we simply solve exactly */
      else
        for(int i = 0; i < n; i++)
          profits_prime[i] = profits[i];
  }
}

/* FPTAS: Make symbolic profit primes function */ 
void make_symbolic_profit_primes(int profits[], int symbolic_profits_prime[], 
                                double K, int n, const int *variable_statuses, 
                                const int dualbound_type){ 
 /* Description: 
  *  Derives the adjusted profits set profits', which is made by scaling every
  *   profit down by 1/K and flooring the result, while zeroing constrained variables.
  *   The process of forcing domination is the symbolic component of this.
  * Inputs:
  *
  * Postconditions:
  *  
  * Notes:
  *  As eps increases, K increases, and so the profit' of each item will get scaled further
  *   and further downwards. Since P is the max, it will be scaled to 1 for eps = 1 
  *   
  */

  switch(dualbound_type)
  {
    /* Case: we need to round up */
    case APOSTERIORI_DUAL_ROUNDUP :
      if(K > 1)
      { 
        for(int i=0; i < n; i++)
        {
          if(variable_statuses[i] == VARIABLE_UNCONSTRAINED)
          {
            double scaled_profit = profits[i]/K;
            symbolic_profits_prime[i] = ceil(scaled_profit);
          }
          else
            symbolic_profits_prime[i] = VARIABLE_OFF; // We just make the item dominated
        }
      }
      else
      {
        for(int i = 0; i < n; i++)
        {
          if(variable_statuses[i] == VARIABLE_UNCONSTRAINED)
            symbolic_profits_prime[i] = profits[i];
          else
            symbolic_profits_prime[i] = VARIABLE_OFF;
        } 
      }
      break;
    /* All other cases: we round down */
    default :
      if(K > 1)
      { 
        for(int i=0; i < n; i++)
        {
          if(variable_statuses[i] == VARIABLE_UNCONSTRAINED)
          {
            double scaled_profit = profits[i]/K;
            symbolic_profits_prime[i] = floor(scaled_profit);
          }
          else
            symbolic_profits_prime[i] = VARIABLE_OFF; // We just make the item dominated
        }
      }
      else
      {
        for(int i = 0; i < n; i++)
        {
          if(variable_statuses[i] == VARIABLE_UNCONSTRAINED)
            symbolic_profits_prime[i] = profits[i];
          else
            symbolic_profits_prime[i] = VARIABLE_OFF;
        } 
      }
  }
}

/* General DP / FPTAS Aux: Find max profits */
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


/* Vasirani DP functions */
/* Vasirani DP: General Dynamic programming algorithm */
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
  int **DP_table = (int **) malloc(sizeof(int *) * (n+1));
  DP_table[0] = (int *)malloc(sizeof(int) * p_upper_bound * (n+1));
  for(int i = 0; i < (n+1); i++)
    DP_table[i] = (*DP_table + p_upper_bound * i);

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
  free(DP_table[0]);
  free(DP_table);
}

/* Vasirani DP: Derive upper bound P (table width) */
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

/* Vasirani DP: profit upper bound auxiliary function */
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

/* Vasirani DP: Fill in base cases */
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

/* Vasirani DP: General case computation */
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

/* Vasirani DP: Find symbolic positive infinity */
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

/* Vasirani DP: Find best solution from table */
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

/* Vasirani DP: Derive solution set */
int DP_derive_solution_set(int n,
                           const int width,
                           int ** DP_table,
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


/* W&S DP Functions */
/* W&S DP Core Algorithm */
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
  struct solution_pair* current = NULL; 
  push(&head, 0, 0, n);


  /* WIP Section */
  int first_index = 0;
  while ((first_index < n) && items[first_index++].weight >= capacity)
    ;
  push(&head, items[first_index-1].weight, items[first_index-1].profit, n);
  head->solution_array[first_index-1] = 1;

  /* General case */
  for(int j=first_index; j < n; j++)
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

/* W&S DP: Linked list push function */
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

/* W&S DP: Remove Dominated Pairs */
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

/* Merge sort */
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

/* Merge sort aux: sorted merge function */
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

/* Merge sort aux: front/back split function */
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

/* Linked list printer function */
void print_list(struct solution_pair* node)
{
  while(node!=NULL)
  {
    printf("%d ", node->profit);
    node = node->next;
  }
}

/* Dynamic Array method: Initialise */
void initialise_dynamic_array(Dynamic_Array **dynamic_array, size_t initial_size)
{
  Dynamic_Array *tmp = *dynamic_array = (Dynamic_Array*)malloc(sizeof(Dynamic_Array));
  tmp->array = (double *)malloc(initial_size * sizeof(double));
  tmp->used = 0;
  tmp->size = initial_size;
}

/* Dynamic Array method: Append */
void append_to_dynamic_array(Dynamic_Array *dynamic_array, double element)
{
  if (dynamic_array->used == dynamic_array->size)
  {
    dynamic_array->size *= 2;
    dynamic_array->array = (double *)realloc(dynamic_array->array, 
                                         dynamic_array->size * sizeof(double));
  }
  dynamic_array->array[dynamic_array->used++] = element; 
}

/* Dynamic Array method: Free */
void free_dynamic_array(Dynamic_Array *dynamic_array)
{
  free(dynamic_array->array);
  dynamic_array->array = NULL;
  dynamic_array->used = dynamic_array->size = 0;
}



