/*****************************************************************************
 * vasirani_DP_test.cpp                                                      *
 * Author: Nelson Frew                                                       *
 * First edit: 30/01/18                                                      *
 * Last edit: 30/01/18                                                       *
 * Description:                                                              *
 *   Unit tests for the Dynamic Programming algorithm as described by Vijay  *
 *    Vasirani in his book Approximation Algorithms, in the chapter about on *
 *    the Knapsack problem.                                                  *
 * TODO:                                                                     *
 *****************************************************************************/

#define TESTING
#define SUPER_TRIVIAL 1
#define TRIVIAL 2
#define INDEX_NOTATION 0
#define BINARY_NOTATION 1

#include "vasirani_dp.c"
#include <gtest/gtest.h>
#include <time.h>
#include <math.h>

class DynamicProgrammingMechanismTests : public testing:: Test
{ 
  protected:
  void SetUp(){
    int n = 7;
    int capacity = 18;

    /* Make some sample profits */
    int profits[] = {12, 10, 8, 11, 14, 7, 9};

    /* Make some sample weights */
    int weights[] = {4, 6, 5, 7, 3, 1, 6};

    /* Define the solution */
    int optimal_profit = 44;
    int optimal_solution[] = {1, 1, 1, 0, 1, 0, 0};

    /* Allocate the DP for the table ahead of time */
    /* First one for super trivial */
    int super_trivial_bound = n * 14;
    int **STB_DP_table = (int **) malloc(sizeof(int *) * (n+1));
    STB_DP_table[0] = (int *)malloc(sizeof(int) * super_trivial_bound * (n+1));
    for(int i=0; i < (n+1); i++)
      STB_DP_table[i] = (*STB_DP_table + super_trivial_bound * i);

    /* Then one for ordinary trivial */
    int trivial_bound = 71;
    int **TB_DP_table = (int **) malloc(sizeof(int *) * (n+1));
    TB_DP_table[0] = (int *)malloc(sizeof(int) * trivial_bound * (n+1));
    for(int i=0; i < (n+1); i++)
      TB_DP_table[i] = (*TB_DP_table + trivial_bound * i);
  }
  void TearDown(){
    /* Apparently these aren't necessary? 
    free(STB_DP_table);
    free(STB_DP_tabl;e[0]);
    free(TB_DP_table);
    free(TB_DP_table[0]);
     lol */
  }
};

TEST(DynamicProgrammingMechanismTests, ProperlyDerivesUpperBound){
  /* Ensures that the bounding function properly computes and returns the 
   * trivial upper bounds on profit. */
  /* Variable set up */ 
  int n = 7;
  int capacity = 18;
  int P = 14;

  /* Make some sample profits */
  int profits[] = {12, 10, 8, 11, 14, 7, 9};

  /* Make some sample weights */
  int weights[] = {4, 6, 5, 7, 3, 1, 6};

  /* Define the solution */
  int optimal_profit = 44;
  int optimal_solution[] = {1, 1, 1, 0, 1, 0, 0};

  /* Allocate the DP for the table ahead of time */
  /* First one for super trivial */
  int super_trivial_bound = n * P;
  int **STB_DP_table = (int **) malloc(sizeof(int *) * (n+1));
  STB_DP_table[0] = (int *)malloc(sizeof(int) * super_trivial_bound * (n+1));
  for(int i=0; i < (n+1); i++)
    STB_DP_table[i] = (*STB_DP_table + super_trivial_bound * i);

  /* Then one for ordinary trivial */
  int trivial_bound = 71;
  int **TB_DP_table = (int **) malloc(sizeof(int *) * (n+1));
  TB_DP_table[0] = (int *)malloc(sizeof(int) * trivial_bound * (n+1));
  for(int i=0; i < (n+1); i++)
    TB_DP_table[i] = (*TB_DP_table + trivial_bound * i);

  /* Test if the upper bound is reasonable */

  int test_super_trivial_bound = DP_p_upper_bound(profits, n, P, SUPER_TRIVIAL);
  ASSERT_EQ(test_super_trivial_bound, super_trivial_bound);
  int test_trivial_bound = DP_p_upper_bound(profits, n, P, TRIVIAL); 
  ASSERT_EQ(test_trivial_bound, trivial_bound);
}

