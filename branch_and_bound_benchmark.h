#define BRANCH_STRAT_NO_OF_OPTIONS 3

void benchmark_instance(char *file_name_holder, int problem_no, int timeout, 
                       int DP_method, int allocation_limit, 
                       FILE *benchmark_stream, int branching_strategy);

void benchmark(int memory_allocation_limit, int timeout, char *DP_set, 
               char *n_set, char *coefficient_set, char *instance_set,
               char *branching_strategies, FILE *benchmark_stream, 
               int problem_set);
