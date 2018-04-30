/*****************************************************************************
 * branch_and_bound_night_test.cpp                                           *
 * Author: Nelson Frew                                                       *
 * TODO the branch and bound calls need to have memory_allocation limit,     *
 *  start_time, and timeout                                                  * 
 * Description:                                                              *
 *   Heavy unit tests to simply try the branch and bound on different        *
 *        instances.                                                         *
 *****************************************************************************/

#include <stdio.h>
#include <time.h>
#define TESTING
#include <gtest/gtest.h>
extern "C"
{
    #include "pisinger_reader.h"
    #include "branch_and_bound.h"
    #include "fptas.h"
}
//#include <math.h>

class branch_and_bound_correctnessTest : public testing::Test
{
  void SetUp(){
  }
  void TearDown(){
  }
};

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_uncorrelated_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_50_1000.csv";
  /* For each 1_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
								DP_method, logging_rule, logging_stream, epsilon, 
                                &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
    /* TODO For each test I gotta free profits, weights and x, and close logging stream */
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_uncorrelated_50_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_50_10000.csv";
  /* For each 1_50_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_uncorrelated_50_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_50_100000.csv";
  /* For each 1_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_uncorrelated_50_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_50_1000000.csv";
  /* For each 1_50_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_uncorrelated_50_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_50_100000.csv";
  /* For each 1_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_uncorrelated_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_100_1000.csv";
  /* For each 1_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_uncorrelated_100_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_100_10000.csv";
  /* For each 1_100_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_uncorrelated_100_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_100_100000.csv";
  /* For each 1_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_uncorrelated_100_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_100_1000000.csv";
  /* For each 1_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_uncorrelated_100_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_100_100000.csv";
  /* For each 1_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_weaklycorrelated_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_50_1000.csv";
  /* For each 2_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_weaklycorrelated_50_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_50_10000.csv";
  /* For each 2_50_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_weaklycorrelated_50_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_50_100000.csv";
  /* For each 2_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_weaklycorrelated_50_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_50_1000000.csv";
  /* For each 2_50_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_weaklycorrelated_50_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_50_100000.csv";
  /* For each 2_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_weaklycorrelated_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_100_1000.csv";
  /* For each 2_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_weaklycorrelated_100_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_100_10000.csv";
  /* For each 2_100_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_weaklycorrelated_100_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_100_100000.csv";
  /* For each 2_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_weaklycorrelated_100_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_100_1000000.csv";
  /* For each 2_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_weaklycorrelated_100_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_100_100000.csv";
  /* For each 2_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}


TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_stronglycorrelated_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_50_1000.csv";
  /* For each 3_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_stronglycorrelated_50_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_50_10000.csv";
  /* For each 3_50_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_stronglycorrelated_50_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_50_100000.csv";
  /* For each 3_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_stronglycorrelated_50_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_50_1000000.csv";
  /* For each 3_50_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_stronglycorrelated_50_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_50_100000.csv";
  /* For each 3_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_stronglycorrelated_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_100_1000.csv";
  /* For each 3_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_stronglycorrelated_100_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_100_10000.csv";
  /* For each 3_100_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_stronglycorrelated_100_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_100_100000.csv";
  /* For each 3_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_stronglycorrelated_100_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_100_1000000.csv";
  /* For each 3_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_stronglycorrelated_100_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_100_100000.csv";
  /* For each 3_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}


TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_inversestronglycorrelated_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_4_50_1000.csv";
  /* For each 4_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_inversestronglycorrelated_50_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_4_50_10000.csv";
  /* For each 4_50_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_inversestronglycorrelated_50_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_4_50_100000.csv";
  /* For each 4_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_inversestronglycorrelated_50_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_4_50_1000000.csv";
  /* For each 4_50_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_inversestronglycorrelated_50_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_4_50_100000.csv";
  /* For each 4_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_inversestronglycorrelated_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_4_100_1000.csv";
  /* For each 4_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_inversestronglycorrelated_100_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_4_100_10000.csv";
  /* For each 4_100_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_inversestronglycorrelated_100_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_4_100_100000.csv";
  /* For each 4_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_inversestronglycorrelated_100_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_4_100_1000000.csv";
  /* For each 4_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_inversestronglycorrelated_100_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_4_100_100000.csv";
  /* For each 4_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}


TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_almoststronglycorrelated_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_5_50_1000.csv";
  /* For each 5_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_almoststronglycorrelated_50_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_5_50_10000.csv";
  /* For each 5_50_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_almoststronglycorrelated_50_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_5_50_100000.csv";
  /* For each 5_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_almoststronglycorrelated_50_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_5_50_1000000.csv";
  /* For each 5_50_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_almoststronglycorrelated_50_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_5_50_100000.csv";
  /* For each 5_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_almoststronglycorrelated_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_5_100_1000.csv";
  /* For each 5_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_almoststronglycorrelated_100_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_5_100_10000.csv";
  /* For each 5_100_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_almoststronglycorrelated_100_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_5_100_100000.csv";
  /* For each 5_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_almoststronglycorrelated_100_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_5_100_1000000.csv";
  /* For each 5_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_almoststronglycorrelated_100_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_5_100_100000.csv";
  /* For each 5_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}


TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_subsetsum_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_6_50_1000.csv";
  /* For each 6_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_subsetsum_50_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_6_50_10000.csv";
  /* For each 6_50_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_subsetsum_50_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_6_50_100000.csv";
  /* For each 6_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_subsetsum_50_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_6_50_1000000.csv";
  /* For each 6_50_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_subsetsum_50_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_6_50_100000.csv";
  /* For each 6_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_subsetsum_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_6_100_1000.csv";
  /* For each 6_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_subsetsum_100_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_6_100_10000.csv";
  /* For each 6_100_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_subsetsum_100_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_6_100_100000.csv";
  /* For each 6_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_subsetsum_100_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_6_100_1000000.csv";
  /* For each 6_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_subsetsum_100_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_6_100_100000.csv";
  /* For each 6_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}


TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_similarweights_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_9_50_1000.csv";
  /* For each 11_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}
TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_similarweights_50_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_9_50_100000.csv";
  /* For each 11_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_similarweights_50_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_9_50_1000000.csv";
  /* For each 11_50_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_similarweights_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_9_100_1000.csv";
  /* For each 11_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}
TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_similarweights_100_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_9_100_100000.csv";
  /* For each 11_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_similarweights_100_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_9_100_1000000.csv";
  /* For each 11_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}


TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_uncorrelatedspan_20_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_11_20_1000.csv";
  /* For each 11_20_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_uncorrelatedspan_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_11_50_1000.csv";
  /* For each 11_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_uncorrelatedspan_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_11_100_1000.csv";
  /* For each 11_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}


TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_weaklycorrelatedspan_20_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_12_20_1000.csv";
  /* For each 11_20_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_weaklycorrelatedspan_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_12_50_1000.csv";
  /* For each 11_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_weaklycorrelatedspan_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_12_100_1000.csv";
  /* For each 11_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}


TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_stronglycorrelatedspan_20_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_13_20_1000.csv";
  /* For each 11_20_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_stronglycorrelatedspan_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_13_50_1000.csv";
  /* For each 11_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_stronglycorrelatedspan_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_13_100_1000.csv";
  /* For each 11_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_mstr_20_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_14_20_1000.csv";
  /* For each 11_20_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_mstr_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_14_50_1000.csv";
  /* For each 11_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_mstr_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_14_100_1000.csv";
  /* For each 11_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}


TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_pceil_20_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_15_20_1000.csv";
  /* For each 11_20_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_pceil_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_15_50_1000.csv";
  /* For each 11_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_pceil_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_15_100_1000.csv";
  /* For each 11_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_circle_20_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_16_20_1000.csv";
  /* For each 11_20_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_circle_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_16_50_1000.csv";
  /* For each 11_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_circle_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_16_100_1000.csv";
  /* For each 11_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}


TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_uncorrelated_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_50_1000.csv";
  /* For each 1_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_uncorrelated_50_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_50_10000.csv";
  /* For each 1_50_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_uncorrelated_50_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_50_100000.csv";
  /* For each 1_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_uncorrelated_50_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_50_1000000.csv";
  /* For each 1_50_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_uncorrelated_50_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_50_100000.csv";
  /* For each 1_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_uncorrelated_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_100_1000.csv";
  /* For each 1_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_uncorrelated_100_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_100_10000.csv";
  /* For each 1_100_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_uncorrelated_100_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_100_100000.csv";
  /* For each 1_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_uncorrelated_100_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_100_1000000.csv";
  /* For each 1_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_uncorrelated_100_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_100_100000.csv";
  /* For each 1_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}


TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_weaklycorrelated_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_50_1000.csv";
  /* For each 2_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_weaklycorrelated_50_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_50_10000.csv";
  /* For each 2_50_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_weaklycorrelated_50_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_50_100000.csv";
  /* For each 2_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_weaklycorrelated_50_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_50_1000000.csv";
  /* For each 2_50_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_weaklycorrelated_50_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_50_100000.csv";
  /* For each 2_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_weaklycorrelated_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_100_1000.csv";
  /* For each 2_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_weaklycorrelated_100_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_100_10000.csv";
  /* For each 2_100_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_weaklycorrelated_100_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_100_100000.csv";
  /* For each 2_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_weaklycorrelated_100_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_100_1000000.csv";
  /* For each 2_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_weaklycorrelated_100_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_100_100000.csv";
  /* For each 2_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_stronglycorrelated_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_50_1000.csv";
  /* For each 3_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_stronglycorrelated_50_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_50_10000.csv";
  /* For each 3_50_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_stronglycorrelated_50_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_50_100000.csv";
  /* For each 3_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_stronglycorrelated_50_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_50_1000000.csv";
  /* For each 3_50_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_stronglycorrelated_50_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_50_100000.csv";
  /* For each 3_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_stronglycorrelated_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_100_1000.csv";
  /* For each 3_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_stronglycorrelated_100_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_100_10000.csv";
  /* For each 3_100_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_stronglycorrelated_100_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_100_100000.csv";
  /* For each 3_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_stronglycorrelated_100_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_100_1000000.csv";
  /* For each 3_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_stronglycorrelated_100_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_100_100000.csv";
  /* For each 3_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}


TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_inversestronglycorrelated_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_4_50_1000.csv";
  /* For each 4_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_inversestronglycorrelated_50_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_4_50_10000.csv";
  /* For each 4_50_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_inversestronglycorrelated_50_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_4_50_100000.csv";
  /* For each 4_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_inversestronglycorrelated_50_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_4_50_1000000.csv";
  /* For each 4_50_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_inversestronglycorrelated_50_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_4_50_100000.csv";
  /* For each 4_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_inversestronglycorrelated_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_4_100_1000.csv";
  /* For each 4_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_inversestronglycorrelated_100_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_4_100_10000.csv";
  /* For each 4_100_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_inversestronglycorrelated_100_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_4_100_100000.csv";
  /* For each 4_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_inversestronglycorrelated_100_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_4_100_1000000.csv";
  /* For each 4_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_inversestronglycorrelated_100_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_4_100_100000.csv";
  /* For each 4_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}


TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_almoststronglycorrelated_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_5_50_1000.csv";
  /* For each 5_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_almoststronglycorrelated_50_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_5_50_10000.csv";
  /* For each 5_50_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_almoststronglycorrelated_50_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_5_50_100000.csv";
  /* For each 5_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_almoststronglycorrelated_50_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_5_50_1000000.csv";
  /* For each 5_50_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_almoststronglycorrelated_50_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_5_50_100000.csv";
  /* For each 5_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_almoststronglycorrelated_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_5_100_1000.csv";
  /* For each 5_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_almoststronglycorrelated_100_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_5_100_10000.csv";
  /* For each 5_100_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_almoststronglycorrelated_100_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_5_100_100000.csv";
  /* For each 5_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_almoststronglycorrelated_100_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_5_100_1000000.csv";
  /* For each 5_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_almoststronglycorrelated_100_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_5_100_100000.csv";
  /* For each 5_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_subsetsum_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_6_50_1000.csv";
  /* For each 6_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_subsetsum_50_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_6_50_10000.csv";
  /* For each 6_50_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_subsetsum_50_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_6_50_100000.csv";
  /* For each 6_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_subsetsum_50_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_6_50_1000000.csv";
  /* For each 6_50_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_subsetsum_50_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_6_50_100000.csv";
  /* For each 6_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_subsetsum_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_6_100_1000.csv";
  /* For each 6_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_subsetsum_100_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_6_100_10000.csv";
  /* For each 6_100_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_subsetsum_100_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_6_100_100000.csv";
  /* For each 6_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_subsetsum_100_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_6_100_1000000.csv";
  /* For each 6_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_subsetsum_100_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_6_100_100000.csv";
  /* For each 6_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_similarweights_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_9_50_1000.csv";
  /* For each 11_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}
TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_similarweights_50_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_9_50_100000.csv";
  /* For each 11_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_similarweights_50_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_9_50_1000000.csv";
  /* For each 11_50_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_similarweights_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_9_100_1000.csv";
  /* For each 11_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}
TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_similarweights_100_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_9_100_100000.csv";
  /* For each 11_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_uncorrelatedspan_20_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_11_20_1000.csv";
  /* For each 11_20_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_uncorrelatedspan_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_11_50_1000.csv";
  /* For each 11_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_uncorrelatedspan_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_11_100_1000.csv";
  /* For each 11_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_weaklycorrelatedspan_20_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_12_20_1000.csv";
  /* For each 11_20_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_weaklycorrelatedspan_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_12_50_1000.csv";
  /* For each 11_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_weaklycorrelatedspan_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_12_100_1000.csv";
  /* For each 11_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}


TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_stronglycorrelatedspan_20_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_13_20_1000.csv";
  /* For each 11_20_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_stronglycorrelatedspan_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_13_50_1000.csv";
  /* For each 11_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_stronglycorrelatedspan_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_13_100_1000.csv";
  /* For each 11_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}


TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_mstr_20_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_14_20_1000.csv";
  /* For each 11_20_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_mstr_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_14_50_1000.csv";
  /* For each 11_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_mstr_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_14_100_1000.csv";
  /* For each 11_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_pceil_20_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_15_20_1000.csv";
  /* For each 11_20_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_pceil_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_15_50_1000.csv";
  /* For each 11_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_pceil_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_15_100_1000.csv";
  /* For each 11_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_circle_20_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_16_20_1000.csv";
  /* For each 11_20_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_circle_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_16_50_1000.csv";
  /* For each 11_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_circle_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_16_100_1000.csv";
  /* For each 11_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_uncorrelated_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_50_1000.csv";
  /* For each 1_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_uncorrelated_50_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_50_10000.csv";
  /* For each 1_50_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_uncorrelated_50_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_50_100000.csv";
  /* For each 1_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_uncorrelated_50_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_50_1000000.csv";
  /* For each 1_50_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_uncorrelated_50_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_50_100000.csv";
  /* For each 1_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_uncorrelated_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_100_1000.csv";
  /* For each 1_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_uncorrelated_100_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_100_10000.csv";
  /* For each 1_100_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_uncorrelated_100_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_100_100000.csv";
  /* For each 1_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_uncorrelated_100_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_100_1000000.csv";
  /* For each 1_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_uncorrelated_100_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_100_100000.csv";
  /* For each 1_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_weaklycorrelated_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_50_1000.csv";
  /* For each 2_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_weaklycorrelated_50_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_50_10000.csv";
  /* For each 2_50_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_weaklycorrelated_50_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_50_100000.csv";
  /* For each 2_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_weaklycorrelated_50_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_50_1000000.csv";
  /* For each 2_50_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_weaklycorrelated_50_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_50_100000.csv";
  /* For each 2_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_weaklycorrelated_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_100_1000.csv";
  /* For each 2_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_weaklycorrelated_100_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_100_10000.csv";
  /* For each 2_100_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_weaklycorrelated_100_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_100_100000.csv";
  /* For each 2_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_weaklycorrelated_100_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_100_1000000.csv";
  /* For each 2_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_weaklycorrelated_100_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_100_100000.csv";
  /* For each 2_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}


TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_stronglycorrelated_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_50_1000.csv";
  /* For each 3_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_stronglycorrelated_50_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_50_10000.csv";
  /* For each 3_50_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_stronglycorrelated_50_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_50_100000.csv";
  /* For each 3_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_stronglycorrelated_50_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_50_1000000.csv";
  /* For each 3_50_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_stronglycorrelated_50_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_50_100000.csv";
  /* For each 3_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_stronglycorrelated_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_100_1000.csv";
  /* For each 3_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_stronglycorrelated_100_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_100_10000.csv";
  /* For each 3_100_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_stronglycorrelated_100_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_100_100000.csv";
  /* For each 3_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_stronglycorrelated_100_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_100_1000000.csv";
  /* For each 3_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_stronglycorrelated_100_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_100_100000.csv";
  /* For each 3_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}


TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_inversestronglycorrelated_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_4_50_1000.csv";
  /* For each 4_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_inversestronglycorrelated_50_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_4_50_10000.csv";
  /* For each 4_50_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_inversestronglycorrelated_50_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_4_50_100000.csv";
  /* For each 4_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_inversestronglycorrelated_50_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_4_50_1000000.csv";
  /* For each 4_50_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_inversestronglycorrelated_50_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_4_50_100000.csv";
  /* For each 4_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_inversestronglycorrelated_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_4_100_1000.csv";
  /* For each 4_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_inversestronglycorrelated_100_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_4_100_10000.csv";
  /* For each 4_100_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_inversestronglycorrelated_100_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_4_100_100000.csv";
  /* For each 4_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_inversestronglycorrelated_100_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_4_100_1000000.csv";
  /* For each 4_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_inversestronglycorrelated_100_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_4_100_100000.csv";
  /* For each 4_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}


TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_almoststronglycorrelated_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_5_50_1000.csv";
  /* For each 5_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_almoststronglycorrelated_50_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_5_50_10000.csv";
  /* For each 5_50_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_almoststronglycorrelated_50_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_5_50_100000.csv";
  /* For each 5_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_almoststronglycorrelated_50_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_5_50_1000000.csv";
  /* For each 5_50_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_almoststronglycorrelated_50_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_5_50_100000.csv";
  /* For each 5_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_almoststronglycorrelated_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_5_100_1000.csv";
  /* For each 5_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_almoststronglycorrelated_100_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_5_100_10000.csv";
  /* For each 5_100_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_almoststronglycorrelated_100_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_5_100_100000.csv";
  /* For each 5_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_almoststronglycorrelated_100_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_5_100_1000000.csv";
  /* For each 5_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_almoststronglycorrelated_100_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_5_100_100000.csv";
  /* For each 5_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}


TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_subsetsum_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_6_50_1000.csv";
  /* For each 6_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_subsetsum_50_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_6_50_10000.csv";
  /* For each 6_50_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_subsetsum_50_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_6_50_100000.csv";
  /* For each 6_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_subsetsum_50_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_6_50_1000000.csv";
  /* For each 6_50_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_subsetsum_50_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_6_50_100000.csv";
  /* For each 6_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_subsetsum_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_6_100_1000.csv";
  /* For each 6_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_subsetsum_100_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_6_100_10000.csv";
  /* For each 6_100_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_subsetsum_100_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_6_100_100000.csv";
  /* For each 6_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_subsetsum_100_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_6_100_1000000.csv";
  /* For each 6_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_subsetsum_100_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_6_100_100000.csv";
  /* For each 6_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_similarweights_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_9_50_1000.csv";
  /* For each 11_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}
TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_similarweights_50_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_9_50_100000.csv";
  /* For each 11_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_similarweights_50_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_9_50_1000000.csv";
  /* For each 11_50_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_similarweights_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_9_100_1000.csv";
  /* For each 11_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}
TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_similarweights_100_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_9_100_100000.csv";
  /* For each 11_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_similarweights_100_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_9_100_1000000.csv";
  /* For each 11_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}
TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_uncorrelatedspan_20_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_11_20_1000.csv";
  /* For each 11_20_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_uncorrelatedspan_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_11_50_1000.csv";
  /* For each 11_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_uncorrelatedspan_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_11_100_1000.csv";
  /* For each 11_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}


TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_weaklycorrelatedspan_20_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_12_20_1000.csv";
  /* For each 11_20_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_weaklycorrelatedspan_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_12_50_1000.csv";
  /* For each 11_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_weaklycorrelatedspan_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_12_100_1000.csv";
  /* For each 11_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}


TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_stronglycorrelatedspan_20_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_13_20_1000.csv";
  /* For each 11_20_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_stronglycorrelatedspan_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_13_50_1000.csv";
  /* For each 11_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_stronglycorrelatedspan_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_13_100_1000.csv";
  /* For each 11_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}


TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_mstr_20_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_14_20_1000.csv";
  /* For each 11_20_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_mstr_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_14_50_1000.csv";
  /* For each 11_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}


TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_pceil_20_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_15_20_1000.csv";
  /* For each 11_20_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_pceil_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_15_50_1000.csv";
  /* For each 11_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_pceil_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_15_100_1000.csv";
  /* For each 11_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_circle_20_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_16_20_1000.csv";
  /* For each 11_20_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_circle_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_16_50_1000.csv";
  /* For each 11_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_circle_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_16_100_1000.csv";
  /* For each 11_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}


TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_uncorrelated_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_50_1000.csv";
  /* For each 1_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_uncorrelated_50_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_50_10000.csv";
  /* For each 1_50_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_uncorrelated_50_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_50_100000.csv";
  /* For each 1_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_uncorrelated_50_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_50_1000000.csv";
  /* For each 1_50_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_uncorrelated_50_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_50_100000.csv";
  /* For each 1_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_uncorrelated_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_100_1000.csv";
  /* For each 1_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_uncorrelated_100_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_100_10000.csv";
  /* For each 1_100_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_uncorrelated_100_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_100_100000.csv";
  /* For each 1_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_uncorrelated_100_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_100_1000000.csv";
  /* For each 1_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_uncorrelated_100_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_100_100000.csv";
  /* For each 1_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}


TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_weaklycorrelated_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_50_1000.csv";
  /* For each 2_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_weaklycorrelated_50_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_50_10000.csv";
  /* For each 2_50_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_weaklycorrelated_50_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_50_100000.csv";
  /* For each 2_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_weaklycorrelated_50_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_50_1000000.csv";
  /* For each 2_50_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_weaklycorrelated_50_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_50_100000.csv";
  /* For each 2_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_weaklycorrelated_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_100_1000.csv";
  /* For each 2_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_weaklycorrelated_100_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_100_10000.csv";
  /* For each 2_100_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_weaklycorrelated_100_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_100_100000.csv";
  /* For each 2_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_weaklycorrelated_100_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_100_1000000.csv";
  /* For each 2_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_weaklycorrelated_100_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_100_100000.csv";
  /* For each 2_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}


TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_stronglycorrelated_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_50_1000.csv";
  /* For each 3_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_stronglycorrelated_50_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_50_10000.csv";
  /* For each 3_50_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_stronglycorrelated_50_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_50_100000.csv";
  /* For each 3_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_stronglycorrelated_50_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_50_1000000.csv";
  /* For each 3_50_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_stronglycorrelated_50_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_50_100000.csv";
  /* For each 3_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_stronglycorrelated_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_100_1000.csv";
  /* For each 3_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_stronglycorrelated_100_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_100_10000.csv";
  /* For each 3_100_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_stronglycorrelated_100_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_100_100000.csv";
  /* For each 3_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_stronglycorrelated_100_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_100_1000000.csv";
  /* For each 3_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_stronglycorrelated_100_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_100_100000.csv";
  /* For each 3_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}


TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_inversestronglycorrelated_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_4_50_1000.csv";
  /* For each 4_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_inversestronglycorrelated_50_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_4_50_10000.csv";
  /* For each 4_50_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_inversestronglycorrelated_50_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_4_50_100000.csv";
  /* For each 4_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_inversestronglycorrelated_50_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_4_50_1000000.csv";
  /* For each 4_50_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_inversestronglycorrelated_50_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_4_50_100000.csv";
  /* For each 4_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_inversestronglycorrelated_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_4_100_1000.csv";
  /* For each 4_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_inversestronglycorrelated_100_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_4_100_10000.csv";
  /* For each 4_100_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_inversestronglycorrelated_100_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_4_100_100000.csv";
  /* For each 4_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_inversestronglycorrelated_100_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_4_100_1000000.csv";
  /* For each 4_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_inversestronglycorrelated_100_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_4_100_100000.csv";
  /* For each 4_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}


TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_almoststronglycorrelated_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_5_50_1000.csv";
  /* For each 5_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_almoststronglycorrelated_50_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_5_50_10000.csv";
  /* For each 5_50_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_almoststronglycorrelated_50_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_5_50_100000.csv";
  /* For each 5_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_almoststronglycorrelated_50_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_5_50_1000000.csv";
  /* For each 5_50_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_almoststronglycorrelated_50_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_5_50_100000.csv";
  /* For each 5_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_almoststronglycorrelated_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_5_100_1000.csv";
  /* For each 5_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_almoststronglycorrelated_100_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_5_100_10000.csv";
  /* For each 5_100_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_almoststronglycorrelated_100_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_5_100_100000.csv";
  /* For each 5_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_almoststronglycorrelated_100_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_5_100_1000000.csv";
  /* For each 5_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_almoststronglycorrelated_100_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_5_100_100000.csv";
  /* For each 5_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}


TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_subsetsum_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_6_50_1000.csv";
  /* For each 6_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_subsetsum_50_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_6_50_10000.csv";
  /* For each 6_50_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_subsetsum_50_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_6_50_100000.csv";
  /* For each 6_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_subsetsum_50_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_6_50_1000000.csv";
  /* For each 6_50_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_subsetsum_50_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_6_50_100000.csv";
  /* For each 6_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_subsetsum_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_6_100_1000.csv";
  /* For each 6_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_subsetsum_100_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_6_100_10000.csv";
  /* For each 6_100_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_subsetsum_100_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_6_100_100000.csv";
  /* For each 6_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_subsetsum_100_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_6_100_1000000.csv";
  /* For each 6_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_subsetsum_100_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_6_100_100000.csv";
  /* For each 6_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}


TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_similarweights_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_9_50_1000.csv";
  /* For each 11_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}
TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_similarweights_50_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_9_50_100000.csv";
  /* For each 11_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_similarweights_50_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_9_50_1000000.csv";
  /* For each 11_50_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_similarweights_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_9_100_1000.csv";
  /* For each 11_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}
TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_similarweights_100_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_9_100_100000.csv";
  /* For each 11_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_similarweights_100_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_9_100_1000000.csv";
  /* For each 11_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}


TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_uncorrelatedspan_20_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_11_20_1000.csv";
  /* For each 11_20_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_uncorrelatedspan_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_11_50_1000.csv";
  /* For each 11_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_uncorrelatedspan_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_11_100_1000.csv";
  /* For each 11_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}


TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_weaklycorrelatedspan_20_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_12_20_1000.csv";
  /* For each 11_20_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_weaklycorrelatedspan_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_12_50_1000.csv";
  /* For each 11_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_weaklycorrelatedspan_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_12_100_1000.csv";
  /* For each 11_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_stronglycorrelatedspan_20_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_13_20_1000.csv";
  /* For each 11_20_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_stronglycorrelatedspan_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_13_50_1000.csv";
  /* For each 11_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_stronglycorrelatedspan_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_13_100_1000.csv";
  /* For each 11_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}


TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_mstr_20_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_14_20_1000.csv";
  /* For each 11_20_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_mstr_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_14_50_1000.csv";
  /* For each 11_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_mstr_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_14_100_1000.csv";
  /* For each 11_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_pceil_20_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_15_20_1000.csv";
  /* For each 11_20_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_pceil_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_15_50_1000.csv";
  /* For each 11_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_pceil_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_15_100_1000.csv";
  /* For each 11_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}


TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_circle_20_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_16_20_1000.csv";
  /* For each 11_20_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_circle_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_16_50_1000.csv";
  /* For each 11_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_circle_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.0;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_16_100_1000.csv";
  /* For each 11_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}


TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_uncorrelated_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_50_1000.csv";
  /* For each 1_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_uncorrelated_50_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_50_10000.csv";
  /* For each 1_50_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_uncorrelated_50_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_50_100000.csv";
  /* For each 1_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_uncorrelated_50_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_50_1000000.csv";
  /* For each 1_50_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_uncorrelated_50_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_50_100000.csv";
  /* For each 1_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_uncorrelated_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_100_1000.csv";
  /* For each 1_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_uncorrelated_100_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_100_10000.csv";
  /* For each 1_100_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_uncorrelated_100_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_100_100000.csv";
  /* For each 1_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_uncorrelated_100_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_100_1000000.csv";
  /* For each 1_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_uncorrelated_100_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_100_100000.csv";
  /* For each 1_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}


TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_weaklycorrelated_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_50_1000.csv";
  /* For each 2_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_weaklycorrelated_50_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_50_10000.csv";
  /* For each 2_50_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_weaklycorrelated_50_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_50_100000.csv";
  /* For each 2_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_weaklycorrelated_50_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_50_1000000.csv";
  /* For each 2_50_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_weaklycorrelated_50_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_50_100000.csv";
  /* For each 2_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_weaklycorrelated_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_100_1000.csv";
  /* For each 2_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_weaklycorrelated_100_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_100_10000.csv";
  /* For each 2_100_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_weaklycorrelated_100_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_100_100000.csv";
  /* For each 2_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_weaklycorrelated_100_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_100_1000000.csv";
  /* For each 2_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_weaklycorrelated_100_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_100_100000.csv";
  /* For each 2_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_stronglycorrelated_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_50_1000.csv";
  /* For each 3_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_stronglycorrelated_50_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_50_10000.csv";
  /* For each 3_50_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_stronglycorrelated_50_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_50_100000.csv";
  /* For each 3_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_stronglycorrelated_50_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_50_1000000.csv";
  /* For each 3_50_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_stronglycorrelated_50_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_50_100000.csv";
  /* For each 3_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_stronglycorrelated_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_100_1000.csv";
  /* For each 3_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_stronglycorrelated_100_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_100_10000.csv";
  /* For each 3_100_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_stronglycorrelated_100_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_100_100000.csv";
  /* For each 3_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_stronglycorrelated_100_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_100_1000000.csv";
  /* For each 3_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_stronglycorrelated_100_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_100_100000.csv";
  /* For each 3_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}


TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_inversestronglycorrelated_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_4_50_1000.csv";
  /* For each 4_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_inversestronglycorrelated_50_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_4_50_10000.csv";
  /* For each 4_50_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
 } 

}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_inversestronglycorrelated_50_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_4_50_100000.csv";
  /* For each 4_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_inversestronglycorrelated_50_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_4_50_1000000.csv";
  /* For each 4_50_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_inversestronglycorrelated_50_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_4_50_100000.csv";
  /* For each 4_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_inversestronglycorrelated_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_4_100_1000.csv";
  /* For each 4_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_inversestronglycorrelated_100_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_4_100_10000.csv";
  /* For each 4_100_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_inversestronglycorrelated_100_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_4_100_100000.csv";
  /* For each 4_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_inversestronglycorrelated_100_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_4_100_1000000.csv";
  /* For each 4_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_inversestronglycorrelated_100_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_4_100_100000.csv";
  /* For each 4_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}


TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_almoststronglycorrelated_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_5_50_1000.csv";
  /* For each 5_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_almoststronglycorrelated_50_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_5_50_10000.csv";
  /* For each 5_50_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_almoststronglycorrelated_50_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_5_50_100000.csv";
  /* For each 5_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_almoststronglycorrelated_50_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_5_50_1000000.csv";
  /* For each 5_50_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_almoststronglycorrelated_50_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_5_50_100000.csv";
  /* For each 5_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_almoststronglycorrelated_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_5_100_1000.csv";
  /* For each 5_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_almoststronglycorrelated_100_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_5_100_10000.csv";
  /* For each 5_100_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_almoststronglycorrelated_100_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_5_100_100000.csv";
  /* For each 5_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_almoststronglycorrelated_100_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_5_100_1000000.csv";
  /* For each 5_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_almoststronglycorrelated_100_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_5_100_100000.csv";
  /* For each 5_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_subsetsum_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_6_50_1000.csv";
  /* For each 6_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_subsetsum_50_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_6_50_10000.csv";
  /* For each 6_50_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_subsetsum_50_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_6_50_100000.csv";
  /* For each 6_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_subsetsum_50_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_6_50_1000000.csv";
  /* For each 6_50_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_subsetsum_50_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_6_50_100000.csv";
  /* For each 6_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_subsetsum_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_6_100_1000.csv";
  /* For each 6_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_subsetsum_100_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_6_100_10000.csv";
  /* For each 6_100_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_subsetsum_100_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_6_100_100000.csv";
  /* For each 6_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_subsetsum_100_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_6_100_1000000.csv";
  /* For each 6_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_subsetsum_100_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_6_100_100000.csv";
  /* For each 6_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_similarweights_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_9_50_1000.csv";
  /* For each 11_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}
TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_similarweights_50_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_9_50_100000.csv";
  /* For each 11_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_similarweights_50_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_9_50_1000000.csv";
  /* For each 11_50_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_similarweights_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_9_100_1000.csv";
  /* For each 11_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}
TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_similarweights_100_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_9_100_100000.csv";
  /* For each 11_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_similarweights_100_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_9_100_1000000.csv";
  /* For each 11_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_uncorrelatedspan_20_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_11_20_1000.csv";
  /* For each 11_20_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_uncorrelatedspan_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_11_50_1000.csv";
  /* For each 11_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_uncorrelatedspan_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_11_100_1000.csv";
  /* For each 11_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}


TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_weaklycorrelatedspan_20_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_12_20_1000.csv";
  /* For each 11_20_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_weaklycorrelatedspan_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_12_50_1000.csv";
  /* For each 11_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_weaklycorrelatedspan_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_12_100_1000.csv";
  /* For each 11_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}


TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_stronglycorrelatedspan_20_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_13_20_1000.csv";
  /* For each 11_20_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_stronglycorrelatedspan_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_13_50_1000.csv";
  /* For each 11_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_stronglycorrelatedspan_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_13_100_1000.csv";
  /* For each 11_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}


TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_mstr_20_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_14_20_1000.csv";
  /* For each 11_20_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_mstr_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_14_50_1000.csv";
  /* For each 11_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_mstr_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_14_100_1000.csv";
  /* For each 11_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_pceil_20_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_15_20_1000.csv";
  /* For each 11_20_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_pceil_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_15_50_1000.csv";
  /* For each 11_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_pceil_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_15_100_1000.csv";
  /* For each 11_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}


TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_circle_20_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_16_20_1000.csv";
  /* For each 11_20_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_circle_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_16_50_1000.csv";
  /* For each 11_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_circle_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.1;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_16_100_1000.csv";
  /* For each 11_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_uncorrelated_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_50_1000.csv";
  /* For each 1_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_uncorrelated_50_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_50_10000.csv";
  /* For each 1_50_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_uncorrelated_50_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_50_100000.csv";
  /* For each 1_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_uncorrelated_50_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_50_1000000.csv";
  /* For each 1_50_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_uncorrelated_50_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_50_100000.csv";
  /* For each 1_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_uncorrelated_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_100_1000.csv";
  /* For each 1_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_uncorrelated_100_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_100_10000.csv";
  /* For each 1_100_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_uncorrelated_100_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_100_100000.csv";
  /* For each 1_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_uncorrelated_100_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_100_1000000.csv";
  /* For each 1_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_uncorrelated_100_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_100_100000.csv";
  /* For each 1_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_weaklycorrelated_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_50_1000.csv";
  /* For each 2_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_weaklycorrelated_50_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_50_10000.csv";
  /* For each 2_50_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_weaklycorrelated_50_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_50_100000.csv";
  /* For each 2_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_weaklycorrelated_50_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_50_1000000.csv";
  /* For each 2_50_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_weaklycorrelated_50_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_50_100000.csv";
  /* For each 2_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_weaklycorrelated_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_100_1000.csv";
  /* For each 2_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_weaklycorrelated_100_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_100_10000.csv";
  /* For each 2_100_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_weaklycorrelated_100_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_100_100000.csv";
  /* For each 2_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_weaklycorrelated_100_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_100_1000000.csv";
  /* For each 2_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_weaklycorrelated_100_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_100_100000.csv";
  /* For each 2_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}


TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_stronglycorrelated_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_50_1000.csv";
  /* For each 3_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_stronglycorrelated_50_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_50_10000.csv";
  /* For each 3_50_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_stronglycorrelated_50_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_50_100000.csv";
  /* For each 3_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_stronglycorrelated_50_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_50_1000000.csv";
  /* For each 3_50_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_stronglycorrelated_50_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_50_100000.csv";
  /* For each 3_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_stronglycorrelated_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_100_1000.csv";
  /* For each 3_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_stronglycorrelated_100_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_100_10000.csv";
  /* For each 3_100_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_stronglycorrelated_100_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_100_100000.csv";
  /* For each 3_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_stronglycorrelated_100_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_100_1000000.csv";
  /* For each 3_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_stronglycorrelated_100_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_100_100000.csv";
  /* For each 3_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_inversestronglycorrelated_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_4_50_1000.csv";
  /* For each 4_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_inversestronglycorrelated_50_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_4_50_10000.csv";
  /* For each 4_50_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_inversestronglycorrelated_50_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_4_50_100000.csv";
  /* For each 4_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_inversestronglycorrelated_50_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_4_50_1000000.csv";
  /* For each 4_50_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_inversestronglycorrelated_50_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_4_50_100000.csv";
  /* For each 4_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_inversestronglycorrelated_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_4_100_1000.csv";
  /* For each 4_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_inversestronglycorrelated_100_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_4_100_10000.csv";
  /* For each 4_100_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_inversestronglycorrelated_100_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_4_100_100000.csv";
  /* For each 4_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_inversestronglycorrelated_100_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_4_100_1000000.csv";
  /* For each 4_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_inversestronglycorrelated_100_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_4_100_100000.csv";
  /* For each 4_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_almoststronglycorrelated_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_5_50_1000.csv";
  /* For each 5_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_almoststronglycorrelated_50_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_5_50_10000.csv";
  /* For each 5_50_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_almoststronglycorrelated_50_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_5_50_100000.csv";
  /* For each 5_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_almoststronglycorrelated_50_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_5_50_1000000.csv";
  /* For each 5_50_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_almoststronglycorrelated_50_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_5_50_100000.csv";
  /* For each 5_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_almoststronglycorrelated_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_5_100_1000.csv";
  /* For each 5_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_almoststronglycorrelated_100_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_5_100_10000.csv";
  /* For each 5_100_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_almoststronglycorrelated_100_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_5_100_100000.csv";
  /* For each 5_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_almoststronglycorrelated_100_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_5_100_1000000.csv";
  /* For each 5_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_almoststronglycorrelated_100_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_5_100_100000.csv";
  /* For each 5_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_subsetsum_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_6_50_1000.csv";
  /* For each 6_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_subsetsum_50_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_6_50_10000.csv";
  /* For each 6_50_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_subsetsum_50_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_6_50_100000.csv";
  /* For each 6_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_subsetsum_50_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_6_50_1000000.csv";
  /* For each 6_50_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_subsetsum_50_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_6_50_100000.csv";
  /* For each 6_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_subsetsum_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_6_100_1000.csv";
  /* For each 6_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_subsetsum_100_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_6_100_10000.csv";
  /* For each 6_100_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_subsetsum_100_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_6_100_100000.csv";
  /* For each 6_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_subsetsum_100_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_6_100_1000000.csv";
  /* For each 6_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_subsetsum_100_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_6_100_100000.csv";
  /* For each 6_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_similarweights_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_9_50_1000.csv";
  /* For each 11_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}
TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_similarweights_50_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_9_50_100000.csv";
  /* For each 11_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_similarweights_50_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_9_50_1000000.csv";
  /* For each 11_50_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_similarweights_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_9_100_1000.csv";
  /* For each 11_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}
TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_similarweights_100_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_9_100_100000.csv";
  /* For each 11_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_similarweights_100_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_9_100_1000000.csv";
  /* For each 11_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_similarweights_200_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_9_200_1000.csv";
  /* For each 11_200_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_uncorrelatedspan_20_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_11_20_1000.csv";
  /* For each 11_20_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_uncorrelatedspan_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_11_50_1000.csv";
  /* For each 11_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_uncorrelatedspan_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_11_100_1000.csv";
  /* For each 11_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}


TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_weaklycorrelatedspan_20_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_12_20_1000.csv";
  /* For each 11_20_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_weaklycorrelatedspan_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_12_50_1000.csv";
  /* For each 11_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_weaklycorrelatedspan_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_12_100_1000.csv";
  /* For each 11_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}


TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_stronglycorrelatedspan_20_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_13_20_1000.csv";
  /* For each 11_20_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_stronglycorrelatedspan_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_13_50_1000.csv";
  /* For each 11_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_stronglycorrelatedspan_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_13_100_1000.csv";
  /* For each 11_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}


TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_mstr_20_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_14_20_1000.csv";
  /* For each 11_20_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_mstr_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_14_50_1000.csv";
  /* For each 11_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_mstr_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_14_100_1000.csv";
  /* For each 11_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}


TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_pceil_20_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_15_20_1000.csv";
  /* For each 11_20_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_pceil_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_15_50_1000.csv";
  /* For each 11_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_pceil_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_15_100_1000.csv";
  /* For each 11_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}


TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_circle_20_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_16_20_1000.csv";
  /* For each 11_20_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_circle_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_16_50_1000.csv";
  /* For each 11_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_circle_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.3;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  clock_t t = clock();
  int timeout = -1;
  int memory_allocation_limit = -1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_16_100_1000.csv";
  /* For each 11_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes, memory_allocation_limit, &t, timeout);
    ASSERT_EQ(z_out, z);
    free(profits);
    free(weights);
    free(x);
  }
}

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
