#ifndef BRANCH_AND_BOUND_BENCHMARK_H
#define BRANCH_AND_BOUND_BENCHMARK_H
#include <stdio.h>

#define BRANCH_STRAT_NO_OF_OPTIONS 3
#define NELEMS(x) (sizeof(x) / sizeof((x)[0]))

void benchmark_instance(char *file_name_holder, int problem_no, int timeout, 
                       int DP_method, int allocation_limit, 
                       FILE *benchmark_stream, int branching_strategy,
                       int dualbounding_method);

void benchmark(int memory_allocation_limit, int timeout, char *DP_set, 
               char *n_set, char *coefficient_set, char *instance_set,
               char *branching_strategies, FILE *benchmark_stream, 
               int problem_set, char *hard_instance_set, char *hard_n_set,
               char *dualbound_type);

void command_line_validation(const char argv1[], const char argv2[], 
                            const char argv3[], const char argv4[], 
                            const char argv5[], const char argv6[],
                            const char argv7[], const char argv8[], 
                            const char argv9[], const char argv10[], 
                            const char argv11[], const char argv12[]);

int file_test(const char file_name[]);


#endif
