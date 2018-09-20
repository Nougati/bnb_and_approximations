#include <stdio.h>
#include <math.h>
#include <limits.h>
#include "kellerer_pferschy_fptas.h"

/******************************************************************************
 * Description                                                                *
 *   General implementation for Kellerer and Pferschy's FPTAS for 0,1 KP      *
 *                                                                            *
 * Notes                                                                      *
 *   Scaling Reduction:                                                       *
 *     I don't know how to represent sets and partitions                      *
 *   Interval Dynamic Programming                                             *
 *     I need to understand y more                                            *
 * TODO                                                                       *
 *  Scaling reduction                                                         *
 *    redefine_large_set                                                      *
 *    prune_excess_weight_items                                               *
 *    reduce_profits_to_minimal                                               *

 *    partition_interval                                                      *
 *    partition_large_set                                                     *
 *    small_large_split                                                       *
 *    modify_epsilon                                                          *
 *    get_knapsack_lowerbound                                                 *
 *                                                                            *
 *                                                                            *
 ******************************************************************************/

/*
int main(int argc, char *argv[])
{
/* This main function will be removed when this all works  
  return 0;
}*/

void kellerer_pferschy_fptas(void)
{
 /**keller_pferschy_fptas******************************************************
  * Description                                                               *
  *   Implements the FPTAS for Knapsack as described by Keller and Pferschy   *
  *    in Knapsack Problems (2004)                                            *
  * TODO                                                                      *
  *  Generate test cases                                                      *
  *                                                                           *
  *****************************************************************************/
 
  // Perform scaling reduction
  // Initialisation
  // Perform Interval-Dynamic-Programming(L, 2z^l) returning (y, r) 
  // Sort S in decreasing order of efficiencies
  // Greedily add smalls
  // Let X_S subsetEq S contain items with profit z^A - Z_L from iteration z_L
  // z_N = backtracking(y, r, z_L);
  // recursion(L, z_L - z_N);
  // merge_solutions(x_A, x_L, x_S); 

}

void scaling_reduction(double epsilon)
{
 /**scaling_reduction**********************************************************
  * USED BY CORE KELLERER AND PFERSCHY FPTAS                                  *
  * Description                                                               *
  *  Given ε, a set of items with associated weights and profits, create a    *
  *   set of items with adjusted profits and reduced size.                    *
  * TODO                                                                      *
  *   Generate test cases for this                                            *
  *                                                                           *
  *                                                                           *
  *****************************************************************************/
  
  /* Compute z^l and modify e */
  // get_knapsack_lowerbound(item set);
  modify_epsilon(&epsilon);

  /* Derive small and large sets */
  // small_large_split(items);

  /* Partition large set into 1/ε - 1 intervals */
  // partition_large_set(large_set);

  //for(i=1, i <= 1/ε-1; i++)

    /* Partition intervals  */
    //partition_interval(L[i])

    //for (k=1; k <= ceil(1/iε); k++)
      
      /* Reduce every profit to lower subinterval bound */
      //reduce_profits_to_minimal(L[i][k]);

      /* Prune excess weight items */
      // if (size(L[i][k]) > ceil(2/iε))
        // Take only the first ceil(2/iε) items w/ min weight
        // Remove the rest
      
  // Change large set to whatever we have left
}



