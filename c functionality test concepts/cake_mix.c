/*This is not actual code*/
/* This is the framework for Williamson and Shmoy's 
   DP Algo for 0,1 Knapsack */
/* Before I do anything about coding this I need to do 
   more analysis on how it would be implemented */

#include <stdio.h>

int main(){
  // Assuming we already have an encoded input
  // Create tuple array
  
  // Then the pseudocode
  // A(1) ← {(0,0),(s_1, w_1)}
  // for j←2 to n do
  //	A(j)←A(j-1)
  //	for each (t,w)∈A(j-1) do
  //		if t+s_j <= B then
  //			Add (t+s_j, w+v_j) to A(j)
  // 	remove dominated pairs from A(j)
  // return max w of the tuples
  return 0;
}

typedef struct{
  int weight;
  int value;
} tTuple;

int * create_tuple_array(capacity){
  /*
    Description:
      Defines a tuple array for a max of 2(B+1) items
    Inputs:
      capacity - corresponds to B
    Returns:
      a pointer to the tuple array
    Notes:
      I'm not sure how exactly to define enough space for 2(B+1) structs.
      Also this will hopefully be the only array in the whole program.
      I want to have the remove_dominating_tuples function pass through this.
  */
}

