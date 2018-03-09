/*****************************************************************************
 * williamson_shmoy_dp_test.cpp                                              *
 * Author: Nelson Frew                                                       *
 * First edit: 24/01/18                                                      *
 * Last edit: 24/01/18                                                       *
 * Description:                                                              *
 *   Unit tests for williamson_shmoy_dp.c implemented with the google unit   *
 *   testing library.                                                        *
 * TODO:                                                                     *
 *   Write down testing compilation instructions!                            *
 *   Make sure all the tests clean up after themselves!                      *
 *****************************************************************************/

#define TESTING
#include "williamson_shmoy_dp.c"
#include <gtest/gtest.h>
#include <time.h>
#include <math.h>


int compare_ints(const void* a, const void* b)
{
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;
 
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
 
    // return (arg1 > arg2) - (arg1 < arg2); // possible shortcut
    // return arg1 - arg2; // erroneous shortcut (fails if INT_MIN is present)
}

int brute_force_knapsack(struct problem_item items[], int capacity, int n, int *solution_array)
{
  int upper_bound = (int) pow(2.0, (double) n);
  int best_profit = 0; 
  int best_solution = 0;
  int this_profit, this_weight, current_solution, item_of_interest;
 
  /* Brute force search for the solution */
  for(int i = 0; i < upper_bound; i++)
  {
    current_solution = i;
    this_profit = 0;
    this_weight = 0;
    item_of_interest = 0;
    while (current_solution > 0)
    {
      if (current_solution % 2)
      {
        this_profit += items[item_of_interest].profit;
        this_weight += items[item_of_interest].weight;
      }
      current_solution >>= 1;
    item_of_interest++;
    }
    if ((this_weight <= capacity)&&(this_profit > best_profit))
    {
      best_profit = this_profit;
      best_solution = i;
    }
  }
  
  /* Derive solution and put in solution_array */
  int item_no = 0;
  while(best_solution > 0)
  {
    if (best_solution & 1)
    {
      solution_array[item_no] == 1;
    }
    best_solution >>= 1;
    item_no++;
  }
  return best_profit;
} 

class sorted_mergeTest : public testing::Test
{
  void SetUp(){
    
  }
  void TearDown(){

  }
};

class front_back_splitTest : public testing::Test
{
  void SetUp(){
    
  }
  void TearDown(){
    
  }
};

class merge_sortTest : public testing::Test
{
  void SetUp(){
    
  }
  void TearDown(){
    
  }
};

class remove_dominated_pairsTest : public testing::Test
{
  void SetUp(){
    
  }
  void TearDown(){
    
  }
};

class pushTest : public testing::Test
{
  void SetUp(){
    
  }
  void TearDown(){
    
  }
};

class williamson_shmoys_DPTest : public testing::Test
{
  void SetUp(){
    
  }
  void TearDown(){
    
  }
};

struct solution_pair* make_solution_pair(int weight, int profit, int n)
{
  struct solution_pair* new_pair = 
    (struct solution_pair*) calloc(sizeof(struct solution_pair) + n,
                                   sizeof(int)); 
  if (new_pair)
  {
    struct solution_pair const temp_pair =
      {.weight = weight, .profit = profit};
    memcpy(new_pair, &temp_pair, sizeof(struct solution_pair));
  }
  return new_pair;
}

TEST(pushTest, NodesPushedToHead){
  /* Make sure that the haed before is the same as the head->next afterward, 
     and also check the tails of both lists to ensure they are the same. */
}

