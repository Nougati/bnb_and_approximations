/*****************************************************************************
 *  williamson_shmoy_dp.c                                                    *
 *  Author: Nelson Frew                                                      *
 *  First Edit: 19/01/18                                                     *
 *  Last Edit: 19/01/18                                                      *
 *  Description:                                                             *
 *    Implements the knapsack dynamic programming algorithm as described by  *
 *    Williamson and Shmoy in their book Design of Approximation Algorithms  *
 *    which can be found at www.designofapproxalgs.com/book.pdf              *
 *  Notes:                                                                   *
 *                                                                           *
 *  TODO:                                                                    *
 *    Incorporate the Psinger problem instance reader                        *
 *      Importantly, this program uses item structures to organise the data  *
 *    Do commandline args for problem files                                  *
 *    Error catching and asserts                                             *
 *      Set up mechanisms to catch malloc errors                             *
 *      Set up mechanisms to catch file reading errors                       *
 *    If I want to, make Pisinger Reader read into a struct array            *
 *                                                                           *
 *****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Prototypes go here */
struct problem_item
{
  int weight;
  int profit;
};


struct solution_pair 
{
  int weight;
  int profit;
  struct solution_pair *next;
};

int williamson_shmoys_DP(struct problem_item items[], int capacity, int n);
void push(struct solution_pair** head_ref, int new_weight, int new_profit);
void remove_dominated_pairs(struct solution_pair** head_ref);
void merge_sort(struct solution_pair** head_ref);
struct solution_pair* sorted_merge(struct solution_pair* a, 
                                   struct solution_pair* b);
void front_back_split(struct solution_pair* source, 
                      struct solution_pair** front_ref, 
                      struct solution_pair** back_ref);
void print_list(struct solution_pair* node);
void pisinger_reader(int *n, int *c, int *z, int **p, int **w, int **x,
                     char *problem_file);

int williamson_shmoys_DP(struct problem_item items[], int capacity, int n)
{
 /***william_shmoys_DP********************************************************
  *  Description: Implements the dynamic programming algorithm for the       *
  *               knapsack problem as described by Williamson and Shmoys.    *
  *  Inputs:                                                                 *
  *    struct problem_item items[]                                           *
  *      An array of all the items in the problem instance, built from       *
  *      reading and encoding an input file. Each item struct has profit     * 
  *      and weight members.                                                 *
  *    int capacity                                                          *
  *      The capacity as described by the problem statement                  *
  *  Outputs:                                                                *
  *    int w                                                                 *
  *      the max weight of a tuple in the list at the end of the algorithm   *
  *  Notes:                                                                  *
  *                                                                          *
  ****************************************************************************/

  /* Base case */
  struct solution_pair* head = NULL;
  struct solution_pair* current; 
  push(&head, 0, 0);
  push(&head, items[0].weight, items[0].profit);

  /* General case */
  for(int j=2; j < n; j++)
  {
    current = head;
    while(current != NULL)
    {
      /* Only add if we can feasibly add it */
      int possible_weight = current->weight + items[j].weight;
      if (possible_weight <= capacity)
        push(&head, current->profit + items[j].profit, possible_weight);
      current = current->next;
      remove_dominated_pairs(&head);
    }
  }

  /* TODO: Extract solution */
  /* return max ((t,w) in A max) w*/
  current = head;
  int max_profit = -1;
  while (current != NULL)
  {
    if (current->profit > max_profit)
      max_profit = current->profit;
    current = current->next;  
  }
  return max_profit;
}

void push(struct solution_pair** head_ref, int new_weight, int new_profit)
{
  /* Allocate memory for the new solution pair */
  struct solution_pair* new_solution_pair = 
    (struct solution_pair*) malloc(sizeof(struct solution_pair));

  /* Define new pair's data */
  new_solution_pair->weight = new_weight;

  /* Connect pair to the head of the list */
  new_solution_pair->next = (*head_ref);

  /* Set the new node to be the new head of the list */
  (*head_ref) = new_solution_pair;
   
}

void remove_dominated_pairs(struct solution_pair** head_ref)
{
 /***remove_dominated_pairs***************************************************
  *  Description:                                                            *
  *    Removes the dominated pairs within a linked list of solution_pairs by *
  *    a two phase approach consistening of a merge sort on each of the      * 
  *    weights and a series of iteratively shortening comparisons based on   *
  *    the profits.                                                          *
  *  Inputs:                                                                 *
  *    struct solution_pair** headRef                                        *
  *      Double pointer to the head of the linked list to allow for          *
  *      reallocation of the head, should it be dominated                    * 
  *  Postconditions:                                                         *
  *    Linked list will have entirely non-dominated pairs.                   *
  *  Notes:                                                                  *
  *    Has function dependencies in merge sort and all of its constituent    *
  *    functions                                                             *
  ****************************************************************************/
  /* Merge sort the list by weight */
  merge_sort(head_ref);

  /* Remove dominated nodes */
  struct solution_pair* outer_current = *head_ref;
  struct solution_pair* inner_current, *inner_current_prev;
  while(outer_current != NULL)
  {
    inner_current_prev = outer_current;
    inner_current = outer_current->next;
    while(inner_current != NULL)
    {
      if (outer_current->profit >= inner_current->profit)
      {
        /* Outer current dominates inner current */
        inner_current = inner_current->next;
        free(inner_current_prev->next);
        inner_current_prev->next = inner_current;         
      }
      else
      {
        /* No domination, progress further into the list */
        inner_current = inner_current->next;
        inner_current_prev->next = inner_current;
      } 
    }
  outer_current = outer_current->next;
  }
}

