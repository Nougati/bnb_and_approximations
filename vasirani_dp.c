/* ~~ vasirani_dp.c ~~
   Description: Tries to implement the DP for the 0,1 Knapsack as
    described by Vijay Vasirani
   Notes:
    This was once cheesecake. Sad!
    Data type assertions seem unnecessary because C is pretty tight about 
    that anyway.
   TODO
    Update the 2D array arg declarations to double pointer notation for 
    consistency's sake
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define HYPER_TRIVIAL_BOUND 1
#define TRIVIAL_BOUND 2
#define RATIO_BOUND 3

/* This block is stolen from
https://stackoverflow.com/questions/6280055/how-do-i-check-if-a-variable-is-of-a-certain-type-compare-two-types-in-c
"When I'm done I'll reduce the size of this block to just the necessary ones." - Nelson, the court jester.
 */
/*

#define typename(x) _Generic((x),        /* Get the name of a type            \
                                                                                  \
        _Bool: "_Bool",                  unsigned char: "unsigned char",          \
         char: "char",                     signed char: "signed char",            \
    short int: "short int",         unsigned short int: "unsigned short int",     \
          int: "int",                     unsigned int: "unsigned int",           \
     long int: "long int",           unsigned long int: "unsigned long int",      \
long long int: "long long int", unsigned long long int: "unsigned long long int", \
        float: "float",                         double: "double",                 \
  long double: "long double",                   char *: "pointer to char",        \
       void *: "pointer to void",                int *: "pointer to int",         \
      default: "other")
*/
/*
#define min(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a < _b ? _a : _b; })
*/
/* Function Declarations */
void DP(const int problem_profits[],
        const int problem_weights[],
        const int x[],
        int sol[],
        const int n,
        const int capacity,
        const int z,
        const int sol_flag,
        const int bounding_method,
        char *problem_file);

int DP_max_profit(const int problem_profits[],
                  int n);

int DP_p_upper_bound(const int problem_profits[],
                     const int problem_weights[],
                     const int n,
                     int P,
                     int bounding_method,
                     const int c);

int p_upper_bound_aux(const int problem_profits[],
                      int n);

void DP_fill_in_base_cases(const int width,
                           const int n,
                           int ** DP_table, //int DP_table[][width],
                           const int problem_profits[],
                           const int problem_weights[]);

int derive_pinf(const int problem_weights[], const int n);

void DP_fill_in_general_cases(const int width,
                              const int n,
                              int ** DP_table,//int DP_table[][width],
                              const int problem_profits[],
                              const int problem_weights[]);

int DP_find_best_solution(const int width,
                        const int n,
                        int ** DP_table, //const int DP_table[][width],
                        const int capacity,
                        const int my_pinf);

int DP_derive_solution_set(int n,
                            const int width,
                            int ** DP_table, //const int DP_table[][width],
                            const int problem_profits[],
                            int solution[],
                            int p,
                            const int sol_flag);


void pisinger_reader(int *n,
                     int *c,
                     int *z,
                     int *(*p),
                     int **w,
                     int **x,
                     char *problem_file);

void pisinger_generator_reader(int *n,
                               int *c,
                               int **p,
                               int **w,
                               char *problem_file);

int p_upper_bound_ratio(const int problem_profits[], const int problem_weights[], const int n, const int c);

