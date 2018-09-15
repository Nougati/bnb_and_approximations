#include <stdio.h>
#include <math.h>
#include "kellerer_pferschy_fptas.h"
#define SUCCESS 1
#define FAILURE 0
#define TRUE 1
#define FALSE 0

void test_modify_epsilon(void);
void test_get_knapsack_lowerbound(void);
void test_small_large_split(void);
int is_in(int value, int arr[], int arr_len);
void test_partition_large_set(void);
void test_partition_interval(void);
void test_reduce_profits_to_minimal(void);
void test_prune_excess_weight_items(void);

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
  //test_redefine_large_set(); TODO
  
  /* Everything for interval dynamic programming */
  //test_vector_merge();TODO

  /* TODO Everything for greedily add smalls */

  /* TODO Everything for backtracking */

  /* TODO Everything for recursion */

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

  int small[n1];
  for(int i = 0; i < n1; i++)
    small[i] = 0;

  int large[n1];
  for(int i = 0; i < n1; i++)
    large[i] = 0;

  small_large_split(profits1, weights1, n1, capacity1, epsilon1, lower_bound, 
                    small, large);
  
  /* Check that small was right */
  for(int i = 0; i < 2; i++)
  {
    if(!is_in(expected_small1[i], small, n1))
    {
      return_val = FAILURE;
      suite_return_val = FAILURE;
      break;
    }
  }

  /* Check that large was right */
  for(int i = 0; i < 48; i++)
  {
    if(!is_in(expected_large1[i], large, n1))
    {
      return_val = FAILURE;
      suite_return_val = FAILURE;
      break;
    }
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
      printf(" %d", small[i]);
      if((i+1)%15 == 0)
        printf("\n\t\t ");
    }
    printf("], and\n\t\t[");
    for(int i = 0; i < n1; i++)
    {
      printf(" %d", large[i]);
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
    small[i] = 0;

  for(int i = 0; i < n1; i++)
    large[i] = 0;

  small_large_split(profits1, weights1, n1, capacity1, epsilon2, lower_bound, 
                    small, large);

  /* Check that small was right */
  for(int i = 0; i < 41; i++)
  {
    if(!is_in(expected_small2[i], small, n1))
    {
      return_val = FAILURE;
      suite_return_val = FAILURE;
      break;
    }
  }

  /* Check that large was right */
  for(int i = 0; i < 9; i++)
  {
    if(!is_in(expected_large2[i], large, n1))
    {
      return_val = FAILURE;
      suite_return_val = FAILURE;
      break;
    }
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
      printf(" %d", small[i]);
      if((i+1)%15 == 0)
        printf("\n\t\t ");
    }
    printf("], and\n\t\t[");
    for(int i = 0; i < n1; i++)
    {
      printf(" %d", large[i]);
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
    small[i] = 0;
  for(int i = 0; i < n1; i++)
    large[i] = 0;

  /* Run algorithm */
  small_large_split(profits1, weights1, n1, capacity1, epsilon3, lower_bound, 
                    small, large);
  
  /* Check that large was right */
  for(int i = 0; i < 50; i++)
  {
    if(!is_in(expected_large3[i], large, n1))
    {
      return_val = FAILURE;
      suite_return_val = FAILURE;
      break;
    }
  }

  /* Check that small was right */
  for(int i = 0; i < n1; i++)
  {
    if(small[i] != 0)
    {
      return_val = FAILURE;
      suite_return_val = FAILURE;
      break;
    }
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
      printf(" %d", small[i]);
      if((i+1)%15 == 0)
        printf("\n\t\t ");
    }
    printf("], and\n\t\t[");
    for(int i = 0; i < n1; i++)
    {
      printf(" %d", large[i]);
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
    small[i] = 0;
  for(int i = 0; i < n1; i++)
    large[i] = 0;

  /* Run algorithm */
  small_large_split(profits1, weights1, n1, capacity1, epsilon4, lower_bound, 
                    small, large);
  
  /* Check that small was right */
  for(int i = 0; i < n1; i++)
  {
    if(!is_in(expected_small4[i], small, n1))
    {
      return_val = FAILURE;
      suite_return_val = FAILURE;
      break;
    }
  }

  /* Check that large was right */
  for(int i = 0; i < n1; i++)
  {
    if(large[i] != 0)
    {
      return_val = FAILURE;
      suite_return_val = FAILURE;
      break;
    }
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
      printf(" %d", small[i]);
      if((i+1)%15 == 0)
        printf("\n\t\t ");
    }
    printf("], and\n\t\t[");
    for(int i = 0; i < n1; i++)
    {
      printf(" %d", large[i]);
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
    small[i] = 0;
  for(int i = 0; i < n5; i++)
    large[i] = 0;
  int expected_large5[] = {94};
  int expected_small5[] = {};

  /* Run algorithm */
  small_large_split(profits5, weights5, n5, capacity5, epsilon5, lower_bound5, 
                    small, large);

  /* Check that small was right */
  for(int i = 0; i < 50; i++)
  {
    if(small[i] != 0)
    {
      return_val = FAILURE;
      suite_return_val = FAILURE;
      break;
    }
  }

  /* Check that large was right */
  for(int i = 0; i < n5; i++)
  {
    if(!is_in(expected_large5[i], large, n5))
    {
      return_val = FAILURE;
      suite_return_val = FAILURE;
      break;
    }
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
      printf(" %d", small[i]);
      if((i+1)%15 == 0)
        printf("\n\t\t ");
    }
    printf("], and\n\t\t[");
    for(int i = 0; i < n1; i++)
    {
      printf(" %d", large[i]);
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
  for(int i = 0; i < n6; i++)
    small[i] = 0;
  for(int i = 0; i < n6; i++)
    large[i] = 0;
  int expected_large6[] = {};
  int expected_small6[] = {};

  /* Run algorithm */
  small_large_split(profits6, weights6, n6, capacity6, epsilon6, lower_bound6, 
                    small, large);

  /* Check that small was right (all 50 slots should be empty) */
  for(int i = 0; i < 50; i++)
  {
    if(small[i] != 0)
    {
      return_val = FAILURE; 
      suite_return_val = FAILURE;
    }
  }

  /* Check that large was right */
  for(int i = 0; i < 50; i++)
  {
    if(large[i] != 0)
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
      printf(" %d", small[i]);
      if((i+1)%15 == 0)
        printf("\n\t\t ");
    }
    printf("], and\n\t\t[");
    for(int i = 0; i < n1; i++)
    {
      printf(" %d", large[i]);
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

  printf("Running test_small_large_split\n");
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
  partition_large_set(input_profits1, input_weights1, n1, epsilon1, lower_bound1,
                      indices_out1);

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
    printf("\tEverything passed!");
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
  int intervals1[] = { 1,  1,  1,  1,  1,  1,  1,  2,  2,  4,  4,  4,  4};
  int expected_subintervals1[] = 
    { 1,  1,  3,  3,  3,  4,  4,  1,  2,  1,  1,  1,  2};
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
  int n2 = 4;
  int profits2[] = {45, 65, 94, 134};
  int intervals2[] = {1, 1, 2, 3};
  int expected_subintervals2[] = {2, 4, 2, 2};
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
  int intervals1[] = { 1,  1,  1,  1,  1,  1,  1,  2,  2,  4,  4,  4,  4};
  int subintervals1[] = 
    { 1,  1,  3,  3,  3,  4,  4,  1,  2,  1,  1,  1,  2};

  int expected_profits1[] = {10, 10, 14, 14, 14, 16, 16, 18, 28, 40, 40, 40, 48 };

  /* Run the algorithm */
  reduce_profits_to_mimimal(profits1, intervals1, subintervals1, epsilon1, 
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
  int subintervals2[] = {2, 4, 2, 2};
  int expected_profits2[] = {44, 62, 89, 107};

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

  if(suite_status == SUCCESS)
    printf("\tAll passed!\n");

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

  /* Check expected outputs */  
  for(int i = 0; i < n1; i++)
  {
    if(profits1[i] != expected_profits1[i] || weights1[i] == expected_weights1[i])
    {
      suite_status = FAILURE;
      status = FAILURE;
    }
  }

  /* Log errors */
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
  status = SUCCESS;
  int profits2[] = {15855, 15855, 20385, 20385, 20385, 24915, 31711, 31711,
                    31711, 31711, 31711, 31711, 0, 0, 47566, 47566, 47566, 
                    47566, 67952, 79277};
  int weights2[] = {1, 1, 2, 2, 2, 3, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 6, 7};
  int intervals2[] = {1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2 };
  int subintervals2[] = {2, 2, 4, 4, 4, 6, 2, 2, 2, 2, 2, 2, 2, 2};
  int n2 = 20;
  int current_i2 = 3;
  int current_k2 = 2;
  double epsilon2 = 1.0/6.0;

  prune_excess_weight_items(profits2, weights2, intervals2, subintervals2,
                            current_i2, current_k2, epsilon2, n2);

  int expected_profits2[] = {15855, 15855, 20385, 20385, 20385, 24915, 31711, 
                            31711, 31711, 31711, 31711, 31711, 0, 0, 47566, 
                            47566, 47566, 0, 67952, 79277};
  int expected_weights2[] = {1, 1, 2, 2, 2, 3, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 0,
                             6, 7};

  /* Check expected outputs */  
  for(int i = 0; i < n2; i++)
  {
    if(profits2[i] != expected_profits2[i] || weights2[i] == expected_weights2[i])
    {
      suite_status = FAILURE;
      status = FAILURE;
    }
  }

  /* Log errors */
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
  int weights3[] = {1, 1, 1, 1, 1, 1, 2, 2, 3, 3, 3, 3, 3};
  int intervals3[] = {1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2};
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
    if(profits3[i] != expected_profits3[i] || weights3[i] == expected_weights3[i])
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

void test_redefine_large_set(void);
void test_redefine_large_set(void)
{
  /* Check that the pointers that originally pointed to an array of profits and
     weights with 0 profit and 0 weight items have been updated to ones without
     such cases */
  
}

