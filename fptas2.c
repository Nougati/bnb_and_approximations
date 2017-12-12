/* ~~fptas2.c~~
 * MAJOR WORK IN PROGRESS LOL
 * SOOOOO NOT FINISHED
 * AHHHHHHHHHHHHHHHHHHH
 * YESSSSSSSSSSSSSSSSSSS
 * This will not compile! I promise you that.
 * TODO
 *  - First thing to do is to sort out function declarations and definitions 
 *     so those debug messages come up.
 */

#include <stdio.h>
#include <math.h>
#include <assert.h> 

int main(){
  /* Some things to note:
   *   As eps approaches 0, FPTAS's lower bound approaches true solution
   *   As eps approaches 1, FPTAS's lower bound approaches (1-eps)OPT
   *    ... I think
   */
  /* Declarations */
  float eps, K;
  char *problem_file;
  int *profits, *weights, *x, *profit_primes;
  int n, capacity, sol_flag; 
  const int bounding_method;

  /* Initialisations */
  eps = 0.75;
  problem_file = "knapPI_1_50_1000.csv";

  pisinger_reader(&n,
                  &capacity,
                  &z,
                  &profits,
                  &weights,
                  &x,
                  problem_file);
  sol_flag = 1;
  sol_prime[n];
  for (int i=0; i < n; i++) S[i] = 0;
  bounding_method = 2;
  profit_primes = (int *) malloc(n * sizeof(*profit_primes));

  /* Begin Debug */
  printf("DEBUG n: %d\nDEBUG c: %d\nDEBUG: z", n, capacity, z);
  /* End Debug */

  /* Run the FPTAS...
     I want to give to FPTAS to update:
       profit_prime: the FPTAS's guess on profit
       sol_prime: the FPTAS's guess on sol (already malloc'd)
       a K so I can get the rescaled profits on choice.. Just in case!
  */ 
  FPTAS(eps,
        profits,
        weights,
        x,
        sol_prime,
        n,
        capacity,
        sol_flag,
        bounding_method,
        problem_file,
        &K,  // out parameter
        profit_primes); // out parameter

  /* Derive profit'(S') */
  // Iterate over every profit' and scale it to Kprofit' and just sum it up
  /* Print profit results */
  printf("True profit: <Insert true profit here>.\n");
  printf("Computed profit: <Insert computed profit here>.\n");
  printf("Deviation from optimal: <Insert percentage deviation here>.\n");

  free(profit_primes);
  return 0;
}

void FPTAS(eps, 
           profits,
           weights,
           x,
           sol_prime,
           n,
           capacity,
           sol_flag,
           bounding_method,
           problem_file,
           &K,
           profits_prime){
  /* Description
   *  Recreates the FPTAS for the 0,1 KP as described by V. Vasirani in his
   *   chapter on Knapsack in Approximation Algorithms.
   * Inputs
   *  eps - the epsilon value representing the level of approximation on the
   *        result. A lower epsilon value will indicate less error and thus 
   *        worse performance in terms of time. Epsilon is a positive real 
   *        number no greater than 1.
   *  profits - The input profit array
   *  weights - The input weight array
   *  x - The input problem optimal solution binary representation
   *  sol_prime - The array for the approximate solution S' to be stored. This 
   *   It is by definition the optimal solution to the KP problem with profits 
   *   described by profits_prime. For our purposes it'll stored as a bitstr.
   *  n - the number of items in the problem
   *  capacity - the capacity of the knapsack as specified by the problem
   *  sol_flag - a flag which should always be 1 (binary).
   *  bounding_method - a flag which should always be 2 (simple sum)
   *  problem_file - just the string of the problem file
   *  K - the husk where we store the K value determined by this algo.
   */

  /* Declarations */
  int P, K;
   
  /* Initialisations */
  P = DP_max_profit(problem_profits,//undefined!
                    n);
  K = define_K(eps, P, n);//undefined!
  make_profit_primes(profits, profit_primes, K, n); // undefined!

  /* Now with amended profits list "profit_primes," solve the DP */
  DP(profit_primes,
     weights,
     x,
     sol_prime,
     n,
     capacity,
     sol_flag,
     bounding_method,
     problem_file);

  /* Solution should be in sol_prime */
  /* Nothing else done in this place? */
}

void pisinger_reader(int *n, int *c, int *z, int **p, int **w, int **x, char *problem_file){
  /* 
   * TODO Document me!
   */
  FILE *fp;
  char str[256];
  char * pch;

  fp = fopen(problem_file, "r");

  /* Get n */
  if (fp == NULL) exit(EXIT_FAILURE);
  while (fgets(str, sizeof(str), fp)){
    if (str[0] == 'n'){
      pch = strtok(str, " ");
      pch = strtok(NULL, " ");
      *n = atoi(pch);
      // I could probably just break here and keep moving on
    }
  }

  int *tmp_p = (int *)malloc(*n * sizeof(*tmp_p));
  int *tmp_w = (int *)malloc(*n * sizeof(*tmp_w));
  int *tmp_x = (int *)malloc(*n * sizeof(*tmp_x));

  rewind(fp); // Meaning this would probably be unnecessary
  int counter=0;
  if (fp == NULL) exit(EXIT_FAILURE);
  while ((fgets(str, sizeof(str), fp))&&(counter<*n)){

  if(str[0] == 'c'){
      pch = strtok(str, " ");
      pch = strtok(NULL, " ");
      *c = atoi(pch);
  }else if (str[0] == 'z'){
      pch = strtok(str, " ");   
      pch = strtok(NULL, " ");
      *z = atoi(pch);
  }else if (!((str[0] == 'n')
              ||(str[0] == 'z')
              ||(str[0] == 'k')
              ||(str[0] == 't'))){

      pch = strtok(str, ",");
      pch = strtok(NULL, ",");

      tmp_p[counter] = atoi(pch);

      pch = strtok(NULL, ",");

      tmp_w[counter] = atoi(pch);

      pch = strtok(NULL, ",");

      tmp_x[counter] = atoi(pch);

      counter += 1;

    }
  }
  fclose(fp);

  *p = tmp_p;
  *w = tmp_w;
  *x = tmp_x;
}

