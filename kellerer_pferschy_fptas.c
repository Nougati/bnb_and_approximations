#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <limits.h>
#include <time.h>
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
 * TODO, in order of execution                                                *
 *   Finish interval dynamic programming                                      *
 *     Which involves VM                                                      *
 *   Plan recursion and backtracking                                          *
 *                                                                            *
 *                                                                            *
 ******************************************************************************/

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

  int new_n, lower_bound;
  double upper_bound;

  /* Do array business */
  int *large_profits, *large_weights, *small_profits, *small_weights, 
      *intervals, *subintervals;
  large_profits = malloc(n * sizeof(int));
  large_weights = malloc(n * sizeof(int));
  small_profits = malloc(n * sizeof(int));
  small_weights = malloc(n * sizeof(int));
  intervals = malloc(n * sizeof(int));
  subintervals = malloc(n * sizeof(int));

  /* Perform scaling reduction */
  scaling_reduction(profits, weights, n, capacity, &new_epsilon, large_profits, 
                    large_weights, small_profits, small_weights, intervals, 
                    subintervals, &new_n, &lower_bound, &upper_bound);

  // Initialisation
  // Perform Interval-Dynamic-Programming(L, 2z^l) returning (y, r) 
  // Sort S in decreasing order of efficiencies
  // Greedily add smalls
  // Let X_S subsetEq S contain items with profit z^A - Z_L from iteration z_L
  // z_N = backtracking(y, r, z_L);
  // recursion(L, z_L - z_N);
  // merge_solutions(x_A, x_L, x_S); 

  free(large_profits);
  free(large_weights);
  free(small_profits);
  free(small_weights);
  free(intervals);
  free(subintervals);
}

