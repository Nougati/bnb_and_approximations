#include <stdio.h>
#include <math.h>
#include "kellerer_pferschy_fptas.h"
#define SUCCESS 1
#define FAILURE 0
#define TRUE 1
#define FALSE 0

/* NOTE TO SELF 02-10-2018:
    Finish test_get_number_of_weights();
    Then finish interval DP
*/

void test_modify_epsilon(void);
void test_get_knapsack_lowerbound(void);
void test_small_large_split(void);
int is_in(int value, int arr[], int arr_len);
void test_partition_large_set(void);
void test_partition_interval(void);
void test_reduce_profits_to_minimal(void);
void test_prune_excess_weight_items(void);
void test_redefine_large_set(void);
void test_scaling_reduction(void);
void test_vector_merge_interval(void);
void test_vector_merge_naive(void);
void test_interval_dynamic_programming(void);
void test_get_ith_interval(void);
void test_get_number_of_weights(void);
void test_get_no_subintervals_used(void);

int main(int argc, char *argv[])
{
  /* Everything for scaling reduction */
  //test_modify_epsilon();
  //test_get_knapsack_lowerbound();
  //test_small_large_split();
  //test_partition_large_set();
  //test_partition_interval();
  //test_reduce_profits_to_minimal();
  //test_prune_excess_weight_items(); 
  //test_redefine_large_set();
  //test_scaling_reduction();
  //test_interval_dynamic_programming();


  /* Everything for interval dynamic programming */
  //test_vector_merge_naive();
  //test_vector_merge_interval();
  //test_interval_dynamic_programming();
  //test_get_ith_interval();
  //test_get_number_of_weights();
  test_get_no_subintervals_used();

  /* TODO Everything for greedily add smalls */
  

  /* TODO Everything for backtracking */

  /* TODO Everything for recursion */

  /* Just leaving this here just in case: testing quick sort? */
  /*
  int profits[] = {94, 506, 416, 992, 649, 237, 457, 815, 446, 422};
  int weights[] = {485, 326, 248, 421, 322, 795, 43, 845, 955, 252};
  int n = 1;
  quick_sort_parallel_lists_asc_int(profits, weights, 0, n-1);
  for(int i = 0; i < n; i++) 
    printf("%s%d%s%s", i == 0 ? "profits: [" : "", profits[i], 
           i == n-1 ? "]\n" : ", ", i % 5 == 0 && i != 0 ? "\n\t" : ""); 

  for(int i = 0; i < n; i++) 
    printf("%s%d%s%s", i == 0 ? "weights: [" : "", weights[i], 
           i == n-1 ? "]\n" : ", ", i % 5 == 0 && i != 0 ? "\n\t" : ""); 
  */

  return 0;
}

void test_modify_epsilon(void)
{
  double first_epsilon = 0.0002;
  double second_epsilon = 0.06;
  double third_epsilon = 0.9;
  int return_val = SUCCESS;

  printf("Running test_modify_epsilon...\n");

  /* First test */
  modify_epsilon(&first_epsilon);
  if(1/first_epsilon != 10000)
  {
    printf("\tfailed on first_epsilon (expected 10000, got %lf)\n",
           1/first_epsilon);
    return_val = FAILURE;
  }

  /* Second test */
  modify_epsilon(&second_epsilon);
  if(1/second_epsilon != 34)
  {
    printf("\tfailed on second_epsilon (expected 34, got %lf)\n",
           1/second_epsilon);
    return_val = FAILURE;
  }

  /* Third test */
  modify_epsilon(&third_epsilon);
  if(1/third_epsilon != 3)
  {
    printf("\tfailed on third_epsilon (expected 3, got %lf)\n",
           1/third_epsilon);
    return_val = FAILURE;
  }

  if(return_val == SUCCESS)
    printf("\tAll passed! \n");
}

void test_get_knapsack_lowerbound(void)
{
  printf("Running test_get_knapsack_lowerbound\n");
  int return_val = SUCCESS;
  int lower_out;
  double upper_out;

  /* First test */
  int test_profits1[] = {100, 200, 300, 400};
  int test_weights1[] = {50, 20, 10, 100};
  int n1 = 4;
  int capacity1 = 15;
  int expected_LB1 = 300;
  int expected_UB1 = 350;

  get_knapsack_lowerbound(test_profits1, test_weights1, n1, capacity1, 
                          &lower_out, &upper_out); 
  if(lower_out != expected_LB1)
  {
    printf("\tfailed on get_knapsack_lowerbound test #1: (lower_out: expected 3"
           "00, got %d)\n", lower_out); 
    return_val = FAILURE;
  }
  if(upper_out != expected_UB1)
  {
    printf("\tfailed on get_knapsack_lowerbound test #1: (upper_out: expected 3"
           "50, got %lf)\n", upper_out); 
    return_val = FAILURE;
  }
  
  /* Second test */
  int *test_profits2;
  int *test_weights2;
  int n2 = 0;
  int capacity2 = 0;
  int expected_LB2 = 0;
  int expected_UB2 = 0;
  get_knapsack_lowerbound(test_profits2, test_weights2, n2, capacity2, 
                          &lower_out, &upper_out); 
  if(lower_out != expected_LB2)
  {
    printf("\tfailed on get_knapsack_lowerbound test #2: (lower_out: expected 0"
           ", got %d)\n", lower_out); 
    return_val = FAILURE;
  }
  if(upper_out != expected_UB2)
  {
    printf("\tfailed on get_knapsack_lowerbound test #2: (upper_out: expected 0"
           ", got %lf)\n", upper_out); 
    return_val = FAILURE;
  }
  
  /* Third test */
  int test_profits3[] = {5, 3, 6, 7, 2, 10, 1};
  int test_weights3[] = {6, 4, 7, 8, 3, 11, 2};
  int capacity3 = 21;
  int n3 = 7;
  int expected_LB3 = 18;
  double expected_UB3 = (17.0 + (2.0/7.0)*6.0);

  get_knapsack_lowerbound(test_profits3, test_weights3, n3, capacity3, 
                          &lower_out, &upper_out); 
  if(lower_out != expected_LB3)
  {
    printf("\tfailed on get_knapsack_lowerbound test #2: (lower_out: expected "
           "%d, got %d)\n", expected_LB3, lower_out); 
    return_val = FAILURE;
  }
  if(upper_out != expected_UB3)
  {
    printf("\tfailed on get_knapsack_lowerbound test #2: (upper_out: expected 0"
           "%lf, got %lf)\n", expected_UB3, upper_out); 
    return_val = FAILURE;
  }

  if(return_val == SUCCESS)
    printf("\tAll passed! \n");
}

