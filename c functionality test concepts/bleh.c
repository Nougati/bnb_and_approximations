/*Compile with:
  gcc bleh.c -lm -o bleh
*/
#include <stdio.h>
#include <math.h>

int main () {
   float eps, val2, val3, val4;
   eps = 1.0;
   int n = 25; 
   int P = 200;
   float K = floor((eps*P)/n);
   printf("eps = %.1f, K: %.1f\n", eps, K);
   eps = 0.8;
   K = (eps*P)/n;
   printf("eps = %.1f, K: %.1f\n", eps, K);
   eps = 0.6; 
   K = (eps*P)/n;
   printf("eps = %.1f, K: %.1f\n", eps, K);
   eps = 0.4;
   K = (eps*P)/n;
   printf("eps = %.1f, K: %.1f\n", eps, K);
   eps = 0.2;
   K = (eps*P)/n;
   printf("eps = %.1f, K: %.1f\n", eps, K);
   return(0);
}