void get_knapsack_lowerbound(int *profits, int *weights, int n, int capacity,
                             int *lower_bound, double *upper_bound)
{
 /**get_knapsack_lowerbound****************************************************
  * USED BY SCALING REDUCTION ALGORITHM                                       *
  *   FROM CORE KELLERER AND PFERSCHY FPTAS                                   *
  * Description                                                               *
  *  Given a set of items with associated weights and profits, find the basic *
  *   lower bound on the optimal solution via greedy search.                  *
  *                                                                           *
  *****************************************************************************/

  /* Just use linear_programming_dual from b&b */
  if(n == 0 || capacity <= 0)
  {
    *lower_bound = 0;
    *upper_bound = 0;
    return;
  }

  /* Order by non-increasing profit/weight ratio */
  double ratios[n];
  double indices[n];
  for(int i = 0; i < n; i++) indices[i] = 0;
  for(int i = 0; i < n; i++)
  {
    if (weights[i] != 0)
      ratios[i] = (double) profits[i]/weights[i];
    else
      ratios[i] = 0;
    indices[i] = (double) i;
  }

  /* Sort ratios in descending order */
  quick_sort_parallel_lists(ratios, indices, 0, n-1);

  /* Pick items in that order, one by one until picking an item would 
      overfill the knapsack */
  int current_weight = 0;
  int current_profit = 0;
  int i = 0;
  for(i = 0; i < n && weights[(int)indices[i]]+current_weight <= capacity; i++)
  {
    current_weight += weights[(int)indices[i]];
    current_profit += profits[(int)indices[i]];
  }

  /* Then pick the fractional component of that item that you can fit to get
      the dual bound */
  double scale = 0;
  if(i < n)
  {
    scale = (double)(capacity - current_weight) / weights[(int)indices[i]];
    *upper_bound = current_profit + scale * profits[(int)indices[i]];
  }
  else *upper_bound = current_profit;
  
  /* Continue traversing the list until you find the next item that you can
      fit to get the primal bound */

  while (i < n && weights[(int)indices[i]]+current_weight > capacity)
    i++;
  if(i < n)
    *lower_bound = profits[(int)indices[i]]+current_profit;
  else
    *lower_bound = current_profit;

}

void quick_sort_parallel_lists(double *list1, double *list2, int lo, int hi)
{
  /**quick_sort_parallel_lists*************************************************
   * Description                                                              *
   *  Sort according to the first list, but also reflect changes in second    *
   *  list in parallel.                                                       *
   *  Sorts in descending order.                                              *
   *                                                                          *
   ****************************************************************************/

    // Create an auxiliary stack
    double stack[ hi - lo + 1 ];
 
    // initialize top of stack
    int top = -1;
 
    // push initial values of l and h to stack
    stack[ ++top ] = lo;
    stack[ ++top ] = hi;
 
    // Keep popping from stack while is not empty
    while ( top >= 0 )
    {
        // Pop h and l
        hi = stack[ top-- ];
        lo = stack[ top-- ];
 
        // Set pivot element at its correct position
        // in sorted array
        int p = partition( list1, list2, lo, hi );
 
        // If there are elements on left side of pivot,
        // then push left side to stack
        if ( p-1 > lo )
        {
            stack[ ++top ] = lo;
            stack[ ++top ] = p - 1;
        }
 
        // If there are elements on right side of pivot,
        // then push right side to stack
        if ( p+1 < hi )
        {
            stack[ ++top ] = p + 1;
            stack[ ++top ] = hi;
        }
    }
}

/* swap function from geeksforgeeks.org/iterative-quick-sort/ */
void swap ( double* a, double* b )
{
    double t = *a;
    *a = *b;
    *b = t;
}

/*  partition function from geeksforgeeks.org/iterative-quick-sort/ */
int partition (double arr1[], double arr2[], int l, int h)
{
    double x = arr1[h];
    int i = (l - 1);
 
    for (int j = l; j <= h- 1; j++)
    {
        if (arr1[j] >= x)
        {
            i++;
            swap (&arr1[i], &arr1[j]);
            swap (&arr2[i], &arr2[j]);
        }
    }
    swap (&arr1[i + 1], &arr1[h]);
    swap (&arr2[i + 1], &arr2[h]);
    return (i + 1);
}

  



