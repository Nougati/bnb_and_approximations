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
}
*/

void kellerer_pferschy_fptas(int *profits, int *weights, int n, int capacity,
                             double epsilon)
{
 /**keller_pferschy_fptas******************************************************
  * Description                                                               *
  *   Implements the FPTAS for Knapsack as described by Keller and Pferschy   *
  *    in Knapsack Problems (2004)                                            *
  * TODO                                                                      *
  *  Generate test cases                                                      *
  *                                                                           *
  *****************************************************************************/
 
  /* We use our own epsilon derived from the input */
  double new_epsilon = epsilon;

  /* Perform scaling reduction */
  int large_profits[n], large_weights[n], small_profits[n], small_weights[n];
  int new_n;
  scaling_reduction(profits, weights, n, capacity, &new_epsilon, large_profits, 
                    large_weights, small_profits, small_weights, &new_n);

  // Initialisation
  
  // Perform Interval-Dynamic-Programming(L, 2z^l) returning (y, r) 
  // Sort S in decreasing order of efficiencies
  // Greedily add smalls
  // Let X_S subsetEq S contain items with profit z^A - Z_L from iteration z_L
  // z_N = backtracking(y, r, z_L);
  // recursion(L, z_L - z_N);
  // merge_solutions(x_A, x_L, x_S); 

}

