/*****************************************************************************
 * FPTAS_test.cpp                                                            *
 * Author: Nelson Frew                                                       *
 * First edit: 19/02/18                                                      *
 * Last edit: 19/02/18                                                       *
 * Description:                                                              *
 *   Unit tests for the branch and bound algorithm which uses an unspecified *
 *   but already tested FPTAS framework.                                     *
 * TODO:                                                                     *
 *   Problem Instance structure tests                                        *
 *   Problem Queue                                                           *
 *     create queue                                                          *
 *     is full                                                               *
 *     is empty                                                              *
 *     enqueue                                                               *
 *     dequeue                                                               *
 *     front                                                                 *
 *     rear                                                                  *
 *   Branch and bound                                                        *
 *     Find heuristic initial glb                                            *
 *     Find bounds                                                           *
 *     Find branching variables                                              *
 *     Generate and enqueue                                                  *
 *     Select and dequeue nodes                                              *
 *                                                                           *
 *****************************************************************************/

#define TESTING
#include "branch_and_bound_2.c"
#include <gtest/gtest.h>
#include <time.h>
#include <math.h>

class branch_and_bound_mechanismTest : public testing::Test
{
  void SetUp(){
  }
  void TearDown(){
  }
};

class problem_instance_queueTest : public testing::Test
{
  void SetUp(){
  }
  void TearDown(){
  }
};

/* Queue Test Cases */

TEST(problem_instance_queueTest, create_queueTest){
  /* Make sure that the create_queue algorithm indeed creates an instance of 
   * a queue which has all the expected structure members and is initialised
   * completely empty */
  srand(time(NULL));

  /* Create the queue */
  int capacity = rand() % 10000000;
  Problem_Queue *test_problem_queue = create_queue(capacity);

  /* Check that it has a front, a rear, a size, a capacity and an array which 
   * is NULL. */
  ASSERT_EQ(test_problem_queue->capacity, capacity);
  ASSERT_EQ(test_problem_queue->rear, capacity - 1);
  ASSERT_EQ(test_problem_queue->size, 0);

}

TEST(problem_instance_queueTest, enqueueTest){
  /* Make sure, given a random problem node, the enqueue operation correctly 
   * places the problem at the rear of the queue 
   * TODO there's a segfault somewhere in here. */
  srand(time(NULL));

  /* Create the queue */
  int capacity = rand() % 10000000 + 1;
  Problem_Queue *test_problem_queue = create_queue(capacity);

  /* Create the problem instance */
  int n = capacity;
  Problem_Instance *test_instance;
  test_instance->parent = NULL;
  test_instance->variable_statuses = (int *) malloc(sizeof(int) * n);
  memset(test_instance->variable_statuses, 1, sizeof(int) * n);
  test_instance->lower_bound = 0;
  test_instance->upper_bound = 100;  

  /* Save all the properties of the problem instance */
  int lower_bound = test_instance->lower_bound;
  int upper_bound = test_instance->upper_bound;
  int *variable_statuses = test_instance->variable_statuses;

  /* Place the instance in the queue*/
  enqueue(test_problem_queue, test_instance);

  /* Access the head of the queue and compare the problem characteristics with
   * the saved characteristics */
  int front = test_problem_queue->front;
  ASSERT_EQ(NULL, test_problem_queue->array[front]->parent);
  ASSERT_EQ(test_problem_queue->array[front]->variable_statuses, variable_statuses);
  ASSERT_EQ(test_problem_queue->array[front]->lower_bound, lower_bound);
  ASSERT_EQ(test_problem_queue->array[front]->upper_bound, upper_bound); 

  free(test_instance->variable_statuses);
}