void test_small_large_split(void)
{
  /* Given a set of items, derive two sets: "Small items" and "large items" */
  /* Relies on get_knapsack_lowerbound and modify_epsilon */
  printf("Running test_small_large_split\n");
  int return_val = SUCCESS;
  int suite_return_val = SUCCESS;

  /********* Test 1: Normal input 1 *********/
  int profits1[] = { 94,506,416,992,649,237,457,815,446,422,791,359,667,598,  7,
                    544,334,766,994,893,633,131,428,700,617,874,720,419,794,196,
                    997,116,908,539,707,569,537,931,726,487,772,513, 81,943, 58,
                    303,764,536,724,789};
  int weights1[] = {485,326,248,421,322,795, 43,845,955,252,  9,901,122, 94,738,
                    574,715,882,367,984,299,433,682, 72,874,138,856,145,995,529,
                    199,277, 97,719,242,107,122, 70, 98,600,645,267,972,895,213,
                    748,487,923, 29,674};
  int n1 = 50;
  int capacity1 = 995;
  int lower_bound = 7945;
  double epsilon1 = 0.01;

  int expected_small1[] = {7, 58};
  int expected_large1[] = { 94,506,416,992,649,237,457,815,446,422,791,359,667,
                          598,544,334,766,994,893,633,131,428,700,617,874,720,
                          419,794,196,997,116,908,539,707,569,537,931,726,487,
                          772,513, 81,943,303,764,536,724,789};

  int small_profits[n1], small_weights[n1];
  for(int i = 0; i < n1; i++)
    small_profits[i] = small_weights[i] = 0;

  int large_profits[n1], large_weights[n1];
  for(int i = 0; i < n1; i++)
    large_profits[i] = large_weights[i] = 0;

  int n_large;
  small_large_split(profits1, weights1, n1, capacity1, epsilon1, lower_bound, 
                    small_profits, large_profits, small_weights, large_weights,
                    &n_large);
  
  /* Check that small was right */
  for(int i = 0; i < 2; i++)
  {
    if(!is_in(expected_small1[i], small_profits, n1))
    {
      return_val = FAILURE;
      suite_return_val = FAILURE;
      break;
    }
  }
  if(!is_in(-1, small_profits, n1))
  {
      printf("\tSmall doesn't have a -1!\n");
      return_val = FAILURE;
      suite_return_val = FAILURE;
  }

  /* Check that large was right */
  for(int i = 0; i < 48; i++)
  {
    if(!is_in(expected_large1[i], large_profits, n1))
    {
      return_val = FAILURE;
      suite_return_val = FAILURE;
      break;
    }
  }
  if(!is_in(-1, large_profits, n1))
  {
      printf("\tLarge doesn't have a -1!\n");
      return_val = FAILURE;
      suite_return_val = FAILURE;
  }

  if(return_val == FAILURE)
  {
    /* Print expected outputs */
    printf("\tTest 1 failure: expected\n\t\t[");
    for(int i = 0; i < 2; i++)
    {
      printf(" %d", expected_small1[i]);
      if((i+1)%15 == 0)
        printf("\n\t\t ");
    }
    printf("], and\n\t\t[");
    for(int i = 0; i < 48; i++)
    {
      printf(" %d", expected_large1[i]);
      if((i+1)%15 == 0)
        printf("\n\t\t ");
    }
    printf("],\n\tbut we got\n\t\t[");

    /* Print received outputs */
    for(int i = 0; i < n1; i++)
    {
      printf(" %d", small_profits[i]);
      if((i+1)%15 == 0)
        printf("\n\t\t ");
    }
    printf("], and\n\t\t[");
    for(int i = 0; i < n1; i++)
    {
      printf(" %d", large_profits[i]);
      if((i+1)%15 == 0)
        printf("\n\t\t ");
    }
    printf("].\n");
  }

  /********* Test 2: Normal input 2 *********/
  // Small should have everything less than or equal to 794
  double epsilon2 = 0.1;
  return_val = SUCCESS;
  int expected_small2[] = {  7, 58, 94,506,416,649,237,457,446,422,791,359,667,
                           598,544,334,766,633,131,428,700,617,720,419,196,116,
                           539,707,569,537,794,726,487,772,513, 81,303,764,536,
                           724,789};
  int expected_large2[] = { 992, 815, 994, 893, 874, 997, 908, 931, 943};

  for(int i = 0; i < n1; i++)
    small_profits[i] = small_weights[i] = 0;

  for(int i = 0; i < n1; i++)
    large_profits[i] = large_weights[i] = 0;

  small_large_split(profits1, weights1, n1, capacity1, epsilon2, lower_bound, 
                    small_profits, large_profits, small_weights, large_weights,
                    &n_large);

  /* Check that small was right */
  for(int i = 0; i < 41; i++)
  {
    if(!is_in(expected_small2[i], small_profits, n1))
    {
      return_val = FAILURE;
      suite_return_val = FAILURE;
      break;
    }
  }
  if(!is_in(-1, small_profits, n1))
  {
      printf("\tSmall doesn't have a -1!\n");
      return_val = FAILURE;
      suite_return_val = FAILURE;
  }

  /* Check that large was right */
  for(int i = 0; i < 9; i++)
  {
    if(!is_in(expected_large2[i], large_profits, n1))
    {
      return_val = FAILURE;
      suite_return_val = FAILURE;
      break;
    }
  }
  if(!is_in(-1, large_profits, n1))
  {
      printf("\tLarge doesn't have a -1!\n");
      return_val = FAILURE;
      suite_return_val = FAILURE;
  }

  if(return_val == FAILURE)
  {
    /* Print expected outputs */
    printf("\tTest 2 failure: expected\n\t\t[");
    for(int i = 0; i < 41; i++)
    {
      printf(" %d", expected_small2[i]);
      if((i+1)%15 == 0)
        printf("\n\t\t ");
    }
    printf("], and\n\t\t[");
    for(int i = 0; i < 9; i++)
    {
      printf(" %d", expected_large2[i]);
      if((i+1)%15 == 0)
        printf("\n\t\t ");
    }
    printf("],\n\tbut we got\n\t\t[");

    /* Print received outputs */
    for(int i = 0; i < n1; i++)
    {
      printf(" %d", small_profits[i]);
      if((i+1)%15 == 0)
        printf("\n\t\t ");
    }
    printf("], and\n\t\t[");
    for(int i = 0; i < n1; i++)
    {
      printf(" %d", large_profits[i]);
      if((i+1)%15 == 0)
        printf("\n\t\t ");
    }
    printf("].\n");
  }

  /********* Test 3: Nothing in small *********/
  double epsilon3 = 0.0001;
  return_val = SUCCESS;
  int expected_large3[] = { 94,506,416,992,649,237,457,815,446,422,791,359,667,
                           598,  7,544,334,766,994,893,633,131,428,700,617,874,
                           720,419,794,196,997,116,908,539,707,569,537,931,726,
                           487,772,513, 81,943, 58,303,764,536,724,789};
  int expected_small3[] = {};

  /* Set up instance */
  for(int i = 0; i < n1; i++)
    small_profits[i] = small_weights[i] = 0;

  for(int i = 0; i < n1; i++)
    large_profits[i] = large_weights[i] = 0;

  /* Run algorithm */
  small_large_split(profits1, weights1, n1, capacity1, epsilon3, lower_bound, 
                    small_profits, large_profits, small_weights, large_weights,
                    &n_large);
  
  /* Check that large was right */
  for(int i = 0; i < 50; i++)
  {
    if(!is_in(expected_large3[i], large_profits, n1))
    {
      return_val = FAILURE;
      suite_return_val = FAILURE;
      break;
    }
  }
  if(is_in(-1, large_profits, n1))
  {
      printf("\tLarge has a -1!\n");
      return_val = FAILURE;
      suite_return_val = FAILURE;
  }

  /* Check that small was right */
  for(int i = 0; i < n1; i++)
  {
    if(small_profits[i] != 0 && small_profits[i] != -1)
    {
      return_val = FAILURE;
      suite_return_val = FAILURE;
      break;
    }
  }
  if(!is_in(-1, small_profits, n1))
  {
      printf("\tSmall doesn't have a -1!\n");
      return_val = FAILURE;
      suite_return_val = FAILURE;
  }

  /* If we failed, print the arrays */
  if(return_val == FAILURE)
  {
    /* Print expected outputs */
    printf("\tTest 3 failure: expected\n\t\t[");
    for(int i = 0; i < 0; i++)
    {
      printf(" %d", expected_small3[i]);
      if((i+1)%15 == 0)
        printf("\n\t\t ");
    }
    printf("], and\n\t\t[");
    for(int i = 0; i < 50; i++)
    {
      printf(" %d", expected_large3[i]);
      if((i+1)%15 == 0)
        printf("\n\t\t ");
    }
    printf("],\n\tbut we got\n\t\t[");

    /* Print received outputs */
    for(int i = 0; i < n1; i++)
    {
      printf(" %d", small_profits[i]);
      if((i+1)%15 == 0)
        printf("\n\t\t ");
    }
    printf("], and\n\t\t[");
    for(int i = 0; i < n1; i++)
    {
      printf(" %d", large_profits[i]);
      if((i+1)%15 == 0)
        printf("\n\t\t ");
    }
    printf("].\n");
  }

  /********* Test 4: Nothing in large *********/
  double epsilon4 = 0.9;
  return_val = SUCCESS;
  int expected_small4[] = { 94,506,416,992,649,237,457,815,446,422,791,359,667,
                           598,  7,544,334,766,994,893,633,131,428,700,617,874,
                           720,419,794,196,997,116,908,539,707,569,537,931,726,
                           487,772,513, 81,943, 58,303,764,536,724,789};
  int expected_large4[] = {};


  /* Set up instance */
  for(int i = 0; i < n1; i++)
    small_profits[i] = small_weights[i] = 0;

  for(int i = 0; i < n1; i++)
    large_profits[i] = large_weights[i] = 0;

  /* Run algorithm */
  small_large_split(profits1, weights1, n1, capacity1, epsilon4, lower_bound, 
                    small_profits, large_profits, small_weights, large_weights,
                    &n_large);
  
  /* Check that small was right */
  for(int i = 0; i < n1; i++)
  {
    if(!is_in(expected_small4[i], small_profits, n1))
    {
      return_val = FAILURE;
      suite_return_val = FAILURE;
      break;
    }
  }
  if(is_in(-1, small_profits, n1))
  {
      printf("\tSmall has a -1!\n");
      return_val = FAILURE;
      suite_return_val = FAILURE;
  }

  /* Check that large was right */
  for(int i = 0; i < n1; i++)
  {
    if(large_profits[i] != 0 && large_profits[i] != -1)
    {
      return_val = FAILURE;
      suite_return_val = FAILURE;
      break;
    }
  }
  if(!is_in(-1, large_profits, n1))
  {
      printf("\tLarge doesn't have  a -1!\n");
      return_val = FAILURE;
      suite_return_val = FAILURE;
  }

  /* If we failed, print the arrays */
  if(return_val == FAILURE)
  {
    /* Print expected outputs */
    printf("\tTest 4 failure: expected\n\t\t[");
    for(int i = 0; i < n1; i++)
    {
      printf(" %d", expected_small4[i]);
      if((i+1)%15 == 0)
        printf("\n\t\t ");
    }
    printf("], and\n\t\t[");
    for(int i = 0; i < 0; i++)
    {
      printf(" %d", expected_large4[i]);
      if((i+1)%15 == 0)
        printf("\n\t\t ");
    }
    printf("],\n\tbut we got\n\t\t[");

    /* Print received outputs */
    for(int i = 0; i < n1; i++)
    {
      printf(" %d", small_profits[i]);
      if((i+1)%15 == 0)
        printf("\n\t\t ");
    }
    printf("], and\n\t\t[");
    for(int i = 0; i < n1; i++)
    {
      printf(" %d", large_profits[i]);
      if((i+1)%15 == 0)
        printf("\n\t\t ");
    }
    printf("].\n");
  }

  /********* Test 5: List length 1 *********/
  double epsilon5 = 0.01;
  return_val = SUCCESS;

  /* Set up instance */
  int profits5[] = { 94};
  int weights5[] = {485};
  int n5 = 1;
  int capacity5 = 485;
  int lower_bound5 = 94;

  for(int i = 0; i < n5; i++)
    small_profits[i] = small_weights[i] = 0;

  for(int i = 0; i < n5; i++)
    large_profits[i] = large_weights[i] = 0;

  int expected_large5[] = {94};
  int expected_small5[] = {};

  /* Run algorithm */
  small_large_split(profits5, weights5, n5, capacity5, epsilon5, lower_bound5, 
                    small_profits, large_profits, small_weights, large_weights,
                    &n_large);

  /* Check that small was right */
  for(int i = 0; i < n5; i++)
  {
    if(small_profits[i] != 0 && small_profits[i] != -1)
    {
      printf("Something wrong with small_profits[%d]: %d!\n", i,
               small_profits[i]);
      return_val = FAILURE;
      suite_return_val = FAILURE;
      break;
    }
  }
  if(!is_in(-1, small_profits, n5))
  {
      printf("\tSmall doesn't have a -1!\n");
      return_val = FAILURE;
      suite_return_val = FAILURE;
  }

  /* Check that large was right */
  for(int i = 0; i < n5; i++)
  {
    if(!is_in(expected_large5[i], large_profits, n5))
    {
      return_val = FAILURE;
      suite_return_val = FAILURE;
      break;
    }
  }
  if(is_in(-1, large_profits, n5))
  {
      printf("\tLarge has a -1!\n");
      return_val = FAILURE;
      suite_return_val = FAILURE;
  }

  /* If we failed, print the arrays */
  if(return_val == FAILURE)
  {
    /* Print expected outputs */
    printf("\tTest 5 failure: expected\n\t\t[");
    for(int i = 0; i < 0; i++)
    {
      printf(" %d", expected_small5[i]);
      if((i+1)%15 == 0)
        printf("\n\t\t ");
    }
    printf("], and\n\t\t[");
    for(int i = 0; i < n5; i++)
    {
      printf(" %d", expected_large5[i]);
      if((i+1)%15 == 0)
        printf("\n\t\t ");
    }
    printf("],\n\tbut we got\n\t\t[");

    /* Print received outputs */
    for(int i = 0; i < n1; i++)
    {
      printf(" %d", small_profits[i]);
      if((i+1)%15 == 0)
        printf("\n\t\t ");
    }
    printf("], and\n\t\t[");
    for(int i = 0; i < n1; i++)
    {
      printf(" %d", large_profits[i]);
      if((i+1)%15 == 0)
        printf("\n\t\t ");
    }
    printf("].\n");
  }
  
  /********* Test 6: List length 0 *********/
  double epsilon6 = 0.05;
  return_val = SUCCESS;

  /* Set up instance */
  int profits6[] = { };
  int weights6[] = {};
  int n6 = 0;
  int capacity6 = 0;
  int lower_bound6 = 0;

  for(int i = 0; i < n1; i++)
    small_profits[i] = small_weights[i] = 0;

  for(int i = 0; i < n1; i++)
    large_profits[i] = large_weights[i] = 0;

  int expected_large6[] = {};
  int expected_small6[] = {};

  /* Run algorithm */
  small_large_split(profits6, weights6, n6, capacity6, epsilon6, lower_bound6, 
                    small_profits, large_profits, small_weights, large_weights,
                    &n_large);

  /* Check that small was right (all 50 slots should be empty) */
  for(int i = 0; i < 50; i++)
  {
    if(small_profits[i] != 0)
    {
      return_val = FAILURE; 
      suite_return_val = FAILURE;
    }
  }

  /* Check that large was right */
  for(int i = 0; i < 50; i++)
  {
    if(large_profits[i] != 0)
    {
      return_val = FAILURE; 
      suite_return_val = FAILURE;
    }
  }
  

  /* If we failed, print the arrays */
  if(return_val == FAILURE)
  {
    /* Print expected outputs */
    printf("\tTest 6 failure: expected\n\t\t[");
    printf("], and\n\t\t[");
    printf("],\n\tbut we got\n\t\t[");

    /* Print received outputs */
    for(int i = 0; i < n1; i++)
    {
      printf(" %d", small_profits[i]);
      if((i+1)%15 == 0)
        printf("\n\t\t ");
    }
    printf("], and\n\t\t[");
    for(int i = 0; i < n1; i++)
    {
      printf(" %d", large_profits[i]);
      if((i+1)%15 == 0)
        printf("\n\t\t ");
    }
    printf("].\n");
  }


  if(suite_return_val == SUCCESS)
    printf("\tAll passed! \n");

  
  
}

int is_in(int value, int arr[], int arr_len)
{
 /* Returns true if value is in arr, false otherwise */
  int found = FALSE;

  for(int i = 0; i < arr_len; i++)
    if(arr[i] == value)
      found = TRUE;
  
  return found;
}

