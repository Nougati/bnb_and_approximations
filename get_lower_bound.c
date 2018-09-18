#include <stdio.h>
#include "kellerer_pferschy_fptas.h"

int main(int argc, char *argv[])
{
  int profits[] = {11, 11, 18, 30};
  int weights[] = {5, 4, 10, 15};
  int lower = 0;
  double upper = 0.0;
  get_knapsack_lowerbound(profits, weights, 4, 25, &lower, &upper);

  printf("Solution is between [%d, %d]", lower,(int)upper);
  return 0;
}