void modify_epsilon(double *epsilon)
{
 /**modify_epsilon*************************************************************
  * USED BY SCALING REDUCTION ALGORITHM                                       *
  *   FROM CORE KELLERER AND PFERSCHY FPTAS                                   *
  * Description                                                               *
  *  Given an input epsilon value, modify it so that it can be used to        *
  *   partition the sets of items. After modification, epsilon is modified    *
  *   such that 1/epsilon and 1/epsilon^2 is an integer.                      *
  * TODO                                                                      *
  *   Generate test cases for this                                            *
  *                                                                           *
  *****************************************************************************/
  *epsilon = 1/ceil(2 / *epsilon);
}

void small_large_split(int *profits, int *weights, int n, int capacity, 
                       double epsilon, int lower_bound, int *small, int *large)
{
 /**small_large_split*********************************************************a
  * USED BY SCALING REDUCTION ALGORITHM                                       *
  *   FROM CORE KELLERER AND PFERSCHY FPTAS                                   *
  * Description                                                               *
  *  Partitions a given set of items into two sets, based on the product of   *
  *   the solution's lower bound and the modified epsilon.                    *
  * TODO                                                                      *
  *   Generate test cases for this                                            *
  *                                                                           *
  *                                                                           *
  *****************************************************************************/
  /* Define boundary */  
  int boundary = lower_bound * epsilon;

  /* For each item, those less than the boundary go into the small set, and 
      all else go to the large set */  

}

void partition_large_set(int *profits, int *weights, int n, double epsilon, 
                         int lower_bound, int *indices_out)
{
 /**partition_large_set********************************************************
  * USED BY SCALING REDUCTION ALGORITHM                                       *
  *   FROM CORE KELLERER AND PFERSCHY FPTAS                                   *
  * Description                                                               *
  *  Given a set of items partitioned and categorised as "large," partition   *
  *   these further into 1/epsilon -1 intervals.                              *
  * TODO                                                                      *
  *   Generate test cases for this                                            *
  *                                                                           *
  *****************************************************************************/
  
  // Sort item by profits, changing weights array as necessary 
  //  (using iterative quick sort?)
  // Then make an array where each index i has the index of the first profit in
  //   i*z^l*eps
  // Should be in linear time?
  
  // Just sort
  // Then set each profit's interval to be floor(profit[i]/z^l*eps)
  // if profit[i] / z^l * eps = floor(profit[i] / z^l * eps)
  //    then interval -= 1

}

void partition_interval(int *profits, int n, double epsilon, int lowerbound, 
                        int *intervals, int *indices_out)
{
 /**partition_interval*********************************************************
  * USED BY SCALING REDUCTION ALGORITHM                                       *
  *   FROM CORE KELLERER AND PFERSCHY FPTAS                                   *
  * Description                                                               *
  *  Given an interval of the large set, derive ceil(1/iepsilon) subintervals *
  * TODO                                                                      *
  *   Generate test cases for this                                            *
  *                                                                           *
  *                                                                           *
  *****************************************************************************/

  //happily assume indices_out is of length n
  // Because profits are sorted now, we can do the same thing as we did for the
  // first one and just have an array where each index i has a list of indices 
  // of the start indices for each subinterval in profits

}

void reduce_profits_to_mimimal(int *profits, int *intervals, int *subintervals,
                               double epsilon, int lowerbound, int n)
{
 /**reduce_profits_to_minimal**************************************************
  * USED BY SCALING REDUCTION ALGORITHM                                       *
  *   FROM CORE KELLERER AND PFERSCHY FPTAS                                   *
  * Description                                                               *
  *  Given a subinterval of the large set reduce all profits to its lower     *
  *   bound.                                                                  *
  * TODO                                                                      *
  *   Generate test cases for this                                            *
  *                                                                           *
  *****************************************************************************/

  // For i = start_index of subinterval... end index
  //    Set them to the value iz^l*e
}