void scaling_reduction(int *profits, int *weights, int n, int capacity,
                       double *epsilon, int *large_profits, int *large_weights, 
                       int *small_profits, int *small_weights, int *intervals,
                       int *subintervals, int *new_n, int *lower_bound,   
                       double *upper_bound)
{
 /**scaling_reduction**********************************************************
  * USED BY CORE KELLERER AND PFERSCHY FPTAS                                  *
  * Description                                                               *
  *  Given ε, a set of items with associated weights and profits, create a    *
  *   set of items with adjusted profits and reduced size.                    *
  *                                                                           *
  *****************************************************************************/
  
  /* Compute z^l and modify e */
  get_knapsack_lowerbound(profits, weights, n, capacity, lower_bound,
                          upper_bound);
  modify_epsilon(epsilon);

  /* Derive small and large sets */
  int n_large;
  small_large_split(profits, weights, n, capacity, *epsilon, *lower_bound, 
                    small_profits, large_profits, small_weights, large_weights,
                    &n_large);

  /* Partition large set into 1/ε - 1 intervals */
  for(int i = 0; i < n; i++) intervals[i] = subintervals[i] = -1;
  partition_large_set(large_profits, large_weights, n, *epsilon, *lower_bound, 
                      intervals);

  /* Derive all the subintervals for derived intervals, for the large set */
  partition_interval(large_profits, n, *epsilon, *lower_bound, intervals,  
                     subintervals);

  /* Given derived intervals and subintervals, set every item to the lower bound
      of its respective subinterval */
  reduce_profits_to_minimal(large_profits, intervals, subintervals, *epsilon,
                            *lower_bound, n);

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

  int i, this_subinterval;
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
  *   We do this symbolically by setting them all to 0 weight and 0 profit.   *
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

  i++;
  while(i < n && subintervals[i] == current_subinterval)
  {
    m++;
    i++;
  }

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

  while(i < n && subintervals[i++] == current_subinterval)
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

void interval_dynamic_programming(int *large_profits_prime, 
                                  int *large_weights_prime, int *intervals,
                                  int *subintervals, int n, int capacity,
                                  int lower_bound, double epsilon,
                                  int profits_upper_bound, int *y, int *r)
{
 /**interval_dynamic_programming***********************************************
  * USED BY CORE KELLERER AND PFERSCHY FPTAS                                  *
  * Description                                                               *
  *  Performs dynamic programming with auxiliary vector merging procedure     *
  *   on a series of items.                                                   *
  * Notes                                                                     *
  *   This will have n == new_n, because we'll have scaled and reduced the    *
  *    item item by this point.                                               *
  * TODO                                                                      *
  *   make sure this works with the data structures we have                   *
  *                                                                           *
  *****************************************************************************/
  
  /* y is of length q, the upper bound on profit */
  //int *y;
  //y = malloc(profits_upper_bound * sizeof(int));
  //y = calloc(profits_upper_bound, sizeof(int));

  double epsilon_squared = epsilon * epsilon;
  double lower_bound_by_epsilon_squared = lower_bound * epsilon_squared;
  int scaled_profit_upper_bound = //TODO come up with a better name
                    floor(profits_upper_bound / lower_bound_by_epsilon_squared);
  
  /* Initialisation of y, every multiple of z^l*eps is c+1 */
  int index;
  for(int k = 1; k <= scaled_profit_upper_bound; k++)
  {
    index = floor(k*lower_bound_by_epsilon_squared);
    y[index] = capacity + 1;
  }
  y[0] = 0;

  /* Initalisation of A, B and C */
  /* Note to self: we used profits_upper_bound + 1 because 
      A = (A(1), A(2), ... , A(n))
      B = (B(0), B(1), ... , B(n-1))
      C = (C(1), C(2), ... , C(n)) 
     as defined by Kellerer & Pferschy. To remain consistent with their 
     indexing, we need to be able to reach index n, as opposed to n-1. 
     If the VM algorithm is designed correctly, it should never touch A[0], 
     B[n], or C[0]. */
  int *A, *B, *C;
  A = calloc(profits_upper_bound + 1, sizeof(int));
  B = calloc(profits_upper_bound + 1, sizeof(int));
  C = calloc(profits_upper_bound + 1, sizeof(int));
  
  
  /* Find number of subintervals */
  int no_subintervals = 0; 
  int no_intervals = 1/epsilon - 1; 
  int val; 

  no_subintervals = get_no_subintervals_used(intervals, subintervals, n);

  int some_infinity = sum_of_all(large_weights_prime, n) + 1;

  /* Begin the interesting part */  
  int p_t, k_cap, no_weights;
  for(int i = 1; i <= no_subintervals; i++)
  {
    /* Get index of the i'th subinterval; 
        For each distinct profit value (i.e. each subinterval
        with positive items) */
    index = get_ith_subinterval(i, intervals, subintervals, n);
    
    /* This should never happen */
    if(index == -1) 
    {
      printf("What? We tried to get the %dth subinterval out of %d?\n",
             i, no_subintervals);
      break;
    }

    /* Get the relevant profit value */
    p_t = large_profits_prime[index];
    no_weights = 
         get_number_of_weights(index, large_profits_prime, n);

    /* For each residual value */
    for(int r = 0; r < p_t; r++)
    {
    clock_t start_iter = clock();
      /* For each profit value we can get from p_t */
      k_cap = floor(profits_upper_bound/p_t)+1;
      for(int k = 1; k <= k_cap; k++)
      {
        int indexo = (k-1)*p_t + r;
        A[k] = y[(k-1)*p_t + r];
        if (k <= no_weights) B[k] = large_weights_prime[index+k-1];
        else B[k] = some_infinity;
      }
      B[0] = 0;

      clock_t start = clock();
      vector_merge_interval(A, B, C, profits_upper_bound);
      clock_t end = clock();
      double elapsed =  ((double) (end - start)) / CLOCKS_PER_SEC;

      /* Put the result of vector merge into this array */
      for(int k = 1; k < k_cap; k++)
        y[(k-1)*p_t + r] = C[k];

    clock_t end_iter = clock();
    double elapsed_iter =  ((double) (end_iter - start_iter)) / CLOCKS_PER_SEC;
    }
  }

  /* Housekeeping */
  free(A);
  free(B);
  free(C);
  //free(y);
}

int get_ith_subinterval(int i, int *intervals, int *subintervals, 
                        int n)
{
  /* Given an i, return the index of the i'th subinterval */
  /* This is meant to be a way to grab the i'th distinct profit value, i.e.
      "for all different profit values p_t in L' ..." from the pseudocode */
  /* IMPORTANT! Since subintervals start at 1, the subinterval starting at
      0 is the first subinterval. This should not be confused with the index, 
      which will be returned. That is, while i may be 1, it will be at 
      index 0 */
  //TODO this doesn't work if i = 1
  assert(i > 0 && i <= n);

  int interval_number = 1;
  for(int j = 0; j < n; j++)
  {
    /* Either a subinterval changes within an interval, or an interval changes
        to another subinterval which was the same as the previous */
    if (interval_number == i)
      return j; 
    if( !(subintervals[j] == subintervals[j+1]
       &&    intervals[j] == intervals[j+1]))
    {
      interval_number++;
    }
  }
  
  /* There is no i'th subinterval */
  return -1;
}

int get_number_of_weights(int start_index, int *profits, int n)
{
  /* Assumes that profits[start_index] points to the profit value 
      of interest.
     Returns the number of distinct weight values associated to a single
      profit value */
  int m = 1;
  for(int i = start_index+1; profits[i] == profits[i-1] && m < n; i++, m++)
   ;
  return m;
}


int sum_of_all(int *arr, int n)
{
  /* Sums all the items of an array and returns the value */
  int sum = 0;
  for(int i = 0; i < n; i++)
    sum += arr[i];
  return sum;
}

void vector_merge_interval(int *A, int *B, int *C, int n)
{
 /**vector_merge_interval******************************************************
  * USED BY INTERVAL DYNAMIC PROGRAMMING                                      *
  *   FROM CORE KELLERER AND PFERSCHY FPTAS                                   *
  * Description                                                               *
  *  Solves the vector merging problem in O(nlogn) time                       *
  * Inputs                                                                    *
  *  A, B and C are all of length q                                           *
  *  n is the length of the arrays A, B and C. Recall that this is by default *
  *   the value profit_upper_bound = 2*lower_bound.                           *
  * TODO                                                                      *
  *   Generate test cases for this                                            *
  * NOTE TO SELF: BE VERY CAREFUL WHEN IMPLEMENTING THIS!                     *
  *                                                                           *
  *****************************************************************************/

  /* Initialise C */
  C[1] = A[1] + B[0];
  for(int j = 2; j <= n; j++)
    C[j] = C[j-1] + B[j-1];
  /* Start valgrind playing section */

  /* End valgrind playing section */

  // Define a(1), b(1), and pred(1)
  /* a, b and pred are all of length n+1 because they index C,
     which is of length n+1. It is necessary to be able to say
     where the interval of consecutive entries ending at C[n]
     resides with regards to a, b and pred, should C[n] use A[n]. */
  /* Despite each having n+1 slots, each will only have n elements */
  int *a = calloc(n+1, sizeof(int));
  int *b = calloc(n+1, sizeof(int));
  int *pred = calloc(n+1, sizeof(int));
  int *origin = calloc(n+1, sizeof(int));

  /* Symbolic infinity is n+2 for a, b, and pred because they index the ranges
     of A, B and C, who are all of range n+1... Well actually n+1 would do because
     n = q+1 anyway. TODO */
  int symbolic_infinity = n+2;

  /* Sanity check these base cases (in particular their indices) */
  a[1] = 1;
  b[1] = n+1;
  pred[1] = 0;

  /* Last is the index of the most recent non-empty interval. At the start,
      the most recent non-empty interval is clearly the first...? */
  int last = 1;
  
  int last_i_B_sum = sum_of(B, 0, n-1);
  // for i=2 to n
  for(int i = 2; i <= n; i++)
  {
    // if C(n) > A(i) + sumof(B, 0, n-i)
    last_i_B_sum = last_i_B_sum - B[n-(i-1)];
    if(C[n] > A[i] + last_i_B_sum)
    {
      // b(i) = n
      b[i] = n;
      // j = a(last)
      int j = a[last];
      // while C(j) > A(i) + sumof(B, 0, j-i) AND j>=i
      int this_sum = sum_of(B, 0, j-i);

      while(C[j] > A[i] + this_sum && j >= i) 
      {
        // C(j) = A(i) + sumof(B, 0, j-i)
        C[j] = A[i] + this_sum;
        // a(last) = infinity
        a[last] = symbolic_infinity;
        // b(last) = infinity
        b[last] = symbolic_infinity;
        // last = pred(last)
        last = pred[last];
        // j = a(last)
        j = a[last];
      }
      // if j >= i
      if(j >= i)
      {
        // perform binary search to find the largest value j in interval a[last] .. b[last] with C[j] <= A[i] + sum_of(B,0, j-i)
        int threshold = A[i] + this_sum;
        j = binary_search_max_value(a[last], b[last], threshold, C);
        // b[last] = j; a[i] = j+1;
        b[last] = j; a[i] = j+1;
      }
      // else
      else
      {
        //b(last) = i-1; a(i) = i;
       b[last] = i-1; 
       a[i] = i;
      }
      // pred(i) = last
      pred[i] = last;
      //last = i
      last = i;
    }
    // else
    else
    {
      // a(i) = infinity; b(i) = infinity
      /* Symbolic infinity is n+2 because the arrays are of range n+1*/
      a[i] = symbolic_infinity; 
      b[i] = symbolic_infinity;
    }
  }

  /* Reconstruction of origin */
  while(last > 0)
  {
    //for j := b(last) down to a(last) do
    for(int j = b[last]; j >= a[last]; j--)
      origin[j] = last;
    
    last = pred[last];
    //last := pred(last)
  }

  for(int i = 1; i < n+1; i++)
    C[i] = A[origin[i]] + sum_of(B, 0, i - origin[i]);
  free(a);
  free(b);
  free(pred);
}

void vector_merge_quadratic(int *A, int *B, int *C, int n)
{
  int *a = calloc(n+1, sizeof(int));
  int *b = calloc(n+1, sizeof(int));
  int *pred = calloc(n+1, sizeof(int));
  int *origin = calloc(n+1, sizeof(int));
  int symb_inf = n+2;
  int last, j;

  for(int j = 1; j <= n; j++)
    C[j] = A[1] + sum_of(B, 0, j-1);

  a[1] = 1; b[1] = n; pred[1] = 0;
  last = 1;
  for(int i = 2; i <= n; i++)
  {
    if(C[n] > A[i] + sum_of(B, 0, n-i))
    {
      b[i] = n;
      j = n-1;
      while(C[j] > A[i] + sum_of(B, 0, j-i) && j >= i)
      {
        C[j] = A[i] + sum_of(B, 0, j-1);
        if (j == a[last])
        {
          a[last] = symb_inf; b[last] = symb_inf;
          last = pred[last];
        }
        j = j-1;
      }
      b[last] = j;
      a[i] = j +1; pred[i] = last;
      last = i;
    }
    else
    {
      a[i] = symb_inf; b[i] = symb_inf;
    }
  }

  /* Reconstruction of origin */
  while(last > 0)
  {
    for(int j = b[last]; j >= a[last]; j--)
    {
      origin[j] = last;
    }
    last = pred[last];
  }
  for(int i = 1; i < n+1; i++)
    C[i] = A[origin[i]] + sum_of(B, 0, i - origin[i]);
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
  *  An auxiliary method for .ector_merge_interval                            *
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


void quicksort_and_print(int *list1, int *list2, int n, const char *name1, 
                         const char *name2)
{
 /**quicksort_and_print********************************************************
  * Description                                                               *
  *   Given two lists, and the length of each (they're the same size), sort   *
  *    them by the indices of the first list and then print them both.        *
  *                                                                           *
  *****************************************************************************/

  quick_sort_parallel_lists_asc_int(list1, list2, 0, n-1);

  for(int i = 0; i < n; i++) printf("%s%s%s%d%s",
      i == 0 ? "  int " : "", i==0 ? name1 : "", i == 0 ? "[] = {" : "", 
      list1[i], i == n-1 ? "};\n" : ", ");
  for(int i = 0; i < n; i++) printf("%s%s%s%d%s",
      i == 0 ? "  int " : "", i==0 ? name2 : "", i == 0 ? "[] = {" : "", 
      list2[i], i == n-1 ? "};\n" : ", ");
}

int get_no_subintervals(int no_intervals, double epsilon)
{
 /**get_no_subintervals********************************************************
  * Description                                                               *
  *   Given a number of intervals and a value epsilon, returns the number of  *
  *    subintervals in total across the entire set.                           *
  *                                                                           *
  *****************************************************************************/

  int val;
  int no_subintervals = 0;
  for(int i = 1; i <= no_intervals; i++)
  {
    val = ceil(1/(i*epsilon));
    no_subintervals += val;
  }
}

int get_no_subintervals_used(int *intervals, int *subintervals, int n)
{
 /**get_no_subintervals_used***************************************************
  * Description                                                               *
  *  Instead of determining the theoretical max number of intervals (as is    *
  *   done in get_no_subintervals), we simply count how many distinct         *
  *   subintervals are used in the given context.                             *
  *  Essentially, the loop just decides that a new subinterval has started    *
  *   if either of the intervals or subintervals has changed.                 *
  *                                                                           *
  *****************************************************************************/
  int subintervals_used = 1;

  for(int i = 1; i < n; i++)
    if (!(intervals[i-1] == intervals[i] && subintervals[i-1] == subintervals[i]))
      subintervals_used++;

  return subintervals_used;
}

int sum_of(int *array, int start, int end)
{
 /**sum_of*********************************************************************
  * Description                                                               *
  *  Returns the sum of the elements of array:                                *
  *   array[start] + array[start+1] + ... + array[end]                        *
  *                                                                           *
  *****************************************************************************/
  int sum = 0;
  for(int i = start; i <= end; i++)
    sum += array[i];
  return sum;
}

int binary_search_max_value(int left, int right, int threshold, int *arr)
{ 
 /**binary_search_max_value****************************************************
  * Description                                                               *
  *   Returns the maximum values less than or equal to threshold.             *
  *****************************************************************************/
  int best_index = -1;
  while(left <= right)
  {
    int mid = left + (right - left) / 2;
    if (arr[mid] == threshold)
      return mid;

    if (arr[mid] > threshold)
      right = mid - 1;

    else
    {
      if (arr[mid] > best_index)
        best_index = mid;
      left = mid + 1;
    }
  }
  return best_index;
}

void interval_dynamic_programming_for_testing(int *large_profits_prime, 
                                  int *large_weights_prime, int *intervals,
                                  int *subintervals, int n, int capacity,
                                  int lower_bound, double epsilon,
                                  int profits_upper_bound, int *y, int *r)
{
 /**interval_dynamic_programming***********************************************
  * USED BY CORE KELLERER AND PFERSCHY FPTAS                                  *
  * Description                                                               *
  *  Performs dynamic programming with auxiliary vector merging procedure     *
  *   on a series of items.                                                   *
  * Notes                                                                     *
  *   This will have n == new_n, because we'll have scaled and reduced the    *
  *    item item by this point.                                               *
  * TODO                                                                      *
  *   make sure this works with the data structures we have                   *
  *                                                                           *
  *****************************************************************************/
  
  /* y is of length q, the upper bound on profit */
  //y = malloc(profits_upper_bound * sizeof(int));
  //y = calloc(profits_upper_bound, sizeof(int));

  double epsilon_squared = epsilon * epsilon;
  double lower_bound_by_epsilon_squared = lower_bound * epsilon_squared;
  int scaled_profit_upper_bound = //TODO come up with a better name
                    floor(profits_upper_bound / lower_bound_by_epsilon_squared);
  
  /* Initialisation of y, every multiple of z^l*eps is c+1 */
  int index;
  for(int k = 1; k <= scaled_profit_upper_bound; k++)
  {
    index = floor(k*lower_bound_by_epsilon_squared);
    y[index] = capacity + 1;
  }
  y[0] = 0;

  /* Initalisation of A, B and C */
  /* Note to self: we used profits_upper_bound + 1 because 
      A = (A(1), A(2), ... , A(n))
      B = (B(0), B(1), ... , B(n-1))
      C = (C(1), C(2), ... , C(n)) 
     as defined by Kellerer & Pferschy. To remain consistent with their 
     indexing, we need to be able to reach index n, as opposed to n-1. 
     If the VM algorithm is designed correctly, it should never touch A[0], 
     B[n], or C[0]. */
  int *A, *B, *C;
  A = calloc(profits_upper_bound + 1, sizeof(int));
  B = calloc(profits_upper_bound + 1, sizeof(int));
  C = calloc(profits_upper_bound + 1, sizeof(int));
  
  
  /* Find number of subintervals */
  int no_subintervals = 0; 
  int no_intervals = 1/epsilon - 1; 
  int val; 

  no_subintervals = get_no_subintervals_used(intervals, subintervals, n);

  int some_infinity = sum_of_all(large_weights_prime, n) + 1;

  /* Begin the interesting part */  
  int p_t, k_cap, no_weights;
  for(int i = 1; i <= no_subintervals; i++)
  {
    /* Get index of the i'th subinterval; 
        For each distinct profit value (i.e. each subinterval
        with positive items) */
    index = get_ith_subinterval(i, intervals, subintervals, n);
    
    /* This should never happen */
    if(index == -1) 
    {
      printf("What? We tried to get the %dth subinterval out of %d?\n",
             i, no_subintervals);
      break;
    }

    /* Get the relevant profit value */
    p_t = large_profits_prime[index];
    no_weights = 
         get_number_of_weights(index, large_profits_prime, n);

    /* For each residual value */
    //TODO 1000 iterations of this takes about 11 seconds
    for(int r = 0; r < p_t; r++)
    {
    clock_t start_iter = clock();
      /* For each profit value we can get from p_t */
      k_cap = floor(profits_upper_bound/p_t)+1;
      for(int k = 1; k <= k_cap; k++)
      {
        int indexo = (k-1)*p_t + r;
        A[k] = y[(k-1)*p_t + r];
        if (k <= no_weights) B[k] = large_weights_prime[index+k-1];
        else B[k] = some_infinity;
      }
      B[0] = 0;

      clock_t start = clock();
      //vector_merge_interval(A, B, C, profits_upper_bound);
      //vector_merge_naive(A, B, C, profits_upper_bound);
      vector_merge_quadratic(A, B, C, profits_upper_bound);
      clock_t end = clock();
      double elapsed =  ((double) (end - start)) / CLOCKS_PER_SEC;
      //printf("Vector merge completed after %lf seconds.\n", elapsed);

      /* Put the result of vector merge into this array */
      for(int k = 1; k < k_cap; k++)
        y[(k-1)*p_t + r] = C[k];

    clock_t end_iter = clock();
    double elapsed_iter =  ((double) (end_iter - start_iter)) / CLOCKS_PER_SEC;
    //printf("Iteration completed after %lf seconds.\n", elapsed_iter);
    }
  }

  /* Housekeeping */
  free(A);
  free(B);
  free(C);
  //free(y);
}
