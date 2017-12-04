/* I'm sure about:
  Returning a pointer in c


I can test pointer returns with a function
  Design something */

#include <stdio.h>
#include <stdlib.h>

void make_array(int * array_pointer);

int main(){
  int * array_pointer;

  array_pointer = (int *)malloc(10 * sizeof(int));
  //make_array(array_pointer);  <-- I can't get this working

  *array_pointer = 123;

  *(array_pointer+1) = 456;
  
  printf("*array_pointer: %d \n", *array_pointer);

  printf("*(array_pointer+1): %d \n", *(array_pointer+1));

  printf("array_pointer[0]: %d \n", array_pointer[0]);

  printf("array_pointer[1]: %d \n", array_pointer[1]); 

  printf("array_pointer: %p \n", array_pointer);

  return 0;

}

void make_array(int * array_pointer){

  array_pointer = (int *)malloc(10 * sizeof(int));

}