TEST(sorted_mergeTest, MergesInOrder){
  /* For two 1-item linked lists, it should return the head of a linked list of
     length 2 in ascending order, according to weight */
  /* This assumes that pushTest passed */
  struct solution_pair* first_head = NULL;
  struct solution_pair* second_head = NULL;
  int length = 2;
  int control_array[length*2];
  int old_random_number, new_random_number;

  /* Initialise random seed */
  srand(time(NULL));
  old_random_number = rand();
  for(int i = 0; i < length; i++)
  {
    do
    {
      new_random_number = rand();
    } while(new_random_number >= old_random_number);
    /* New random number must be at most as big as the old one */
    /* This is because it needs to be nondecreasing from head to tail */
    control_array[i] = new_random_number;
    push(&first_head, new_random_number, 0, length);
    old_random_number = new_random_number;  
  }
  old_random_number = rand();
  for(int i = 0; i < length; i++)
  {
    do{
      new_random_number = rand();
    } while(new_random_number >= old_random_number);
    /* New random numbe must be at least as big as the old one */
    control_array[i+length] = new_random_number;
    push(&second_head, new_random_number, 0, length); 
    old_random_number = new_random_number;
  }

  /* Sort the control array */
  int size = sizeof(control_array)/sizeof(control_array[0]);
  qsort(control_array, size, sizeof(int), compare_ints);

  /* Merge the two linked lists */
  struct solution_pair* head;
  head = sorted_merge(first_head, second_head);

  /* I think now we can just compare each element */
  int n = 0;
  for(int i = 0; i < 2*length; i++)
  {
    //ASSERT_NE(head, NULL);
    ASSERT_EQ(control_array[i], head->weight);
    head = head->next;
    n++;
  }
  ASSERT_EQ(4, n);
}

TEST(sorted_mergeTest, MergesInOrderGeneral){
  /* For two 10-item linked lists, each in ascending order, it should return 
     the head of a linked list of length 20 in ascending order */
  /* This assumes that pushTest passed */
  struct solution_pair* first_head = NULL;
  struct solution_pair* second_head = NULL;
  int length = 10;
  int control_array[length*2];
  int old_random_number, new_random_number;

  /* Initialise random seed */
  srand(time(NULL));
  old_random_number = rand();
  for(int i = 0; i < length; i++)
  {
    do
    {
      new_random_number = rand();
    } while(new_random_number >= old_random_number);
    /* New random number must be at most as big as the old one */
    /* This is because it needs to be nondecreasing from head to tail */
    control_array[i] = new_random_number;
    push(&first_head, new_random_number, 0, length);
    old_random_number = new_random_number;  
  }
  old_random_number = rand();
  for(int i = 0; i < length; i++)
  {
    do{
      new_random_number = rand();
    } while(new_random_number >= old_random_number);
    /* New random numbe must be at least as big as the old one */
    control_array[i+length] = new_random_number;
    push(&second_head, new_random_number, 0, length); 
    old_random_number = new_random_number;
  }

  /* Sort the control array */
  int size = sizeof(control_array)/sizeof(control_array[0]);
  qsort(control_array, size, sizeof(int), compare_ints);

  /* Merge the two linked lists */
  struct solution_pair* head;
  head = sorted_merge(first_head, second_head);

  /* I think now we can just compare each element */
  int n = 0;
  for(int i = 0; i < 2*length; i++)
  {
    //ASSERT_NE(head, NULL);
    ASSERT_EQ(control_array[i], head->weight);
    head = head->next;
    n++;
  }
  ASSERT_EQ(20, n);
}

TEST(sorted_mergeTest, MergesInOrderGeneralLongInput){
  /* For two 500-item linkd lists, each in ascending order, it should return 
     the head of a linked list of length 1000 in ascending order */
  /* This assumes that pushTest passed */
  /* For two 10-item linked lists, each in ascending order, it should return 
     the head of a linked list of length 20 in ascending order */
  /* This assumes that pushTest passed */
  /* TODO Get this working. it keeps breaking! */
}

