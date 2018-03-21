/*****************************************************************************
 * branch_and_bound_quick_correctness_test.cpp                               *
 * Author: Nelson Frew                                                       *
 * First edit: 27/02/18                                                      *
 *                                                                           *
 * Description:                                                              *
 *   Unit tests to simply try the branch and bound on different instances.   *
 *****************************************************************************/

#define TESTING
#include "branch_and_bound.c"
#include <gtest/gtest.h>
#include <time.h>
#include <math.h>

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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
																	DP_method, logging_rule, logging_stream,epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);

  }
}

  /* For each 1_50_1000000 */
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

  /* For each 1_50_10000000 */
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_50_10000000.csv";
  /* For each 1_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

/* For each 1_100_1000 */
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

/* For each 1_100_10000 */
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

/* For each 1_100_100000 */
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

/* For each 1_100_1000000 */
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}
/* For each 1_100_10000000 */
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_100_10000000.csv";
  /* For each 1_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_50_10000.csv";
  /* For each 1_50_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_50_10000000.csv";
  /* For each 2_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_100_10000.csv";
  /* For each 1_100_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_100_100000.csv";
  /* For each 1_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_100_1000000.csv";
  /* For each 1_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_100_10000000.csv";
  /* For each 2_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_50_100000.csv";
  /* For each 2_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_50_10000000.csv";
  /* For each 3_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_100_100000.csv";
  /* For each 1_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_100_1000000.csv";
  /* For each 1_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_100_10000000.csv";
  /* For each 3_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}
  /* Linear enum branching */

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_auto_eps_uncorrelated_50_1000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_50_1000.csv";
  /* For each 1_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_auto_eps_uncorrelated_50_10000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_50_10000.csv";
  /* For each 1_50_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_auto_eps_uncorrelated_50_100000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_50_100000.csv";
  /* For each 1_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

  /* For each 1_50_1000000 */
TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_auto_eps_uncorrelated_50_1000000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_50_1000000.csv";
  /* For each 1_50_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

  /* For each 1_50_10000000 */
TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_auto_eps_uncorrelated_50_10000000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_50_10000000.csv";
  /* For each 1_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

/* For each 1_100_1000 */
TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_auto_eps_uncorrelated_100_1000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_100_1000.csv";
  /* For each 1_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

/* For each 1_100_10000 */
TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_auto_eps_uncorrelated_100_10000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_100_10000.csv";
  /* For each 1_100_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

/* For each 1_100_100000 */
TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_auto_eps_uncorrelated_100_100000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_100_100000.csv";
  /* For each 1_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

/* For each 1_100_1000000 */
TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_auto_eps_uncorrelated_100_1000000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_100_1000000.csv";
  /* For each 1_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}
/* For each 1_100_10000000 */
TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_auto_eps_uncorrelated_100_10000000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_100_10000000.csv";
  /* For each 1_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_auto_eps_weaklycorrelated_50_1000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_50_1000.csv";
  /* For each 2_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_auto_eps_weaklycorrelated_50_10000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_50_10000.csv";
  /* For each 1_50_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_auto_eps_weaklycorrelated_50_100000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_50_100000.csv";
  /* For each 2_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_auto_eps_weaklycorrelated_50_1000000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_50_1000000.csv";
  /* For each 2_50_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_auto_eps_weaklycorrelated_50_10000000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_50_10000000.csv";
  /* For each 2_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_auto_eps_weaklycorrelated_100_1000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_100_1000.csv";
  /* For each 2_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_auto_eps_weaklycorrelated_100_10000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_100_10000.csv";
  /* For each 1_100_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_auto_eps_weaklycorrelated_100_100000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_100_100000.csv";
  /* For each 1_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_auto_eps_weaklycorrelated_100_1000000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_100_1000000.csv";
  /* For each 1_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_auto_eps_weaklycorrelated_100_10000000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_100_10000000.csv";
  /* For each 2_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_auto_eps_stronglycorrelated_50_1000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_50_1000.csv";
  /* For each 3_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_auto_eps_stronglycorrelated_50_10000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_50_10000.csv";
  /* For each 3_50_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_auto_eps_stronglycorrelated_50_100000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_50_100000.csv";
  /* For each 2_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_auto_eps_stronglycorrelated_50_1000000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_50_1000000.csv";
  /* For each 3_50_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_auto_eps_stronglycorrelated_50_10000000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_50_10000000.csv";
  /* For each 3_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_auto_eps_stronglycorrelated_100_1000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_100_1000.csv";
  /* For each 3_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_auto_eps_stronglycorrelated_100_10000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_100_10000.csv";
  /* For each 3_100_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_auto_eps_stronglycorrelated_100_100000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_100_100000.csv";
  /* For each 1_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_auto_eps_stronglycorrelated_100_1000000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_100_1000000.csv";
  /* For each 1_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_auto_eps_stronglycorrelated_100_10000000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_100_10000000.csv";
  /* For each 3_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

  /* Truncation Branching */
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

  /* For each 1_50_1000000 */
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

  /* For each 1_50_10000000 */
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_50_10000000.csv";
  /* For each 1_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

/* For each 1_100_1000 */
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

/* For each 1_100_10000 */
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

/* For each 1_100_100000 */
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

/* For each 1_100_1000000 */
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}
/* For each 1_100_10000000 */
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_100_10000000.csv";
  /* For each 1_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_50_10000.csv";
  /* For each 1_50_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_50_10000000.csv";
  /* For each 2_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_100_10000.csv";
  /* For each 1_100_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_100_100000.csv";
  /* For each 1_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_100_1000000.csv";
  /* For each 1_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_100_10000000.csv";
  /* For each 2_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_50_100000.csv";
  /* For each 2_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_50_10000000.csv";
  /* For each 3_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_100_100000.csv";
  /* For each 1_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_100_1000000.csv";
  /* For each 1_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_100_10000000.csv";
  /* For each 3_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
                                  
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_uncorrelated_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_uncorrelated_50_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_uncorrelated_50_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);

  }
}

  /* For each 1_50_1000000 */
TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_uncorrelated_50_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

  /* For each 1_50_10000000 */
TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_uncorrelated_50_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_50_10000000.csv";
  /* For each 1_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

/* For each 1_100_1000 */
TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_uncorrelated_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

/* For each 1_100_10000 */
TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_uncorrelated_100_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

/* For each 1_100_100000 */
TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_uncorrelated_100_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

/* For each 1_100_1000000 */
TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_uncorrelated_100_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}
/* For each 1_100_10000000 */
TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_uncorrelated_100_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_100_10000000.csv";
  /* For each 1_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_weaklycorrelated_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_weaklycorrelated_50_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_50_10000.csv";
  /* For each 1_50_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_weaklycorrelated_50_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_weaklycorrelated_50_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_weaklycorrelated_50_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_50_10000000.csv";
  /* For each 2_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_weaklycorrelated_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_weaklycorrelated_100_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_100_10000.csv";
  /* For each 1_100_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_weaklycorrelated_100_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_100_100000.csv";
  /* For each 1_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_weaklycorrelated_100_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_100_1000000.csv";
  /* For each 1_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_weaklycorrelated_100_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_100_10000000.csv";
  /* For each 2_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_stronglycorrelated_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_stronglycorrelated_50_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_stronglycorrelated_50_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_50_100000.csv";
  /* For each 2_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_stronglycorrelated_50_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_stronglycorrelated_50_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_50_10000000.csv";
  /* For each 3_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_stronglycorrelated_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_stronglycorrelated_100_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_stronglycorrelated_100_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_100_100000.csv";
  /* For each 1_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_stronglycorrelated_100_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_100_1000000.csv";
  /* For each 1_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_stronglycorrelated_100_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_100_10000000.csv";
  /* For each 3_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}
  /* Linear enum branching */

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_low_eps_uncorrelated_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_50_1000.csv";
  /* For each 1_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_low_eps_uncorrelated_50_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_50_10000.csv";
  /* For each 1_50_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_low_eps_uncorrelated_50_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_50_100000.csv";
  /* For each 1_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

  /* For each 1_50_1000000 */
TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_low_eps_uncorrelated_50_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_50_1000000.csv";
  /* For each 1_50_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

  /* For each 1_50_10000000 */
TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_low_eps_uncorrelated_50_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_50_10000000.csv";
  /* For each 1_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

/* For each 1_100_1000 */
TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_low_eps_uncorrelated_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_100_1000.csv";
  /* For each 1_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

/* For each 1_100_10000 */
TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_low_eps_uncorrelated_100_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_100_10000.csv";
  /* For each 1_100_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

/* For each 1_100_100000 */
TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_low_eps_uncorrelated_100_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_100_100000.csv";
  /* For each 1_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

/* For each 1_100_1000000 */
TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_low_eps_uncorrelated_100_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_100_1000000.csv";
  /* For each 1_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}
/* For each 1_100_10000000 */
TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_low_eps_uncorrelated_100_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_100_10000000.csv";
  /* For each 1_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_low_eps_weaklycorrelated_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_50_1000.csv";
  /* For each 2_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_low_eps_weaklycorrelated_50_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_50_10000.csv";
  /* For each 1_50_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_low_eps_weaklycorrelated_50_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_50_100000.csv";
  /* For each 2_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_low_eps_weaklycorrelated_50_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_50_1000000.csv";
  /* For each 2_50_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_low_eps_weaklycorrelated_50_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_50_10000000.csv";
  /* For each 2_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_low_eps_weaklycorrelated_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_100_1000.csv";
  /* For each 2_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_low_eps_weaklycorrelated_100_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_100_10000.csv";
  /* For each 1_100_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_low_eps_weaklycorrelated_100_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_100_100000.csv";
  /* For each 1_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_low_eps_weaklycorrelated_100_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_100_1000000.csv";
  /* For each 1_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_low_eps_weaklycorrelated_100_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_100_10000000.csv";
  /* For each 2_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_low_eps_stronglycorrelated_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_50_1000.csv";
  /* For each 3_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_low_eps_stronglycorrelated_50_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_50_10000.csv";
  /* For each 3_50_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_low_eps_stronglycorrelated_50_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_50_100000.csv";
  /* For each 2_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_low_eps_stronglycorrelated_50_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_50_1000000.csv";
  /* For each 3_50_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_low_eps_stronglycorrelated_50_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_50_10000000.csv";
  /* For each 3_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_low_eps_stronglycorrelated_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_100_1000.csv";
  /* For each 3_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_low_eps_stronglycorrelated_100_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_100_10000.csv";
  /* For each 3_100_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_low_eps_stronglycorrelated_100_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_100_100000.csv";
  /* For each 1_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_low_eps_stronglycorrelated_100_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_100_1000000.csv";
  /* For each 1_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_low_eps_stronglycorrelated_100_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_100_10000000.csv";
  /* For each 3_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

  /* Truncation Branching */
TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_uncorrelated_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_uncorrelated_50_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_uncorrelated_50_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

  /* For each 1_50_1000000 */
TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_uncorrelated_50_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

  /* For each 1_50_10000000 */
TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_uncorrelated_50_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_50_10000000.csv";
  /* For each 1_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

/* For each 1_100_1000 */
TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_uncorrelated_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

/* For each 1_100_10000 */
TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_uncorrelated_100_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

/* For each 1_100_100000 */
TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_uncorrelated_100_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