TEST(DynamicProgrammingMechanismTests, DerivesMyPinf){
  /* Ensures that the algorithm derives my integer substritute for positive 
   * infinity adequately. */
  /* Variable set up */ 
  int n = 7;
  int capacity = 18;
  int P = 14;

  /* Make some sample profits */
  int profits[] = {12, 10, 8, 11, 14, 7, 9};

  /* Make some sample weights */
  int weights[] = {4, 6, 5, 7, 3, 1, 6};

  /* Define the solution */
  int optimal_profit = 44;
  int optimal_solution[] = {1, 1, 1, 0, 1, 0, 0};

  /* Allocate the DP for the table ahead of time */
  /* First one for super trivial */
  int super_trivial_bound = n * P;
  int **STB_DP_table = (int **) malloc(sizeof(int *) * (n+1));
  STB_DP_table[0] = (int *)malloc(sizeof(int) * super_trivial_bound * (n+1));
  for(int i=0; i < (n+1); i++)
    STB_DP_table[i] = (*STB_DP_table + super_trivial_bound * i);

  /* Then one for ordinary trivial */
  int trivial_bound = 71;
  int **TB_DP_table = (int **) malloc(sizeof(int *) * (n+1));
  TB_DP_table[0] = (int *)malloc(sizeof(int) * trivial_bound * (n+1));
  for(int i = 0; i < (n+1); i++)
    TB_DP_table[i] = (*TB_DP_table + trivial_bound * i);

  int pinf = 1;
  for (int i = 0; i < n; i++)
    pinf += weights[i];
  int test_pinf = derive_pinf(weights, n);
  ASSERT_EQ(test_pinf, pinf);
} 

TEST(DynamicProgrammingMechanismTests, CorrectlyComputesBases){
  /* Ensures that the algorithm for computing the dynamic programming bases
   * is carried out as expected. */
  /* Variable set up */ 
  int n = 7;
  int capacity = 18;
  int P = 14;

  /* Make some sample profits */
  int profits[] = {12, 10, 8, 11, 14, 7, 9};

  /* Make some sample weights */
  int weights[] = {4, 6, 5, 7, 3, 1, 6};

  /* Define the solution */
  int optimal_profit = 44;
  int optimal_solution[] = {1, 1, 1, 0, 1, 0, 0};

  /* Allocate the DP for the table ahead of time */
  /* First one for super trivial */
  int super_trivial_bound = n * P;
  int **STB_DP_table = (int **) malloc(sizeof(int *) * (n+1));
  STB_DP_table[0] = (int *)malloc(sizeof(int) * super_trivial_bound * (n+1));
  for(int i=0; i < (n+1); i++)
    STB_DP_table[i] = (*STB_DP_table + super_trivial_bound * i);

  /* Then one for ordinary trivial */
  int trivial_bound = 71;
  int **TB_DP_table = (int **) malloc(sizeof(int *) * (n+1));
  TB_DP_table[0] = (int *)malloc(sizeof(int) * trivial_bound * (n+1));
  for(int i=0; i < (n+1); i++)
    TB_DP_table[i] = (*TB_DP_table + trivial_bound * i);

  int pinf = 1;
  for (int i = 0; i < n; i++)
    pinf += weights[i];
  
  DP_fill_in_base_cases(super_trivial_bound, n+1, STB_DP_table, profits, 
                        weights);

  /* Control case: compute base cases for super trivial*/
  for(int i=1; i < super_trivial_bound; i++)
    ASSERT_EQ(STB_DP_table[0][i], pinf);
  for(int i=0; i < n; i++)
    ASSERT_EQ(STB_DP_table[i][0], 0);

  DP_fill_in_base_cases(trivial_bound, n+1, TB_DP_table, profits, weights);

  /* Control case: compute the base cases for trivial */
  for(int i=1; i < trivial_bound; i++)
    ASSERT_EQ(TB_DP_table[0][i], pinf);
  for(int i=0; i < n; i++)
    ASSERT_EQ(TB_DP_table[i][0], 0);
}

TEST(DynamicProgrammingMechanismTests, CorrectlyFindsBestSolution){
  /* Ensures the general case is working as expected by just looking at the 
   * table's general entry*/

  /* Variable set up */ 
  int n = 7;
  int capacity = 18;
  int P = 14;

  /* Make some sample profits */
  int profits[] = {12, 10, 8, 11, 14, 7, 9};

  /* Make some sample weights */
  int weights[] = {4, 6, 5, 7, 3, 1, 6};

  /* Define the solution */
  int optimal_profit = 44;
  int optimal_solution[] = {1, 1, 1, 0, 1, 0, 0};

  /* Allocate the DP for the table ahead of time */
  /* First one for super trivial */
  int super_trivial_bound = n * P;
  int **STB_DP_table = (int **) malloc(sizeof(int *) * (n+1));
  STB_DP_table[0] = (int *)malloc(sizeof(int) * super_trivial_bound * (n+1));
  for(int i=0; i < (n+1); i++)
    STB_DP_table[i] = (*STB_DP_table + super_trivial_bound * i);

  /* Then one for ordinary trivial */
  int trivial_bound = 71;
  int **TB_DP_table = (int **) malloc(sizeof(int *) * (n+1));
  TB_DP_table[0] = (int *)malloc(sizeof(int) * trivial_bound * (n+1));
  for(int i=0; i < (n+1); i++)
    TB_DP_table[i] = (*TB_DP_table + trivial_bound * i);

  int pinf = 1;
  for (int i = 0; i < n; i++)
    pinf += weights[i];
  
  DP_fill_in_base_cases(super_trivial_bound, n+1, STB_DP_table, profits, 
                        weights);
  DP_fill_in_general_cases(super_trivial_bound, n+ 1, STB_DP_table, profits,
                           weights);

  int super_trivial_solution = DP_find_best_solution(super_trivial_bound, n, 
                                                     STB_DP_table, capacity,
                                                     pinf);

  DP_fill_in_base_cases(trivial_bound, n+1, TB_DP_table, profits, weights);
  DP_fill_in_general_cases(trivial_bound, n+1, TB_DP_table, profits, weights);

  int trivial_solution = DP_find_best_solution(trivial_bound, n, TB_DP_table,
                                               capacity, pinf); 

  ASSERT_EQ(optimal_profit, super_trivial_solution);
  ASSERT_EQ(optimal_profit, trivial_solution);
}