/* .ılılılılılılılılıl Program body lılılılılılılılılı. */
#ifndef TESTING
int main(int argc, char *argv[]){
  /*
    Notes:
      Profits, weights, and capacity are aimed to be dynamically read from source files.
      As it stands, this is not a functionality.

      Also remember sol_flag = 0 means indexed, 1 means binary
                    bounding_method = 1 -> nP, 2 -> simple sum

      Input files: "knapPI_1_50_1000.csv"
                   "small_instance"
                   "knapPI_1_100_1000.csv"
                   "knapPI_1_1000_1000.csv"
                   "knapPI_11_1000_1000.csv" <- Hard
                   "knapPI_11_10000_1000.csv" <- Hard instance (Won't compute)
                   "knapPI_16_1000_1000.csv" <- Hard
                   "test.in" for the auto generated instances.
                     To generate instances:
                      cc -Aa -O -o generator generator.c -lm
                     Actually, use this:
                      gcc -O3 -march=native -o generator generator.c
                     To run:
                      generator n r type i S
                     where n: number of items,
                           r: range of coefficients,
                        type: 1=uncorr., 2=weakly corr., 3=strongly corr., 4=subset sum
                           i: instance no
                           S: number of tests in series (typically 1000)

      Important: Valgrind will return false positives for larger problem instances.
                 We can see this as the small instance and the large instance varies.
                 Source:
                 http://blog.purevirtual.net/2012/01/valgrind-client-switching-stacks.html
                 The crux of the issue lies in the fact that in even moderately large
                  instances the DP_table data structure gets so large that valgrind is
                  inclined to believe something has gone wrong. This is why an upper bound
                  on p would be nice!
  */
  int n, capacity, z, bounding_method;
  int *profits, *weights, *x;
  char problem_file[100];
  int sol_flag = 1;

  /* Command line verification */
  if (argc != 3)
  {
    if (strcmp(argv[1], "help") == 0)
      printf("bounding methods\n\t-np: nP\n\t-bps: basic profit sum\n\t-r: max r"
             "atio times capacity\n");
    printf("Usage: %s <problem_file> <bounding_method>\nType \"%s help\" for o"
           "ptions\n", argv[0], argv[0]);
    exit(EXIT_FAILURE);
  }
  else
  {
    strcpy(problem_file, "./problems/");
    strcat(problem_file, argv[1]);
    if (strcmp(argv[2], "-np")==0)
      bounding_method = HYPER_TRIVIAL_BOUND;
    else if (strcmp(argv[2], "-bps")==0)
      bounding_method = TRIVIAL_BOUND;
    else if (strcmp(argv[2], "-r")==0)
      bounding_method = RATIO_BOUND;
    else
    {
      printf("There was a problem deciphering the bounding method. Exiting...\n");
      exit(-1);
    }
  }
  
  /* pisinger_reader only works if the input file is of the form of the
     standard knapsack instances that accompany "Where are all the the hard
     Knapsack instances" by Pisinger. As a result, we must use a seperate
     reader for the other file format. */
  if (strcmp(argv[1], "test.in")==0)
  {
    pisinger_generator_reader(&n,
                              &capacity,
                              &profits,
                              &weights,
                              problem_file);

  }
  else
  {
    pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, problem_file);
  }

  int S[n];
  for (int i=0; i < n; i++) S[i] = 0;

  DP(profits, weights, x, S, n, capacity, z, sol_flag, bounding_method,
     problem_file);

  /*Reader frees */
  free(profits);
  free(weights);
  if (problem_file != "test.in") free(x);

  return 0;
}
#endif