TEST(front_back_splitTest, ListsDisconnectedGeneralVerySmallEven){
  /* Traversal through to end of both lists shuld not yield the same node 
     pointer. This case has length 2. */
  /* This assumes push works */

  /* Create linked list of length 2 */
  int length = 2;
  struct solution_pair* original_head = NULL;
  for(int i=0; i < length; i++)
    push(&original_head, 0, 0, length);

  /* Split the linked list in two */
  struct solution_pair* first_sublist_head = NULL;
  struct solution_pair* second_sublist_head = NULL;
  front_back_split(original_head, &first_sublist_head, &second_sublist_head);

  /* Traverse first list */
  struct solution_pair* first_sublist_probe = first_sublist_head;
  if (second_sublist_head != NULL)
    while (first_sublist_probe->next != NULL)
      first_sublist_probe = first_sublist_probe->next;

  /* Traverse second list */
  struct solution_pair* second_sublist_probe = second_sublist_head;
  if (second_sublist_head != NULL)
    while (second_sublist_probe->next != NULL)
      second_sublist_probe = second_sublist_probe->next;
  
  /* If both lists were not NULL */
  if (!((first_sublist_head == NULL) && (second_sublist_head == NULL)))
    ASSERT_NE(first_sublist_probe, second_sublist_probe);
  else
  {
    /* Splitting an empty linked list should give NULL everywhere */
    ASSERT_EQ(first_sublist_head, second_sublist_head);
    ASSERT_EQ(first_sublist_head, second_sublist_probe);
    ASSERT_EQ(first_sublist_head, first_sublist_probe);
    ASSERT_EQ(first_sublist_probe, second_sublist_head);
    ASSERT_EQ(first_sublist_probe, second_sublist_probe);
    ASSERT_EQ(second_sublist_probe, second_sublist_head); 
  }
}

TEST(front_back_splitTest, ListsDisconnectedGeneralVerySmallOdd){
  /* Traversal through to end of both lists shuld not yield the same node
     pointer. This case has length 3. */

  /* This assumes push works */

  /* Create linked list of length 2 */
  int length = 3;
  struct solution_pair* original_head = NULL;
  for(int i=0; i < length; i++)
    push(&original_head, 0, 0, length);

  /* Split the linked list in two */
  struct solution_pair* first_sublist_head = NULL;
  struct solution_pair* second_sublist_head = NULL;
  front_back_split(original_head, &first_sublist_head, &second_sublist_head);

  /* Traverse first list */
  struct solution_pair* first_sublist_probe = first_sublist_head;
  if (second_sublist_head != NULL)
    while (first_sublist_probe->next != NULL)
      first_sublist_probe = first_sublist_probe->next;

  /* Traverse second list */
  struct solution_pair* second_sublist_probe = second_sublist_head;
  if (second_sublist_head != NULL)
    while (second_sublist_probe->next != NULL)
      second_sublist_probe = second_sublist_probe->next;
  
  /* If both lists were not NULL */
  if (!((first_sublist_head == NULL) && (second_sublist_head == NULL)))
    ASSERT_NE(first_sublist_probe, second_sublist_probe);
  else
  {
    /* Splitting an empty linked list should give NULL everywhere */
    ASSERT_EQ(first_sublist_head, second_sublist_head);
    ASSERT_EQ(first_sublist_head, second_sublist_probe);
    ASSERT_EQ(first_sublist_head, first_sublist_probe);
    ASSERT_EQ(first_sublist_probe, second_sublist_head);
    ASSERT_EQ(first_sublist_probe, second_sublist_probe);
    ASSERT_EQ(second_sublist_probe, second_sublist_head); 
  }
}

TEST(front_back_splitTest, ListsDisconnectedGeneralLargeEven){
  /* Traversal through to end of both lists shuld not yield the same node
     pointer. This case has length 500. */

  /* This assumes push works */

  /* Create linked list of length 2 */
  int length = 500;
  struct solution_pair* original_head = NULL;
  for(int i=0; i < length; i++)
    push(&original_head, 0, 0, length);

  /* Split the linked list in two */
  struct solution_pair* first_sublist_head = NULL;
  struct solution_pair* second_sublist_head = NULL;
  front_back_split(original_head, &first_sublist_head, &second_sublist_head);

  /* Traverse first list */
  struct solution_pair* first_sublist_probe = first_sublist_head;
  if (second_sublist_head != NULL)
    while (first_sublist_probe->next != NULL)
      first_sublist_probe = first_sublist_probe->next;

  /* Traverse second list */
  struct solution_pair* second_sublist_probe = second_sublist_head;
  if (second_sublist_head != NULL)
    while (second_sublist_probe->next != NULL)
      second_sublist_probe = second_sublist_probe->next;
  
  /* If both lists were not NULL */
  if (!((first_sublist_head == NULL) && (second_sublist_head == NULL)))
    ASSERT_NE(first_sublist_probe, second_sublist_probe);
  else
  {
    /* Splitting an empty linked list should give NULL everywhere */
    ASSERT_EQ(first_sublist_head, second_sublist_head);
    ASSERT_EQ(first_sublist_head, second_sublist_probe);
    ASSERT_EQ(first_sublist_head, first_sublist_probe);
    ASSERT_EQ(first_sublist_probe, second_sublist_head);
    ASSERT_EQ(first_sublist_probe, second_sublist_probe);
    ASSERT_EQ(second_sublist_probe, second_sublist_head); 
  }
}