TEST(DynamicProgrammingMechanismTests, CorrectlyDerivesSolutionSet){
  /* Ensures that the algorithm which scours the DP table will find the right
   * set of items */
  /* Variable set up */ 
  int n = 7;
  int capacity = 18;
  int P = 14;

  /* Make some sample profits */
  int profits[] = {12, 10, 8, 11, 14, 7, 9};

  /* Make some sample weights */
  int weights[] = {4, 6, 5, 7, 3, 1, 6};

  /* Define the solution */
  int optimal_profit = 44;
  int optimal_solution[] = {1, 1, 1, 0, 1, 0, 0};

  /* Allocate the DP for the table ahead of time */
  /* First one for super trivial */
  int super_trivial_bound = n * P;
  int **STB_DP_table = (int **) malloc(sizeof(int *) * (n+1));
  STB_DP_table[0] = (int *)malloc(sizeof(int) * super_trivial_bound * (n+1));
  for(int i=0; i < (n+1); i++)
    STB_DP_table[i] = (*STB_DP_table + super_trivial_bound * i);

  /* Then one for ordinary trivial */
  int trivial_bound = 71;
  int **TB_DP_table = (int **) malloc(sizeof(int *) * (n+1));
  TB_DP_table[0] = (int *)malloc(sizeof(int) * trivial_bound * (n+1));
  for(int i=0; i < (n+1); i++)
    TB_DP_table[i] = (*TB_DP_table + trivial_bound * i);

  int pinf = 1;
  for (int i = 0; i < n; i++)
    pinf += weights[i];
  
  DP_fill_in_base_cases(super_trivial_bound, n+1, STB_DP_table, profits, 
                        weights);
  DP_fill_in_general_cases(super_trivial_bound, n+ 1, STB_DP_table, profits,
                           weights);

  int super_trivial_solution = DP_find_best_solution(super_trivial_bound, n, 
                                                     STB_DP_table, capacity,
                                                     pinf);

  DP_fill_in_base_cases(trivial_bound, n+1, TB_DP_table, profits, weights);
  DP_fill_in_general_cases(trivial_bound, n+1, TB_DP_table, profits, weights);

  int trivial_solution = DP_find_best_solution(trivial_bound, n, TB_DP_table,
                                               capacity, pinf); 

  int ST_solution_set[n]; 
  int useful_variable = DP_derive_solution_set(n+1, super_trivial_bound,
                                               STB_DP_table, profits,
                                               ST_solution_set, 
                                               super_trivial_solution,
                                               BINARY_NOTATION);
  int T_solution_set[n];
  int another_useful_variable = DP_derive_solution_set(n+1, trivial_bound,
                                                       TB_DP_table,
                                                       profits, T_solution_set,
                                                       trivial_solution, 
                                                       BINARY_NOTATION);
  /* Check that the solution sets all make sense*/
  /* TODO Add testing for the non unique set solution verification */
  /*
  for(int i=0; i<n; i++)
  {
    EXPECT_EQ(optimal_solution[i], ST_solution_set[i]);
    EXPECT_EQ(optimal_solution[i], T_solution_set[i]);
  }*/
  int ST_profit_sanity_check = 0;
  int T_profit_sanity_check = 0;
  for(int i = 0; i < n; i++)
  {
    if(ST_solution_set[i]) ST_profit_sanity_check += profits[i];
    if(T_solution_set[i]) T_profit_sanity_check += profits[i];
  }
  ASSERT_EQ(ST_profit_sanity_check, optimal_profit);
  ASSERT_EQ(optimal_profit, T_profit_sanity_check);
}

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