void DP(const int problem_profits[],
        const int problem_weights[],
        const int x[],
        int sol[],
        const int n,
        const int capacity,
        const int z,
	const int sol_flag,
        const int bounding_method,
        char * problem_file){
  /*
    Description:
      Carries out DP to compute the optimal solution for knapsack,
       given profits and weights.
    Inputs:
      problem_profits (int *) array start
      problem_weights (int *) array start
      sol (int *) array start - the output array
      n - the number of items in the array
    Postconditions:
      The array S will be totally filled out
    Notes:
      Indexing for this will be confuuusing
  */

  // Find max profit item
  int max_profit = DP_max_profit(problem_profits,
                                 n);

  // Find upper bound on p for DP
  int p_upper_bound = DP_p_upper_bound(problem_profits,
                                       problem_weights,
                                       n,
                                       max_profit,
                                       bounding_method,
                                       capacity);

  printf("Table is of size %d * %d\n", n+1, p_upper_bound);

  int **DP_table;
  DP_table = (int **)malloc((n+1) * sizeof(int *));
  for(int i = 0; i < (n+1); i++)
    DP_table[i] = (int *)malloc(p_upper_bound * sizeof(int));

  // Compute base cases
  DP_fill_in_base_cases(p_upper_bound,
                        n,
                        DP_table,
                        problem_profits,
                        problem_weights);
  // Compute general cases
  DP_fill_in_general_cases(p_upper_bound,
                           n,
                           DP_table,
                           problem_profits,
                           problem_weights);
  int my_pinf = derive_pinf(problem_weights, n);

  int p = DP_find_best_solution(p_upper_bound,
                                n,
                                DP_table,
                                capacity,
                                my_pinf);

  int n_solutions = DP_derive_solution_set(n,
                                           p_upper_bound,
                                           DP_table,
                                           problem_profits,
                                           sol,
                                           p,
                                           sol_flag);
  /* Solution output*/
  if (sol_flag == 0){
    /* This is just printing the solution set. It is clutter at the moment
    for(int i=0; i<n_solutions; i++){
      printf("%d ", sol[i]);
    }*/printf("\nComputed optimal profit: %d\n", 
              p);
  }else{
    /* This is just printing the solution set. It is clutter at the moment
    for(int i=0; i<n; i++){
      printf("%d ", sol[i]);
    }*/
    printf("\nComputed optimal profit: %d\n", p);
  }
  printf("True optimal profit: %d\n", z);
  float deviation = (1-(p/z))*100;
  printf("Deviation by %.2f%s!\n", deviation, "%");
  int correct_flag = 1;
  if (problem_file != "test.in"){
    if (sol_flag != 0){
      for (int i=0; i<n; i++){
        if (sol[i] != x[i]){
          printf("Disparity between solution sets... %s \n",z==p?"Profits are "
                 "same though ¯\\_(ツ)_/¯":"And the profits are different.. It"
                 " didn't work.");
          correct_flag = 0;
          break;
        }
      }
      if (correct_flag) printf("Solution sets match. Correct solution obtained"
                               "!\n");
    }else printf("I'm not going to check the solution set of an indexed soluti"
                 "on. You do it.\n");
  }

  free(DP_table);
}

int DP_max_profit(const int problem_profits[],
                  const int n){
  /*
    Description:
      Finds the highest profit in the array of item profits
    Inputs:
      problem_profits - the profit array
      n - the number of objects
    Outputs:
      max - the value of the highest profit item.
  */
  int max = 0;
  for(int i = 0; i < n; i++){
    if (max < problem_profits[i]){
      max = problem_profits[i];
    }
  }
  return max;
}

int DP_p_upper_bound(const int problem_profits[],
                     const int problem_weights[],
                     const int n,
                     const int P,
                     const int bounding_method,
                     const int c){
  /*
    Description:
      Derives the upper bound for the DP table, based on the bounding
       method specified.
    Inputs:
      problem_profts[] - the profit array
      n - the number of objects
      P - the highest profit among every item in the set
  */
  int upper_bound;

  switch (bounding_method){
    case HYPER_TRIVIAL_BOUND: upper_bound = n*P; break;
    case TRIVIAL_BOUND: upper_bound = p_upper_bound_aux(problem_profits, n); break;
    case RATIO_BOUND: upper_bound = p_upper_bound_ratio(problem_profits, problem_weights, n, c); break;
    default: printf("Hmmm... What bounding method was that?\n");
    exit(-1);
  }

  return upper_bound;
}


int p_upper_bound_ratio(const int problem_profits[],
                        const int problem_weights[], const int n, const int c)
{
  /*TODO Does this work?!*/
  double biggest_ratio = 0.0;
  double this_ratio;
  for(int i = 0; i < n; i++)
  {
    this_ratio = (double)problem_profits[i] / (double)problem_weights[i];
    if (this_ratio > biggest_ratio)
      biggest_ratio = this_ratio;
  }
  biggest_ratio *= c;
  int upper_bound = (int)floor(biggest_ratio);
  return upper_bound;
}



int p_upper_bound_aux(const int problem_profits[],
                      const int n){
  /*
    Description:
      An auxiliary function used to calculate the intelligent trivial
       upper bound on the profit.
    Inputs:
      problem_profits[] -  the profit array
      n - the number of objects
    Outputs:
      total - the sum of all the item profits
    Notes:
      There's a funny story behind this function.
  */

  int total=0;

  for(int i=0; i < n; i++){
    total += problem_profits[i];
  }
  return total;
}