TEST(front_back_splitTest, ListsDisconnectedGeneralLargeOdd){
  /* Traversal through to end of both lists shuld not yield the same node
     pointer. This case has length 501. */

  /* This assumes push works */

  /* Create linked list of length 2 */
  int length = 501;
  struct solution_pair* original_head = NULL;
  for(int i=0; i < length; i++)
    push(&original_head, 0, 0, length);

  /* Split the linked list in two */
  struct solution_pair* first_sublist_head = NULL;
  struct solution_pair* second_sublist_head = NULL;
  front_back_split(original_head, &first_sublist_head, &second_sublist_head);

  /* Traverse first list */
  struct solution_pair* first_sublist_probe = first_sublist_head;
  if (second_sublist_head != NULL)
    while (first_sublist_probe->next != NULL)
      first_sublist_probe = first_sublist_probe->next;

  /* Traverse second list */
  struct solution_pair* second_sublist_probe = second_sublist_head;
  if (second_sublist_head != NULL)
    while (second_sublist_probe->next != NULL)
      second_sublist_probe = second_sublist_probe->next;
  
  /* If both lists were not NULL */
  if (!((first_sublist_head == NULL) && (second_sublist_head == NULL)))
    ASSERT_NE(first_sublist_probe, second_sublist_probe);
  else
  {
    /* Splitting an empty linked list should give NULL everywhere */
    ASSERT_EQ(first_sublist_head, second_sublist_head);
    ASSERT_EQ(first_sublist_head, second_sublist_probe);
    ASSERT_EQ(first_sublist_head, first_sublist_probe);
    ASSERT_EQ(first_sublist_probe, second_sublist_head);
    ASSERT_EQ(first_sublist_probe, second_sublist_probe);
    ASSERT_EQ(second_sublist_probe, second_sublist_head); 
  }
}

TEST(front_back_splitTest, ListsDisconnectedFirstBasis){
  /* For list length 0 */

  /* This assumes push works */

  /* Create linked list of length 2 */
  int length = 0;
  struct solution_pair* original_head = NULL;
  for(int i=0; i < length; i++)
    push(&original_head, 0, 0, length);

  /* Split the linked list in two */
  struct solution_pair* first_sublist_head = NULL;
  struct solution_pair* second_sublist_head = NULL;
  front_back_split(original_head, &first_sublist_head, &second_sublist_head);

  /* Traverse first list */
  struct solution_pair* first_sublist_probe = first_sublist_head;
  if (second_sublist_head != NULL)
    while (first_sublist_probe->next != NULL)
      first_sublist_probe = first_sublist_probe->next;

  /* Traverse second list */
  struct solution_pair* second_sublist_probe = second_sublist_head;
  if (second_sublist_head != NULL)
    while (second_sublist_probe->next != NULL)
      second_sublist_probe = second_sublist_probe->next;
  
  /* If both lists were not NULL */
  if (!((first_sublist_head == NULL) && (second_sublist_head == NULL)))
    ASSERT_NE(first_sublist_probe, second_sublist_probe);
  else
  {
    /* Splitting an empty linked list should give NULL everywhere */
    ASSERT_EQ(first_sublist_head, second_sublist_head);
    ASSERT_EQ(first_sublist_head, second_sublist_probe);
    ASSERT_EQ(first_sublist_head, first_sublist_probe);
    ASSERT_EQ(first_sublist_probe, second_sublist_head);
    ASSERT_EQ(first_sublist_probe, second_sublist_probe);
    ASSERT_EQ(second_sublist_probe, second_sublist_head); 
  }
}

