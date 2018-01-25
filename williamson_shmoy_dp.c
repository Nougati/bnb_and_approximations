/*****************************************************************************
 *  williamson_shmoy_dp.c                                                    *
 *  Author: Nelson Frew                                                      *
 *  First Edit: 19/01/18                                                     *
 *  Last Edit: 24/01/18                                                      *
 *  Description:                                                             *
 *    Implements the knapsack dynamic programming algorithm as described by  *
 *    Williamson and Shmoy in their book Design of Approximation Algorithms  *
 *    which can be found at www.designofapproxalgs.com/book.pdf              *
 *  Notes:                                                                   *
 *                                                                           *
 *  TODO:                                                                    *
 *    Valgrind tests for the complicated struct arrays :O                    *
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
  /* Begin tentative changes */  
  int solution_array[];
  /* End tentative changes */ 
};

int williamson_shmoys_DP(struct problem_item items[], int capacity, int n, int *solution_array);
void push(struct solution_pair** head_ref, int new_weight, int new_profit, int n);
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

int williamson_shmoys_DP(struct problem_item items[], int capacity, int n,
                         int *solution_array)
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
  push(&head, 0, 0, n);
  /* ASSUMPTION MADE: the 0'th item will feasibly fit! */
  push(&head, items[0].weight, items[0].profit, n);
  head->solution_array[0] = 1;

  /* General case */
  for(int j=1; j < n; j++)
  {
    current = head;
    while(current != NULL)
    {
      /* Only add if we can feasibly add it */
      int possible_weight = current->weight + items[j].weight;
      if (possible_weight <= capacity)
      {
        /* Put new partial solution on the head */
        push(&head, possible_weight, current->profit + items[j].profit, n);
        /* Copy the partial solution array  */
        for (int i=0; i <= j; i++)
          head->solution_array[i] = current->solution_array[i];
        /* Distinguish it from the others */
        head->solution_array[j] = 1;
      }
      current = current->next;
    }
    remove_dominated_pairs(&head);
  }

  /* return max ((t,w) in A max) w*/
  current = head;
  struct solution_pair* best_pair;
  int max_profit = -1;
  while (current != NULL)
  {
    if (current->profit > max_profit)
      max_profit = current->profit;
      best_pair = current;
    current = current->next;  
  }

  /* Assuming solution_array has been malloc'd already */
  for(int i=0; i < n; i++)
  {
    solution_array[i] = best_pair->solution_array[i];
  }


  /* Clean up */
  current = head;
  while (current != NULL)
  {
    current = current->next;
    free(head);
    head = current;
  }
  /* TODO Find out if we need to clena up individual struct arrays */

  return max_profit;
}

void push(struct solution_pair** head_ref, int new_weight, int new_profit,
          int n)
{
 /***push*********************************************************************
  *  Description:                                                            *
  *    Given a pointer to a solution_pair structure pointer (the head of a   *
  *    linked list of such structures), link a new structure into the list   *
  *    with given weight new_weight and profit new_profit.                   *
  *  Postconditions:                                                         *
  *    This will put the new structure at the top of the list.               *
  *  Notes:                                                                  *
  *    This is taken from the geeksforgeeks linked list mergesort article    *
  *    This needs n in order to dynamically allocate enough space for the    *
  *    struct member solution_array                                          * 
  ****************************************************************************/
  /* Allocate memory for the new solution pair 
  struct solution_pair* new_solution_pair = 
    (struct solution_pair*) malloc(sizeof(struct solution_pair) + n * sizeof(int));
  */
  /*Tentative start*/
  struct solution_pair* new_solution_pair =
    (struct solution_pair*)calloc(sizeof(struct solution_pair) + n, sizeof(int));
  if (new_solution_pair)
  {
    struct solution_pair const temp_pair =
      {.weight = new_weight, .profit = new_profit, .next=(*head_ref)};
    /*Old code
    memcpy(new_solution_pair, &(struct solution_pair const){ .weight = new_weight,
           .profit = new_profit, .next=(*head_ref)},
           sizeof(struct solution_pair));*/
   /*New Code*/
     memcpy(new_solution_pair, &temp_pair, sizeof(struct solution_pair));
    
  }

  /*Tentative end*/

  /* Define new pair's data */
  new_solution_pair->weight = new_weight;
  new_solution_pair->profit = new_profit;

  /* Connect pair to the head of the list */
  new_solution_pair->next = (*head_ref);

  
  /* TENTATIVE Initialise the array to 0's*/
  for(int i = 0; i < n; i++)
    *(new_solution_pair->solution_array+i) = 0;
 
  /* Set the new node to be the new head of the list */
  (*head_ref) = new_solution_pair;
}