void DP_fill_in_base_cases(const int width,
                           const int n,
                           int ** DP_table, //int DP_table[][width],
                           const int problem_profits[],
                           const int problem_weights[]){
  /*
    Description:
      Fills in the base cases for the DP. In Vasirani's terminology this
       is every A(1,p) for every p between 0 and width.
    Inputs:
      width - the upper bound on the width of the table
      n - the number of rows. Remember this is passed in as n+1 to account
           for the 0th row of the table. As a result derive_pinf passes n-1
      DP_table - the two dimensional array to calculate the DP in
    Preconditions:
      The space for the table must be allocated
    Postconditions:
      The cases where profit is limited to 0, and the cases where the there is
       a set of 0 items in the solution will be filled out.
    Notes:
      The rows of the table is expected to represent the number of items
       included. The columns of the table is expected to represent the
       maximum profit achievable.
      Also worth mentioning:
       A(i,p) = A[i][p]
      Another thing: I couldn't use the in built pinf because it was a double
       being stored in an int array. Instead I've defined my_pinf, which is a
       simple upper bound on the problem_weight of any solution represented by
       the sum of all the items in problem_weights + 1.
       This has led to the definition of the function derive_pinf.
  */

  int my_pinf = derive_pinf(problem_weights, n);
  // Go over the first column with 0's
  for(int i = 0; i < n; i++){
     DP_table[i][0] = 0;
  }

  // Go over the first row with infinities
  for(int i = 1; i <= width; i++) {
    DP_table[0][i] = my_pinf;
  }
}

void DP_fill_in_general_cases(const int width,
                              const int n,
                              int ** DP_table, //int DP_table[][width],
                              const int problem_profits[],
                              const int problem_weights[]){
  /*
    Description:
      Fills in the fields of the DP table which are defined by the
       general recurrence.
      Specifically fields A[1][nP] to A[n][nP] (using Vasirani's definition)
    Inputs:
      width - the upper bound on p, the max allowable profit for the given
               subproblem.
      n - the number of items and also the number of rows in the DP table
      DP_table - the n*width table which will store our solution.
      problem_profits - an array of all the problem profits
      problem_weights - an array of all the problem weights
    Preconditions:
      The base cases must be filled in for this general algorithm to return
       a reasonable result. For our purposes, the base cases include the cases
       where profit is 0 and where items = 0
    Postconditions:
      Hopefully a completed DP table which will, within it, contain the optimal
       solution to the 0,1 Knapsack.
    Notes:
      Serious consideration: the problem_profits are 0-indexed, as are the 
      problem weights.
      As a result the field A[1][1] is actually the solution which considers 
      the combination of problem_profits[0] and problem_weights[0].
      This means when designing this, it is *crucial* to account for this
       semantic indexing issue.
  */

  int a, b;
  for (int p = 1; p <= width; p++){
    for (int i = 1; i <= n; i++){
      if (problem_profits[i-1] <= p){
        a = DP_table[i-1][p];
        b = problem_weights[i-1] + DP_table[i-1][(p-problem_profits[i-1])];
        //DP_table[i][p] = min(a,b);
        DP_table[i][p] = ((a < b) ? a : b);
      }else DP_table[i][p] = DP_table[i-1][p];
    }
  }
}

int derive_pinf(const int problem_weights[],
                const int n){
  /*
    Description:
      Sums up all the item weights to obtain a trivial upper bound on the weight
      of any given solution.
    Input:
      problem_weights - a 1D array of the problem's weight values.
    Output:
      my_pinf - my version of positive infinity.
    Notes:

  */

  int my_pinf = 1;
  for(int i = 0; i < n; i++){
    my_pinf += problem_weights[i];
  }
  return my_pinf;
}

