/* pisinger_reader.c */
/* Implements a makeshift CSV reader for pisinger's knapsack instances. It makes some assumptions about the input file format. This is because I intend to use this over and over for different instances as I move through a collection of CSVs and analyse the performance of my DP etc etc. 
😮|/|\|\|\/😮\~~THIS IS A SERIOUS W😮RK IN PR😮GRESS~~/😮\/|/|/|\|😮

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void pisinger_reader();

int main(){

  int n, c;
  int *p, *w, *x;

  pisinger_reader();

  return 0;
}

void pisinger_reader(){
  /* This is a haggard mess */

  FILE *fp;
  char str[256];
  char * pch;
  fp = fopen("knapPI_1_50_1000.csv", "r");
  int n, c;
  int counter=0;
  
  /* Get n */

  if (fp == NULL) exit(EXIT_FAILURE);
  while (fgets(str, sizeof(str), fp)){
    if (str[0] == 'n'){
      pch = strtok(str, " ");
      pch = strtok(NULL, " ");
      n = atoi(pch);
    }
  }
  printf("n: %d\n", n);
  int p[n], w[n], x[n];

  rewind(fp);
  if (fp == NULL) exit(EXIT_FAILURE);
  while ((fgets(str, sizeof(str), fp))&&(counter<n)){
   if(str[0] == 'c'){
      pch = strtok(str, " ");
      pch = strtok(NULL, " ");
      printf("Capacity: %s", pch);
      c = atoi(pch);
    }else if (!((str[0] == 'n')
              ||(str[0] == 'z')
              ||(str[0] == 'k')
              ||(str[0] == 't'))){
      pch = strtok(str, ",");
      pch = strtok(NULL, ",");
      p[counter] = atoi(pch);
      printf("p[%d]: %d \t", counter, p[counter]);
      pch = strtok(NULL, ",");
      w[counter] = atoi(pch);
      printf("w[%d]: %d \t", counter, w[counter]);
      pch = strtok(NULL, ",");
      x[counter] = atoi(pch);
      printf("x[%d]: %d \n", counter, x[counter]);
      counter += 1;
    }
  }
  fclose(fp);
}