void test_partition_large_set(void)
{
 /* One thing to note about testing this: z^l and eps are just values,
     i.e. we should be able to just correctly make the index list. This
     functionality is sort of independent of an instance's profits */ 
 /* Apparently the output of this is an array where each index i has the index
     of the first profit in i*z^l*eps */ 

  printf("Running test_parition_large_set\n");
  int suite_status = SUCCESS;

  /********* Test 1: Basic #1 *********/
  int status = SUCCESS;
  /* Inputs */
  int input_profits1[] = {20, 30,  5, 25, 50};
  int input_weights1[] = { 1,  2,  3,  4,  5};
  int n1 = 5;
  int indices_out1[n1];
  double epsilon1 = 0.2;
  int lower_bound1 = 55;

  /* Expected output */
  int expected_interval_indices1[] = {0, 1, 2, 2, 4};
  
  /* Run algorithm */
  partition_large_set(input_profits1, input_weights1, n1, epsilon1, 
                      lower_bound1, indices_out1);

  /* Check how we went */
  for(int i = 0; i < n1; i++)
  {
    if (indices_out1[i] != expected_interval_indices1[i])
    {
      status = FAILURE;
      suite_status = FAILURE;
    }
  }

  /* Print errors, if any */
  if (status == FAILURE)
  {
    printf("\tTest 1 failed. Expected [");
    for(int i = 0; i < n1; i++)
      printf("%d%s", expected_interval_indices1[i], 
                     i == n1-1 ? "], got\n\t\t[" : ", ");
    for(int i = 0; i < n1; i++)
      printf("%d%s", indices_out1[i], i == n1-1 ? "]\n" : ", ");
  }
  

  /********* Test 2: Basic #2 *********/
  status = SUCCESS;
  int input_profits2[] = {200, 700, 1239, 650, 650, 0, 813, 1154, 1239};
  int input_weights2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int n2 = 9;
  int indices_out2[n2];
  double epsilon2 = 0.001;
  int lower_bound2 = 1500;

  /* Expected output */
  // 0 200 650 650 700 813 1154 1239 1239 
  int expected_interval_indices2[] = {0, 133, 433, 433, 466, 541, 769, 825, 825};

  /* Run algorithm */
  partition_large_set(input_profits2, input_weights2, n2, epsilon2, lower_bound2,
                      indices_out2);

  /* Check how we went */
  for(int i = 0; i < n2; i++)
  {
    if (indices_out2[i] != expected_interval_indices2[i])
    {
      status = FAILURE;
      suite_status = FAILURE;
    }
  }
  
  /* Print errors, if any */
  if (status == FAILURE)
  {
    printf("\tTest 2 failed. Expected [");
    for(int i = 0; i < n2; i++)
      printf("%d%s", expected_interval_indices2[i], 
                     i == n2-1 ? "], got\n\t\t[" : ", ");
    for(int i = 0; i < n2; i++)
      printf("%d%s", indices_out2[i], i == n2-1 ? "]\n" : ", ");
  }

  /********* Test 3: Weird (everything in first index) *********/
  status = SUCCESS;
  int input_profits3[] = {21, 20, 23, 22, 25, 24};
  int input_weights3[] = {1, 2, 3, 4, 5, 6};
  int n3 = 6;
  int indices_out3[n3];
  double epsilon3 = 0.9;
  int lower_bound3 = 100;

  /* Expected output */
  int expected_interval_indices3[] = {0, 0, 0, 0, 0, 0};
  
  /* Run algorithm */
  partition_large_set(input_profits3, input_weights3, n3, epsilon3, lower_bound3,
                      indices_out3);

  /* Check how we went */
  for(int i = 0; i < n3; i++)
  {
    if (indices_out3[i] != expected_interval_indices3[i])
    {
      status = FAILURE;
      suite_status = FAILURE;
    }
  }

  /* Print errors, if any */
  if (status == FAILURE)
  {
    printf("\tTest 3 failed. Expected [");
    for(int i = 0; i < n3; i++)
      printf("%d%s", expected_interval_indices3[i], 
                     i == n3-1 ? "], got\n\t\t[" : ", ");
    for(int i = 0; i < n3; i++)
      printf("%d%s", indices_out3[i], i == n3-1 ? "]\n" : ", ");
  }

  /********* Test 4: Weird (everything in one general index) *********/
  status = SUCCESS;
  int input_profits4[] = {21, 20, 23, 22, 25, 24};
  int input_weights4[] = {1, 2, 3, 4, 5, 6};
  int n4 = 6;
  int indices_out4[n4];
  double epsilon4 = 0.9;
  int lower_bound4 = 10;

  /* Expected output */
  int expected_interval_indices4[] = {2, 2, 2, 2, 2, 2};
  
  /* Run algorithm */
  partition_large_set(input_profits4, input_weights4, n4, epsilon4, lower_bound4,
                      indices_out4);

  /* Check how we went */
  for(int i = 0; i < n4; i++)
  {
    if (indices_out4[i] != expected_interval_indices4[i])
    {
      status = FAILURE;
      suite_status = FAILURE;
    }
  }

  /* Print errors, if any */
  if (status == FAILURE)
  {
    printf("\tTest 4 failed. Expected [");
    for(int i = 0; i < n4; i++)
      printf("%d%s", expected_interval_indices4[i], 
                     i == n4-1 ? "], got\n\t\t[" : ", ");
    for(int i = 0; i < n4; i++)
      printf("%d%s", indices_out4[i], i == n4-1 ? "]\n" : ", ");
  }

  /********* Test 5: List length 1 *********/
  status = SUCCESS;
  int input_profits5[] = {5};
  int input_weights5[] = {1};
  int n5 = 1;
  int indices_out5[n5];
  double epsilon5 = 0.675;
  int lower_bound5 = 5;

  /* Expected output */
  int expected_interval_indices5[] = {1};

  /* Run algorithm */
  partition_large_set(input_profits5, input_weights5, n5, epsilon5, lower_bound5,
                      indices_out5);

  /* Check how we went */
  for(int i = 0; i < n5; i++)
  {
    if (indices_out5[i] != expected_interval_indices5[i])
    {
      status = FAILURE;
      suite_status = FAILURE;
    }
  }

  /* Print errors, if any */
  if (status == FAILURE)
  {
    printf("\tTest 5 failed. Expected [");
    for(int i = 0; i < n5; i++)
      printf("%d%s", expected_interval_indices5[i], 
                     i == n5-1 ? "], got\n\t\t[" : ", ");
    for(int i = 0; i < n5; i++)
      printf("%d%s", indices_out5[i], i == n5-1 ? "]\n" : ", ");
  }

  /********* Test 6: List length 0 *********/
  status = SUCCESS;
  int input_profits6[] = {};
  int input_weights6[] = {};
  int n6 = 0;
  int indices_out6[n6];
  double epsilon6 = 0.123;
  int lower_bound6 = 0;

  /* Expected output */
  int expected_interval_indices6[] = {};

  /* Run algorithm */
  partition_large_set(input_profits6, input_weights6, n6, epsilon6, lower_bound6,
                      indices_out6);

  /* Check how we went */
  for(int i = 0; i < n6; i++)
  {
    if (indices_out6[i] != expected_interval_indices6[i])
    {
      status = FAILURE;
      suite_status = FAILURE;
    }
  }
  
  /* Print errors, if any */
  if (status == FAILURE)
  {
    printf("\tTest 6 failed. Expected [");
    for(int i = 0; i < n6; i++)
      printf("%d%s", expected_interval_indices6[i], 
                     i == n6-1 ? "], got\n[" : ", ");
    for(int i = 0; i < n6; i++)
      printf("%d%s", indices_out6[i], i == n6-1 ? "]\n" : ", ");
  }

  if (suite_status == SUCCESS)
    printf("\tEverything passed!\n");
}

void test_partition_interval(void)
{
 /* Virtually the same as partition_large_set, we get a bunch of profits which 
    are in intervals, and derive a second index for them indicating which
    subinterval that they are in */
  printf("Running test_paritition_interval\n");
  int suite_status = SUCCESS;
  /* Test 1 */
  int status = SUCCESS;
  double epsilon1 = 0.2;
  int lowerbound1 = 50;
  int n1 = 13;
  int profits1[] = {11, 12, 15, 15, 16, 17, 18, 20, 28, 41, 45, 48, 49};
  int intervals1[] = { 1,  1,  1,  1,  1,  1,  1,  1,  2,  4,  4,  4,  4};
  int expected_subintervals1[] = 
    { 1,  1,  3,  3,  3,  4,  4,  5,  2,  1,  1,  1,  2};
  int indices_out1[n1];

  /* Run the algorithm */
  partition_interval(profits1, n1, epsilon1, lowerbound1, intervals1, 
                     indices_out1);

  /* Make sure it worked */
  for(int i = 0; i < n1; i++)
  {
    if (indices_out1[i] != expected_subintervals1[i])
    {
      status = FAILURE;
      suite_status = FAILURE;
    }
  }

  /* Log values to terminal */
  if(status == FAILURE)
  {
    printf("\tTest 1 failed! Expected\n\t[");
    for(int i = 0; i < n1; i++)
    {
      printf("%d%s", expected_subintervals1[i], i == n1-1 ? "]\n\t" : ", ");
      if (i%5 == 0 && i != 0)
        printf("\n\t");
    }
    printf(" but got\n\t[");
    for(int i = 0; i < n1; i++)
    {
      printf("%d%s", indices_out1[i], i == n1-1 ? "]\n" : ", ");
      if (i%5 == 0 && i != 0)
        printf("\n\t");
    }
  }

  
  /* Test 2 */
  status = SUCCESS;
  double epsilon2 = 0.25;
  int lowerbound2 = 143;  
  int n2 = 5;
  int profits2[] = {45, 65, 94, 134, 143};
  int intervals2[] = {1, 1, 2, 3, 3};
  int expected_subintervals2[] = {2, 4, 2, 1, 2};
  int indices_out2[n2];

  /* Run the algorithm */
  partition_interval(profits2, n2, epsilon2, lowerbound2, intervals2, 
                     indices_out2);

  /* Make sure it worked */
  for(int i = 0; i < n2; i++)
  {
    if (indices_out2[i] != expected_subintervals2[i])
    {
      status = FAILURE;
      suite_status = FAILURE;
    }
  }
  
  /* Log values to terminal */
  if(status == FAILURE)
  {
    printf("\tTest 2 failed! Expected\n\t[");
    for(int i = 0; i < n2; i++)
    {
      printf("%d%s", expected_subintervals2[i], i == n2-1 ? "]\n\t" : ", ");
      if (i%5 == 0 && i != 0)
        printf("\n\t");
    }
    printf(" but got\n\t[");
    for(int i = 0; i < n2; i++)
    {
      printf("%d%s", indices_out2[i], i == n2-1 ? "]\n" : ", ");
      if (i%5 == 0 && i != 0)
        printf("\n\t");
    }
  }

  /* Test 3 */
  status = SUCCESS;
  double epsilon3 = 1.0/3.0;
  int lowerbound3 = 16540;
  int n3 = 1;
  int profits3[] = {13456};
  int intervals3[] = {2};
  int expected_subintervals3[] = {1};
  int indices_out3[n3];

  /* Run the algorithm */
  partition_interval(profits3, n3, epsilon3, lowerbound3, intervals3, 
                     indices_out3);

  /* Make sure it worked */
  for(int i = 0; i < n3; i++)
  {
    if (indices_out3[i] != expected_subintervals3[i])
    {
      status = FAILURE;
      suite_status = FAILURE;
    }
  }

  /* Log values to terminal */
  if(status == FAILURE)
  {
    printf("\tTest 3 failed! Expected\n\t[");
    for(int i = 0; i < n3; i++)
    {
      printf("%d%s", expected_subintervals3[i], i == n3-1 ? "]\n\t" : ", ");
      if (i%15 == 0 && i != 0)
        printf("\n\t");
    }
    printf(" but got\n\t[");
    for(int i = 0; i < n3; i++)
    {
      printf("%d%s", indices_out3[i], i == n3-1 ? "]\n" : ", ");
      if (i%15 == 0 && i != 0)
        printf("\n\t");
    }
  }

  if(suite_status == SUCCESS)
    printf("\tAll passed!\n");

}

void test_reduce_profits_to_minimal(void)
{
  /* Given a set of profits, their interval indices, and their subinterval
      indices, set all the profits to their respective subinterval lowerbound */ 
  printf("Running test_reduce_profits_to_minimal\n");
  int suite_status = SUCCESS;
  int status = SUCCESS;
  double epsilon1 = 0.2;
  int lowerbound1 = 50;
  int n1 = 13;
  int profits1[] = {11, 12, 15, 15, 16, 17, 18, 20, 28, 41, 45, 48, 49};
  int intervals1[] = { 1,  1,  1,  1,  1,  1,  1,  1,  2,  4,  4,  4,  4};
  int subintervals1[] = 
    { 1,  1,  3,  3,  3,  4,  4,  5,  2,  1,  1,  1,  2};

  int expected_profits1[] = {10, 10, 14, 14, 14, 16, 16, 18, 24, 40, 40, 40, 48 };

  /* Run the algorithm */
  reduce_profits_to_minimal(profits1, intervals1, subintervals1, epsilon1, 
                            lowerbound1, n1); 
  
  /* Check if it's right */
  for (int i = 0; i < n1; i++)
  {
    if (profits1[i] != expected_profits1[i])
    {
      status = FAILURE;
      suite_status = FAILURE;
    }
  }

  /* Log values to terminal if we failed */
  if(status == FAILURE)
  {
    printf("\tTest 1 failed! Expected\n\t[");
    for(int i = 0; i < n1; i++)
    {
      printf("%d%s", expected_profits1[i], i == n1-1 ? "]\n\t" : ", ");
      if (i%15 == 0 && i != 0)
        printf("\n\t");
    }
    printf(" but got\n\t[");
    for(int i = 0; i < n1; i++)
    {
      printf("%d%s", profits1[i], i == n1-1 ? "]\n" : ", ");
      if (i%15 == 0 && i != 0)
        printf("\n\t");
    }
  }
  
  /*Test 2*/
  status = SUCCESS;
  double epsilon2 = 0.25;
  int lowerbound2 = 143;  
  int n2 = 4;
  int profits2[] = {45, 65, 94, 134};
  int intervals2[] = {1, 1, 2, 3};
  int subintervals2[] = {2, 4, 2, 1};
  int expected_profits2[] = {44, 62, 89, 107};

  /* Run the algorithm */
  reduce_profits_to_minimal(profits2, intervals2, subintervals2, epsilon2, 
                            lowerbound2, n2); 

  /* Check if it's right */
  for (int i = 0; i < n2; i++)
  {
    if (profits2[i] != expected_profits2[i])
    {
      status = FAILURE;
      suite_status = FAILURE;
    }
  }

  /* Log values to terminal if we failed */
  if(status == FAILURE)
  {
    printf("\tTest 2 failed! Expected\n\t[");
    for(int i = 0; i < n2; i++)
    {
      printf("%d%s", expected_profits2[i], i == n2-1 ? "]\n\t" : ", ");
      if (i%15 == 0 && i != 0)
        printf("\n\t");
    }
    printf(" but got\n\t[");
    for(int i = 0; i < n2; i++)
    {
      printf("%d%s", profits2[i], i == n2-1 ? "]\n" : ", ");
      if (i%15 == 0 && i != 0)
        printf("\n\t");
    }
  }
  
  /*Test 3*/
  status = SUCCESS;
  double epsilon3 = 1.0/3.0;
  int lowerbound3 = 16540;
  int n3 = 1;
  int profits3[] = {13456};
  int intervals3[] = {2};
  int subintervals3[] = {1};
  int expected_profits3[] = {11026};

  /* Run the algorithm */
  reduce_profits_to_minimal(profits3, intervals3, subintervals3, epsilon3, 
                            lowerbound3, n3); 

  /* Check if it's right */
  for (int i = 0; i < n3; i++)
  {
    if (profits3[i] != expected_profits3[i])
    {
      status = FAILURE;
      suite_status = FAILURE;
    }
  }

  /* Log values to terminal if we failed */
  if(status == FAILURE)
  {
    printf("\tTest 3 failed! Expected\n\t[");
    for(int i = 0; i < n3; i++)
    {
      printf("%d%s", expected_profits3[i], i == n3-1 ? "]\n\t" : ", ");
      if (i%15 == 0 && i != 0)
        printf("\n\t");
    }
    printf(" but got\n\t[");
    for(int i = 0; i < n3; i++)
    {
      printf("%d%s", profits3[i], i == n3-1 ? "]\n" : ", ");
      if (i%15 == 0 && i != 0)
        printf("\n\t");
    }
  }

  if(suite_status == SUCCESS)
    printf("\tAll passed!\n");
}