void scaling_reduction(int *profits, int *weights, int n, int capacity,
                       double *epsilon, int *large_profits, int *large_weights, 
                       int *small_profits, int *small_weights, int *new_n)
{
 /**scaling_reduction**********************************************************
  * USED BY CORE KELLERER AND PFERSCHY FPTAS                                  *
  * Description                                                               *
  *  Given ε, a set of items with associated weights and profits, create a    *
  *   set of items with adjusted profits and reduced size.                    *
  *                                                                           *
  *****************************************************************************/
  
  /* Compute z^l and modify e */
  int lower_bound;
  double upper_bound;
  get_knapsack_lowerbound(profits, weights, n, capacity, &lower_bound,
                          &upper_bound);
  modify_epsilon(epsilon);
  printf("Lower_bound: %d\n", lower_bound);

  /* Derive small and large sets */
  int n_large;
  small_large_split(profits, weights, n, capacity, *epsilon, lower_bound, 
                    small_profits, large_profits, small_weights, large_weights,
                    &n_large);

  /* Partition large set into 1/ε - 1 intervals */
  int intervals[n], subintervals[n];
  for(int i = 0; i < n; i++) intervals[i] = subintervals[i] = -1;
  partition_large_set(large_profits, large_weights, n, *epsilon, lower_bound, 
                      intervals);

  /* Derive all the subintervals for derived intervals, for the large set */
  partition_interval(large_profits, n, *epsilon, lower_bound, intervals,  
                     subintervals);

  /* Given derived intervals and subintervals, set every item to the lower bound
      of its respective subinterval */
  reduce_profits_to_minimal(large_profits, intervals, subintervals, *epsilon,
                            lower_bound, n);

  /* For each interval, and each subinterval, keep only some of the minimum
      weight items */
  int interval_upper_bound = (1 / *epsilon) - 1;
  int subinterval_upper_bound;
  for(int current_interval = 1; current_interval <= interval_upper_bound; 
      current_interval++)
  {
    subinterval_upper_bound = ceil(1/(current_interval * *epsilon));
    for(int current_subinterval = 1; current_subinterval <= subinterval_upper_bound;
        current_subinterval++)
    {
      prune_excess_weight_items(large_profits, large_weights, intervals,
                                subintervals, current_interval,
                                current_subinterval, *epsilon, n);
    }
  }

  /* Finally, redefine the large set of profits and weights in light of the
      pruning that has occurred */
  redefine_large_set(large_profits, large_weights, intervals, subintervals, n,
                     new_n);

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
  quick_sort_parallel_lists_desc_double(ratios, indices, 0, n-1);

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

void quick_sort_parallel_lists_desc_double(double *list1, double *list2, int lo, int hi)
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
        int p = partition_desc_double( list1, list2, lo, hi );
 
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

void quick_sort_parallel_lists_asc_double(double *list1, double *list2, int lo,
                                           int hi)
{
  /**quick_sort_parallel_lists_asc*********************************************
   * Description                                                              *
   *  Sort according to the first list, but also reflect changes in second    *
   *  list in parallel.                                                       *
   *  Sorts in ascending order.                                               *
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
        int p = partition_asc_double(list1, list2, lo, hi);
 
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
void swap_double( double* a, double* b )
{
    double t = *a;
    *a = *b;
    *b = t;
}

/*  partition function from geeksforgeeks.org/iterative-quick-sort/ */
int partition_desc_double(double arr1[], double arr2[], int l, int h)
{
  /* Used by quick_sort_parallel_lists_desc */
    double x = arr1[h];
    int i = (l - 1);
 
    for (int j = l; j <= h- 1; j++)
    {
        if (arr1[j] >= x)
        {
            i++;
            swap_double(&arr1[i], &arr1[j]);
            swap_double(&arr2[i], &arr2[j]);
        }
    }
    swap_double(&arr1[i + 1], &arr1[h]);
    swap_double(&arr2[i + 1], &arr2[h]);
    return (i + 1);
}

/*  partition function from geeksforgeeks.org/iterative-uick-sort/ */
int partition_asc_double(double arr1[], double arr2[], int l, int h)
{
  /* Used by quick_sort_parallel_lists_asc */
    double x = arr1[h];
    int i = (l - 1);
 
    for (int j = l; j <= h- 1; j++)
    {
        if (arr1[j] <= x)
        {
            i++;
            swap_double(&arr1[i], &arr1[j]);
            swap_double(&arr2[i], &arr2[j]);
        }
    }
    swap_double(&arr1[i + 1], &arr1[h]);
    swap_double(&arr2[i + 1], &arr2[h]);
    return (i + 1);
}
  
void quick_sort_parallel_lists_asc_int(int *list1, int *list2, int lo,
                                           int hi)
{
  /**quick_sort_parallel_lists_asc*********************************************
   * Description                                                              *
   *  Sort according to the first list, but also reflect changes in second    *
   *  list in parallel.                                                       *
   *  Sorts in ascending order.                                               *
   *                                                                          *
   ****************************************************************************/

    // Create an auxiliary stack
    int stack[ hi - lo + 1 ];
 
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
        int p = partition_asc_int(list1, list2, lo, hi);
 
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
void swap_int( int* a, int* b )
{
    int t = *a;
    *a = *b;
    *b = t;
}

/*  partition function from geeksforgeeks.org/iterative-quick-sort/ */
int partition_desc_int(int arr1[], int arr2[], int l, int h)
{
  /* Used by quick_sort_parallel_lists_desc */
    int x = arr1[h];
    int i = (l - 1);
 
    for (int j = l; j <= h- 1; j++)
    {
        if (arr1[j] >= x)
        {
            i++;
            swap_int(&arr1[i], &arr1[j]);
            swap_int(&arr2[i], &arr2[j]);
        }
    }
    swap_int(&arr1[i + 1], &arr1[h]);
    swap_int(&arr2[i + 1], &arr2[h]);
    return (i + 1);
}

/*  partition function from geeksforgeeks.org/iterative-uick-sort/ */
int partition_asc_int(int arr1[], int arr2[], int l, int h)
{
  /* Used by quick_sort_parallel_lists_asc */
    int x = arr1[h];
    int i = (l - 1);
 
    for (int j = l; j <= h- 1; j++)
    {
        if (arr1[j] <= x)
        {
            i++;
            swap_int(&arr1[i], &arr1[j]);
            swap_int(&arr2[i], &arr2[j]);
        }
    }
    swap_int(&arr1[i + 1], &arr1[h]);
    swap_int(&arr2[i + 1], &arr2[h]);
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
                       double epsilon, int lower_bound, int *small_profits,
                       int *large_profits, int *small_weights, int *large_weights,
                       int *n_large)
{
 /**small_large_split*********************************************************a
  * USED BY SCALING REDUCTION ALGORITHM                                       *
  *   FROM CORE KELLERER AND PFERSCHY FPTAS                                   *
  * Description                                                               *
  *  Partitions a given set of items into two sets, based on the product of   *
  *   the solution's lower bound and the modified epsilon.                    *
  *                                                                           *
  *                                                                           *
  *****************************************************************************/
  /* Define boundary */  
  int boundary = lower_bound * epsilon;

  /* For each item, those less than the boundary go into the small set, and 
      all else go to the large set */  
  int small_counter = 0;
  int large_counter = 0;
 
  for(int i = 0; i < n; i++)
  {
    if (profits[i] <= boundary)
    {
      small_profits[small_counter] = profits[i];
      small_weights[small_counter++] = weights[i];
    }
    else
    {
      large_profits[large_counter] = profits[i];
      large_weights[large_counter++] = weights[i];
    }
  } 
  
  /* Flag the last space with a -1 */
  if(small_counter < n)
  {
    small_profits[small_counter] = -1;
    small_weights[small_counter] = -1;
  }

  if(large_counter < n)
  {
    large_profits[large_counter] = -1;
    large_weights[large_counter] = -1;
  }
  *n_large = large_counter;
  large_counter++;
  small_counter++;

  while(large_counter < n)
  {
    large_profits[large_counter] = 0;
    large_weights[large_counter++] = 0;
  }
  while(small_counter < n)
  {
    small_profits[small_counter] = 0;
    small_weights[small_counter++] = 0;
  }
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
  * TODO make sure this doesn't go above 1/epsilon - 1 intervals              *
  *****************************************************************************/
  
  /* Just sort */
  quick_sort_parallel_lists_asc_int(profits, weights, 0, n-1);

  /* Then set each profit's interval to be floor(profit[i]/z^l*eps) */
  for(int i = 0; i < n; i++)
  {
    indices_out[i] = 
      (int) floor((double)profits[i] / ((double)lower_bound * epsilon));

    /* If it is sitting at the boundary of the interval below it */
    if((profits[i]/((double) lower_bound * epsilon)) ==
         floor((profits[i]/((double) lower_bound * epsilon)))
        && indices_out[i] != 0)
    {
      /* Take it down one interval */
      indices_out[i] -= 1;
    }
  }  
}

void partition_interval(int *profits, int n, double epsilon, int lowerbound, 
                        int *intervals, int *indices_out)
{
 /**partition_interval*********************************************************
  * USED BY SCALING REDUCTION ALGORITHM                                       *
  *   FROM CORE KELLERER AND PFERSCHY FPTAS                                   *
  * Description                                                               *
  *   Given an array of profits, and a parallel array with each profit's      *
  *    respective interval, derive the subintervals array.                    *
  *                                                                           *
  *                                                                           *
  *****************************************************************************/

  int i, k_stop, this_subinterval;
  double zeps = lowerbound*epsilon;
  double epsilon_squared = epsilon * epsilon;
    for(int p = 0; p < n; p++)
    {
      i = intervals[p];
      this_subinterval = ceil((profits[p] - i*zeps)/(i*lowerbound*epsilon_squared));
      indices_out[p] = this_subinterval;
    }
}

void reduce_profits_to_minimal(int *profits, int *intervals, int *subintervals,
                               double epsilon, int lowerbound, int n)
{
 /**reduce_profits_to_minimal**************************************************
  * USED BY SCALING REDUCTION ALGORITHM                                       *
  *   FROM CORE KELLERER AND PFERSCHY FPTAS                                   *
  * Description                                                               *
  *  Given a subinterval of the large set reduce all profits to its lower     *
  *   bound.                                                                  *
  *                                                                           *
  *****************************************************************************/

  for(int p = 0; p < n; p++)
    profits[p] = intervals[p]*lowerbound*epsilon*(1+(subintervals[p]-1)*epsilon);
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
  
  /* We could sort the subinterval by weights, (they'll all have the same profit) */

  /* Find the start of the subinterval and save this index */
  int i;
  for(i = 0; i < n; i++)
  {
    if(intervals[i] == current_interval 
       && subintervals[i] == current_subinterval)
      break;
    if(i == n-1)
      return; //Interval + subinterval combo doesn't exist
  }
  int start_index = i;

  /* Let m be the number of items within this subinterval */
  int m = 1;
  while(subintervals[++i] == current_subinterval)
    m++;

  /* Make temporary arrays of size m */
  int temp_profits[m];  
  int temp_weights[m];

  int temp_i = 0;
  //Copy everything in subinterval this
  for(i = start_index; i < (start_index+m); i++)
  {
    temp_profits[temp_i] = profits[i];
    temp_weights[temp_i++] = weights[i];
  }

  /* Sort these */
  quick_sort_parallel_lists_asc_int(temp_weights, temp_profits, 0, m-1);  

  /* Copy em back */
  temp_i = 0;
  for(i = start_index; i < (start_index+m); i++)
  {
    profits[i] = temp_profits[temp_i];
    weights[i] = temp_weights[temp_i++];
  }
  
  /* Set everything after the ceil(2/i*epsilon)'th to 0 */
  int cutoff = ceil(2/(current_interval*epsilon));
  i = start_index;
  while(subintervals[i++] == current_subinterval)
  {
    if(i-start_index >= cutoff)
    {
      profits[i] = 0;
      weights[i] = 0;
    }
  }
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
  *                                                                           *
  *****************************************************************************/
  // basically interate over each subinterval up to the weight index boundary
  // defined, then skip to next subinterval start. This should happen in O(n)
  // Update all arrays to have no gaps with 0 in them. For simplicity, we're not
  // redefining the pointer to the array.
  int temp_profits[n];
  int temp_weights[n];
  int temp_intervals[n];
  int temp_subintervals[n];
  int i = 0;
  int j = 0;

  /* Create new compressed version of the arrays */
  while(i < n && j < n && profits[i] != -1)
  {
    /* If the item hasn't been removed */
    if(profits[i] != 0)
    {
      temp_profits[j] = profits[i];
      temp_weights[j] = weights[i];
      temp_intervals[j] = intervals[i];
      temp_subintervals[j++] = subintervals[i++];
    }
    else
      i++;
  }
  
  /* Copy the changes over */
  *new_n = j;
  for(i = 0; i < *new_n; i++)
  {
    profits[i] = temp_profits[i];
    weights[i] = temp_weights[i];
    intervals[i] = temp_intervals[i];
    subintervals[i] = temp_subintervals[i];
  }

  if(i < n)
  {
    profits[i] = -1;
    weights[i] = -1;
    intervals[i] = -1;
    subintervals[i++] = -1;
  }

  /* Make the rest of each of the arrays 0 */
  while(i < n)
  {
    profits[i] = -1;
    weights[i] = -1;
    intervals[i] = -1;
    subintervals[i++] = -1;
  }
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


