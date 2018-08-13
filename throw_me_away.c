#include <stdio.h>
#include <stdlib.h>
#include "generalised_branch_and_bound.h"

struct a_struct{
  int x;  
};

int problem_reader(const char *filename, void *problem);

int main(int argc, char *argv[])
{
  int (*prob_read)(const char *, void *) = &problem_reader;
  
  struct a_struct* min_struct = (struct a_struct *) malloc(sizeof(struct a_struct));

  min_struct->x = 3;

  generalised_branch_and_bound(prob_read, min_struct);

  return 0;
}

int problem_reader(const char *filename, void *problem)
{
  printf("Poo.\n");
  struct a_struct *p_struct = (struct a_struct *) problem;
  p_struct->x = 123;
  problem = (void *) p_struct;
  return 0;
}