void test_prune_excess_weight_items(void)
{
  /* Given a set of profits in subintervals with each profit reduced to minimal
`     profit, symbolically prune everything after the first ceil(2/e*epsilon)
      items with minimal weight */
  /* The weights won't necessarily be in any sorted order (we only sorted by
      profits), so prune_excess_weight-items will be expected to sort and set
      the items to profit and weight 0 */
  
  printf("Running test_small_large_split...\n");
  int suite_status = SUCCESS;
  int status;
  
  /* Test 1: only clearing those in the first subinterval */
  /* Everything after ceil(2/i*eps) = ceil(2/1*0.2) = 10 is not considered, 
     just incase, lower_bound was 984 */
  /*
  status = SUCCESS;
  int profits1[] = {196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196,
                     275, 314, 551, 551};
  int weights1[] = {12, 46, 81, 32, 15, 84, 52, 64, 21, 32, 16, 80, 101, 101,
                     101, 101 };
  int intervals1[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2 };
  int subintervals1[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 5, 1};
  int n1 = 16;
  int current_i1 = 1;
  int current_k1 = 1;
  double epsilon1 = 0.2;

  
  prune_excess_weight_items(profits1, weights1, intervals1, subintervals1,
                            current_i1, current_k1, epsilon1, n1);

  int expected_profits1[] = {196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 
                             0, 0, 275, 314, 551, 551};
  int expected_weights1[] = {12, 15, 16, 21, 32, 32, 46, 52, 64, 80, 0, 0,
                             101, 101, 101, 101}; 
  */
  /* Check expected outputs */  
  /*
  for(int i = 0; i < n1; i++)
  {
    if(profits1[i] != expected_profits1[i] || weights1[i] != expected_weights1[i])
    {
      suite_status = FAILURE;
      status = FAILURE;
    }
  }
  */

  /* Log errors */
  /*
  if(status == FAILURE)
  {
    printf("\tTest 1 failed! Expected\n\t[");
    for(int i = 0; i < n1; i++)
      printf("%d%s", expected_profits1[i], i < n1-1 ? ", " : "]\n" );
    printf("\tBut we got\n\t[");
    for(int i = 0; i < n1; i++)
      printf("%d%s", profits1[i], i < n1-1 ? ", " : "]\n" );
    printf("\tand weights;\n\t[");
    for(int i = 0; i < n1; i++)
      printf("%d%s", expected_weights1[i], i < n1-1 ? ", " : "]\n");
    printf("\tBut we got\n\t[");
    for(int i = 0; i < n1; i++)
      printf("%d%s", weights1[i], i < n1-1 ? ", " : "]\n");
  }
  */
  /* Test 2: Some intermediary subinterval is considered */
  /* Everything after ceil(2/i*eps) = ceil(2/(3*(1/6) = 4 is not considered */
  /*
    lower_bound = 81543, (modified) epsilon = 0.166667
    Interval #1: (13590, 27181]
      Subinterval #1: (13590, 15855]
      Subinterval #2: (15855, 18120]
      Subinterval #3: (18120, 20385]
      Subinterval #4: (20385, 22650]
      Subinterval #5: (22650, 24915]
      Subinterval #6: (24915, 27181]
    Interval #2: (27181, 40771]
      Subinterval #1: (27181, 31711]
      Subinterval #2: (31711, 36241]
      Subinterval #3: (36241, 40771]
    Interval #3: (40771, 54362]**
      Subinterval #1: (40771, 47566]
      Subinterval #2: (47566, 54362]
    Interval #4: (54362, 67952]
      Subinterval #1: (54362, 63422]
      Subinterval #2: (63422, 67952]
    Interval #5: (67952, 81543]
      Subinterval #1: (67952, 79277]
      Subinterval #2: (79277, 81543]
  */
  /*
  status = SUCCESS;
  int profits2[] = {15855, 15855, 20385, 20385, 20385, 24915, 31711, 31711,
                    31711, 31711, 31711, 31711, 0, 0, 47566, 47566, 47566, 
                    47566, 67952, 79277};
  int weights2[] = 
                  {1, 1, 2, 2, 2, 3, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 6, 7, 8};
  int intervals2[] =  
                  {1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 5, 5};
  int subintervals2[] =
                  {2, 2, 4, 4, 4, 6, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 1, 2};
  int n2 = 20;
  int current_i2 = 3;
  int current_k2 = 2;
  double epsilon2 = 1.0/6.0;

  prune_excess_weight_items(profits2, weights2, intervals2, subintervals2,
                            current_i2, current_k2, epsilon2, n2);

  int expected_profits2[] = {15855, 15855, 20385, 20385, 20385, 24915, 31711, 
                            31711, 31711, 31711, 31711, 31711, 0, 0, 47566, 
                            47566, 47566, 47566, 67952, 79277};
  int expected_weights2[] = 
                  {1, 1, 2, 2, 2, 3, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 6, 7, 8};

  */
  /* Check expected outputs */  
  /*
  for(int i = 0; i < n2; i++)
  {
    if(profits2[i] != expected_profits2[i] || weights2[i] != expected_weights2[i])
    {
      suite_status = FAILURE;
      status = FAILURE;
    }
  }
  */

  /* Log errors */
  /*
  if(status == FAILURE)
  {
    printf("\tTest 2 failed! Expected\n\t[");
    for(int i = 0; i < n2; i++)
      printf("%d%s", expected_profits2[i], i < n2-1 ? ", " : "]\n");
    printf("\tBut we got\n\t[");
    for(int i = 0; i < n2; i++)
      printf("%d%s", profits2[i], i < n2-1 ? ", " : "]\n" );
    printf("\tand weights;\n\t[");
    for(int i = 0; i < n2; i++)
      printf("%d%s", expected_weights2[i], i < n2-1 ? ", " : "]\n" );
    printf("\tBut we got\n\t[");
    for(int i = 0; i < n2; i++)
      printf("%d%s", weights2[i], i < n2-1 ? ", " : "]\n" );
  }
  */
  /* Test 3: */
  /* Everything after ceil(2/i*eps) = 3 is not considered */
  /*
  Interval #1: (104, 209]
    Subinterval #1: (104, 139]
    Subinterval #2: (139, 174]
    Subinterval #3: (174, 209]
  Interval #2: (209, 314]
    Subinterval #1: (209, 279]
    Subinterval #2: (279, 314]
  */
  status = SUCCESS;
  int profits3[] = {104, 104, 104, 0, 0, 0, 174, 174, 279, 279, 279, 279, 279};
  int weights3[] =      {1, 1, 1, 1, 1, 1, 2, 2, 3, 3, 3, 3, 3};
  int intervals3[] =    {1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2};
  int subintervals3[] = {1, 1, 1, 1, 1, 1, 3, 3, 2, 2, 2, 2, 2};
  int n3 = 13;
  int current_i3 = 2;
  int current_k3 = 2;
  double epsilon3 = 1.0/3.0;

  prune_excess_weight_items(profits3, weights3, intervals3, subintervals3,
                            current_i3, current_k3, epsilon3, n3);

  int expected_profits3[] = {104, 104, 104, 0, 0, 0, 174, 174, 279, 279, 279, 0,
                             0};
  int expected_weights3[] = {1, 1, 1, 1, 1, 1, 2, 2, 3, 3, 3, 0, 0};

  /* Check expected outputs */  
  for(int i = 0; i < n3; i++)
  {
    if(profits3[i] != expected_profits3[i] || weights3[i] != expected_weights3[i])
    {
      suite_status = FAILURE;
      status = FAILURE;
    }
  }

  /* Log errors */
  if(status == FAILURE)
  {
    printf("\tTest 3 failed! Expected\n\t[");
    for(int i = 0; i < n3; i++)
      printf("%d%s", expected_profits3[i], i < n3-1 ? ", " : "]\n" );
    printf("\tBut we got\n\t[");
    for(int i = 0; i < n3; i++)
      printf("%d%s", profits3[i], i < n3-1 ? ", " : "]\n" );
    printf("\tand weights;\n\t[");
    for(int i = 0; i < n3; i++)
      printf("%d%s", expected_weights3[i], i < n3-1 ? ", " : "]\n");
    printf("\tBut we got\n\t[");
    for(int i = 0; i < n3; i++)
      printf("%d%s", weights3[i], i < n3-1 ? ", " :  "]\n");
  }

  if(suite_status == SUCCESS)
    printf("\tAll passed!\n");

}

