void kellerer_pferschy_fptas(void);
void scaling_reduction(double epsilon);
void get_knapsack_lowerbound(int *profits, int *weights, int n, int capacity, 
                             int *lower_bound, double *upper_bound);
void modify_epsilon(double *epsilon);
void small_large_split(int *profits, int *weights, int n, int capacity, 
                       double epsilon, int lower_bound, int *small, int *large);
void partition_large_set(int *profits, int *weights, int n, double epsilon, 
                         int lower_bound, int *indices_out);
void partition_interval(int *profits, int n3, double epsilon, int lowerbound, int *intervals, int *indices_out);
void reduce_profits_to_mimimal(int *profits, int *intervals, int *subintervals,
                               double epsilon, int lowerbound, int n);
void prune_excess_weight_items(void);
void redefine_large_set(void);
void binary_search(void);
void interval_dynamic_programming(void);
void vector_merge_interval(void);
void quick_sort_parallel_lists(double *list1, double *list2, int lo, int hi);
void swap ( double* a, double* b );
int partition (double arr1[], double arr2[], int l, int h); 


