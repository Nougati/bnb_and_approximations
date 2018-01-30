/******************************************************************************
 * FPTAS_test.cpp                                                             *
 * Author: Nelson Frew                                                        *
 * First edit: 29/01/18                                                       *
 * Last edit 29/01/18                                                         *
 * Description:                                                               *
 *   Unit tests for the FPTAS basic functionality which uses an unspecified   *
 *   but already tested DP framework.                                         *
 * TODO:                                                                      *
 ******************************************************************************/

#define TESTING
#include "fptas.c"
#include <gtest/gtest.h>
#include <time.h>
#include <math.h>

class FPTAS_mechanismTest : public testing::Test
{
  void SetUp(){
  }
  void TearDown(){
  }
};

TEST(FPTAS_mechanismTest, FindsMaxProfit){
  /* Make sure, given a list of profits, that the max profit is correctly 
     obtained */
  /* Define profits such that we know exactly what the max profit is */
  srand(time(NULL));
  int max_profit = (rand() % 900) + 100;

  int list_length = (rand() % 10)+1;

  int test_profit_list[list_length];

  int die_roll = 0;
  int debug_int;
  for (int i = 0; i < list_length; i++)
  {
    if (die_roll == 7)
      test_profit_list[i] = rand() % max_profit;
    else
    {
      /* Roll the dice */
      die_roll = (rand() % 6) + 1;

      /* If we got a 6, we put max_profit in */
      if(die_roll == 6)
      {
        die_roll = 7;
        test_profit_list[i] = max_profit;
      }
      else
        test_profit_list[i] = rand() % max_profit;
    }
    /* Handling the unlikely scenario that the die never comes up 6 */
    if (i == list_length-1)
      if (die_roll != 7)
        test_profit_list[i] = max_profit;
  }

  /* Run the algorithm */
  int algorithm_max_profit = DP_max_profit(test_profit_list, list_length);

  /* Compare results */
  ASSERT_EQ(algorithm_max_profit, max_profit);
}

TEST(FPTAS_mechanismTest, DefinesK){
  /* Ensure that, given parameter eps, max profit P, and item amount n, that 
     the scaling parameter K is correctly defined */
  /* Find some epsilon value, with some arbitrary P and n */
  /* This mightn't be a great test method but until I figure a better way 
     we're doing this */
  float eps = (float) rand() / (float)(RAND_MAX); 

  int P = rand();
  int n = rand();

  float control_K = ((float) eps * P) / n;

  float algo_K = define_K(eps, P, n);

  ASSERT_EQ(control_K, algo_K);
}

TEST(FPTAS_mechanismTest, CreatesProfitPrimes){
  /* We show that given a list of profits, manually amending the profits will
     yield the same result as pumping it through the algorithm with creates 
     the profit' set. */
  /* This assumes that define_K and DP_max_profit both work */
  int list_length = rand() % 1000 + 100;
  int test_profits[list_length];

  /* Define profits */
  for (int i = 0; i < list_length; i++)
  {
    test_profits[i] = rand() % 10000;
  }

  /* Find P */
  int P = DP_max_profit(test_profits, list_length);

  float eps = (float)rand() / (float)RAND_MAX;

  /* Define K */ 
  float K = define_K(eps, P, list_length);

  /* Make the profit primes here */  
  int test_profits_prime[list_length];
  for(int i = 0; i < list_length; i++)
  {
    test_profits_prime[i] = floor(test_profits[i] / K);
  }

  /* Then do it via the algorithm */
  int algorithm_profits_prime[list_length];
  make_profit_primes(test_profits, algorithm_profits_prime, K, list_length);

  /* Assert that the two are identical */
  for(int i = 0; i < list_length; i++)
    ASSERT_EQ(algorithm_profits_prime[i], test_profits_prime[i]);

}

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