void test_redefine_large_set(void)
{
  /* Check that the pointers that originally pointed to an array of profits and
     weights with 0 profit and 0 weight items have been updated to ones without
     such cases */
  printf("Running test_redefine_large_set...\n");
  int suite_status = SUCCESS;
  int status;
  
  /*******************************************/
  /* Test 1: z_lower = 34, epsilon = 1.0/3.0 */
  /*      Cutoff for first interval is 3     */
  /*     Cutoff for second interval is 2     */
  /*                                         */
  /*        Interval #1: (11, 22]            */
  /*          Subinterval #1: (11, 15]       */
  /*          Subinterval #2: (15, 18]       */
  /*          Subinterval #3: (18, 22]       */
  /*        Interval #2: (22, 34]            */
  /*          Subinterval #1: (22, 30]       */
  /*          Subinterval #2: (30, 34]       */
  /*                                         */
  /*******************************************/
  
  /* Initialise variables */
  status = SUCCESS;
  int profits1[] = {11, 11, 11, 0, 0, 0, 15, 15, 15, 0, 18, 18, 18, 0, 0, 22,
                     22, 0, 0, 30, 30, 0, 0, 0 };
  int weights1[] = {1, 1, 1, 0, 0, 0, 2, 2, 2, 0, 3, 3, 3, 0, 0, 4, 4, 0, 0, 5,
                     5, 0, 0, 0};
  int intervals1[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2,
                       2, 2, 2, 2};
  int subintervals1[] = {1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 1, 1, 1,
                          1, 2, 2, 2, 2, 2, 2};
  int n1 = 24;
  int new_n1 = -1;

  int expected_profits1[] = {11, 11, 11, 15, 15, 15, 18, 18, 18, 22, 22, 30, 30};
  int expected_intervals1[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2};
  int expected_subintervals1[] = {1, 1, 1, 2, 2, 2, 3, 3, 3, 1, 1, 2, 2};
  int expected_weights1[] = {1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 5, 5};
  int expected_new_n1 = 13;
  
  /* Run algorithm */
  redefine_large_set(profits1, weights1, intervals1, subintervals1, n1, 
                     &new_n1);
  
  /* TODO FIX INDEXING HERE */
  /* Evaluate results */
  
  for(int i = 0; i < expected_new_n1; i++)
  {
    if(profits1[i] != expected_profits1[i]
      || weights1[i] != expected_weights1[i]
      || intervals1[i] != expected_intervals1[i]
      || subintervals1[i] != expected_subintervals1[i])
    {
      status = FAILURE;
      suite_status = FAILURE;
      break;
    }
  }

  /* Print errors, if applicable */
  if(status == FAILURE)
  {
    printf("\tTest 1 failed! Expected:\n\tprofits:\n\t\[");
    for(int i = 0; i < expected_new_n1; i++)
    {
      printf("%d%s", expected_profits1[i], i == expected_new_n1-1 ? "]\n\t" : ", ");
      if (i%5 == 0 && i != 0)
        printf("\n\t");
    }
    printf("weights:\n\t[");
    for(int i = 0; i < expected_new_n1; i++)
    {
      printf("%d%s", expected_weights1[i], i == expected_new_n1-1 ? "]\n\t" : ", ");
      if (i%5 == 0 && i != 0)
        printf("\n\t");
    }
    printf("intervals:\n\t[");
    for(int i = 0; i < expected_new_n1; i++)
    {
      printf("%d%s", expected_intervals1[i], i == expected_new_n1-1 ? "]\n\t" : ", ");
      if (i%5 == 0 && i != 0)
        printf("\n\t");
    }
    printf("subintervals:\n\t[");
    for(int i = 0; i < expected_new_n1; i++)
    {
      printf("%d%s", expected_subintervals1[i], i == expected_new_n1-1 ? "]\n\t" : ", ");
      if (i%5 == 0 && i != 0)
        printf("\n\t");
    }
    printf("new_n: %d\n", expected_new_n1);

    printf("\n\tBut we got:\n\tprofits:\n\t\[");
    for(int i = 0; i < n1; i++)
    {
      printf("%d%s", profits1[i], i == n1-1 ? "]\n\t" : ", ");
      if (i%5 == 0 && i != 0)
        printf("\n\t");
    }
    printf("weights:\n\t[");
    for(int i = 0; i < n1; i++)
    {
      printf("%d%s", weights1[i], i == n1-1 ? "]\n\t" : ", ");
      if (i%5 == 0 && i != 0)
        printf("\n\t");
    }
    printf("intervals:\n\t[");
    for(int i = 0; i < n1; i++)
    {
      printf("%d%s", intervals1[i], i == n1-1 ? "]\n\t" : ", ");
      if (i%5 == 0 && i != 0)
        printf("\n\t");
    }
    printf("subintervals:\n\t[");
    for(int i = 0; i < n1; i++)
    {
      printf("%d%s", subintervals1[i], i == n1-1 ? "]\n\t" : ", ");
      if (i%5 == 0 && i != 0)
        printf("\n\t");
    }
    printf("new_n: %d\n\n", new_n1);
  }


  /*******************************************/
  /* Test 2: z_lower = 651, epsilon = 0.2    */
  /*      Cutoff for first interval is 5     */
  /*     Cutoff for second interval is 3     */
  /*      Cutoff for third interval is 2     */
  /*      Cutoff for forth interval is 2     */
  /*                                         */
  /*        Interval #1: (130, 260]          */
  /*          Subinterval #1: (130, 156]     */
  /*          Subinterval #2: (156, 182]     */
  /*          Subinterval #3: (182, 208]     */
  /*          Subinterval #4: (208, 234]     */
  /*          Subinterval #5: (234, 260]     */
  /*        Interval #2: (260, 390]          */
  /*          Subinterval #1: (260, 312]     */
  /*          Subinterval #2: (312, 364]     */
  /*          Subinterval #3: (364, 390]     */
  /*        Interval #3: (390, 520]          */
  /*          Subinterval #1: (390, 468]     */
  /*          Subinterval #2: (468, 520]     */
  /*        Interval #4: (520, 651]       i  */
  /*          Subinterval #1: (520, 624]     */
  /*          Subinterval #2: (624, 651]     */
  /*                                         */
  /*******************************************/

  /* Initialise variables */
  status = SUCCESS;
  int profits2[] = {130, 130, 130, 182, 182, 182, 182, 182, 0, 234, 312, 312, 
                     312, 0, 390, 390, 468, 520, 624};
  int intervals2[] = 
                {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 4, 4};
  int subintervals2[] = 
                {1, 1, 1, 3, 3, 3, 3, 3, 3, 5, 2, 2, 2, 2, 1, 1, 2, 1, 2};
  int weights2[] =
                {1, 1, 1, 2, 2, 2, 2, 2, 0, 3, 4, 4, 4, 0, 5, 5, 6, 7, 8};
  int n2 = 19;
  int new_n2 = -1;
  
  int expected_profits2[] = 
                {130, 130, 130, 182, 182, 182, 182, 182, 234, 312, 
                             312, 312, 390, 390, 468, 520, 624 };
  int expected_weights2[] = 
                {1, 1, 1, 2, 2, 2, 2, 2, 3, 4, 4, 4, 5, 5, 6, 7, 8};
  int expected_intervals2[] = 
                {1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4};
  int expected_subintervals2[] =
                {1, 1, 1, 3, 3, 3, 3, 3, 5, 2, 2, 2, 1, 1, 2, 1, 2};
  int expected_new_n2 = 17;

  /* Run algorithm */
  redefine_large_set(profits2, weights2, intervals2, subintervals2, n2, &new_n2);
  
  /* Evaluate results */
  for(int i = 0; i < expected_new_n2; i++)
  {
    if(profits2[i] != expected_profits2[i]
      || weights2[i] != expected_weights2[i]
      || intervals2[i] != expected_intervals2[i]
      || subintervals2[i] != expected_subintervals2[i])
    {
      status = FAILURE;
      suite_status = FAILURE;
      break;
    }
  }

  /* Print errors, if applicable */
  if(status == FAILURE)
  {
    printf("\tTest 2 failed! Expected:\n\tprofits:\n\t\[");
    for(int i = 0; i < expected_new_n2; i++)
    {
      printf("%d%s", expected_profits2[i], i == expected_new_n2-1 ? "]\n\t" : ", ");
      if (i%5 == 0 && i != 0)
        printf("\n\t");
    }
    printf("weights:\n\t[");
    for(int i = 0; i < expected_new_n2; i++)
    {
      printf("%d%s", expected_weights2[i], i == expected_new_n2-1 ? "]\n\t" : ", ");
      if (i%5 == 0 && i != 0)
        printf("\n\t");
    }
    printf("intervals:\n\t[");
    for(int i = 0; i < expected_new_n2; i++)
    {
      printf("%d%s", expected_intervals2[i], i == expected_new_n2-1 ? "]\n\t" : ", ");
      if (i%5 == 0 && i != 0)
        printf("\n\t");
    }
    printf("subintervals:\n\t[");
    for(int i = 0; i < expected_new_n2; i++)
    {
      printf("%d%s", expected_subintervals2[i], i == expected_new_n2-1 ? "]\n\t" : ", ");
      if (i%5 == 0 && i != 0)
        printf("\n\t");
    }
    printf("new_n2: %d\n", expected_new_n2);

    printf("\n\tBut we got:\n\tprofits:\n\t\[");
    for(int i = 0; i < n2; i++)
    {
      printf("%d%s", profits2[i], i == n2-1 ? "]\n\t" : ", ");
      if (i%5 == 0 && i != 0)
        printf("\n\t");
    }
    printf("weights:\n\t[");
    for(int i = 0; i < n2; i++)
    {
      printf("%d%s", weights2[i], i == n2-1 ? "]\n\t" : ", ");
      if (i%5 == 0 && i != 0)
        printf("\n\t");
    }
    printf("intervals:\n\t[");
    for(int i = 0; i < n2; i++)
    {
      printf("%d%s", intervals2[i], i == n2-1 ? "]\n\t" : ", ");
      if (i%5 == 0 && i != 0)
        printf("\n\t");
    }
    printf("subintervals:\n\t[");
    for(int i = 0; i < n2; i++)
    {
      printf("%d%s", subintervals2[i], i == n2-1 ? "]\n\t" : ", ");
      if (i%5 == 0 && i != 0)
        printf("\n\t");
    }
    printf("new_n2: %d\n\n", new_n2);
  }
 
  /*******************************************/
  /* Test 3: z_lower = 984, epsilon = 0.25   */ 
  /*      Cutoff for first interval is 4     */
  /*     Cutoff for second interval is 2     */
  /*      Cutoff for third interval is 2     */
  /*                                         */
  /*  Interval #1: (246, 492]                */
  /*          Subinterval #1: (246, 307]     */
  /*          Subinterval #2: (307, 369]     */
  /*          Subinterval #3: (369, 430]     */
  /*          Subinterval #4: (430, 492]     */
  /*        Interval #2: (492, 738]          */
  /*          Subinterval #1: (492, 615]     */
  /*          Subinterval #2: (615, 738]     */
  /*        Interval #3: (738, 984]          */
  /*          Subinterval #1: (738, 922]     */
  /*          Subinterval #2: (922, 984]     */
  /*                                         */
  /*******************************************/


  /* Initialise variables */
  status = SUCCESS;
  int profits3[] = {246, 246, 246, 307, 307, 307, 307, 369, 369, 430, 615};
  int intervals3[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2};
  int subintervals3[] = {1, 1, 1, 2, 2, 2, 2, 3, 3, 4, 2};
  int weights3[] = {1, 1, 1, 2, 2, 2, 2, 3, 3, 4, 5};
  int n3 = 11;
  int new_n3 = -1;

  int expected_profits3[] = {246, 246, 246, 307, 307, 307, 307, 369, 369, 430,
                             615};
  int expected_intervals3[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2};
  int expected_subintervals3[] = {1, 1, 1, 2, 2, 2, 2, 3, 3, 4, 2};
  int expected_weights3[] = {1, 1, 1, 2, 2, 2, 2, 3, 3, 4, 5};
  int expected_new_n3 = 11;


  /* Run algorithm */
  redefine_large_set(profits3, weights3, intervals3, subintervals3, n3, 
                     &new_n3);
  
  /* Evaluate results */
  for(int i = 0; i < n3; i++)
  {
    if(profits3[i] != expected_profits3[i]
      || weights3[i] != expected_weights3[i]
      || intervals3[i] != expected_intervals3[i]
      || subintervals3[i] != expected_subintervals3[i])
    {
      status = FAILURE;
      suite_status = FAILURE;
      break;
    }
  }

  /* Print errors, if applicable */
  if(status == FAILURE)
  {
    printf("\tTest 3 failed! Expected:\n\tprofits:\n\t\[");
    for(int i = 0; i < expected_new_n3; i++)
    {
      printf("%d%s", expected_profits3[i], i == expected_new_n3-1 ? "]\n\t" : ", ");
      if (i != expected_new_n3-1 && i%5 == 0 && i != 0)
        printf("\n\t");
    }
    printf("weights:\n\t[");
    for(int i = 0; i < expected_new_n3; i++)
    {
      printf("%d%s", expected_weights3[i], i == expected_new_n3-1 ? "]\n\t" : ", ");
      if (i != expected_new_n3-1 && i%5 == 0 && i != 0)
        printf("\n\t");
    }
    printf("intervals:\n\t[");
    for(int i = 0; i < expected_new_n3; i++)
    {
      printf("%d%s", expected_intervals3[i], i == expected_new_n3-1 ? "]\n\t" : ", ");
      if (i != expected_new_n3-1 && i%5 == 0 && i != 0)
        printf("\n\t");
    }
    printf("subintervals:\n\t[");
    for(int i = 0; i < expected_new_n3; i++)
    {
      printf("%d%s", expected_subintervals3[i], i == expected_new_n3-1 ? "]\n\t" : ", ");
      if (i != expected_new_n3-1 && i%5 == 0 && i != 0)
        printf("\n\t");
    }
    printf("new_n: %d\n\n", expected_new_n3);

    printf("\tBut we got:\n\tprofits:\n\t\[");
    for(int i = 0; i < n3; i++)
    {
      printf("%d%s", profits3[i], i == n3-1 ? "]\n\t" : ", ");
      if (i != n3-1 && i%5 == 0 && i != 0)
        printf("\n\t");
    }
    printf("weights:\n\t[");
    for(int i = 0; i < n3; i++)
    {
      printf("%d%s", weights3[i], i == n3-1 ? "]\n\t" : ", ");
      if (i != n3-1 && i%5 == 0 && i != 0)
        printf("\n\t");
    }
    printf("intervals:\n\t[");
    for(int i = 0; i < n3; i++)
    {
      printf("%d%s", intervals3[i], i == n3-1 ? "]\n\t" : ", ");
      if (i != n3-1 && i%5 == 0 && i != 0)
        printf("\n\t");
    }
    printf("subintervals:\n\t[");
    for(int i = 0; i < n3; i++)
    {
      printf("%d%s", subintervals3[i], i == n3-1 ? "]\n\t" : ", ");
      if (i != n3-1 && i%5 == 0 && i != 0)
        printf("\n\t");
    }
    printf("new_n: %d\n\n", new_n3);
  }

  if(suite_status == SUCCESS)
    printf("\tAll passed!\n");
}

void test_vector_merge_naive(void)
{
  printf("Running test_vector_merge_naive");
  int suite_status = SUCCESS;
  int status;

  /*******************************************/
  /*     Test 1: Small toy example           */
  /*                                         */
  /*******************************************/
  printf("Test 1...\n");
  status = SUCCESS;
  int n = 4;
  int A[] = {0, 1, 2,  3, 4};
  int B[] = {2, 4, 8, 16, 0};
  int C[]   = {0, 0, 0, 0, 0};

  int exp_C[] = {0, 3, 4, 5, 6};  

  vector_merge_naive(A, B, C, n);

  for(int i = 0; i <= n; i++)
    if(C[i] != exp_C[i])
    {
      status = FAILURE;
      suite_status = FAILURE;
    }

  if(status == FAILURE)
  {
    printf("\tExpected:\n");  
    for(int i = 0; i <= n; i++)
      printf("%s%d%s", i == 0 ? "[" : "", exp_C[i], i == n ? "]\n" : ", ");

    printf("\tGot:\n");  
    for(int i = 0; i <= n; i++)
      printf("%s%d%s", i == 0 ? "[" : "", C[i], i == n ? "]\n" : ", ");
  }

  /*******************************************/
  /*     Test 2: Another toy example         */
  /*                                         */
  /*******************************************/
  printf("Test 2...\n");
  status = SUCCESS;
  int n2 = 6;
  int A2[] = {0, 7, 5, 9, 2, 4, 6};
  int B2[] = {15, 18, 12, 16, 17, 14, 0};
  int C2[]   = {0, 0, 0, 0, 0, 0, 0} ;

  int exp_C2[] = {0, 22, 20, 24, 17, 19, 21};

  vector_merge_naive(A2, B2, C2, n2);

  for(int i = 0; i <= n2; i++)
    if(C2[i] != exp_C2[i])
    {
      status = FAILURE;
      suite_status = FAILURE;
    }


  if(status == FAILURE)
  {
    printf("\tExpected:\n");  
    for(int i = 0; i <= n2; i++)
      printf("%s%d%s", i == 0 ? "[" : "", exp_C2[i], i == n2 ? "]\n" : ", ");

    printf("\tGot:\n");  
    for(int i = 0; i <= n2; i++)
      printf("%s%d%s", i == 0 ? "[" : "", C2[i], i == n2 ? "]\n" : ", ");

  }

  if(suite_status == SUCCESS)
  {
    printf("\tAll passed!\n");
  }
}