void prune_excess_weight_items(int *profits, int *weights, int *intervals, 
                               int *subintervals, int current_interval, 
                               int current_subinterval, double epsilon, int n)
{
 /**prune_excess_weight_items**************************************************
  * USED BY SCALING REDUCTION ALGORITHM                                       *
  *   FROM CORE KELLERER AND PFERSCHY FPTAS                                   *
  * Description                                                               *
  *  Given a subinterval of items with profits reduced to the same weights,   *
  *   reduce the set to only the first ceil(2/iepsilon) with minimal weight   *
  * TODO                                                                      *
  *   Generate test cases for this                                            *
  *                                                                           *
  *****************************************************************************/
  // REMEMBER this is only going to prune FOR A GIVEN SUBINTERVAL
  // So it needs to take a parameter "interval of interest" and "subinterval of
  //  interest" 
  // Then create an array of the subinterval
  //  sort subinterval by weight (they all have the same profit by this point)
  //  maintain an array of length 1/iepsilon where each index is the last
  //  considered weight
  // THEN COPY THE SUBINTERVAL INFORMATION BACK TO THE ORIGINAL ARRAYS
}

void redefine_large_set(int *profits, int *weights, int *intervals, 
                        int *subintervals, int n, int *new_n)
{
 /**redefine_large_set*********************************************************
  * USED BY SCALING REDUCTION ALGORITHM                                       *
  *   FROM CORE KELLERER AND PFERSCHY FPTAS                                   *
  * Description                                                               *
  *  Not sure if this is necessary; just a definition change within their     *
  *   pseudocode.                                                             *
  * TODO                                                                      *
  *   Generate test cases for this                                            *
  *                                                                           *
  *****************************************************************************/
  // basically interate over each subinterval up to the weight index boundary
  // defined, then skip to next subinterval start. This should happen in O(n)
}

void interval_dynamic_programming(void)
{
 /**interval_dynamic_programming***********************************************
  * USED BY CORE KELLERER AND PFERSCHY FPTAS                                  *
  * Description                                                               *
  *  Performs dynamic programming with auxiliary vector merging procedure     *
  *   on a series of items.                                                   *
  * TODO                                                                      *
  *   Generate test cases for this                                            *
  *                                                                           *
  *****************************************************************************/
  /* y is of length q, the upper bound on profit */
  /* Initialisation of y, every multiple of z^l*eps is c+1 */
  /* y(0):= 0 */
  
  // for all different profit values (i.e. for every subinterval with at least one item)
    // for every residual value
      // k=1, ... floor(q/p_t) + 1 TODO what does this represent?
        // A(k) := y((k-1)p_t + r)
        // if k<=m then B(k) = weight[k] of distinct profit t
        // else B(k) is infinity
      // B(0) = 0
      // vector_merge_interval(A, B, C)
      // for k = 1, .. floor(q/p_t)+1
        // y((k-1)p_t+r) = C(k)
}

void vector_merge_interval(int *A, int *B, int *C, int n)
{
 /**vector_merge_interval******************************************************
  * USED BY INTERVAL DYNAMIC PROGRAMMING                                      *
  *   FROM CORE KELLERER AND PFERSCHY FPTAS                                   *
  * Description                                                               *
  *  Solves the vector merging problem in O(nlogn) time                       *
  * TODO                                                                      *
  *   Generate test cases for this                                            *
  *                                                                           *
  *****************************************************************************/
  // Initialise C

  // Define a(1), b(1), and pred(1)
  
  // last = 1:
  // for i=2 to n
    // if C(n) > A(i) + sumof(B, 0, n-i) 
      // b(i) = n
      // j = a(last)
      // while C(j) > A(i) + sumof(B, 0, j-i) AND j>=i
        // C(j) = A(i) + sumof(B, 0, j-i)
        // a(last) = infinity
        // b(last) = infinity
        // last = pred(last)
        // j = a(last)
      // if j >= i
        // TODO intuit this part!
      // else
        //b(last) = i-1; a(i) = i;
      // pred(i) = last
      //last = i
    // else
      // a(i) = infinity; b(i) = infinity

  

}