TEST(problem_instance_queueTest, dequeueTest){
  /* Make sure, given a random queue of problem nodes, that the dequeue operation
   * correctly removes the node at the head of the queue. */
  srand(time(NULL));

  /* Create the queue */
  int capacity = rand() % 10000000 + 1;
  Problem_Queue *test_problem_queue = create_queue(capacity);
  int n = capacity;

  /* Create the problem node*/
  Problem_Instance *test_instance;
  test_instance->parent = NULL;
  test_instance->variable_statuses = (int *) malloc(sizeof(int) * n);
  memset(test_instance->variable_statuses, 1, sizeof(int) * n);
  test_instance->lower_bound = 10;
  test_instance->upper_bound = 110;

  /* Put the node in */
  enqueue(test_problem_queue, test_instance);

  /* Create blank slate problem node */
  Problem_Instance *blank_slate_instance;

  /* Dequeue the node into this blank slate */
  blank_slate_instance = dequeue(test_problem_queue);

  /* Compare and assert the original with the dequeued */
  ASSERT_EQ(test_instance->parent, blank_slate_instance->parent);
  ASSERT_EQ(test_instance->variable_statuses, blank_slate_instance->variable_statuses);
  ASSERT_EQ(test_instance->lower_bound, blank_slate_instance->lower_bound);
  ASSERT_EQ(test_instance->upper_bound, blank_slate_instance->upper_bound);

  /* Make sure the queue is now empty */
  ASSERT_EQ(NULL, dequeue(test_problem_queue));
  ASSERT_EQ(test_problem_queue->size, 0);
}


TEST(problem_instance_queueTest, is_fullTest){
  /* Make sure, given a random series of problem instances pumped 
   * into a randomly sized (i.e. random capacity) queue that the queue correctly
   * recognises when it has reached capacity. */
  srand(time(NULL));

  /* Randomly generate the queue capacity */
  int capacity = rand() % 10000000 + 1;

  /* Create the queue */
  Problem_Queue *test_problem_queue = create_queue(capacity);

  /* Generate as many unique nodes as there is capacity */
  /* Enqueue the nodes and make sure that the queue thinks it is full */
  int n = capacity;
  for(int i = 0; i < n; i++)
  {
    Problem_Instance *test_problem;
    test_problem->parent = i*3;
    test_problem->lower_bound = i*3;
    test_problem->upper_bound = i*3;
    enqueue(test_problem_queue, test_problem);
  }  
  
   ASSERT_EQ(is_full(test_problem_queue, 1));

  /* Try to append another unique node, hoping that it fails */
  Problem_Instance *test_problem;
  test_problem->parent = n*3;
  test_problem->lower_bound = n*3;
  test_problem->upper_bound = n*3;

  int size_before = test_problem->size;
  enqueue(test_problem_queue, test_problem);
  int size_after = test_problem->size;
  ASSERT_EQ(size_before, size_after);

  /* Check the whole queue and make sure that the node isn't in it */
  for(int i = 0; i < n; i++)
    ASSERT_NEQ(test_problem_queue->array[i]->lower_bound, test_problem->lower_bound);
}