void test_vector_merge_interval(void)
{
  int suite_status = SUCCESS;
  int status;

  /*******************************************/
  /*  Test 1: The first toy example from     */
  /*   testing the naive method. First,      */
  /*  we run the naive algorithm, and then   */
  /*  the interval Vmerge, and compare them. */
  /*                                         */
  /*******************************************/
  printf("Test 1...\n");
  status == SUCCESS;
  int n1 = 4;
  int A1[] = {0, 1, 2,  3, 4};
  int B1[] = {2, 4, 8, 16, 0};
  int C1[]  = {0, 0, 0, 0, 0};
  int quadratic_vmerge_C1[]  = {0, 0, 0, 0, 0};

  vector_merge_naive(A1, B1, quadratic_vmerge_C1, n1);

  vector_merge_interval(A1, B1, C1, n1);

  for(int i = 0; i <= n1; i++)
  {
    if(C1[i] != quadratic_vmerge_C1[i])
    {
      suite_status = FAILURE;
      status = FAILURE;
      break;
    }
  }
  
  if(status == FAILURE)
  {
    printf("\tTest 1 failed! Expected\n\t");
    for(int i = 0; i <= n1; i++)
     printf("%s%d%s%s", i == 0 ? "[" : "", quadratic_vmerge_C1[i], 
            i == n1 ? "]\n" : ", ",
            i % 5 == 0 && i != n1 && i != 0 ? "\n\t" : "");
    printf("\tBut we got\n\t");
    for(int i = 0; i <= n1; i++)
     printf("%s%d%s%s", i == 0 ? "[" : "", C1[i], 
            i == n1 ? "]\n" : ", ",
            i % 5 == 0 && i != n1 && i != 0 ? "\n\t" : "");
  }
  
  /*******************************************/
  /*  Test 2: Just the next example from     */
  /*       testing the naive method.         */
  /*                                         */
  /*******************************************/
  printf("Test 2...\n");
  status == SUCCESS;
  int n2 = 6;
  int A2[] = {0, 7, 5, 9, 2, 4, 6};
  int B2[] = {15, 18, 12, 16, 17, 14, 0};
  int C2[]   = {0, 0, 0, 0, 0, 0, 0} ;
  int quadratic_vmerge_C2[]   = {0, 0, 0, 0, 0, 0, 0} ;

  vector_merge_naive(A2, B2, quadratic_vmerge_C2, n2);

  vector_merge_interval(A2, B2, C2, n2);

  for(int i = 0; i <= n2; i++)
  {
    if(C2[i] != quadratic_vmerge_C2[i])
    {
      suite_status = FAILURE;
      status = FAILURE;
      break;
    }
  }
  
  if(status == FAILURE)
  {
    printf("\tTest 2 failed! Expected\n\t");
    for(int i = 0; i <= n2; i++)
     printf("%s%d%s%s", i == 0 ? "[" : "", quadratic_vmerge_C2[i], 
            i == n2 ? "]\n" : ", ",
            i % 5 == 0 && i != n2 && i != 0 ? "\n\t" : "");
    printf("\tBut we got\n\t");
    for(int i = 0; i <= n2; i++)
     printf("%s%d%s%s", i == 0 ? "[" : "", C2[i], 
            i == n2 ? "]\n" : ", ",
            i % 5 == 0 && i != n2 && i != 0 ? "\n\t" : "");
  }

  /*******************************************/
  /*  Test 3: Huge!                          */
  /*                                         */
  /*                                         */
  /*******************************************/
  int n3 = 750;
  int A3[] =
    {0, 118, 427, 229, 352, 99, 112, 398, 437, 490, 432, 262, 396, 267, 
    461, 460, 400, 459, 238, 87, 440, 82, 427, 333, 374, 383, 
    190, 153, 194, 226, 335, 68, 344, 114, 148, 47, 212, 112, 
    445, 500, 101, 376, 113, 348, 495, 73, 159, 246, 384, 249, 
    332, 323, 330, 110, 156, 203, 493, 345, 207, 38, 423, 394, 
    105, 266, 7, 105, 312, 70, 216, 108, 69, 168, 484, 181, 
    368, 478, 106, 26, 75, 341, 274, 258, 163, 104, 368, 170, 
    158, 212, 367, 217, 249, 289, 110, 206, 406, 116, 310, 69, 
    37, 377, 177, 105, 44, 160, 137, 411, 489, 94, 289, 63, 
    286, 62, 320, 449, 17, 39, 118, 27, 250, 484, 243, 351, 
    124, 352, 56, 29, 319, 217, 98, 355, 93, 274, 311, 488, 
    285, 299, 399, 273, 245, 187, 187, 30, 100, 358, 478, 117, 
    397, 448, 143, 146, 283, 237, 496, 407, 88, 403, 435, 258, 
    119, 32, 112, 63, 305, 422, 51, 89, 72, 449, 213, 316, 
    487, 251, 346, 86, 109, 175, 54, 5, 122, 48, 2, 405, 
    284, 350, 311, 223, 104, 245, 332, 223, 129, 443, 285, 433, 
    216, 187, 374, 288, 487, 438, 455, 473, 189, 300, 411, 149, 
    475, 316, 5, 448, 364, 6, 352, 499, 207, 14, 74, 311, 
    111, 405, 385, 239, 200, 21, 23, 415, 208, 248, 54, 194, 
    186, 9, 19, 226, 160, 429, 374, 134, 96, 378, 434, 459, 
    235, 137, 310, 294, 151, 383, 456, 113, 139, 192, 351, 338, 
    212, 225, 253, 271, 473, 158, 465, 10, 166, 483, 87, 326, 
    263, 312, 311, 358, 41, 96, 169, 127, 233, 330, 420, 235, 
    212, 227, 347, 350, 418, 49, 40, 130, 273, 292, 252, 97, 
    449, 216, 458, 467, 50, 396, 144, 164, 207, 454, 374, 247, 
    402, 394, 374, 134, 223, 145, 368, 286, 372, 214, 487, 141, 
    114, 26, 122, 386, 169, 374, 335, 470, 89, 144, 436, 491, 
    40, 79, 154, 98, 384, 379, 197, 285, 272, 70, 270, 494, 
    66, 137, 279, 289, 202, 118, 430, 315, 143, 51, 53, 312, 
    276, 239, 281, 365, 382, 68, 207, 273, 498, 212, 371, 381, 
    91, 67, 18, 362, 488, 287, 208, 53, 276, 338, 194, 477, 
    455, 123, 292, 450, 25, 344, 261, 301, 434, 393, 17, 315, 
    460, 75, 440, 457, 286, 310, 189, 376, 228, 58, 90, 67, 
    197, 297, 119, 472, 486, 164, 448, 441, 138, 91, 390, 163, 
    286, 2, 315, 219, 246, 183, 386, 205, 257, 325, 13, 42, 
    134, 53, 270, 213, 111, 359, 279, 307, 7, 249, 278, 492, 
    413, 77, 284, 50, 168, 25, 64, 305, 26, 378, 24, 123, 
    60, 261, 327, 168, 85, 191, 210, 70, 244, 331, 282, 354, 
    41, 60, 12, 47, 160, 141, 390, 424, 217, 26, 474, 236, 
    50, 389, 41, 428, 267, 416, 50, 178, 176, 229, 346, 112, 
    419, 407, 181, 14, 237, 462, 219, 277, 373, 230, 175, 384, 
    370, 416, 308, 439, 441, 281, 174, 343, 21, 66, 122, 139, 
    333, 171, 317, 360, 251, 14, 471, 22, 272, 151, 35, 360, 
    464, 254, 488, 336, 483, 14, 72, 205, 429, 379, 143, 222, 
    11, 316, 64, 31, 234, 185, 170, 418, 207, 338, 278, 310, 
    203, 248, 331, 474, 399, 217, 185, 214, 470, 172, 402, 305, 
    185, 473, 9, 465, 351, 151, 186, 361, 318, 101, 391, 403, 
    137, 60, 321, 196, 249, 98, 5, 451, 197, 187, 276, 447, 
    403, 460, 161, 373, 483, 62, 177, 19, 34, 37, 484, 384, 
    187, 169, 244, 356, 270, 486, 259, 258, 398, 431, 453, 146, 
    28, 457, 449, 224, 143, 224, 23, 46, 184, 183, 270, 18, 
    244, 298, 37, 277, 334, 20, 12, 372, 40, 107, 227, 161, 
    92, 337, 419, 341, 267, 371, 339, 146, 180, 287, 222, 322, 
    10, 244, 219, 45, 426, 340, 63, 21, 137, 99, 149, 470, 
    470, 160, 341, 9, 266, 420, 22, 209, 108, 440, 402, 227, 
    162, 240, 372, 341, 26, 445, 15, 387, 40, 85, 432, 317, 
    425, 494, 337, 61, 444, 485, 383, 413, 496, 75, 273, 113, 
    494, 294, 322, 102, 85, 75, 180, 247, 314, 51, 87, 191, 
    348, 101, 77, 387, 186, 8, 204, 110, 353, 392, 22, 148, 
    229, 404, 412, 224, 479, 185, 337, 324, 330, 10, 277, 415, 
    84, 456, 161, 249, 359, 247, 291, 58, 200, 367, 444, 237, 
    227, 499, 346, 431, 243, 219, 79, 471, 123, 490, 46, 453, 
    26, 382, 128, 356, 243};
  int B3[] =
    {405, 270, 178, 212, 430, 278, 70, 28, 68, 127, 79, 435, 423, 
    315, 13, 273, 160, 443, 15, 231, 373, 337, 205, 363, 383, 
    157, 240, 264, 136, 95, 359, 40, 216, 36, 104, 497, 166, 
    173, 377, 233, 152, 455, 167, 426, 270, 31, 50, 429, 474, 
    65, 11, 346, 401, 215, 60, 283, 223, 300, 399, 359, 246, 
    109, 398, 462, 144, 1, 310, 309, 26, 186, 394, 29, 141, 
    412, 306, 410, 443, 355, 190, 416, 271, 201, 113, 24, 415, 
    173, 158, 490, 324, 56, 348, 421, 164, 97, 234, 160, 450, 
    44, 320, 327, 229, 65, 355, 221, 477, 12, 130, 419, 218, 
    172, 186, 489, 224, 298, 12, 138, 322, 21, 479, 497, 77, 
    326, 418, 92, 423, 151, 103, 372, 46, 275, 198, 127, 339, 
    404, 347, 167, 415, 329, 85, 484, 352, 122, 472, 75, 272, 
    335, 212, 445, 356, 43, 442, 284, 368, 211, 227, 290, 213, 
    182, 13, 259, 308, 62, 385, 146, 465, 83, 165, 231, 263, 
    249, 67, 114, 223, 38, 188, 494, 225, 252, 438, 80, 294, 
    231, 215, 161, 441, 441, 303, 154, 122, 315, 412, 429, 229, 
    148, 427, 45, 230, 91, 128, 493, 191, 194, 458, 265, 231, 
    146, 258, 455, 397, 48, 386, 190, 278, 100, 350, 219, 393, 
    4, 372, 14, 171, 135, 295, 399, 282, 73, 443, 363, 15, 
    422, 207, 57, 115, 165, 322, 198, 310, 79, 4, 58, 126, 
    390, 247, 404, 341, 448, 474, 233, 452, 197, 99, 474, 331, 
    393, 372, 464, 317, 166, 178, 331, 88, 237, 387, 202, 401, 
    208, 251, 62, 139, 255, 471, 116, 144, 217, 371, 336, 16, 
    344, 69, 319, 40, 167, 292, 222, 411, 163, 185, 227, 181, 
    215, 57, 268, 451, 295, 321, 203, 355, 72, 116, 493, 178, 
    86, 108, 321, 302, 331, 156, 169, 174, 76, 488, 66, 242, 
    279, 287, 152, 294, 324, 230, 474, 38, 138, 241, 340, 433, 
    413, 42, 287, 336, 157, 131, 13, 94, 90, 185, 247, 420, 
    193, 415, 94, 268, 402, 159, 362, 181, 297, 365, 474, 472, 
    95, 447, 9, 232, 39, 200, 16, 303, 241, 302, 139, 249, 
    284, 3, 342, 374, 188, 88, 293, 380, 3, 386, 499, 256, 
    396, 360, 436, 45, 77, 261, 16, 171, 59, 377, 254, 449, 
    76, 270, 252, 169, 423, 242, 417, 207, 96, 111, 80, 283, 
    50, 372, 14, 52, 258, 365, 308, 5, 76, 95, 49, 152, 
    208, 417, 322, 266, 293, 428, 67, 220, 197, 170, 388, 119, 
    411, 157, 325, 358, 267, 404, 141, 168, 276, 6, 220, 385, 
    222, 379, 241, 298, 325, 142, 449, 384, 58, 123, 150, 202, 
    50, 68, 421, 98, 237, 161, 216, 499, 317, 393, 356, 435, 
    296, 348, 102, 423, 354, 173, 159, 427, 403, 400, 224, 80, 
    393, 25, 463, 450, 147, 464, 151, 48, 31, 423, 497, 267, 
    83, 212, 265, 251, 456, 121, 37, 252, 468, 491, 26, 173, 
    163, 185, 100, 418, 436, 175, 497, 328, 199, 459, 129, 197, 
    423, 131, 244, 453, 53, 92, 72, 488, 304, 336, 90, 259, 
    308, 127, 362, 128, 117, 240, 152, 131, 276, 103, 48, 211, 
    278, 44, 390, 476, 355, 18, 25, 129, 148, 120, 433, 52, 
    212, 4, 391, 15, 192, 481, 125, 499, 459, 339, 126, 75, 
    430, 130, 205, 205, 232, 253, 267, 9, 148, 156, 337, 354, 
    25, 361, 482, 24, 480, 415, 427, 191, 270, 318, 57, 461, 
    150, 34, 460, 108, 224, 437, 182, 153, 66, 238, 209, 298, 
    342, 475, 158, 342, 482, 494, 195, 6, 206, 177, 381, 38, 
    443, 307, 80, 212, 476, 137, 173, 125, 22, 484, 232, 97, 
    420, 265, 249, 486, 355, 457, 135, 196, 283, 292, 37, 264, 
    138, 84, 121, 195, 112, 353, 232, 54, 11, 312, 117, 487, 
    300, 289, 463, 173, 272, 47, 269, 44, 311, 369, 29, 17, 
    177, 15, 213, 459, 306, 101, 74, 295, 184, 46, 490, 295, 
    398, 221, 200, 408, 384, 317, 394, 35, 457, 209, 59, 81, 
    255, 327, 124, 65, 47, 4, 82, 223, 18, 146, 181, 175, 
    246, 106, 470, 282, 151, 459, 428, 48, 31, 480, 308, 267, 
    296, 53, 153, 104, 261, 212, 184, 15, 390, 159, 432, 437, 
    14, 365, 159, 31, 10, 192, 206, 107, 297, 27, 240, 448, 
    485, 20, 347, 367, 499, 154, 485, 294, 59, 138, 249, 319, 
    201, 285, 186, 90, 443, 117, 378, 457, 333, 37, 339, 194, 
    228, 396, 300, 376, 422, 0};
  int quadratic_vmerge_C3[] =
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0};
  int C3[] =
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0};
    
  vector_merge_naive(A3, B3, quadratic_vmerge_C3, n3);

  vector_merge_interval(A3, B3, C3, n3);

  for(int i = 0; i <= n3; i++)
  {
    if(C3[i] != quadratic_vmerge_C3[i])
    {
      suite_status = FAILURE;
      status = FAILURE;
      break;
    }
  }
  
  if(status == FAILURE)
  {
    printf("\tTest 3 failed! Expected\n\t");
    for(int i = 0; i <= n3; i++)
     printf("%s%d%s%s", i == 0 ? "[" : "", quadratic_vmerge_C3[i], 
            i == n3 ? "]\n" : ", ",
            i % 5 == 0 && i != n3 && i != 0 ? "\n\t" : "");
    printf("\n\tBut we got\n\t");
    for(int i = 0; i <= n3; i++)
     printf("%s%d%s%s", i == 0 ? "[" : "", C3[i], 
            i == n3 ? "]\n" : ", ",
            i % 5 == 0 && i != n3 && i != 0 ? "\n\t" : "");
  }

  if(suite_status == SUCCESS)
    printf("\tAll passed!\n");

}

