/* treacle.c */
/* Just a test file for testing defining a min and max function */

#include <math.h>
#include <stdio.h>

#define max(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })

#define min(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a < _b ? _a : _b; })

int main(){
  int a = -3;
  int b = -2;
  printf("max(a,b): %d\n", max(a,b));
  printf("min(a,b): %d\n", min(a,b));
  
  int pinf = INFINITY;
  if (min(1,pinf) == 1) printf("Yes!");
  else printf("No!"); 

  printf("%s",pinf>100?"pinf>100":"pinf not >100");

  int pinfo = pinf;
  printf("%d",pinfo);
  return 0;
}
