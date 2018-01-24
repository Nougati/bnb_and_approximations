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
 *****************************************************************************/
#include "williamson_shmoy_dp.c"
#include <gtest/gtest.h>
#include <time.h>

#define TESTING

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
  int random_number;

  /* Initialise random seed */
  srand(time(NULL));
  random_number = 0;
  for(int i = 0; i < length; i++)
  {
    random_number += rand(); // To make sure it's nondecreasing 
    control_array[i] = random_number;
    push(&first_head, random_number, 0, length); 
  }
  random_number = 0;
  for(int i = 0; i < length; i++)
  {
    random_number += rand(); // To make sure it's nondecreasing
    control_array[i+length] = random_number;
    push(&second_head, random_number, 0, length); 
  }

  /* Sort the control array */
  int size = sizeof(control_array)/sizeof(control_array[0]);
  qsort(control_array, size, sizeof(int), compare_ints);

  /* Merge the two linked lists */
  struct solution_pair* head;
  head = sorted_merge(first_head, second_head);

  /* I think now we can just compare each element */
  for(int i = 0; i < length; i++)
  {
    //ASSERT_NE(head, NULL);
    ASSERT_EQ(control_array[i], head->weight);
    head = head->next;
  }
}

TEST(sorted_mergeTest, MergesInOrderGeneral){
  /* For two 10-item linked lists, each in ascending order, it should return 
     the head of a linked list of length 20 in ascending order */
}

TEST(sorted_mergeTest, MergesInOrderGeneralLongInput){
  /* For two 500-item linkd lists, each in ascending order, it should return 
     the head of a linked list of length 1000 in ascending order */
}

TEST(front_back_splitTest, ListsDisconnectedGeneralVerySmallEven){
  /* Traversal through to end of both lists shuld not yield the same node 
     pointer. This case has length 2. */
}

TEST(front_back_splitTest, ListsDisconnectedGeneralVerySmallOdd){
  /* Traversal through to end of both lists shuld not yield the same node
     pointer. This case has length 3. */
}

TEST(front_back_splitTest, ListsDisconnectedGeneralLargeEven){
  /* Traversal through to end of both lists shuld not yield the same node
     pointer. This case has length 500. */
}

TEST(front_back_splitTest, ListsDisconnectedGeneralLargeOdd){
  /* Traversal through to end of both lists shuld not yield the same node
     pointer. This case has length 501. */
}

TEST(front_back_splitTest, ListsDisconnectedFirstBasis){
  /* For list length 0 */
}

TEST(front_back_splitTest, ListsDisconnectedSecondBasis){
  /* For list length 1 */
}

TEST(merge_sortTest, MergeSortBaseFirstCase){
  /* For list length 0 */
}

TEST(merge_sortTest, MergeSortBaseSecondCase){
  /* For list length 1 */
}

TEST(merge_sortTest, ListSortedAscendingGeneralVerySmallEven){
  /* Ensure the linked list is sorted in ascending order. List linked in this 
     test is 2. */
}

TEST(merge_sortTest, ListSortedAscendingGeneralVerySmallOdd){
  /* Ensure the linked list is sorted in ascending order. List linked in this 
     test is 3. */
}

TEST(merge_sortTest, ListSortedAscendingGeneralLargeEven){
  /* Ensure the linked list is sorted in ascending order. List linked in this 
     test is 500. */
}

TEST(merge_sortTest, ListSortedAscendingGeneralLargeOdd){
  /* Ensure the linked list is sorted in ascending order. List linked in this 
     test is 501. */
}

TEST(remove_dominated_pairsTest, RemovesAllDominatedPairsGeneral){
  /* First ensure that all weights should be strictly increasing */
  /* Then, if that's true, test that all profits are strictly increasing */
}


TEST(williamson_shmoys_DPTest, MaximisedProfitValid){
  /* I guess just make sure i's getting the same solution as a naive brute 
     force algo */
}
int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