/* For each 1_100_1000000 */
TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_uncorrelated_100_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}
/* For each 1_100_10000000 */
TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_uncorrelated_100_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_100_10000000.csv";
  /* For each 1_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_weaklycorrelated_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_weaklycorrelated_50_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_50_10000.csv";
  /* For each 1_50_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_weaklycorrelated_50_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_weaklycorrelated_50_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_weaklycorrelated_50_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_50_10000000.csv";
  /* For each 2_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_weaklycorrelated_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_weaklycorrelated_100_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_100_10000.csv";
  /* For each 1_100_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_weaklycorrelated_100_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_100_100000.csv";
  /* For each 1_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_weaklycorrelated_100_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_100_1000000.csv";
  /* For each 1_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_weaklycorrelated_100_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_100_10000000.csv";
  /* For each 2_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_stronglycorrelated_50_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_stronglycorrelated_50_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_stronglycorrelated_50_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_50_100000.csv";
  /* For each 2_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_stronglycorrelated_50_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_stronglycorrelated_50_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_50_10000000.csv";
  /* For each 3_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_stronglycorrelated_100_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_stronglycorrelated_100_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_stronglycorrelated_100_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_100_100000.csv";
  /* For each 1_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_stronglycorrelated_100_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_100_1000000.csv";
  /* For each 1_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_stronglycorrelated_100_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_100_10000000.csv";
  /* For each 3_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
                                  
    ASSERT_EQ(z_out, z);
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);

  }
}

  /* For each 1_50_1000000 */
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

  /* For each 1_50_10000000 */
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_50_10000000.csv";
  /* For each 1_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

/* For each 1_100_1000 */
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

/* For each 1_100_10000 */
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

/* For each 1_100_100000 */
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

/* For each 1_100_1000000 */
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}
/* For each 1_100_10000000 */
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_100_10000000.csv";
  /* For each 1_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_50_10000.csv";
  /* For each 1_50_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_50_10000000.csv";
  /* For each 2_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_100_10000.csv";
  /* For each 1_100_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_100_100000.csv";
  /* For each 1_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_100_1000000.csv";
  /* For each 1_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_100_10000000.csv";
  /* For each 2_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_50_100000.csv";
  /* For each 2_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_50_10000000.csv";
  /* For each 3_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_100_100000.csv";
  /* For each 1_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_100_1000000.csv";
  /* For each 1_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_100_10000000.csv";
  /* For each 3_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}
  /* Linear enum branching */

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_midlow_eps_uncorrelated_50_1000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_50_1000.csv";
  /* For each 1_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_midlow_eps_uncorrelated_50_10000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_50_10000.csv";
  /* For each 1_50_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_midlow_eps_uncorrelated_50_100000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_50_100000.csv";
  /* For each 1_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

  /* For each 1_50_1000000 */
TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_midlow_eps_uncorrelated_50_1000000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_50_1000000.csv";
  /* For each 1_50_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

  /* For each 1_50_10000000 */
TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_midlow_eps_uncorrelated_50_10000000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_50_10000000.csv";
  /* For each 1_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

/* For each 1_100_1000 */
TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_midlow_eps_uncorrelated_100_1000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_100_1000.csv";
  /* For each 1_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

/* For each 1_100_10000 */
TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_midlow_eps_uncorrelated_100_10000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_100_10000.csv";
  /* For each 1_100_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

/* For each 1_100_100000 */
TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_midlow_eps_uncorrelated_100_100000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_100_100000.csv";
  /* For each 1_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

/* For each 1_100_1000000 */
TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_midlow_eps_uncorrelated_100_1000000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_100_1000000.csv";
  /* For each 1_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}
/* For each 1_100_10000000 */
TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_midlow_eps_uncorrelated_100_10000000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_100_10000000.csv";
  /* For each 1_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_midlow_eps_weaklycorrelated_50_1000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_50_1000.csv";
  /* For each 2_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_midlow_eps_weaklycorrelated_50_10000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_50_10000.csv";
  /* For each 1_50_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_midlow_eps_weaklycorrelated_50_100000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_50_100000.csv";
  /* For each 2_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_midlow_eps_weaklycorrelated_50_1000000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_50_1000000.csv";
  /* For each 2_50_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_midlow_eps_weaklycorrelated_50_10000000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_50_10000000.csv";
  /* For each 2_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_midlow_eps_weaklycorrelated_100_1000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_100_1000.csv";
  /* For each 2_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_midlow_eps_weaklycorrelated_100_10000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_100_10000.csv";
  /* For each 1_100_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_midlow_eps_weaklycorrelated_100_100000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_100_100000.csv";
  /* For each 1_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_midlow_eps_weaklycorrelated_100_1000000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_100_1000000.csv";
  /* For each 1_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_midlow_eps_weaklycorrelated_100_10000000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_100_10000000.csv";
  /* For each 2_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_midlow_eps_stronglycorrelated_50_1000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_50_1000.csv";
  /* For each 3_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_midlow_eps_stronglycorrelated_50_10000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_50_10000.csv";
  /* For each 3_50_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_midlow_eps_stronglycorrelated_50_100000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_50_100000.csv";
  /* For each 2_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_midlow_eps_stronglycorrelated_50_1000000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_50_1000000.csv";
  /* For each 3_50_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_midlow_eps_stronglycorrelated_50_10000000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_50_10000000.csv";
  /* For each 3_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_midlow_eps_stronglycorrelated_100_1000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_100_1000.csv";
  /* For each 3_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_midlow_eps_stronglycorrelated_100_10000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_100_10000.csv";
  /* For each 3_100_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_midlow_eps_stronglycorrelated_100_100000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_100_100000.csv";
  /* For each 1_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_midlow_eps_stronglycorrelated_100_1000000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_100_1000000.csv";
  /* For each 1_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_midlow_eps_stronglycorrelated_100_10000000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_100_10000000.csv";
  /* For each 3_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

  /* Truncation Branching */
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

  /* For each 1_50_1000000 */
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

  /* For each 1_50_10000000 */
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_50_10000000.csv";
  /* For each 1_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

/* For each 1_100_1000 */
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

/* For each 1_100_10000 */
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

/* For each 1_100_100000 */
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