int DP_find_best_solution(const int width,
                          const int n,
                          int ** DP_table, //const int DP_table[][width],
                          const int capacity,
                          const int my_pinf){
  /*
    Description:
      Given a completed DP_table, find max(p | A(n,p) <= Capacity)
    Inputs:
      width - the width of the tables
      n - the height of the table (also the number of items)
      DP_table - the dynamic programming 2d array
      problem_profits - the input problem's associated item profits
      problem_weights - the input problem's associated item weights
      capacity - the input problem's knapsack capacity
      my_pinf - the input problem's trivial upper bound on weight
    Preconditions:
      DP_table must be completed, both in basis and in general case, for us
       to derive an optimal solution.
    Outputs:
      p - the max(p | A(n,p) <= Capacity)
    Notes:
      This is simply the profit of the optimal solution, nothing else.
      In order to derive the item set, more analysis needs to be done.
  */

  int p= -1;
  for(int i = width; i >= 0; i--){
    if (DP_table[n][i] != my_pinf){
      if (DP_table[n][i] <= capacity){
        p = i;
        break;
      }
    }
  }
  return p;
}

int DP_derive_solution_set(int n,
                           const int width,
                           int ** DP_table, //const int DP_table[][width],
                           const int problem_profits[],
                           int solution[],
                           int p,
                           const int sol_flag){

  /*
    Description:
      Given a completed DP_table, derive the indices of the items of the 
      optimal set.
    Inputs:
      n - the number of rows in the Dynamic Programming table
      DP_table - the 2d array representing the constituent subproblems of the
       DP
      solution - the output array; it will simply hold the indices of the items
       that are included in the optimal solution.
      p - the profit of the optimal solution
      sol_flag - if 0, index notation, if 1, 0/1 notation
    Postconditions:
      solution will be filled out
    Notes:
      This doesn't work on certain instances :/
  */

  int s_index = 0;
  while ((p > 0)&&(n > 0)){
    if (DP_table[n-2][p] > DP_table[n-1][p]){
      // then we had item n and the solution at A[n-1][p-profit(n)]
      if(sol_flag == 0) solution[s_index] = (n-1);
      else solution[n-2] = 1;
      s_index += 1;
      n -= 1;
      p -= problem_profits[n-1]; // remember table n corresponds to profit n-1
    }else{
      // A[n-1][p] must be the same as A[n][p]
      if (sol_flag != 0) solution[n-2] = 0;
      n -= 1;
    }
  }
 return s_index;
}

void pisinger_reader(int *n, int *c, int *z, int **p, int **w, int **x,
                     char *problem_file){
  /* This is a haggard mess*/
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
  int *tmp_x = (int *)malloc(*n * sizeof(*tmp_x)); rewind(fp); // Meaning this would probably be unnecessary
  int counter=0;
  if (fp == NULL) 
  {
    printf("Null file pointer; problem reading in the file.\n");
    exit(EXIT_FAILURE);
  }
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

void pisinger_generator_reader(int *n, int *c, int **p, int **w, char *problem_file){
  /*
    Description:
      Reads in the files that Pisinger's generator creates.
      They're of the form
        n
            1   p[1]   w[1]
            :    :      :
            n   p[n]   w[n]
        c
  */

  FILE *fp;
  char str[256];
  char * pch;

  fp = fopen(problem_file, "r");
  if (fp == NULL) exit(EXIT_FAILURE);

  /* Get n */
  fgets(str, sizeof(str), fp);
  *n = atoi(str);
  printf("n*=%d\n",*n);

  int *tmp_p = (int *)malloc(*n * sizeof(*tmp_p));
  int *tmp_w = (int *)malloc(*n * sizeof(*tmp_w));

  /* Get profits and weights */
  /* This section has each separated by arbitrary amounts of whitespace */
  int counter = 0;
  //for(int i=0; i < *n; i++){
  while ((fgets(str, sizeof(str), fp))&&(counter<*n)){
    //fgets(str, sizeof(str), fp);
    pch = strtok(str, " ");
    // This is just i

    pch = strtok(NULL, " ");
    // Add pch to profits
    //tmp_p[i] = atoi(pch);
    tmp_p[counter] = atoi(pch);

    pch = strtok(NULL, " ");
    // Add pch to weights
    //tmp_w[i] = atoi(pch);
    tmp_w[counter] = atoi(pch);
    counter++;
  }

  /* Get Capacity */
  fgets(str, sizeof(str), fp);
  *c = atoi(str);

  fclose(fp);

  *p = tmp_p;
  *w = tmp_w;
}