void merge_sort(struct solution_pair** head_ref)
{
 /* merge_sort: my adapation for solution pairs as originally described by    *
  *             geeks for geeks.                                              *
  *             This is strictly designed for linked lists                    *
  *             This algorithm is said to have complexity O(nlogn)            */
  struct solution_pair* head = *head_ref;
  struct solution_pair* a;
  struct solution_pair* b;

  if ((head == NULL) || (head->next == NULL))
    return;

  /* Split head into 'a' and 'b' sublists */
  front_back_split(head, &a, &a);

  /* Recursively sort the sublists */
  merge_sort(&a);
  merge_sort(&b);

  /* Merge the two lists of this scope together */
  *head_ref = sorted_merge(a, b);
}

struct solution_pair* sorted_merge(struct solution_pair* a, 
                                   struct solution_pair* b)
{
  struct solution_pair* result = NULL;
  
  /* Base cases */
  if (a == NULL) return (b);
  else if (b == NULL) return (a);

  /* Pick either a or b, and recur */
  if (a->weight <= b->weight)
  {
    /* Corner case: if they're equal weighted, put 
       the one with the lower profit first         */
    if (a->weight == b->weight)
    {
      if (a->profit > b->profit)
      {
        result = a;
        result->next = sorted_merge(a->next, b);
      }
      else 
      {
        result = b;
        result->next = sorted_merge(a, b->next);
      }
    }
    /* Otherwise just merge as normal */
    else
    {
      result = a;
      result->next = sorted_merge(a->next, b);
    }
  }
  else
  {
    result = b;
    result->next = sorted_merge(a, b->next);
  }
  return(result);
}

void front_back_split(struct solution_pair* source, 
                      struct solution_pair** front_ref, 
                      struct solution_pair** back_ref)
{
  struct solution_pair* fast;
  struct solution_pair* slow;
  if (source == NULL || source->next == NULL)
  {
    /* Length < 2 cases */
    *front_ref = source;
    *back_ref = NULL; 
  }
  else
  {
    slow = source;
    fast = source->next;

    /* Advance 'fast' by two nodes, and advance 'slow' by one */
    while (fast != NULL)
    {
      fast = fast->next;
      if (fast != NULL)
      {
        slow = slow->next;
        fast = fast->next;
      }
    }
    /* 'slow' is before the midpoint in the list, so split it at that point */
    *front_ref = source;
    *back_ref = slow->next;
    slow->next = NULL;
  }
}

void print_list(struct solution_pair* node)
{
  while(node!=NULL)
  {
    printf("%d ", node->profit);
    node = node->next;
  }
}

void pisinger_reader(int *n, int *c, int *z, int **p, int **w, int **x, 
                     char *problem_file)
{ 
  /* 
   * Description:
   *   Reads pisinger's csv knapsack instances into arrays. This does not work 
   *    on his automatically generated instances.
   * Inputs:
   *
   * Notes:
   *   This has been copied line for line from my original FPTAS program.
   */
  FILE *fp;
  char str[256];
  char * pch;

  fp = fopen(problem_file, "r");
  printf("File opened\n");
  /* Get n */
  if (fp == NULL) exit(EXIT_FAILURE);
  while (fgets(str, sizeof(str), fp)){
    if (str[0] == 'n'){
      pch = strtok(str, " ");
      pch = strtok(NULL, " ");
      *n = atoi(pch);
      break;
    }
  }

  printf("n read in...\n");

  int *tmp_p;
  if(*tmp_p = (int *)malloc(*n * sizeof(*tmp_p))==NULL)
    perror("Error allocating space for profits\n");

  int *tmp_w;
  if(*tmp_w = (int *)malloc(*n * sizeof(*tmp_w))==NULL)
    perror("Error allocating space for weights\n");
    
  int *tmp_x;
  if (*tmp_x = (int *)malloc(*n * sizeof(*tmp_x))==NULL)
    perror("Error allocating space for solution\n");

  printf("p, w, and x arrays allocated...\n");

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

int main(int argc, char *argv[])
{
  /* Variables set up */
  char *problem_file;
  int *profits, *weights, *x;
  int n, capacity, z;
  printf("Hello?\n");
  /* Read in an instance */
  problem_file = "./problems/knapPI_1_50_1000.csv";
  pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, problem_file);
  printf("Problem read in...\n");
  /* Build items[] array */
  struct problem_item items[n];
  printf("problem_item array made...\n");
  for(int i = 0; i < n; i++)
  {
    items[i].weight = weights[i];
    items[i].profit = profits[i];
  }
  printf("problem_item array completed...\n");

  /* Put items[] array and capacity into DP */
  int result = williamson_shmoys_DP(items, capacity, n);
  printf("williamson_shmoys_DP exited...\n");

  /* Return the solution */
  printf("Result: %d\n", result);
  return result;
}