/* For each 1_100_1000000 */
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}
/* For each 1_100_10000000 */
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_100_10000000.csv";
  /* For each 1_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_50_10000.csv";
  /* For each 1_50_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_50_10000000.csv";
  /* For each 2_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_100_10000.csv";
  /* For each 1_100_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_100_100000.csv";
  /* For each 1_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_100_1000000.csv";
  /* For each 1_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_100_10000000.csv";
  /* For each 2_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_50_100000.csv";
  /* For each 2_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_50_10000000.csv";
  /* For each 3_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_100_100000.csv";
  /* For each 1_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_100_1000000.csv";
  /* For each 1_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_100_10000000.csv";
  /* For each 3_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
                                  
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_uncorrelated_200_1000)
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_200_1000.csv";
  /* For each 1_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_uncorrelated_200_10000)
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_200_10000.csv";
  /* For each 1_50_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_uncorrelated_200_100000)
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_200_100000.csv";
  /* For each 1_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);

  }
}

  /* For each 1_50_1000000 */
TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_uncorrelated_200_1000000)
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_200_1000000.csv";
  /* For each 1_50_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

  /* For each 1_50_10000000 */
TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_uncorrelated_200_10000000)
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_200_10000000.csv";
  /* For each 1_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

/* For each 1_100_1000 */
TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_uncorrelated_500_1000)
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_500_1000.csv";
  /* For each 1_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

/* For each 1_100_10000 */
TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_uncorrelated_500_10000)
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_500_10000.csv";
  /* For each 1_100_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

/* For each 1_100_100000 */
TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_uncorrelated_500_100000)
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_500_100000.csv";
  /* For each 1_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

/* For each 1_100_1000000 */
TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_uncorrelated_500_1000000)
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_500_1000000.csv";
  /* For each 1_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}
/* For each 1_100_10000000 */
TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_uncorrelated_500_10000000)
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_500_10000000.csv";
  /* For each 1_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_weaklycorrelated_200_1000)
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_200_1000.csv";
  /* For each 2_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_weaklycorrelated_200_10000)
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_200_10000.csv";
  /* For each 1_50_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_weaklycorrelated_200_100000)
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_200_100000.csv";
  /* For each 2_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_weaklycorrelated_200_1000000)
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_200_1000000.csv";
  /* For each 2_50_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_weaklycorrelated_200_10000000)
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_200_10000000.csv";
  /* For each 2_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_weaklycorrelated_500_1000)
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_500_1000.csv";
  /* For each 2_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_weaklycorrelated_500_10000)
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_500_10000.csv";
  /* For each 1_100_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_weaklycorrelated_500_100000)
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_500_100000.csv";
  /* For each 1_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_weaklycorrelated_500_1000000)
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_500_1000000.csv";
  /* For each 1_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_weaklycorrelated_500_10000000)
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_500_10000000.csv";
  /* For each 2_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_stronglycorrelated_200_1000)
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_200_1000.csv";
  /* For each 3_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_stronglycorrelated_200_10000)
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_200_10000.csv";
  /* For each 3_50_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_stronglycorrelated_200_100000)
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_200_100000.csv";
  /* For each 2_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_stronglycorrelated_200_1000000)
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_200_1000000.csv";
  /* For each 3_50_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_stronglycorrelated_200_10000000)
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_200_10000000.csv";
  /* For each 3_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_stronglycorrelated_500_1000)
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_500_1000.csv";
  /* For each 3_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_stronglycorrelated_500_10000)
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_500_10000.csv";
  /* For each 3_100_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_stronglycorrelated_500_100000)
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_500_100000.csv";
  /* For each 1_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_stronglycorrelated_500_1000000)
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_500_1000000.csv";
  /* For each 1_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_auto_eps_stronglycorrelated_500_10000000)
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_500_10000000.csv";
  /* For each 3_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}
  /* Linear enum branching */

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_auto_eps_uncorrelated_200_1000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_200_1000.csv";
  /* For each 1_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_auto_eps_uncorrelated_200_10000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_200_10000.csv";
  /* For each 1_50_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_auto_eps_uncorrelated_200_100000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_200_100000.csv";
  /* For each 1_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

  /* For each 1_50_1000000 */
TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_auto_eps_uncorrelated_200_1000000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_200_1000000.csv";
  /* For each 1_50_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

  /* For each 1_50_10000000 */
TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_auto_eps_uncorrelated_200_10000000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_200_10000000.csv";
  /* For each 1_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

/* For each 1_100_1000 */
TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_auto_eps_uncorrelated_500_1000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_500_1000.csv";
  /* For each 1_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

/* For each 1_100_10000 */
TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_auto_eps_uncorrelated_500_10000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_500_10000.csv";
  /* For each 1_100_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

/* For each 1_100_100000 */
TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_auto_eps_uncorrelated_500_100000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_500_100000.csv";
  /* For each 1_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

/* For each 1_100_1000000 */
TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_auto_eps_uncorrelated_500_1000000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_500_1000000.csv";
  /* For each 1_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}
/* For each 1_100_10000000 */
TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_auto_eps_uncorrelated_500_10000000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_500_10000000.csv";
  /* For each 1_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_auto_eps_weaklycorrelated_200_1000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_200_1000.csv";
  /* For each 2_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_auto_eps_weaklycorrelated_200_10000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_200_10000.csv";
  /* For each 1_50_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_auto_eps_weaklycorrelated_200_100000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_200_100000.csv";
  /* For each 2_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_auto_eps_weaklycorrelated_200_1000000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_200_1000000.csv";
  /* For each 2_50_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_auto_eps_weaklycorrelated_200_10000000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_200_10000000.csv";
  /* For each 2_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_auto_eps_weaklycorrelated_500_1000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_500_1000.csv";
  /* For each 2_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_auto_eps_weaklycorrelated_500_10000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_500_10000.csv";
  /* For each 1_100_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_auto_eps_weaklycorrelated_500_100000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_500_100000.csv";
  /* For each 1_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_auto_eps_weaklycorrelated_500_1000000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_500_1000000.csv";
  /* For each 1_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_auto_eps_weaklycorrelated_500_10000000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_500_10000000.csv";
  /* For each 2_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_auto_eps_stronglycorrelated_200_1000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_200_1000.csv";
  /* For each 3_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_auto_eps_stronglycorrelated_200_10000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_200_10000.csv";
  /* For each 3_50_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_auto_eps_stronglycorrelated_200_100000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_200_100000.csv";
  /* For each 2_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_auto_eps_stronglycorrelated_200_1000000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_200_1000000.csv";
  /* For each 3_50_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_auto_eps_stronglycorrelated_200_10000000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_200_10000000.csv";
  /* For each 3_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_auto_eps_stronglycorrelated_500_1000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_500_1000.csv";
  /* For each 3_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_auto_eps_stronglycorrelated_500_10000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_500_10000.csv";
  /* For each 3_100_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_auto_eps_stronglycorrelated_500_100000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_500_100000.csv";
  /* For each 1_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_auto_eps_stronglycorrelated_500_1000000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_500_1000000.csv";
  /* For each 1_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_auto_eps_stronglycorrelated_500_10000000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_500_10000000.csv";
  /* For each 3_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

  /* Truncation Branching */
TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_uncorrelated_200_1000)
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_200_1000.csv";
  /* For each 1_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_uncorrelated_200_10000)
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_200_10000.csv";
  /* For each 1_50_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_uncorrelated_200_100000)
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_200_100000.csv";
  /* For each 1_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

  /* For each 1_50_1000000 */
TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_uncorrelated_200_1000000)
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_200_1000000.csv";
  /* For each 1_50_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

  /* For each 1_50_10000000 */
TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_uncorrelated_200_10000000)
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_200_10000000.csv";
  /* For each 1_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

/* For each 1_100_1000 */
TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_uncorrelated_500_1000)
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_500_1000.csv";
  /* For each 1_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

/* For each 1_100_10000 */
TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_uncorrelated_500_10000)
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_500_10000.csv";
  /* For each 1_100_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

/* For each 1_100_100000 */
TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_uncorrelated_500_100000)
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_500_100000.csv";
  /* For each 1_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

/* For each 1_100_1000000 */
TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_uncorrelated_500_1000000)
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_500_1000000.csv";
  /* For each 1_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}
/* For each 1_100_10000000 */
TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_uncorrelated_500_10000000)
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_500_10000000.csv";
  /* For each 1_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_weaklycorrelated_200_1000)
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_200_1000.csv";
  /* For each 2_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_weaklycorrelated_200_10000)
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_200_10000.csv";
  /* For each 1_50_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_weaklycorrelated_200_100000)
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_200_100000.csv";
  /* For each 2_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_weaklycorrelated_200_1000000)
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_200_1000000.csv";
  /* For each 2_50_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_weaklycorrelated_200_10000000)
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_200_10000000.csv";
  /* For each 2_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_weaklycorrelated_500_1000)
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_500_1000.csv";
  /* For each 2_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_weaklycorrelated_500_10000)
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_500_10000.csv";
  /* For each 1_100_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_weaklycorrelated_500_100000)
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_500_100000.csv";
  /* For each 1_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_weaklycorrelated_500_1000000)
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_500_1000000.csv";
  /* For each 1_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_weaklycorrelated_500_10000000)
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_500_10000000.csv";
  /* For each 2_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_stronglycorrelated_200_1000)
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_200_1000.csv";
  /* For each 3_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_stronglycorrelated_200_10000)
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_200_10000.csv";
  /* For each 3_50_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_stronglycorrelated_200_100000)
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_200_100000.csv";
  /* For each 2_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_stronglycorrelated_200_1000000)
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_200_1000000.csv";
  /* For each 3_50_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_stronglycorrelated_200_10000000)
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_200_10000000.csv";
  /* For each 3_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_stronglycorrelated_500_1000)
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_500_1000.csv";
  /* For each 3_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_stronglycorrelated_500_10000)
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_500_10000.csv";
  /* For each 3_100_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_stronglycorrelated_500_100000)
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_500_100000.csv";
  /* For each 1_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_stronglycorrelated_500_1000000)
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_500_1000000.csv";
  /* For each 1_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_auto_eps_stronglycorrelated_500_10000000)
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_500_10000000.csv";
  /* For each 3_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
                                  
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_uncorrelated_200_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_200_1000.csv";
  /* For each 1_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_uncorrelated_200_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_200_10000.csv";
  /* For each 1_50_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_uncorrelated_200_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_200_100000.csv";
  /* For each 1_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);

  }
}

  /* For each 1_50_1000000 */
TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_uncorrelated_200_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_200_1000000.csv";
  /* For each 1_50_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

  /* For each 1_50_10000000 */
TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_uncorrelated_200_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_200_10000000.csv";
  /* For each 1_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

/* For each 1_100_1000 */
TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_uncorrelated_500_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_500_1000.csv";
  /* For each 1_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

/* For each 1_100_10000 */
TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_uncorrelated_500_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_500_10000.csv";
  /* For each 1_100_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

/* For each 1_100_100000 */
TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_uncorrelated_500_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_500_100000.csv";
  /* For each 1_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

/* For each 1_100_1000000 */
TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_uncorrelated_500_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_500_1000000.csv";
  /* For each 1_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}
/* For each 1_100_10000000 */
TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_uncorrelated_500_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_500_10000000.csv";
  /* For each 1_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_weaklycorrelated_200_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_200_1000.csv";
  /* For each 2_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_weaklycorrelated_200_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_200_10000.csv";
  /* For each 1_50_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_weaklycorrelated_200_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_200_100000.csv";
  /* For each 2_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_weaklycorrelated_200_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_200_1000000.csv";
  /* For each 2_50_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_weaklycorrelated_200_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_200_10000000.csv";
  /* For each 2_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_weaklycorrelated_500_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_500_1000.csv";
  /* For each 2_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_weaklycorrelated_500_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_500_10000.csv";
  /* For each 1_100_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_weaklycorrelated_500_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_500_100000.csv";
  /* For each 1_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_weaklycorrelated_500_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_500_1000000.csv";
  /* For each 1_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_weaklycorrelated_500_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_500_10000000.csv";
  /* For each 2_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_stronglycorrelated_200_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_200_1000.csv";
  /* For each 3_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_stronglycorrelated_200_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_200_10000.csv";
  /* For each 3_50_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_stronglycorrelated_200_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_200_100000.csv";
  /* For each 2_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_stronglycorrelated_200_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_200_1000000.csv";
  /* For each 3_50_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_stronglycorrelated_200_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_200_10000000.csv";
  /* For each 3_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_stronglycorrelated_500_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_500_1000.csv";
  /* For each 3_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_stronglycorrelated_500_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_500_10000.csv";
  /* For each 3_100_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_stronglycorrelated_500_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_500_100000.csv";
  /* For each 1_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_stronglycorrelated_500_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_500_1000000.csv";
  /* For each 1_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_low_eps_stronglycorrelated_500_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_500_10000000.csv";
  /* For each 3_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}
  /* Linear enum branching */

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_low_eps_uncorrelated_200_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_200_1000.csv";
  /* For each 1_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_low_eps_uncorrelated_200_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_200_10000.csv";
  /* For each 1_50_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_low_eps_uncorrelated_200_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_200_100000.csv";
  /* For each 1_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

  /* For each 1_50_1000000 */
TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_low_eps_uncorrelated_200_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_200_1000000.csv";
  /* For each 1_50_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

  /* For each 1_50_10000000 */
TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_low_eps_uncorrelated_200_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_200_10000000.csv";
  /* For each 1_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

/* For each 1_100_1000 */
TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_low_eps_uncorrelated_500_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_500_1000.csv";
  /* For each 1_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

/* For each 1_100_10000 */
TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_low_eps_uncorrelated_500_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_500_10000.csv";
  /* For each 1_100_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

/* For each 1_100_100000 */
TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_low_eps_uncorrelated_500_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_500_100000.csv";
  /* For each 1_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

/* For each 1_100_1000000 */
TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_low_eps_uncorrelated_500_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_500_1000000.csv";
  /* For each 1_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}
/* For each 1_100_10000000 */
TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_low_eps_uncorrelated_500_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_500_10000000.csv";
  /* For each 1_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_low_eps_weaklycorrelated_200_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_200_1000.csv";
  /* For each 2_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_low_eps_weaklycorrelated_200_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_200_10000.csv";
  /* For each 1_50_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_low_eps_weaklycorrelated_200_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_200_100000.csv";
  /* For each 2_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_low_eps_weaklycorrelated_200_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_200_1000000.csv";
  /* For each 2_50_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_low_eps_weaklycorrelated_200_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_200_10000000.csv";
  /* For each 2_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_low_eps_weaklycorrelated_500_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_500_1000.csv";
  /* For each 2_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_low_eps_weaklycorrelated_500_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_500_10000.csv";
  /* For each 1_100_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_low_eps_weaklycorrelated_500_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_500_100000.csv";
  /* For each 1_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_low_eps_weaklycorrelated_500_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_500_1000000.csv";
  /* For each 1_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_low_eps_weaklycorrelated_500_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_500_10000000.csv";
  /* For each 2_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_low_eps_stronglycorrelated_200_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_200_1000.csv";
  /* For each 3_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_low_eps_stronglycorrelated_200_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_200_10000.csv";
  /* For each 3_50_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_low_eps_stronglycorrelated_200_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_200_100000.csv";
  /* For each 2_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_low_eps_stronglycorrelated_200_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_200_1000000.csv";
  /* For each 3_50_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_low_eps_stronglycorrelated_200_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_200_10000000.csv";
  /* For each 3_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_low_eps_stronglycorrelated_500_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_500_1000.csv";
  /* For each 3_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_low_eps_stronglycorrelated_500_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_500_10000.csv";
  /* For each 3_100_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_low_eps_stronglycorrelated_500_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_500_100000.csv";
  /* For each 1_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_low_eps_stronglycorrelated_500_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_500_1000000.csv";
  /* For each 1_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_low_eps_stronglycorrelated_500_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_500_10000000.csv";
  /* For each 3_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

  /* Truncation Branching */
TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_uncorrelated_200_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_200_1000.csv";
  /* For each 1_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_uncorrelated_200_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_200_10000.csv";
  /* For each 1_50_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_uncorrelated_200_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_200_100000.csv";
  /* For each 1_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

  /* For each 1_50_1000000 */
TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_uncorrelated_200_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_200_1000000.csv";
  /* For each 1_50_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

  /* For each 1_50_10000000 */
TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_uncorrelated_200_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_200_10000000.csv";
  /* For each 1_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

/* For each 1_100_1000 */
TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_uncorrelated_500_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_500_1000.csv";
  /* For each 1_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

/* For each 1_100_10000 */
TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_uncorrelated_500_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_500_10000.csv";
  /* For each 1_100_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

/* For each 1_100_100000 */
TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_uncorrelated_500_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_500_100000.csv";
  /* For each 1_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

/* For each 1_100_1000000 */
TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_uncorrelated_500_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_500_1000000.csv";
  /* For each 1_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}
/* For each 1_100_10000000 */
TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_uncorrelated_500_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_500_10000000.csv";
  /* For each 1_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_weaklycorrelated_200_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_200_1000.csv";
  /* For each 2_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_weaklycorrelated_200_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_200_10000.csv";
  /* For each 1_50_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_weaklycorrelated_200_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_200_100000.csv";
  /* For each 2_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_weaklycorrelated_200_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_200_1000000.csv";
  /* For each 2_50_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_weaklycorrelated_200_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_200_10000000.csv";
  /* For each 2_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_weaklycorrelated_500_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_500_1000.csv";
  /* For each 2_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_weaklycorrelated_500_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_500_10000.csv";
  /* For each 1_100_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_weaklycorrelated_500_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_500_100000.csv";
  /* For each 1_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_weaklycorrelated_500_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_500_1000000.csv";
  /* For each 1_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_weaklycorrelated_500_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_500_10000000.csv";
  /* For each 2_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_stronglycorrelated_200_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_200_1000.csv";
  /* For each 3_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_stronglycorrelated_200_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_200_10000.csv";
  /* For each 3_50_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_stronglycorrelated_200_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_200_100000.csv";
  /* For each 2_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_stronglycorrelated_200_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_200_1000000.csv";
  /* For each 3_50_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_stronglycorrelated_200_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_200_10000000.csv";
  /* For each 3_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_stronglycorrelated_500_1000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_500_1000.csv";
  /* For each 3_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_stronglycorrelated_500_10000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_500_10000.csv";
  /* For each 3_100_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_stronglycorrelated_500_100000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_500_100000.csv";
  /* For each 1_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_stronglycorrelated_500_1000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_500_1000000.csv";
  /* For each 1_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_low_eps_stronglycorrelated_500_10000000)
{
  /* Need to test each branching strategy against all instances */
  /* This tests 4000 different problems for each strategy */
  double epsilon = 0.01;
  FILE *logging_stream = stdout;
  int logging_rule = NO_LOGGING;
  int DP_method = WILLIAMSON_SHMOY;
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_500_10000000.csv";
  /* For each 3_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
                                  
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_uncorrelated_200_1000)
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_200_1000.csv";
  /* For each 1_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_uncorrelated_200_10000)
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_200_10000.csv";
  /* For each 1_50_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_uncorrelated_200_100000)
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_200_100000.csv";
  /* For each 1_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);

  }
}

  /* For each 1_50_1000000 */
TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_uncorrelated_200_1000000)
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_200_1000000.csv";
  /* For each 1_50_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

  /* For each 1_50_10000000 */
TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_uncorrelated_200_10000000)
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_200_10000000.csv";
  /* For each 1_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

/* For each 1_100_1000 */
TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_uncorrelated_500_1000)
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_500_1000.csv";
  /* For each 1_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

/* For each 1_100_10000 */
TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_uncorrelated_500_10000)
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_500_10000.csv";
  /* For each 1_100_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

/* For each 1_100_100000 */
TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_uncorrelated_500_100000)
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_500_100000.csv";
  /* For each 1_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

/* For each 1_100_1000000 */
TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_uncorrelated_500_1000000)
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_500_1000000.csv";
  /* For each 1_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}
/* For each 1_100_10000000 */
TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_uncorrelated_500_10000000)
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_500_10000000.csv";
  /* For each 1_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_weaklycorrelated_200_1000)
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_200_1000.csv";
  /* For each 2_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_weaklycorrelated_200_10000)
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_200_10000.csv";
  /* For each 1_50_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_weaklycorrelated_200_100000)
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_200_100000.csv";
  /* For each 2_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_weaklycorrelated_200_1000000)
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_200_1000000.csv";
  /* For each 2_50_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_weaklycorrelated_200_10000000)
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_200_10000000.csv";
  /* For each 2_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_weaklycorrelated_500_1000)
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_500_1000.csv";
  /* For each 2_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_weaklycorrelated_500_10000)
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_500_10000.csv";
  /* For each 1_100_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_weaklycorrelated_500_100000)
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_500_100000.csv";
  /* For each 1_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_weaklycorrelated_500_1000000)
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_500_1000000.csv";
  /* For each 1_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_weaklycorrelated_500_10000000)
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_500_10000000.csv";
  /* For each 2_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_stronglycorrelated_200_1000)
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_200_1000.csv";
  /* For each 3_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_stronglycorrelated_200_10000)
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_200_10000.csv";
  /* For each 3_50_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_stronglycorrelated_200_100000)
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_200_100000.csv";
  /* For each 2_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_stronglycorrelated_200_1000000)
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_200_1000000.csv";
  /* For each 3_50_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_stronglycorrelated_200_10000000)
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_200_10000000.csv";
  /* For each 3_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_stronglycorrelated_500_1000)
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_500_1000.csv";
  /* For each 3_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_stronglycorrelated_500_10000)
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_500_10000.csv";
  /* For each 3_100_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_stronglycorrelated_500_100000)
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_500_100000.csv";
  /* For each 1_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_stronglycorrelated_500_1000000)
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_500_1000000.csv";
  /* For each 1_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, random_branching_willshmoy_midlow_eps_stronglycorrelated_500_10000000)
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
  /* Random branching */
  int branching_strategy = RANDOM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_500_10000000.csv";
  /* For each 3_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}
  /* Linear enum branching */

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_midlow_eps_uncorrelated_200_1000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_200_1000.csv";
  /* For each 1_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_midlow_eps_uncorrelated_200_10000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_200_10000.csv";
  /* For each 1_50_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_midlow_eps_uncorrelated_200_100000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_200_100000.csv";
  /* For each 1_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

  /* For each 1_50_1000000 */
TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_midlow_eps_uncorrelated_200_1000000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_200_1000000.csv";
  /* For each 1_50_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

  /* For each 1_50_10000000 */
TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_midlow_eps_uncorrelated_200_10000000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_200_10000000.csv";
  /* For each 1_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

/* For each 1_100_1000 */
TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_midlow_eps_uncorrelated_500_1000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_500_1000.csv";
  /* For each 1_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

/* For each 1_100_10000 */
TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_midlow_eps_uncorrelated_500_10000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_500_10000.csv";
  /* For each 1_100_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

/* For each 1_100_100000 */
TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_midlow_eps_uncorrelated_500_100000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_500_100000.csv";
  /* For each 1_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

/* For each 1_100_1000000 */
TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_midlow_eps_uncorrelated_500_1000000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_500_1000000.csv";
  /* For each 1_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}
/* For each 1_100_10000000 */
TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_midlow_eps_uncorrelated_500_10000000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_500_10000000.csv";
  /* For each 1_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_midlow_eps_weaklycorrelated_200_1000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_200_1000.csv";
  /* For each 2_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_midlow_eps_weaklycorrelated_200_10000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_200_10000.csv";
  /* For each 1_50_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_midlow_eps_weaklycorrelated_200_100000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_200_100000.csv";
  /* For each 2_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_midlow_eps_weaklycorrelated_200_1000000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_200_1000000.csv";
  /* For each 2_50_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_midlow_eps_weaklycorrelated_200_10000000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_200_10000000.csv";
  /* For each 2_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_midlow_eps_weaklycorrelated_500_1000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_500_1000.csv";
  /* For each 2_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_midlow_eps_weaklycorrelated_500_10000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_500_10000.csv";
  /* For each 1_100_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_midlow_eps_weaklycorrelated_500_100000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_500_100000.csv";
  /* For each 1_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_midlow_eps_weaklycorrelated_500_1000000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_500_1000000.csv";
  /* For each 1_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_midlow_eps_weaklycorrelated_500_10000000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_500_10000000.csv";
  /* For each 2_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_midlow_eps_stronglycorrelated_200_1000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_200_1000.csv";
  /* For each 3_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_midlow_eps_stronglycorrelated_200_10000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_200_10000.csv";
  /* For each 3_50_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_midlow_eps_stronglycorrelated_200_100000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_200_100000.csv";
  /* For each 2_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_midlow_eps_stronglycorrelated_200_1000000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_200_1000000.csv";
  /* For each 3_50_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_midlow_eps_stronglycorrelated_200_10000000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_200_10000000.csv";
  /* For each 3_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_midlow_eps_stronglycorrelated_500_1000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_500_1000.csv";
  /* For each 3_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_midlow_eps_stronglycorrelated_500_10000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_500_10000.csv";
  /* For each 3_100_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_midlow_eps_stronglycorrelated_500_100000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_500_100000.csv";
  /* For each 1_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_midlow_eps_stronglycorrelated_500_1000000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_500_1000000.csv";
  /* For each 1_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, linear_enum_branching_willshmoy_midlow_eps_stronglycorrelated_500_10000000)
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
  /* Random branching */
  int branching_strategy = LINEAR_ENUM_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_500_10000000.csv";
  /* For each 3_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

  /* Truncation Branching */
TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_uncorrelated_200_1000)
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_200_1000.csv";
  /* For each 1_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_uncorrelated_200_10000)
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_200_10000.csv";
  /* For each 1_50_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_uncorrelated_200_100000)
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_200_100000.csv";
  /* For each 1_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

  /* For each 1_50_1000000 */
TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_uncorrelated_200_1000000)
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_200_1000000.csv";
  /* For each 1_50_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

  /* For each 1_50_10000000 */
TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_uncorrelated_200_10000000)
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_200_10000000.csv";
  /* For each 1_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

/* For each 1_100_1000 */
TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_uncorrelated_500_1000)
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_500_1000.csv";
  /* For each 1_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

/* For each 1_100_10000 */
TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_uncorrelated_500_10000)
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_500_10000.csv";
  /* For each 1_100_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

/* For each 1_100_100000 */
TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_uncorrelated_500_100000)
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_500_100000.csv";
  /* For each 1_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

/* For each 1_100_1000000 */
TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_uncorrelated_500_1000000)
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_500_1000000.csv";
  /* For each 1_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}
/* For each 1_100_10000000 */
TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_uncorrelated_500_10000000)
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_1_500_10000000.csv";
  /* For each 1_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_weaklycorrelated_200_1000)
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_200_1000.csv";
  /* For each 2_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_weaklycorrelated_200_10000)
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_200_10000.csv";
  /* For each 1_50_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_weaklycorrelated_200_100000)
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_200_100000.csv";
  /* For each 2_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_weaklycorrelated_200_1000000)
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_200_1000000.csv";
  /* For each 2_50_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_weaklycorrelated_200_10000000)
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_200_10000000.csv";
  /* For each 2_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_weaklycorrelated_500_1000)
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_500_1000.csv";
  /* For each 2_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_weaklycorrelated_500_10000)
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_500_10000.csv";
  /* For each 1_100_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_weaklycorrelated_500_100000)
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_500_100000.csv";
  /* For each 1_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_weaklycorrelated_500_1000000)
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_500_1000000.csv";
  /* For each 1_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_weaklycorrelated_500_10000000)
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_2_500_10000000.csv";
  /* For each 2_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_stronglycorrelated_200_1000)
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_200_1000.csv";
  /* For each 3_50_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_stronglycorrelated_200_10000)
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_200_10000.csv";
  /* For each 3_50_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_stronglycorrelated_200_100000)
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_200_100000.csv";
  /* For each 2_50_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_stronglycorrelated_200_1000000)
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_200_1000000.csv";
  /* For each 3_50_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_stronglycorrelated_200_10000000)
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_200_10000000.csv";
  /* For each 3_50_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_stronglycorrelated_500_1000)
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_500_1000.csv";
  /* For each 3_100_1000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_stronglycorrelated_500_10000)
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_500_10000.csv";
  /* For each 3_100_10000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_stronglycorrelated_500_100000)
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_500_100000.csv";
  /* For each 1_100_100000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_stronglycorrelated_500_1000000)
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_500_1000000.csv";
  /* For each 1_100_1000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
    ASSERT_EQ(z_out, z);
  }
}

TEST(branch_and_bound_correctnessTest, truncation_branching_willshmoy_midlow_eps_stronglycorrelated_500_10000000)
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
  /* Random branching */
  int branching_strategy = TRUNCATION_BRANCHING;
  time_t seed = time(NULL);
  const char *problem_file = "knapPI_3_500_10000000.csv";
  /* For each 3_100_10000000 */
  for(int i = 1; i <= 1; i++)
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, (char*) problem_file, i);
    int sol_out[n];
    branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, (char*) problem_file, branching_strategy, seed,
																	DP_method, logging_rule, logging_stream, epsilon, &number_of_nodes);
                                  
    ASSERT_EQ(z_out, z);
  }
}


int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