void test_interval_dynamic_programming(void)
{
  /* Make the instance
      get the LB
      find the intervals and slot theprofits in
      Derive L'
      Then use it wi/ Int DP */
  /* Instance 1
    Problem inputs
      int profits[] = {94, 506, 416, 992, 649, 237, 457, 815, 446, 422};
      int weights[] = {485, 326, 248, 421, 322, 795, 43, 845, 955, 252};
      int capacity = 1850;
      int n = 10;
      double epsilon = 0.5;

    Results in
      large_profits: [860, -1, -1, -1, -1, -1 , -1, -1, -1, -1] 
      large_weights: [421, -1, -1, -1, -1, -1 , -1, -1, -1, -1] 
      small_profits: [94, 506, 416, 649, 237, 457 , 815, 446, 422, -1]  
      small_weights: [485, 326, 248, 322, 795, 43  , 845, 955, 252, -1]
        new epsilon: 0.250000
  */
      int profits[] = {94, 506, 416, 992, 649, 237, 457, 815, 446, 422};
      int weights[] = {485, 326, 248, 421, 322, 795, 43, 845, 955, 252};
      int capacity = 1850;
      int n = 10;
      double epsilon = 0.3;

  /* Instance 3
    double epsilon = 0.1; int capacity = 99785; int n=50;
    int profits[] = {15094, 24506, 94416, 40992, 66649, 49237,
                     96457, 67815, 19446, 63422, 88791, 49359,
                     45667, 31598, 82007, 20544, 85334, 82766,
                     93994, 59893, 62633, 87131, 5428, 76700,
                     30617, 15874, 77720, 74419, 69794, 28196,
                     95997, 83116, 15908, 55539, 45707, 38569,
                     25537, 90931, 55726, 75487, 59772, 67513,
                     52081, 29943, 88058, 84303, 13764, 6536,
                     90724, 63789};

    int weights[] = {485, 56326, 79248, 45421, 80322, 15795,
                     58043, 42845, 24955, 49252, 61009, 25901,
                     81122, 81094, 38738, 88574, 65715, 78882,
                     31367, 59984, 73299, 49433, 15682, 90072,
                     97874, 138, 53856, 87145, 37995, 91529,
                     36199, 83277, 80097, 59719, 35242, 36107,
                     41122, 41070, 76098, 53600, 36645, 7267,
                     41972, 9895, 83213, 99748, 89487, 71923,
                     17029, 2567};
      Results in:
      large_profits: [24504, 24504, 27700, 29831, 29831, 30897,
                      38355, 40485, 44747, 44747, 49009, 
                      49009, 51140, 55401, 55401, 59663, 
                      59663, 61794, 61794, 61794, 63925, 
                      67121, 67121, 67121, 73513, 73513, 
                      73513, 76710, 79906, 79906, 83102, 
                      83102, 85233, 85233, 85233, 85233, 
                      89495, 89495, 93756, 93756, 93756, 
                      93756, -1, -1, -1, -1, -1, -1, -1, -1] 
      large_weights: [41122, 56326, 91529, 9895, 97874, 81094, 
                      36107, 45421, 35242, 81122, 15795, 
                      25901, 41972, 59719, 76098, 36645, 
                      59984, 2567, 49252, 73299, 80322, 
                      7267, 37995, 42845, 53600, 87145, 
                      90072, 53856, 38738, 78882, 83277, 
                      99748, 49433, 61009, 65715, 83213, 
                      17029, 41070, 31367, 36199, 58043, 
                      79248, -1, -1, -1, -1, -1, -1, -1, -1] 
      small_profits: [15094, 19446, 20544, 5428, 15874, 15908, 
                      13764, 6536, -1, 0, 0, 0, 0, 0, 0, 0, 
                      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                      0, 0, 0, 0, 0, 0, 0, 0] 
      small_weights: [485, 24955, 88574, 15682, 138, 80097, 
                      89487, 71923, -1, 0, 0, 0, 0, 0, 0, 0,
                      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                      0, 0, 0, 0, 0, 0, 0, 0]
  */


  double new_epsilon = epsilon;
  int large_profits[n], large_weights[n], small_profits[n], small_weights[n];
  int intervals[n], subintervals[n];
  int new_n;
  scaling_reduction(profits, weights, n, capacity, &new_epsilon, large_profits,
                    large_weights, small_profits, small_weights, intervals,
                    subintervals, &new_n);

  for(int i = 0; i < n; i++)
    printf("%s%d%s%s", i == 0 ? "large_profits: [" : "", large_profits[i], 
           i == n-1 ? "]\t\n" : ", ", i % 5 == 0 && i != 0 ? "\n\t\t" : "");

  for(int i = 0; i < n; i++)
    printf("%s%d%s%s", i == 0 ? "large_weights: [" : "", large_weights[i],
           i == n-1 ? "]\t\n" : ", ", i % 5 == 0 && i != 0 ? "\n\t\t" : "");

  for(int i = 0; i < n; i++)
    printf("%s%d%s%s", i == 0 ? "small_profits: [" : "", small_profits[i], 
           i == n-1 ? "]\t\n" : ", ", i % 5 == 0 && i != 0 ? "\n\t\t" : "");

  for(int i = 0; i < n; i++)
    printf("%s%d%s%s", i == 0 ? "small_weights: [" : "", small_weights[i], 
           i == n-1 ? "]\n\t" : ", ", i % 5 == 0 && i != 0 ? "\n\t\t" : "");

  printf("%lf\n", new_epsilon);
}

void test_scaling_reduction(void)
{
  /* TODO IMPORTANT THIS HAS ONLY BEEN SUPERFICIALLY TESTED LOL */
  int profits[] = {94, 506, 416, 992, 649, 237, 457, 815, 446, 422};
  int weights[] = {485, 326, 248, 421, 322, 795, 43, 845, 955, 252};
  int capacity = 1850;
  int n = 10;
  double epsilon = 0.5; 

  double new_epsilon = epsilon;
  int large_profits[n], large_weights[n], small_profits[n], small_weights[n];
  int subintervals[n], intervals[n];
  int new_n;
  
  scaling_reduction(profits, weights, n, capacity, &new_epsilon, large_profits,
                    large_weights, small_profits, small_weights, intervals, 
                    subintervals, &new_n);
  /*
  printf("************** PRINTING AFTER SCALING_REDUCTION *********************\n");
  for(int i = 0; i < n; i++) 
    printf("%s%d%s%s", i == 0 ? "large_profits: [" : ", ", large_profits[i], 
           i == n-1 ? "]\t\n" : "", i % 5 == 0 && i != 0 ? "\n\t" : ""); 

  for(int i = 0; i < n; i++) 
    printf("%s%d%s%s", i == 0 ? "large_weights: [" : ", ", large_weights[i], 
           i == n-1 ? "]\t\n" : "", i % 5 == 0 && i != 0 ? "\n\t" : ""); 

  for(int i = 0; i < n; i++) 
    printf("%s%d%s%s", i == 0 ? "small_profits: [" : ", ", small_profits[i], 
           i == n-1 ? "]\t\n" : "", i % 5 == 0 && i != 0 ? "\n\t" : ""); 

  for(int i = 0; i < n; i++) 
    printf("%s%d%s%s", i == 0 ? "small_weights: [" : ", ", small_weights[i], 
           i == n-1 ? "]\n\t" : "", i % 5 == 0 && i != 0 ? "\n\t" : ""); 

  printf("%lf\n", new_epsilon);
  */ 
}

void test_get_ith_interval(void)
{
  printf("Testing get_ith_interval...\n");
  int suite_status = SUCCESS;
  int status;

  /*******************************************/
  /*  Test 1.1: just standard input          */
  /*                                         */
  /*******************************************/
  status = SUCCESS;

  int intervals1[] = {12, 15, 32, 35, 37, 37, 45, 48, 57, 59, 66, 70, 71, 74, 
                     90, 96, 107, 107, 115, 115, 122, 130, 130, 140, 140, 146,
                     148, 149, 156, 158, 159, 163, 174, 177, 179, 182, 192, 
                     194, 195, 197, 200, 204, 206, 208, 212, 213, 220, 221,
                     225, 226};
  int subintervals1[] = {62, 23, 10, 12, 7, 9, 14, 5, 9, 16, 3, 4, 12, 2, 6, 
                        2, 3, 2, 8, 5, 2, 6, 3, 2, 4, 7, 6, 5, 3, 3, 1, 5, 4,
                        1, 6, 3, 3, 2, 1, 5, 2, 3, 4, 2, 5, 2, 3, 3, 2, 2};
    
  double epsilon1 = 0.001;
  int no_subintervals1 = 0;
  int no_intervals1 = 1/epsilon1 - 1;  
  int n1 = 50;


  /* Run algorithm */
  int ith1 = 3;
  int expected_index1 = 2;
  int index1 = get_ith_subinterval(ith1, intervals1, subintervals1, n1);

  /* Check correctness and print errors */
  if(index1 != 2)
  {
    printf("\tTest 1.1 failed! Expected index = %d but got index = %d\n", 
          expected_index1, index1);
    suite_status = FAILURE;
  }

  /*******************************************/
  /* Test 1.2: Same input, different index   */
  /*                                         */
  /*******************************************/
  status = SUCCESS;

  /* Run algorithm */
  ith1 = 30;
  expected_index1 = 29;
  index1 = get_ith_subinterval(ith1, intervals1, subintervals1, n1);

  /* Check correctness and print errors */
  if(index1 != 29)
  {
    printf("\tTest 1.2 failed! Expected index = %d but got index = %d\n", 
          expected_index1, index1);
    suite_status = FAILURE;
  }

  /*******************************************/
  /*  Test 2.1: Interval immediately after   */
  /*          shared subintervals            */
  /*                                         */
  /*******************************************/
  status = SUCCESS;

  int intervals2[] = {1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                     2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4,
                     4, 4, 4, 4, -1, 0, 0, 0, 0, 0, 0, 0};
  int subintervals2[] = {10, 19, 9, 4, 7, 17, 4, 9, 10, 7, 2, 9, 10, 7, 9, 5, 
                        4, 4, 2, 10, 2, 7, 6, 4, 2, 2, 4, 1, 7, 6, 5, 4, 1, 3,
                        3, 1, 1, 3, 2, 1, 2, 3, -1, 0, 0, 0, 0, 0, 0, 0};

  double epsilon2 = 0.05;
  int n2 = 42;

  /* Run algorithm */
  int ith2 = 18;
  int expected_index2 = 18;
  int index2 = get_ith_subinterval(ith2, intervals2, subintervals2, n2);

  /* Check correctness and print errors */
  if(index2 != expected_index2)
  {
    printf("\tTest 2.1 failed! Expected index = %d but got index = %d\n", 
          expected_index2, index2);
    suite_status = FAILURE;
  }

  /*******************************************/
  /*      Test 2.2: Start of identical       */
  /*              subintervals               */
  /*                                         */
  /*******************************************/
  status = SUCCESS;

  /* Run algorithm */
  ith2 = 17;
  expected_index2 = 16;
  index2 = get_ith_subinterval(ith2, intervals2, subintervals2, n2);

  /* Check correctness and print errors */
  if(index2 != expected_index2)
  {
    printf("\tTest 2.2 failed! Expected index = %d but got index = %d\n", 
          expected_index2, index2);
    suite_status = FAILURE;
  }


  /*******************************************/
  /*      Test 2.3: Subinterval not found    */
  /*                                         */
  /*******************************************/
  status = SUCCESS;

  /* Run algorithm */
  ith2 = 42;
  expected_index2 = -1;
  index2 = get_ith_subinterval(ith2, intervals2, subintervals2, n2);

  /* Check correctness and print errors */
  if(index2 != expected_index2)
  {
    printf("\tTest 2.2 failed! Expected index = %d but got index = %d\n", 
          expected_index2, index2);
    suite_status = FAILURE;
  }

  if(suite_status == SUCCESS)
    printf("\tAll passed!\n");
}