TEST(front_back_splitTest, ListsDisconnectedSecondBasis){
  /* For list length 1 TODO This does not work because of assertions about 
     null pointer */

  /* This assumes push works */

  /* Create linked list of length 2 */
  int length = 1;
  struct solution_pair* original_head = NULL;
  for(int i=0; i < length; i++)
    push(&original_head, 0, 0, length);

  /* Split the linked list in two */
  struct solution_pair* first_sublist_head = NULL;
  struct solution_pair* second_sublist_head = NULL;
  front_back_split(original_head, &first_sublist_head, &second_sublist_head);

  /* Traverse first list */
  struct solution_pair* first_sublist_probe = first_sublist_head;
  if (second_sublist_head != NULL)
    while (first_sublist_probe->next != NULL)
      first_sublist_probe = first_sublist_probe->next;

  /* Traverse second list */
  struct solution_pair* second_sublist_probe = second_sublist_head;
  if (second_sublist_head != NULL)
    while (second_sublist_probe->next != NULL)
      second_sublist_probe = second_sublist_probe->next;
  
  /* If neither or one of the sublists is null */
  if (!((first_sublist_head == NULL) && (second_sublist_head == NULL)))
    ASSERT_NE(first_sublist_probe, second_sublist_probe);
  else
  {
    /* Splitting an empty linked list should give NULL everywhere */
    ASSERT_EQ(first_sublist_head, second_sublist_head);
    ASSERT_EQ(first_sublist_head, second_sublist_probe);
    ASSERT_EQ(first_sublist_head, first_sublist_probe);
    ASSERT_EQ(first_sublist_probe, second_sublist_head);
    ASSERT_EQ(first_sublist_probe, second_sublist_probe);
    ASSERT_EQ(second_sublist_probe, second_sublist_head); 
  }
}

TEST(merge_sortTest, MergeSortFirstBaseCase){
  /* For list length 0 */
  /* This assumes that front_back_split and sorted_merge work */
  int length = 0;
  int first_random_val, second_random_val;
  struct solution_pair* head = NULL;
  
  /* Create linked list for given length, populated with random values */
  for(int i = 0; i < length; i++)
  {
    first_random_val = rand();
    second_random_val = rand();
    push(&head, first_random_val, second_random_val, length); 
  }

  /* Merge sort the linked list */
  merge_sort(&head);

  /* Empty list scenario */
  if(length == 0)
    ASSERT_EQ(NULL, head);
  else if (length == 1)
  {
    ASSERT_EQ(NULL, head->next);
  }
  else
  {
    /* Traverse the list, asserting that it is nondecreasing */
    struct solution_pair* this_value = head->next;
    struct solution_pair* previous_value = head;
    while(this_value->next != NULL)
    {
      ASSERT_GE(this_value->weight, previous_value->weight);
      this_value = this_value->next;
      previous_value = previous_value->next;
    }
  }
}

TEST(merge_sortTest, MergeSortSecondBaseCase){
  /* For list length 1 */
  /* This assumes that front_back_split and sorted_merge work */
  int length = 1;
  int first_random_val, second_random_val;
  struct solution_pair* head = NULL;
  
  /* Create linked list for given length, populated with random values */
  for(int i = 0; i < length; i++)
  {
    first_random_val = rand();
    second_random_val = rand();
    push(&head, first_random_val, second_random_val, length); 
  }

  /* Merge sort the linked list */
  merge_sort(&head);

  /* Empty list scenario */
  if(length == 0)
    ASSERT_EQ(NULL, head);
  else if (length == 1)
    ASSERT_EQ(NULL, head->next);
  else
  {
    /* Traverse the list, asserting that it is nondecreasing */
    struct solution_pair* this_value = head->next;
    struct solution_pair* previous_value = head;
    while(this_value->next != NULL)
    {
      ASSERT_GE(this_value->weight, previous_value->weight);
      this_value = this_value->next;
      previous_value = previous_value->next;
    }
  }
}