TEST(problem_instance_queueTest, is_emptyTest){
  /* Make sure, given a randomly populated problem queue of n items, that the
   * queue will correctly recognise when it has no more elements after n 
   * dequeue operations. */
  srand(time(NULL));

  /* Randomly generate the queue capacity */
  int capacity = rand() % 10000000 + 1;

  /* Create the queue */
  Problem_Queue *test_problem_queue = create_queue(capacity);

  /* Assert that its empty */
  ASSERT_EQ(is_empty(test_problem_queue, 1);

  /* Populate it with at most as many unique nodes as there is capacity */
  /* Enqueue the nodes and make sure that the queue thinks it is full */
  int n = rand() % capacity + 1; 
  for(int i = 0; i < n; i++)
  {
    Problem_Instance *test_problem;
    test_problem->parent = i*3;
    test_problem->lower_bound = i*3;
    test_problem->upper_bound = i*3;
    enqueue(test_problem_queue, test_problem);
  }  
  
  /* Dequeue while not empty */
  int counter = 0;
  while(!is_empty(test_problem_queue) && (counter <= 2*n))
  {
    test_problem = dequeue(test_problem_queue);
    counter++;
  }

  /* Make sure we dequeued as many as we put in */
  ASSERT_EQ(counter, n);
}

TEST(problem_instance_queueTest, frontTest){
  /* Make sure, given a randomly populated queue of problem nodes, that the 
   * method which identifies the front of the queue operates as expected. */
  /* Randomly generate queue capacity */

  /* Create queue */

  /* Generate a node and save its pointer */

  /* Generate a random number of nodes from 0 to capacity-1 */

  /* Make sure that the head points to the same structure as saved before */
}

TEST(problem_instance_queueTest, rearTest){
  /* Make sure, given a randomlmy populated queue of problem nodes, that the 
   * method which identifies the rear of the queue operates as expected. */
  /* Randomly generate queue capacity */

  /* Create queue */

  /* Generate a random number of nodes from 0 to capacity-1 */

  /* Generate a node and save its pointer */

  /* Make sure that the rear points to the same structure as this saved 
   * pointer */

}

/* Branch and bound test cases */

TEST(branch_and_bound_mechanismTest, find_heuristic_initial_glbTest){
  /* Make sure, given a problem instance with known optimal objective value
   * that the heuristic initial GLB is indeed less than it. */
  /* Define problem instance */

  int profits[] = {94, 506, 416, 992, 649, 237, 457, 815, 446, 422, 791, 359, 
                  667, 598, 7, 544, 334, 766, 994, 893, 633, 131, 428, 700, 617,
                  874, 720, 419, 794, 196, 997, 116, 908, 539, 707, 569, 537, 
                  931, 726, 487, 772, 513, 81, 943, 58, 303, 764, 536, 724, 789};
  int weights[] = {485, 326, 248, 421, 322, 795, 43, 845, 955, 252, 9, 901, 122,
                   94, 738, 574, 715, 882, 367, 984, 299, 433, 682, 72, 874, 138,
                   856, 145, 995, 529, 199, 277, 97, 719, 242, 107, 122, 70, 98,
                   600, 645, 267, 972, 895, 213, 748, 487, 923, 29, 674}; 
  int n = 50;
  int z = 8373;
  /* Create queue */

  /* Derive initial GLB */

  /* Assert z >= GLB */

}

TEST(branch_and_bound_mechanismTest, find_boundsTest){
  /* Make sure, given a problem instance with known optimal objective value
   * that the return UB and LB are in the correct relative positions. */
  /* Define problem instance */

  int profits[] = {94, 506, 416, 992, 649, 237, 457, 815, 446, 422, 791, 359, 
                  667, 598, 7, 544, 334, 766, 994, 893, 633, 131, 428, 700, 617,
                  874, 720, 419, 794, 196, 997, 116, 908, 539, 707, 569, 537, 
                  931, 726, 487, 772, 513, 81, 943, 58, 303, 764, 536, 724, 789};
  int weights[] = {485, 326, 248, 421, 322, 795, 43, 845, 955, 252, 9, 901, 122,
                   94, 738, 574, 715, 882, 367, 984, 299, 433, 682, 72, 874, 138,
                   856, 145, 995, 529, 199, 277, 97, 719, 242, 107, 122, 70, 98,
                   600, 645, 267, 972, 895, 213, 748, 487, 923, 29, 674}; 
  int n = 50;
  int z = 8373;

  /* Create queue */
  

  /* Derive initial GLB */

  /* Assert UB >= z >= LB*/
}

TEST(branch_and_bound_mechanismTest, generate_and_enqueue_nodesTest){
  /* Make sure, given a problem queue and a current problem instance structure,
   * assuming an abitrary variable to branch on, that the algorithm correctly
   * generates two subinstances: one with the variable constrained on and the
   * other constrained off.*/
  /* Generate a problem with a random n */

  /* Create an empty queue */

  /* Generate a random number to represent the variable to branch on */

  /* Make expected versions of the lists */

  /* Run generate_and_enqueue */

  /* Compare the lists, asserting equality */

}

TEST(branch_and_bound_mechanismTest, select_and_dequeue_nodesTest){
  /* Make sure, given a list of nodes, that the select_and_dequeue algorithm 
   * both correctly returns a problem instance structure and ensures it is no
   * longer a part of the node list. One note to self: this is only going to 
   * pass for thee b&b which has a FIFO strategy for node selection. */

  /* Generate a problem */
 
  /* Create a queue */

  /* Generate and enqueue the node */

  /* Select and dequeue the node */
}

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
