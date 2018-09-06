#include <stdio.h>

/******************************************************************************
 * Description                                                                *
 *   General implementation for Kellerer and Pferschy's FPTAS for 0,1 KP      *
 *                                                                            *
 * Notes                                                                      *
 *   Scaling Reduction:                                                       *
 *     I don't know how to represent sets and partitions                      *
 *   Interval Dynamic Programming                                             *
 *     I need to understand y more                                            *
 *                                                                            *
 ******************************************************************************/


void kellerer_pferschy_fptas(void);
void scaling_reduction(void);
void get_knapsack_lowerbound(void);
void modify_epsilon(double *epsilon);
void small_large_split(void);
void partition_interval(void);
void reduce_profits_to_mimimal(void);
void prune_excess_weight_items(void);
void redefine_large_set(void);
void partition_large_set(void);

int main(int argc, char *argv[])
{
/* This main function will be removed when this all works */
  
  return 0;
}

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

void scaling_reduction(void)
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
  // modify_epsilon(&epsilon);

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

void interval_dynamic_programming(void);
void interval_dynamic_programming(void)
{
 /**interval_dynamic_programming***********************************************
  * Description                                                               *
  *  Performs dynamic programming with auxiliary vector merging procedure     *
  *   on a series of items.                                                   *
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

void vector_merge_interval(void);
void vector_merge_interval(void)
{
 /**vector_merge_interval******************************************************
  * Description                                                               *
  *  Solves the vector merging problem in O(nlogn) time                       *
  *                                                                           *
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

void get_knapsack_lowerbound(void)
{
 /**get_knapsack_lowerbound****************************************************
  * USED BY SCALING REDUCTION ALGORITHM                                       *
  *   FROM CORE KELLERER AND PFERSCHY FPTAS                                   *
  * Description                                                               *
  *  Given a set of items with associated weights and profits, find the basic *
  *   lower bound on the optimal solution via greedy search.                  *
  * TODO                                                                      *
  *   Generate test cases for this                                            *
  *                                                                           *
  *                                                                           *
  *****************************************************************************/

  /* Just use linear_programming_dual from b&b */

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

void small_large_split(int lower_bound, double epsilon, int *profits)
{
 /**small_large_split**********************************************************
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
  int = lower_bound * epsilon;

  /* For each item, those less than the boundary go into the small set, and 
      all else go to the large set */  

}

void partition_large_set(void)
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
  
  // Sort item by profits, changing weights array as necessary (using iterative quick sort?)
  // Then make an array where each index i has the index of the first profit in i*z^l*eps
  // Should be in linear time?

}

void partition_interval(void)
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

  // Because profits are sorted now, we can do the same thing as we did for the
  // first one and just have an array where each index i has a list of indices 
  // of the start indices for each subinterval in profits

}

void reduce_profits_to_mimimal(void)
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

void prune_excess_weight_items(void)
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
  // sort subinterval by weight (they all have the same profit by this point)
  // maintain an array of length 1/iepsilon where each index is the last
  // considered weight
}

void redefine_large_set(void)
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