TEST(merge_sortTest, ListSortedAscendingGeneralVerySmallEven){
  /* Ensure the linked list is sorted in ascending order. List linked in this 
     test is 2. */
  /* This assumes that front_back_split and sorted_merge work */
  int length = 2;
  int first_random_val, second_random_val;
  struct solution_pair* head = NULL;
  
  /* Create linked list for given length, populated with random values */
  for(int i = 0; i < length; i++)
  {
    first_random_val = rand();
    second_random_val = rand();
    push(&head, first_random_val, second_random_val, length); 
  }

  /* Merge sort the linked list */
  merge_sort(&head);

  /* Empty list scenario */
  if(length == 0)
    ASSERT_EQ(NULL, head);
  else if (length == 1)
    ASSERT_EQ(NULL, head->next);
  else
  {
    /* Traverse the list, asserting that it is nondecreasing */
    struct solution_pair* this_value = head->next;
    struct solution_pair* previous_value = head;
    while(this_value->next != NULL)
    {
      ASSERT_GE(this_value->weight, previous_value->weight);
      this_value = this_value->next;
      previous_value = previous_value->next;
    }
  }
}

TEST(merge_sortTest, ListSortedAscendingGeneralVerySmallOdd){
  /* Ensure the linked list is sorted in ascending order. List linked in this 
     test is 3. */
  /* This assumes that front_back_split and sorted_merge work */
  int length = 3;
  int first_random_val, second_random_val;
  struct solution_pair* head = NULL;
  
  /* Create linked list for given length, populated with random values */
  for(int i = 0; i < length; i++)
  {
    first_random_val = rand();
    second_random_val = rand();
    push(&head, first_random_val, second_random_val, length); 
  }

  /* Merge sort the linked list */
  merge_sort(&head);

  /* Empty list scenario */
  if(length == 0)
    ASSERT_EQ(NULL, head);
  else if (length == 1)
    ASSERT_EQ(NULL, head->next);
  else
  {
    /* Traverse the list, asserting that it is nondecreasing */
    struct solution_pair* this_value = head->next;
    struct solution_pair* previous_value = head;
    while(this_value->next != NULL)
    {
      ASSERT_GE(this_value->weight, previous_value->weight);
      this_value = this_value->next;
      previous_value = previous_value->next;
    }
  }
}

TEST(merge_sortTest, ListSortedAscendingGeneralLargeEven){
  /* Ensure the linked list is sorted in ascending order. List linked in this 
     test is 500. */
  /* This assumes that front_back_split and sorted_merge work */
  int length = 500;
  int first_random_val, second_random_val;
  struct solution_pair* head = NULL;
  
  /* Create linked list for given length, populated with random values */
  for(int i = 0; i < length; i++)
  {
    first_random_val = rand();
    second_random_val = rand();
    push(&head, first_random_val, second_random_val, length); 
  }

  /* Merge sort the linked list */
  merge_sort(&head);

  /* Empty list scenario */
  if(length == 0)
    ASSERT_EQ(NULL, head);
  else if (length == 1)
    ASSERT_EQ(NULL, head->next);
  else
  {
    /* Traverse the list, asserting that it is nondecreasing */
    struct solution_pair* this_value = head->next;
    struct solution_pair* previous_value = head;
    while(this_value->next != NULL)
    {
      ASSERT_GE(this_value->weight, previous_value->weight);
      this_value = this_value->next;
      previous_value = previous_value->next;
    }
  }
}

TEST(merge_sortTest, ListSortedAscendingGeneralLargeOdd){
  /* Ensure the linked list is sorted in ascending order. List linked in this 
     test is 501. */
  /* This assumes that front_back_split and sorted_merge work */
  int length = 501;
  int first_random_val, second_random_val;
  struct solution_pair* head = NULL;
  
  /* Create linked list for given length, populated with random values */
  for(int i = 0; i < length; i++)
  {
    first_random_val = rand();
    second_random_val = rand();
    push(&head, first_random_val, second_random_val, length); 
  }

  /* Merge sort the linked list */
  merge_sort(&head);

  /* Empty list scenario */
  if(length == 0)
    ASSERT_EQ(NULL, head);
  else if (length == 1)
    ASSERT_EQ(NULL, head->next);
  else
  {
    /* Traverse the list, asserting that it is nondecreasing */
    struct solution_pair* this_value = head->next;
    struct solution_pair* previous_value = head;
    while(this_value->next != NULL)
    {
      ASSERT_GE(this_value->weight, previous_value->weight);
      this_value = this_value->next;
      previous_value = previous_value->next;
    }
  }
}

