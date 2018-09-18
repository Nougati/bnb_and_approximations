/*******************************************************************************
 *  keller_pferschy_fptas.h                                                    *
 *  Description                                                                * 
 *    The header file for the Kellerer/Pferschy FPTAS implementation.          * 
 *                                                                             * 
 *******************************************************************************/   

void kellerer_pferschy_fptas(void);
void scaling_reduction(double epsilon);
void get_knapsack_lowerbound(int *profits, int *weights, int n, int capacity, 
                             int *lower_bound, double *upper_bound);
void modify_epsilon(double *epsilon);
void small_large_split(int *profits, int *weights, int n, int capacity, 
                       double epsilon, int lower_bound, int *small, int *large);
void partition_large_set(int *profits, int *weights, int n, double epsilon, 
                         int lower_bound, int *indices_out);
void partition_interval(int *profits, int n, double epsilon, int lowerbound, 
                        int *intervals, int *indices_out);
void reduce_profits_to_mimimal(int *profits, int *intervals, int *subintervals,
                               double epsilon, int lowerbound, int n);
void prune_excess_weight_items(int *profits, int *weights, int *intervals, 
                              int *subintervals, int current_interval, 
                              int current_subinterval, double epsilon, int n);
void redefine_large_set(int *profits, int *weights, int *intervals, 
                        int *subintervals, int n, int *new_n);
void binary_search(void);
void interval_dynamic_programming(void);
void vector_merge_interval(int *A, int *B, int *C, int n);
void quick_sort_parallel_lists(double *list1, double *list2, int lo, int hi);
void swap ( double* a, double* b );
int partition (double arr1[], double arr2[], int l, int h); 
void vector_merge_naive(int *A, int *B, int *C, int n); 
void populate(int *sum_array, int *A, int *B, int j); 
int get_associated_sum(int *A, int *B, int j, int i); 
int min_val_of(int *array, int n); 