void remove_dominated_pairs(struct solution_pair** head_ref)
{
 /***remove_dominated_pairs documentation*************************************
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
  *    This function assumes that the (0,0) tuple will always be in an input.*
  *    As such, the case where the linked list is of length 0 is not         *
  *    addressed. The algorithm seems resilient enough to cover length=1     *
  *    with its general case.                                                *
  ****************************************************************************/

  /* Merge sort the list by weight */
  merge_sort(head_ref);

  struct solution_pair* current = (*head_ref)->next;
  struct solution_pair* previous = *head_ref;

  /* Filtration algorithm */
  while (current != NULL)
  {
    if (previous->profit >= current->profit)
    {
      current = current->next;
      free(previous->next);
      previous->next = current;
    }
    else
    {
      current = current->next;
      previous = previous->next;
    }
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

  /* Bases: length 0 or 1 */
  if ((head == NULL) || (head->next == NULL))
    return;

  /* Split head into 'a' and 'b' sublists */
  front_back_split(head, &a, &b);

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

  /* Pick the lower of either a or b, and recur */
  if (a->weight <= b->weight)
  {
    /* Corner case: if they're equal weighted, put the one with the higher 
       profit first. This simplifies the cases we have to consider within
       the filtration step of dominated pair removal */
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
   *   This has been edited to support dynamic allocation error catching.  
   */
  FILE *fp;
  char str[256];
  char * pch;

  fp = fopen(problem_file, "r");

  /* Get n */
  if (fp == NULL)
  {
    printf("Unable to open file. Exiting...\n");
    exit(EXIT_FAILURE);
  }
  while (fgets(str, sizeof(str), fp)){
    if (str[0] == 'n'){
      pch = strtok(str, " ");
      pch = strtok(NULL, " ");
      *n = atoi(pch);
      break;
    }
  }

  int *tmp_p;
  if((tmp_p = (int *)malloc(*n * sizeof(*tmp_p)))==NULL)
  {  //tperror("Error allocating space for profits\n");
    fprintf(stderr, "Cannot malloc tmp_x!\n");
    exit(1);
  }

  int *tmp_w;
  if((tmp_w = (int *)malloc(*n * sizeof(*tmp_w)))==NULL)
  {  //perror("Error allocating space for weights\n");
    fprintf(stderr, "Cannot malloc tmp_x!\n");
    exit(1);
  }

  int *tmp_x;
  if ((tmp_x = (int *)malloc(*n * sizeof(*tmp_x)))==NULL)
  {  //perror("Error allocating space for solution\n");
    fprintf(stderr, "Cannot malloc tmp_x!\n");
    exit(1);
  }

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

#ifndef TESTING

int main(int argc, char *argv[])
{
  /* Variables set up */
  char problem_file[100];
  int *profits, *weights, *x;
  int n, capacity, z;

  /* Command line args */
  if (argc != 2)
  {
    printf("Usage: %s <filename>\n", argv[0]);
    exit(-1);
  }

  /* Read in an instance */
  strcpy(problem_file, "./problems/");
  strcat(problem_file, argv[1]);
  pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, problem_file);

  /* Build items[] structure array */
  struct problem_item items[n];
  for(int i = 0; i < n; i++)
  {
    items[i].weight = weights[i];
    items[i].profit = profits[i];
  }
  
  /* Put items[] array and capacity into DP */
  int *solution_array = (int *) malloc(n*sizeof(int));

  /* Solve it with Williamson and Shmoy's DP */
  int result = williamson_shmoys_DP(items, capacity, n, solution_array);

  /* Return the solution */
  printf("z: %d\tResult: %d\n", z, result);

  /* Check solution set */
  int correct_solution_flag = 1;
  for(int i = 0; i < n; i++)
    if (x[i] != solution_array[i])
      correct_solution_flag = 0;
  printf("%s", correct_solution_flag ? "Solution set identical!\n" : "Disparit"
         "y bewtween solution sets!\n");

  /* Clean up */
  free(profits);
  free(weights);
  free(x);

  return result;
}

#endif