void test_get_number_of_weights(void)
{
  printf("Testing get_number_of_weights...\n");
  int suite_status = SUCCESS;
  int status;

  /*******************************************/
  /*  Test 1: First profit                   */
  /*                                         */
  /*******************************************/
  status = SUCCESS;
  int n1 = 50; 
  int capacity1 = 99748;
  int profits1[] = {15094, 24506, 94416, 40992, 66649, 49237, 96457, 67815, 19446,
                    63422, 88791, 49359, 45667, 31598, 82007, 20544, 85334, 82766,
                    93994, 59893, 62633, 87131, 5428, 76700, 30617, 15874, 77720, 
                    74419, 69794, 28196, 95997, 83116, 15908, 55539, 45707, 38569,
                    25537, 90931, 55726, 75487, 59772, 67513, 52081, 29943, 88058,
                    84303, 13764, 6536, 90724, 63789};

  int weights1[] = {485, 56326, 79248, 45421, 80322, 15795, 58043, 42845, 24955, 
                    49252, 61009, 25901, 81122, 81094, 38738, 88574, 65715, 78882,
                    31367, 59984, 73299, 49433, 15682, 90072, 97874, 138, 53856,
                    87145, 37995, 91529, 36199, 83277, 80097, 59719, 35242, 36107,
                    41122, 41070, 76098, 53600, 36645, 7267, 41972, 9895, 83213, 
                    99748, 89487, 71923, 17029, 2567};
  double epsilon1 = 0.2;
  int large_profits1[n1], large_weights1[n1], small_profits1[n1],
       small_weights1[n1];
  int intervals1[n1], subintervals1[n1];
  int new_n1;

  scaling_reduction(profits1, weights1, n1, capacity1, &epsilon1, 
                    large_profits1, large_weights1, small_profits1,
                    small_weights1, intervals1, subintervals1, &new_n1);

  
  int index_of_interest1 = 0;
  int expected_number_of_weights = 2;
  int number_of_weights = get_number_of_weights(index_of_interest1, 
                                                large_profits1, new_n1); 

  if(expected_number_of_weights != number_of_weights)
  {
    status = FAILURE;
    suite_status = FAILURE;
    printf("\tTest 1 failed! Expected %d but got %d!\n",
           expected_number_of_weights, number_of_weights);
  }

  /*
  print_list(intervals1, n1, "intervals1");
  print_list(subintervals1, n1, "subintervals1");
  printf("%d\n", new_n1);
  */

  /*******************************************/
  /*  Test 2: Mid range profit               */
  /*                                         */
  /*******************************************/
  status = SUCCESS;

  int n2 = 50;
  int capacity2 = 9909895;
  int profits2[] = {8415090, 3280471, 5173662, 2785349, 1246577, 4464416, 5454431, 
               2710495, 5644168, 2612523, 5749573, 4274644, 2726423, 3912054, 
               4019779, 2408872, 7751036, 7860698, 324554, 7419182, 6835394, 
               6536095, 7120355, 3365898, 7327436, 8715849, 530827, 360957, 
               207496, 6519446, 131500, 2865845, 5795909, 3414501, 1080228, 
               3374272, 866066, 3230993, 10431187, 6228475, 3995393, 3273919, 
               5293424, 9339146, 9870875, 9883525, 2602897, 6378122, 5007115, 
               9489045};

  int weights2[] = {9400485, 2756326, 4379248, 2845421, 1680322, 4215795, 4658043,
               1942845, 5524955, 1949252, 5861009, 4125901, 2881122, 3581094,
               3738738, 2488574, 6865715, 8278882, 731367, 7659984, 6073299,  
               5549433, 7415682, 3890072, 6797874, 9500138, 1253856, 387145,
               37995, 7191529, 36199, 3583277, 6580097, 3159719, 1935242, 
               3736107, 41122, 4141070, 9476098, 5753600, 4236645, 2507267,
               6141972, 9909895, 9683213, 9699748, 2689487, 6471923, 5817029, 
               9425674};
  double epsilon2 = 0.2;
  int large_profits2[n2], large_weights2[n2], small_profits2[n2],
       small_weights2[n2];
  int intervals2[n2], subintervals2[n2];
  int new_n2;

  scaling_reduction(profits2, weights2, n2, capacity2, &epsilon2, 
                    large_profits2, large_weights2, small_profits2,
                    small_weights2, intervals2, subintervals2, &new_n2);


  
  int index_of_interest2 = 3;
  expected_number_of_weights = 4;
  number_of_weights = get_number_of_weights(index_of_interest2, large_profits2,
                                            new_n2); 

  if(expected_number_of_weights != number_of_weights)
  {
    status = FAILURE;
    suite_status = FAILURE;
    printf("\tTest 2 failed! Expected %d but got %d!\n",
           expected_number_of_weights, number_of_weights);
  }

  /*
  print_list(intervals2, n2, "intervals2");
  print_list(subintervals2, n2, "subintervals2");
  printf("%d\n", new_n2);
  */

  /*******************************************/
  /*  Test 3: profit at the end              */
  /*                                         */
  /*******************************************/
  status = SUCCESS;

  int capacity3  = 99748;
  int n3 = 50;
  int weights3[] = {485, 15094, 56326, 24506, 79248, 94416, 45421, 40992, 
                    80322, 66649, 15795, 49237, 58043, 96457, 42845, 67815, 
                    24955, 19446, 49252, 63422, 61009, 88791, 25901, 49359, 
                    81122, 45667, 81094, 31598, 38738, 82007, 88574, 20544, 
                    65715, 85334, 78882, 82766, 31367, 93994, 59984, 59893, 
                    73299, 62633, 49433, 87131, 15682, 5428, 90072, 76700, 
                    97874, 30617}; 

  int profits3[] = {10485, 25094, 66326, 34506, 89248, 104416, 55421, 50992, 
                    90322, 76649, 25795, 59237, 68043, 106457, 52845, 77815, 
                    34955, 29446, 59252, 73422, 71009, 98791, 35901, 59359, 
                    91122, 55667, 91094, 41598, 48738, 92007, 98574, 30544, 
                    75715, 95334, 88882, 92766, 41367, 103994, 69984, 69893, 
                    83299, 72633, 59433, 97131, 25682, 15428, 100072, 86700, 
                    107874, 40617};

  double epsilon3 = 0.2;
  int large_profits3[n3], large_weights3[n3], small_profits3[n3],
       small_weights3[n3];
  int intervals3[n3], subintervals3[n3];
  int new_n3;

  scaling_reduction(profits3, weights3, n3, capacity3, &epsilon3, 
                    large_profits3, large_weights3, small_profits3,
                    small_weights3, intervals3, subintervals3, &new_n3);

  
  int index_of_interest3 = 35;
  expected_number_of_weights = 3;
  number_of_weights = get_number_of_weights(index_of_interest3, large_profits3,
                                            new_n3); 

  if(expected_number_of_weights != number_of_weights)
  {
    status = FAILURE;
    suite_status = FAILURE;
    printf("\tTest 3 failed! Expected %d but got %d!\n",
           expected_number_of_weights, number_of_weights);
  }
  
  /*
  print_list(large_profits3, n3, "large_profits3");
  print_list(large_weights3, n3, "large_weights3");
  print_list(intervals3, n3, "intervals3");
  print_list(subintervals3, n3, "subintervals3");
  printf("%d\n", new_n3);
  */
  
  if(suite_status == SUCCESS)
    printf("\tAll passed!\n");
}

void test_get_no_subintervals_used(void)
{
  printf("Testing get_no_subintervals_used...\n");
  int suite_status = SUCCESS;
  int status;

  /*******************************************/
  /*  Test 1:                                */
  /*                                         */
  /*******************************************/
  int intervals1[] = 
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 
     2, 2, 2, 2, 2, 2, 2, 2, 2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
     -1, -1, -1, -1};
  int subintervals1[] = 
    {1, 1, 2, 2, 3, 4, 4, 5, 5, 5, 5, 5, 6, 6, 6, 7, 8, 8, 8, 9, 10, 10, 10, 10,
     1, 1, 1, 1, 1, 1, 2, 2, 2, 2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
     -1, -1, -1, -1, -1};
  int new_n1 = 34;

  int subintervals_used1 = get_no_subintervals_used(intervals1, subintervals1, 
                                                    new_n1);
  int expected_subintervals_used1 = 12;

  int poo = get_ith_subinterval(13, intervals1, subintervals1, new_n1);
  printf("poo: %d\n", poo);

  if(subintervals_used1 != expected_subintervals_used1)
  {
    status = FAILURE;
    suite_status = FAILURE;
    printf("\tTest 1 failed! Expected %d but got %d!\n",
           expected_subintervals_used1, subintervals_used1);
  }
  

  /*******************************************/
  /*  Test 2:                                */
  /*                                         */
  /*******************************************/
  int intervals2[] = 
    {1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 4, 4, 4, 4, 
    4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 6, 6, 6, 7, 7, 7, -1, -1, -1, -1, -1, -1, -1,
     -1, -1};
  int subintervals2[] = 
    {8, 10, 10, 1, 1, 1, 1, 3, 3, 3, 3, 3, 3, 5, 5, 5, 1, 2, 3, 3, 4, 1, 1, 1,
     1, 2, 2, 3, 3, 1, 1, 1, 2, 2, 2, 1, 1, 2, 1, 1, 1, -1, -1, -1, -1, -1, -1,
     -1, -1, -1};
  int new_n2 = 41;

  int subintervals_used2 = get_no_subintervals_used(intervals2, subintervals2, 
                                                    new_n2);
  int expected_subintervals_used2 = 17;

  if(subintervals_used2 != expected_subintervals_used2)
  {
    status = FAILURE;
    suite_status = FAILURE;
    printf("\tTest 2 failed! Expected %d but got %d!\n",
           expected_subintervals_used2, subintervals_used2);
  }

  /*******************************************/
  /*  Test 3:                                */
  /*                                         */
  /*******************************************/

  int intervals3[] = 
    {1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4,
     4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 6, 6, 6, -1, -1, -1, -1, -1, -1, -1, -1, -1,
     -1, -1, -1};
  int subintervals3[] = 
    {6, 6, 6, 9, 9, 1, 1, 2, 3, 3, 3, 5, 1, 1, 2, 2, 3, 3, 3, 3, 1, 1, 1, 1, 1,
     2, 2, 2, 2, 1, 1, 1, 2, 2, 2, 1, 1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
     -1, -1, -1};
  int new_n3 = 38;

  int subintervals_used3 = get_no_subintervals_used(intervals3, subintervals3, 
                                                    new_n3);
  int expected_subintervals_used3 = 14;

  if(subintervals_used3 != expected_subintervals_used3)
  {
    status = FAILURE;
    suite_status = FAILURE;
    printf("\tTest 3 failed! Expected %d but got %d!\n",
           expected_subintervals_used3, subintervals_used3);
  }

  if(suite_status == SUCCESS)
    printf("\tAll passed!\n");
  
}

void print_list(int *list, int length, const char *name)
{
  for(int i = 0; i < length; i++)
    printf("%s%s%s%d%s%s", i == 0 ? "int " : "", i == 0 ? name : "", 
           i == 0 ? "[] = \n\t{" : "", list[i], i == length-1 ? "};\n" : ", ", 
           i % 6 == 0 && i > 0 && i < length-1? "\n\t" : "");
}

