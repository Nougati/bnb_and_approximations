/*******************************************************************************
 *  keller_pferschy_fptas.h                                                    *
 *  Description                                                                * 
 *    The header file for the Kellerer/Pferschy FPTAS implementation.          * 
 *                                                                             * 
 *******************************************************************************/

void kellerer_pferschy_fptas(int *profits, int *weights, int n, int capacity, 
                             double epsilon);
void scaling_reduction(int *profits, int *weights, int n, int capacity,
                       double *epsilon,int *large_profits, int *large_weights,
                       int *small_profits, int *small_weights, int *intervals, 
                       int *subintervals, int *new_n);
void get_knapsack_lowerbound(int *profits, int *weights, int n, int capacity, 
                             int *lower_bound, double *upper_bound);
void modify_epsilon(double *epsilon);
void small_large_split(int *profits, int *weights, int n, int capacity, 
                       double epsilon, int lower_bound, int *small_profits,
                       int *large_profits, int *small_weights, 
                       int *large_weights, int *n_large);
void partition_large_set(int *profits, int *weights, int n, double epsilon, 
                         int lower_bound, int *indices_out);
void partition_interval(int *profits, int n, double epsilon, int lowerbound, 
                        int *intervals, int *indices_out);
void reduce_profits_to_minimal(int *profits, int *intervals, int *subintervals,
                               double epsilon, int lowerbound, int n);
void prune_excess_weight_items(int *profits, int *weights, int *intervals, 
                              int *subintervals, int current_interval, 
                              int current_subinterval, double epsilon, int n);
void redefine_large_set(int *profits, int *weights, int *intervals, 
                        int *subintervals, int n, int *new_n);
void binary_search(void);
void interval_dynamic_programming(int *large_profits_prime, 
                                  int *large_weights_prime, int *intervals,
                                  int *subintervals, int n, int capacity,
                                  int lower_bound, double epsilon,
                                  int profits_upper_bound);
void vector_merge_interval(int *A, int *B, int *C, int n, int q);
void quick_sort_parallel_lists_desc_double(double *list1, double *list2, int lo,
                                           int hi);
void quick_sort_parallel_lists_asc_double(double *list1, double *list2, int lo,
                                           int hi);
void swap_double( double* a, double* b );
int partition_desc_double(double arr1[], double arr2[], int l, int h); 
int partition_asc_double(double arr1[], double arr2[], int l, int h); 

void quick_sort_parallel_lists_desc_int(int *list1, int *list2, int lo, int hi);
void quick_sort_parallel_lists_asc_int(int *list1, int *list2, int lo, int hi);
void swap_int( int * a, int * b );
int partition_desc_int(int arr1[], int arr2[], int l, int h); 
int partition_asc_int(int arr1[], int arr2[], int l, int h); 

void vector_merge_naive(int *A, int *B, int *C, int n); 
void populate(int *sum_array, int *A, int *B, int j); 
int get_associated_sum(int *A, int *B, int j, int i); 
int min_val_of(int *array, int n); 
int sum_of_all(int *array, int n);
int get_ith_subinterval(int i, int *intervals, int *subintervals, 
                        int n);
int get_number_of_weights(int start_index, int *profits, int n);
void quicksort_and_print(int *list1, int *list2, int n,
                         const char *name1, const char *name2); 
int get_no_subintervals(int no_intervals, double epsilon);
void print_list(int *list, int length, const char *name);
int get_no_subintervals_used(int *intervals, int *subintervals, int n);