TEST(remove_dominated_pairsTest, RemovesAllDominatedPairsGeneral){
  /* This assumes that push, merge_sort, front_back_split, and sorted_merge 
     all work. */

  /* Pick a random amount of pairs between 0 and 100 */
  int number_of_pairs = rand() % 10+1;

  /* Generate a linked list of a bunch of pairs that are nondecreasing in 
    weight and profit*/
  /* TODO put this method into whatever the other test was */
  struct solution_pair* head = NULL;
  int iteration = 0;
  int old_random_weight = number_of_pairs*10000+1;
  int old_random_profit = number_of_pairs*10000+1;
  int new_random_weight, new_random_profit;
  while(iteration < number_of_pairs)
  {
    /* TODO Ensure it is strictly increasing, so every subsequent push 
       should be no more than the previous, i.e. each should be lower */
    new_random_weight =
      (number_of_pairs*10000) - (rand() % 10000 + (iteration*10000));
     
    new_random_profit =
      (number_of_pairs*10000) - (rand() % 10000 + (iteration*10000));

    push(&head, new_random_weight, new_random_profit, number_of_pairs);
    iteration++;
  }

  /* Dilute the selection of pairs by a random amount between 100-200 */
  int pair_dilution_amount = (rand() % 100) + 100;
  
  /* For n nodes there will be n-1 gaps; we divide the dilution amount
     evenly between all the gaps
      Note to self: the construction of the nodes on this does not account
     for the variation on all the struct lists.
     TODO Verify this complicated logic */
  pair_dilution_amount /= number_of_pairs-1;
  struct solution_pair* current = head;
  struct solution_pair* temp;
  while(current != NULL)
  {
    temp = current->next;
    for(int i = 0; i < pair_dilution_amount; i++)
    {
      /* Create a new node */
      new_random_profit = rand() % (number_of_pairs*10000);
      new_random_weight = rand() % (number_of_pairs*10000);
      current->next = 
        make_solution_pair(new_random_weight, new_random_profit, number_of_pairs);
      current = current->next;
    }
    current->next = temp;
    current = current->next;

  } 

  /* List should be diluted now and has a very high chance of being dominating */
  /* So, we run the algorithm on it */
  remove_dominated_pairs(&head);

  /* First ensure that all weights should be strictly increasing */
  current = head->next;
  temp = head;
  while (current != NULL)
  {
    ASSERT_GE(current->weight, temp->weight);
    /* Then, if that's true, test that all profits are strictly increasing */
    ASSERT_GE(current->profit, temp->profit);
    current = current->next;
    temp = temp->next;
  }

  /* TODO: cleanup */

}

TEST(williamson_shmoys_DPTest, MaximisedProfitValid){
  /* I guess just make sure i's getting the same solution as a naive brute 
     force algo */
  int capacity = 1000;
  int n_items = 5;
  int brute_force_solution_array[n_items];
  int dp_solution_array[n_items];

  /* Prepare instance */
  struct problem_item items[n_items];  
  for (int i = 0; i < n_items; i++)
  {
    items[i].weight = rand() % 100;
    items[i].profit = rand() % 100;
  }
  
  int brute_force_profit = brute_force_knapsack(items, capacity, n_items, brute_force_solution_array);
  int dp_profit = williamson_shmoys_DP(items, capacity, n_items, dp_solution_array);

  /* First check that the profit is optimal */
  ASSERT_EQ(brute_force_profit, dp_profit);  

  /* Ensure that the profits indeed add up */
  int control_profit = 0;
  int item_no = 0;
  for (int i = 0; i < n_items; i++)
  {
    if(dp_solution_array[i])
      control_profit += items[i].profit;
  }
  ASSERT_EQ(control_profit, dp_profit);
}

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

