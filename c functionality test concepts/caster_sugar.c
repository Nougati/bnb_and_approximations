/* This one is a control for making a tuple struct */
/* Also an array for tuples */
#include <stdio.h>
#include <stdlib.h>

struct tuple {
  int weight;
  int value; 
};

int main(){
  struct tuple tuplearray[] = {
    1, 2,
    3, 4,
    5, 6,
    7, 8
  };
  printf("(%d, %d)", tuplearray[1].weight, tuplearray[0].value);
 
  return 0;
}