void vector_merge_naive(int *A, int *B, int *C, int n)
{
  /* This is a quadratic naive version of vector merge. 
     It shouldn't be used outside of testing. */
  int sum_array[n+1];

  /* For each entry of C */
  for(int j = 0; j <= n; j++)
  {
    for(int i = 0; i <= n; i++)
      sum_array[i] = -1;
    populate(sum_array, A, B, j);
    C[j] = min_val_of(sum_array, n);
  }
}

void populate(int *sum_array, int *A, int *B, int j)
{
  /* Auxiliary function to vector merge naive */
  /* Find sums */
  for(int i = 1; i <= j; i++)
    sum_array[i] = get_associated_sum(A, B, j, i);
}

int get_associated_sum(int *A, int *B, int j, int i)
{
  /* Auxiliary function to vector merge naive */
  int sum = A[i];
  for(int k = 0; k <= j-i; k++)
    sum += B[k];
  return sum;
}

int min_val_of(int *array, int n)
{
  /* Auxiliary function to vector merge naive */
  int min = INT_MAX;

  /* General case */
  for(int i = 1; i <= n; i++)
    if(array[i] != -1 && array[i] < min)
      min =  array[i];

  if (min == INT_MAX)
    return 0;
  else 
    return min;
}

void binary_search(void)
{
 /**binary_search**************************************************************
  * USED BY VECTOR MERGE INTERVAL                                             *
  *   FROM INTERVAL DYNAMIC PROGRAMMING                                       *
  *     FROM CORE KELLERER AND PFERSCHY FPTAS                                 *
  * Description                                                               *
  *  An auxiliary method for vector_merge_interval                            *
  * TODO                                                                      *
  *   Generate test cases for this                                            *
  *                                                                           *
  *****************************************************************************/
}

void compute_sum(void)
{
 /**compute_sum****************************************************************
  * USED BY VECTOR MERGE INTERVAL                                             *
  *   FROM INTERVAL DYNAMIC PROGRAMMING                                       *
  *     FROM CORE KELLERER AND PFERSCHY FPTAS                                 *
  * Description                                                               *
  *   Just a summing algorithm to do all the copious summing that is done     *
  *    in vector_merge_interval                                               *
  * TODO                                                                      *
  *   Generate test cases for this                                            *
  *                                                                           *
  *****************************************************************************/
}

void greedily_add_smalls(void);
void greedily_add_smalls(void)
{
 /**greedily_add_smalls********************************************************
  * USED BY CORE KELLERER AND PFERSCHY FPTAS                                  *
  * Description                                                               *
  *  Having done the DP on the large set, we now greedily add small items     *
  * TODO                                                                      *
  *   Generate test cases for this                                            *
  *                                                                           *
  *****************************************************************************/
  //for all profits q<= 2z^l with y(q) <= c do in decreasing order of y(q)
    // add up items from S as long as their weight sum is not more than c-y(q) yielding a profit z_s
    // if z^A < q + z_S, 
        // z^A = q + z_s, z_L = q
}

void backtracking(void);
void backtracking(void)
{
 /**backtracking***************************************************************
  * USED BY CORE KELLERER AND PFERSCHY FPTAS                                  *
  * Description                                                               *
  *  Reverse engineer the solution from DP arrays y and r, and max profit q   *
  * TODO                                                                      *
  *   Generate test cases for this                                            *
  *                                                                           *
  *****************************************************************************/
}

void recursion(void);
void recursion(void)
{
 /**recursion******************************************************************
  * USED BY CORE KELLERER AND PFERSCHY FPTAS                                  *
  * Description                                                               *
  *   Recursively backtrack through a solution and reconstruct the solution   *
  *    set.                                                                   *
  * TODO                                                                      *
  *   Generate test cases for this                                            *
  *                                                                           *
  *****************************************************************************/
}


