/******************************************************************************
 * Branch_and_bound version                                                   *
 * Implements the B&B with the normal a posteriori bound                      *
 * Notes                                                                      *
 *  - On instances where the WS FPTAS needs to dig deep in recursion to get   *
 *     an answer, stack space needs to be set to unlimited with the bash      *
 *     command:                                                               *
 *       ulimit -s unlimited                                                  *
 *    One such instance is knapPI_3_500_100000 #1 with WS's DP                *
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <math.h>
#include <string.h>
#include "branch_and_bound.h"
#include "branch_and_bound_benchmark.h"
#include "fptas.h"
#include "bench_extern.h"
#include "pisinger_reader.h"

void linear_programming_dual(int *profits, int *weights, int n, int capacity,
                             int *lower_bound, double *upper_bound,
                             int *LP_brancher);
void swap ( double* a, double* b );
int partition (double arr1[], double arr2[], int l, int h);
void quick_sort_parallel_lists(double *list1, double *list2, int lo, int hi);

long long int bytes_allocated;

/* Branch and bound algorithm */
void branch_and_bound_bin_knapsack(int profits[], int weights[], int x[],
                                   int capacity, const long z, long *z_out, 
                                   int sol_out[], int n, char *problem_file, 
                                   int branching_strategy, time_t seed, 
                                   int DP_method, int logging_rule, 
                                   FILE *logging_stream, double eps, 
                                   int *number_of_nodes,
                                   long long int memory_allocation_limit, 
                                   clock_t *start_time, int timeout, 
                                   const int dualbound_type,
                                   int *root_dual_bound) 
{ 
  /**branch_and_bound_bin_knapsack*********************************************
   * Description                                                              *
   *  Carries out a branch and bound search on binary knapsack                *
   * Parameters                                                               *
   *  profits: array of profits                                               *
   *  weights: array of weights                                               *
   *  x: solution array                                                       *
   *  capacity: problem capacity                                              *
   *  z: solution optimal                                                     *
   *  z_out: computed optimal (output parameter)                              *
   *  sol_out: computed optimal solution (output parameter)                   *
   *  n: number of items for the instance                                     *
   *  problem_file: string of the problem file reading from (I think this is  *
   *                only here because of the badly designed VV DP)            *
   *  branching_strategy:                                                     *
   *    -tb, -rb, or -le                                                      *
   *  seed: only relevant for -rb                                             *
   *  DP_method: -vv or -ws                                                   *
   *  logging_rule: NO_LOGGING, PARTIAL_LOGGING, FULL_LOGGING, FILE_LOGGING   *
   *  logging_stream: either stdio or a file                                  *
   *  eps: epsilon for the problem                                            *
   *  number of nodes: how many nodes are generated through the algorithm     *
   *                  (output parameter)                                      *
   *                                                                          *
   ****************************************************************************/
  
  /* Initialise externals */
  bytes_allocated = 0;
  
  /* Logging functionality */
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  if(logging_rule != NO_LOGGING)
  {
    fprintf(logging_stream, "▁ ▂ ▄ ▅ ▆ ▇ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █"
                            " █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ ▇ ▆ ▅ "
                            "▄ ▂ ▁\n"); 
    fprintf(logging_stream, "(¯`·.¸¸.·´¯`·.¸¸.-> [ %d-%d-%d %d:%d:%d - Startin"
                            "g B&B Problem %s] <-.¸¸.·´¯`·.¸¸.·´¯) \nƐ: %lf\n", 
            tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min,
            tm.tm_sec, problem_file, eps);
  }

  /* Initialise variables */
  int count = 0;
  int branching_variable;
  Min_Heap node_queue = PQ_initialise_min_heap(0);
  //LL_Problem_Queue *node_queue = LL_create_queue(); 
  Problem_Instance *root_node = define_root_node(n);
  PQ_enqueue(&node_queue, *root_node, logging_stream, logging_rule, 0);
  free(root_node);
  //LL_enqueue(node_queue, root_node, logging_stream,
  //           logging_rule, 0);
  srand(seed);
  Problem_Instance *current_node;
  int first_iteration = TRUE;
  int global_lower_bound = 0;
  int iterations = 0;
  int LP_brancher = -1;

  /* MAIN LOOP: While our node queue is not empty: */
  //while(node_queue->size >= 1)
  while(node_queue.size >= 1)
  {
    iterations++;

    /* Log information */
    if(logging_rule != NO_LOGGING)
      //fprintf(logging_stream, "\nStarting loop iteration %d (Node queue size: %d"
      //        ")\n", iterations, node_queue->size);
      fprintf(logging_stream, "\nStarting loop iteration %d (Node queue size: %"                              "d)\n", iterations, node_queue.size);

    /* Take node N off queue by some node selection scheme */
    current_node = PQ_pop_node(&node_queue);
    //current_node = select_and_dequeue_node(node_queue);
    
    /* Derive the LB and UB for node N with the FPTAS */
    find_bounds(current_node, profits, weights, x, capacity, n, z,
                &current_node->lower_bound, &current_node->upper_bound,
                problem_file, DP_method, logging_rule, logging_stream, eps,
                dualbound_type, memory_allocation_limit, timeout, 
                start_time, &LP_brancher);
    if(current_node->ID == 1)
      *root_dual_bound = current_node->upper_bound;

    /* Overflow check */
    if (bytes_allocated == -1 || *start_time == -1)
    {
      /* Total clean up */
      printf("%s detected in branch_and_bound.c at node %d\n", 
             bytes_allocated == -1 ? "Overallocation" : "Timeout", 
             current_node->ID);
      free(current_node->variable_statuses);
      free(current_node);
      while(PQ_pop_node(&node_queue) != NULL)
        ;  // This also frees the node_queue array
      //while (LL_dequeue(node_queue) != NULL)
      //  ; 
      //free(node_queue);
      return;
    }

    /* Log information */
    if(logging_rule != NO_LOGGING)
      fprintf(logging_stream, "\tNode %d (parent: %d) - bounds established: "
                              "lower: %d, upper: %d (GLB: %d)\n", 
              current_node->ID, current_node->parent_ID, 
              current_node->lower_bound, current_node->upper_bound,
              global_lower_bound);

    /* If UB <= GLB, we safely prune this branch and continue to loop */
    if ((current_node->ID != 0) && 
        (current_node->upper_bound <= global_lower_bound))
    {
      if(logging_rule != NO_LOGGING)
        fprintf(logging_stream, "\tUpper bound is lower that GLB! Pruning node b"
                "ranch.\n");
      free(current_node->variable_statuses);
      free(current_node);
      current_node = NULL;
      continue;
    }

    /* If LB > GLB, we set GLB = LB */
    if (current_node->lower_bound > global_lower_bound)
    {
      global_lower_bound = current_node->lower_bound;

      if(logging_rule != NO_LOGGING)
        fprintf(logging_stream, "\tLB > GLB: Improving GLB to %d.\n", 
                global_lower_bound);
    }

    /* If for N's parent's upper bound, UB_p, UB > UB_p, UB = UB_p */
    if (current_node->ID != 0 &&
        current_node->upper_bound > current_node->parent_upper_bound)
    {
      if(logging_rule != NO_LOGGING)
        fprintf(logging_stream, "\tParent's upper bound is lower; reducing thi"
                "s node's upper bound from %d to %d\n",
                current_node->upper_bound, current_node->parent_upper_bound);

      current_node->upper_bound = current_node->parent_upper_bound;
    }

    /* If UB > GLB, we branch on the variable */
    if (current_node->upper_bound > global_lower_bound)
    {
      if(logging_rule != NO_LOGGING)
        fprintf(logging_stream, "\tUB > GLB; branching on variable.\n");

      /* Find branching variable accoring to some strategy */
      if(branching_strategy != LINEAR_PROG_DUAL)
        branching_variable = find_branching_variable(n, z, 
                                                current_node->variable_statuses,
                                                branching_strategy, profits);
      else
      {
        branching_variable = LP_brancher;
      }

      /* If we can't constrain anymore variables, move on */
      if (branching_variable == -1) 
      {
        if(logging_rule != NO_LOGGING)
          fprintf(logging_stream, "\tNo variables left to constrain. Continuin"
                  "g...\n");
        free(current_node->variable_statuses);
        free(current_node);
        current_node = NULL;
        continue;
      }
      int node_limit_flag = 0;

      /* Else, generate children */
      generate_and_enqueue_nodes(current_node, n, branching_variable, 
                                 &node_queue, &count, logging_stream, logging_rule,
                                 &node_limit_flag);

      /* Log information */
      if(logging_rule != NO_LOGGING)
        fprintf(logging_stream, "\t Node %d branched on variable %d\n",
                current_node->ID, branching_variable);

      /* Node overflow check */
      if(node_limit_flag)
      { 
        printf("Node overflow! More than %d\n", NODE_OVERFLOW);
        *z_out = global_lower_bound;

        /* Total clean up */
        //while (LL_dequeue(node_queue))
        //  ; 
        //free(node_queue);
        while(PQ_pop_node(&node_queue) != NULL)
         ;
        return;
      } 

      /* Overallocation check */
      int overallocation = is_boundary_exceeded(memory_allocation_limit, *start_time, timeout);
      if(overallocation)
      {
        /* Exit, returning current best guess */
        if(overallocation == MEMORY_EXCEEDED)
        {
          bytes_allocated = -1;
          *z_out = global_lower_bound;
          /* Total clean up */
          //while (LL_dequeue(node_queue))
          //  ; 
          //free(node_queue);
          while(PQ_pop_node(&node_queue) != NULL)
            ;
          return;
        }
        else if (overallocation == TIMEOUT)
        {
          *start_time = -1;
          /* Total clean up */
          //while (LL_dequeue(node_queue))
          //  ; 
          while(PQ_pop_node(&node_queue) != NULL)
            ;
          //free(node_queue);
          return;
        }
      }
    }

    /* Free current node */
    free(current_node->variable_statuses);
    free(current_node);
    current_node = NULL;
    /* Loop again */
  }
  /* Prepare output parameters */
  *z_out = global_lower_bound;
  *number_of_nodes = count;

  /* Logging stuff*/
  if(logging_rule != NO_LOGGING)
    fprintf(logging_stream, "\nAlgorithm finished! Result: %ld / %ld, %d node%s g"
                            "enerated.\n▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄"
                            "▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄\n\n", *z_out, 
            z, count+1, (count == 0) ? "" : "s");

  /* Total clean up */
  if(current_node != NULL)
  {
    /* Clean up */
    free(current_node->variable_statuses);
    free(current_node);
    current_node = NULL;
  }
  //free(node_queue);
  while((current_node = PQ_pop_node(&node_queue)) != NULL)
   free(current_node);
}

/* Initial global lower bound heuristic */
int find_heuristic_initial_GLB(int profits[], int weights[], int x[], const long z, 
                               int n, int capacity, char *problem_file,
                               int DP_method, const int dualbound_type, 
                               const long long int memory_allocation_limit, const int timeout, 
                               clock_t *start_time)
{
  /* Run the FPTAS on the original problem with high epsilon */
  double eps = 0.1;
  double K;
  int sol_prime[n]; 
  int *profits_prime = (int *) malloc(n * sizeof(*profits_prime));
  bytes_allocated += n * sizeof(*profits_prime);
  int node_statuses[n];
  for (int i = 0; i < n; i++) node_statuses[i] = VARIABLE_UNCONSTRAINED;;
  FPTAS(eps, profits, weights, x, sol_prime, n, capacity, z,
        BINARY_SOL, SIMPLE_SUM, problem_file, &K, profits_prime, 
        DP_method, node_statuses, dualbound_type, memory_allocation_limit, 
        timeout, start_time);
  
  int fptas_profit = 0;
  if (bytes_allocated != -1)
  {
    for (int i = 0; i < n; i++)
      if (sol_prime[i] == 1)
        fptas_profit += profits[i];
  }  

  free(profits_prime);

  return fptas_profit;
}

/* Branching algorithm */
int find_branching_variable(int n, const long z, int *variable_statuses, 
                            int branching_strategy, int *profits)
{
  /* Random node enumeration algorithm */
  if (branching_strategy == RANDOM_BRANCHING)
  {
    int number_of_available_variables = 0;
    int available_variables[n];
    for(int i = 0; i < n; i++)
      if (variable_statuses[i] == VARIABLE_UNCONSTRAINED)
        available_variables[number_of_available_variables++] = i;
    int branched_variable;
    if (number_of_available_variables > 0)
      branched_variable = available_variables[rand() % number_of_available_variables];
    else
      branched_variable = -1;
    return branched_variable;
  } 

  /* Linear variable enumeration algorithm */  
  else if (branching_strategy == LINEAR_ENUM_BRANCHING)
  {
    for(int i = 0; i < n; i++)
      if (variable_statuses[i] == VARIABLE_UNCONSTRAINED)
        return i;
    return -1;
  }

  /* Truncation branching algorithm */
  else if (branching_strategy == TRUNCATION_BRANCHING)
  {
    /* For now, find max_profit here */
    int max_profit = -1;
    for(int i = 0; i < n; i++)
      if (profits[i] > max_profit)
        max_profit = profits[i];

    /* For now, we can try a linear pass every time (maybe later we can try a
     *  presort) */
    double max_truncation = -1;
    double this_truncation = -1;
    double epsilon = 0.8;
    double K = epsilon * max_profit / n;
    int best_variable = -1;
   
    for(int i = 0; i < n; i++)
    {
      if(variable_statuses[i] == VARIABLE_UNCONSTRAINED)
      {
        this_truncation = (double) profits[i] - K*floor((double)profits[i] / K);
        if(this_truncation > max_truncation)
        {
          max_truncation = this_truncation;
          best_variable = i;
        }
      }
    }
    return best_variable;
  }
}

/* Root node definition algorithm */
Problem_Instance *define_root_node(int n)
{
  Problem_Instance *root_instance =
                           (Problem_Instance*) malloc(sizeof(Problem_Instance));
  bytes_allocated += sizeof(Problem_Instance);
  root_instance->parent_ID = 0;
  root_instance->ID = 1;
  root_instance->parent_upper_bound = INT_MAX;
  root_instance->variable_statuses = (int *) malloc(n * sizeof(int));
  bytes_allocated += n*sizeof(int);
  for(int i = 0; i < n; i++) 
    root_instance->variable_statuses[i] = VARIABLE_UNCONSTRAINED;
  return root_instance;
}

/* Generation and node enqueuing algorithm */
void generate_and_enqueue_nodes(Problem_Instance *parent, int n, 
                          int branching_variable,
                          //LL_Problem_Queue *problem_queue,
                          Min_Heap *problem_queue,
                          int *count, FILE *logging_stream, int logging_rule, 
                          int *node_limit_flag)
{
  /* This will just use the structure Problem_Queue to enqueue it */
  /* Allocate for each node */
  Problem_Instance *generated_node_variable_on = 
                          (Problem_Instance *) malloc(sizeof(Problem_Instance));
  Problem_Instance *generated_node_variable_off = 
                          (Problem_Instance *) malloc(sizeof(Problem_Instance));
  bytes_allocated += 2*sizeof(Problem_Instance);

  parent->on_child = generated_node_variable_on;
  parent->off_child = generated_node_variable_off;

  /* For debug */
  generated_node_variable_on->ID = ++(*count);
  generated_node_variable_off->ID = ++(*count);


  /* Inherit parent's traits */
  /* First node */
  generated_node_variable_on->parent_ID = parent->ID;
  generated_node_variable_on->parent_upper_bound = parent->upper_bound;
  generated_node_variable_on->variable_statuses =
                                    (int *) malloc(sizeof(int) * n);
  bytes_allocated += n*sizeof(int);
  for(int i = 0; i < n; i++)
    generated_node_variable_on->variable_statuses[i] = 
                                     parent->variable_statuses[i];  
  generated_node_variable_on->variable_statuses[branching_variable] =
                                                                   VARIABLE_ON;
  generated_node_variable_on->on_child = NULL;
  generated_node_variable_on->off_child = NULL;

  /* Then, second node */
  generated_node_variable_off->parent_ID = parent->ID;
  generated_node_variable_off->parent_upper_bound = parent->upper_bound;
  generated_node_variable_off->variable_statuses =
                                    (int *) malloc(sizeof(int) * n);
  bytes_allocated += n*sizeof(int);
  for(int i = 0; i < n; i++)
    generated_node_variable_off->variable_statuses[i] = 
                                     parent->variable_statuses[i];  
  generated_node_variable_off->variable_statuses[branching_variable] = 
                                                                  VARIABLE_OFF; 
  generated_node_variable_off->on_child = NULL;
  generated_node_variable_off->off_child = NULL;


  /* Place into priority queue ))) */
  PQ_enqueue(problem_queue, *generated_node_variable_on, logging_stream, logging_rule, node_limit_flag);
  PQ_enqueue(problem_queue, *generated_node_variable_off, logging_stream, logging_rule, node_limit_flag); 
  //LL_enqueue(problem_queue, generated_node_variable_on, logging_stream, 
  //           logging_rule, node_limit_flag);
  //LL_enqueue(problem_queue, generated_node_variable_off, logging_stream, 
  //           logging_rule, node_limit_flag);

  /* Parent is freed outside */
}

/* Node selection and dequeuing algorithm */
Problem_Instance *select_and_dequeue_node(LL_Problem_Queue *node_queue)
{
  /* This method is largely a placeholder */
  /* It doesn't do much yet, but I made this function to accomodate growth */
  //Problem_Instance *selected_node = dequeue(node_queue);
  Problem_Instance *selected_node = LL_dequeue(node_queue);
  return selected_node;
}

/* General case node bounds derivation algorithm */
void find_bounds(Problem_Instance *current_node, int profits[], int weights[],
                 int x[], int capacity, int n, const long z, int *lower_bound_ptr, 
                 int *upper_bound_ptr, char *problem_file, int DP_method, 
                 int logging_rule, FILE *logging_stream, double eps, 
                 const int dualbound_type, const long long int memory_allocation_limit,
                 const int timeout, clock_t *start_time, int *LP_brancher)
{ 
  /* lower_bound_ptr and upper_bound_ptr are both output parameters */
  /* Solve the FPTAS with current node */
  if (eps == 0.0) eps = 0.002;
  double K;
  int sol_prime[n];
  int *profits_prime = (int *) malloc(n * sizeof(*profits_prime));
  bytes_allocated += n*sizeof(*profits_prime);

  /* Run the FPTAS */
  if(DP_method == SMART_DP)
  {
    printf("SMART DYNAMIC PROGRAAAAAAAAAAAMMING\n");
    exit(-1);
  }

  /* If we were going to use LP dual bounds, we get them in the switch statement below */
  else if (dualbound_type < LINEAR_PROG_DUAL)
  {
    if(logging_rule == FULL_LOGGING)
      fprintf(logging_stream, "\t\tCalling FPTAS for bounds (epsilon: %f, meth"
              "od: %s\n", eps, DP_method==VASIRANI ? "Vasirani" : "Williamson "
              "& Shmoys)");
    
    FPTAS(eps, profits, weights, x, sol_prime, n, capacity, z,
          BINARY_SOL, SIMPLE_SUM, problem_file, &K, profits_prime, 
          DP_method, current_node->variable_statuses, dualbound_type, 
          memory_allocation_limit, timeout, start_time);

    /* Bail out if overallocation happened */
    if (bytes_allocated == -1 || *start_time == -1)
    {
      free(profits_prime);
      printf("  %s detected in branch_and_bound.c\n", bytes_allocated == -1 ?
             "Overallocation" : "Timeout");
      return;
    }
  }

  int fptas_lower_bound = 0;
  double fptas_upper_bound = 0;

  /* Then, from the solution sets returned from the FPTAS, derive bounds */
  switch(dualbound_type) {
    case APRIORI_DUAL :
      for (int i = 0; i < n; i++)
        if (sol_prime[i] == 1)
        {
          fptas_lower_bound += profits[i];
          if (K > 1)  
            fptas_upper_bound += K * profits_prime[i];
          else
            fptas_upper_bound += profits[i];
        }
      fptas_upper_bound /= (1-eps); 
      break;
    case APOSTERIORI_DUAL_PLUS_NK :
      for (int i = 0; i < n; i++)
        if (sol_prime[i] == 1)
        {
          fptas_lower_bound += profits[i];
          if (K > 1)  
            fptas_upper_bound += K * profits_prime[i];
          else
            fptas_upper_bound += profits[i];
        }
      fptas_upper_bound += n*K; 
      break;
    case APOSTERIORI_DUAL_NK_MINUS_OMEGA : ;
      int amount_truncated = 0;
      for (int i = 0; i < n; i++)
        if (sol_prime[i] == 1)
        {
          fptas_lower_bound += profits[i];
          if (K > 1)  
          {
            fptas_upper_bound += profits[i];
            amount_truncated += profits[i] - K*profits_prime[i];
          }
          else
            fptas_upper_bound += profits[i];
        }
      fptas_upper_bound += n*K - amount_truncated; 
      break;
    case APOSTERIORI_DUAL_ROUNDUP :
      for (int i = 0; i < n; i++)
        if (sol_prime[i] == 1)
        {
          fptas_lower_bound += profits[i];
          if (K > 1)
            fptas_upper_bound += K * profits_prime[i];
          else /* K <= 1 */
            fptas_upper_bound += profits_prime[i];
        }
      break;
    case LINEAR_PROG_DUAL : ;
      /* Create symbolic profits: if variables are constrained off/on, set to
          zero */
      int symbolic_profits[n];
      int symbolic_weights[n];
      for(int i = 0; i < n; i++)
      {
        if(current_node->variable_statuses[i] == VARIABLE_UNCONSTRAINED)
        {
          symbolic_profits[i] = profits[i]; 
          symbolic_weights[i] = weights[i];
        }
        else
        {
          symbolic_profits[i] = 0;
          symbolic_weights[i] = 0;
        }
      }

      /* Calculate dual with remaining capacity */
      int adjusted_capacity = capacity;
      for(int i = 0; i < n; i++)
        if (current_node->variable_statuses[i] == VARIABLE_ON)
          adjusted_capacity -= weights[i];

      linear_programming_dual(symbolic_profits, symbolic_weights, n, 
                              adjusted_capacity, &fptas_lower_bound,
                              &fptas_upper_bound, LP_brancher);

      /* Add profits of items constrained on to upper/lower bounds */ 
      if(adjusted_capacity >= 0)
      {
        for(int i = 0; i < n; i++)
          if (current_node->variable_statuses[i] == VARIABLE_ON)
          {
            fptas_upper_bound += profits[i];
            fptas_lower_bound += profits[i];
          }  
        if(fptas_lower_bound > fptas_upper_bound)
          printf("Gotcha!\n");
      }
      break;
  }
  *lower_bound_ptr = fptas_lower_bound;
  *upper_bound_ptr = (int) fptas_upper_bound;

  /* Sanity check */
  if(fptas_lower_bound > fptas_upper_bound)
  {
    printf("Lower bound (%d) is greater than upper bound (%d)!\n", fptas_lower_bound, (int)fptas_upper_bound);
    printf("That can't be right! Let's get outta here!\n");
    exit(-1);
  }

  free(profits_prime);
}

/* Post order node freeing algorithm */
void post_order_tree_clean(Problem_Instance *node)
{
  /* Todo this I need the pointers to the children too */
  if (node == NULL)
    return;
  
  /* Recurse down 'on' subtree */
  post_order_tree_clean(node->on_child);
  
  /* Recurse down 'off' subtree */
  post_order_tree_clean(node->off_child);

  /* Then, free the node we're up to. */
  free(node->variable_statuses);
  free(node);
}

/* Bechmarking auzax: Boundary checking method */
int is_boundary_exceeded(long long int memory_limit, clock_t start_time, int timeout)
{
  /* First check if full memory limit has been exceed (5gb)*/
  //if (bytes_allocated > GLOBAL_MEMORY_LIMIT)
  //  return MEMORY_EXCEEDED;

  /* Then check if user memory limit has been exceeded */
  if (memory_limit != -1 && bytes_allocated > memory_limit)
    return MEMORY_EXCEEDED;

  /* Then check if timeout is reached */
  clock_t elapsed = clock() - start_time;
  double time_taken = ((double)elapsed)/CLOCKS_PER_SEC;
  if (timeout != -1 && time_taken > timeout)
  {
    return TIMEOUT;
  }
  /* Else no boundary is exceeded */
  return 0;
} 

/* Queue Data Structure Methods */
/* Problem Queue method: create_queue */
Problem_Queue *create_queue(int capacity)
{
  Problem_Queue *queue = (Problem_Queue*) malloc(sizeof(Problem_Queue));
  bytes_allocated += sizeof(Problem_Queue);
  queue->capacity = capacity;
  queue->front = queue->size = 0;
  queue->rear = capacity - 1;
  queue->array = (Problem_Instance **) malloc(queue->capacity * sizeof(Problem_Instance*));
  bytes_allocated += queue->capacity * sizeof(Problem_Instance*);
  return queue;
}

/* Problem Queue method: is_full*/
int is_full(Problem_Queue *queue)
{
  return (queue->size == queue->capacity);
}

/* Problem Queue method: is_empty */
int is_empty(Problem_Queue *queue)
{
  return (queue->size == 0);
}

/* Problem Queue method: enqueue */
void enqueue(Problem_Queue *queue, Problem_Instance *problem)
{
  if(is_full(queue))
    return;
  queue->rear = (queue->rear + 1)%queue->capacity;
  queue->array[queue->rear] = problem;
  queue->size = queue->size + 1;
}

/* Problem Queue method: dequeue */
Problem_Instance *dequeue(Problem_Queue *queue)
{
  if(is_empty(queue))
    return NULL;
  Problem_Instance *node = queue->array[queue->front];
  queue->array[queue->front] = NULL;
  queue->front = (queue->front + 1)%queue->capacity;
  queue->size = queue->size - 1;
  return node;
}

/* Problem Queue method: front */
Problem_Instance *front(Problem_Queue *queue)
{
  if(is_empty(queue))
    return NULL;
  return queue->array[queue->front];
}

/* Problem Queue method: rear */
Problem_Instance *rear(Problem_Queue *queue)
{
  if (is_empty(queue))
    return NULL;
  return queue->array[queue->rear];
}


/* LL Queue Data structure methods */
/* LL Problem Queue method: create queue */
LL_Problem_Queue *LL_create_queue(void)
{
  LL_Problem_Queue *queue = (LL_Problem_Queue*) malloc(sizeof(LL_Problem_Queue));
  bytes_allocated += sizeof(LL_Problem_Queue);
  queue->head = NULL;
  queue->tail = NULL;
  queue->size = 0;
  return queue;
}

/* LL Problem Queue method: enqueue */
void LL_enqueue(LL_Problem_Queue *queue, Problem_Instance *problem, 
              FILE *logging_stream, int logging_rule, int *node_limit_flag)
{
  LL_Node_Queue_Item *new_item = 
    (LL_Node_Queue_Item *) malloc(sizeof(LL_Node_Queue_Item));
  bytes_allocated += sizeof(LL_Node_Queue_Item);
  new_item->problem = problem;
  if(queue->size == 0)
  {
    queue->head = new_item;
    queue->tail = new_item;
    queue->size = 1;
  }
  else if(queue->size >= NODE_OVERFLOW)
  {
    printf("%d nodes in queue! Abandon ship!\n", NODE_OVERFLOW);
    if(logging_rule != NO_LOGGING)
      fprintf(logging_stream, "NODE OVERFLOW AAAAAAAAAAAAAAAAAAAHH-- \n");
    *node_limit_flag = 1;
  }
  else
  {
    new_item->in_front = queue->tail;
    queue->tail->behind = new_item;
    queue->tail = new_item;
    queue->size++;
  }
}


/* LL Problem Queue method: dequeue */
Problem_Instance *LL_dequeue(LL_Problem_Queue *queue)
{
  if(queue->size == 0)
    return NULL;
  
  Problem_Instance *dequeued_problem = queue->head->problem;
  LL_Node_Queue_Item *temp_node_pointer = queue->head->behind;
  free(queue->head);
  queue->head = temp_node_pointer;
  queue->size -= 1;
  return dequeued_problem;
}

void linear_programming_dual(int *profits, int *weights, int n, int capacity,
                             int *lower_bound, double *upper_bound,
                             int *LP_brancher)
{
  /**linear_programming_dual***************************************************
   * Description                                                              *
   *   Given parallel lists of profits and weights, calculate the basic       *
   *   linear programming dual and primal bounds for knapsack.                *
   * Notes                                                                    *
   *   lower_bound and upper_bound are output parameters.                     *
   ****************************************************************************/ 
  
  if(capacity <= 0)
    return;

  /* Order by non-increasing profit/weight ratio */
  double ratios[n];
  double indices[n];
  for(int i = 0; i < n; i++) indices[i] = 0;
  for(int i = 0; i < n; i++)
  {
    if (weights[i] != 0)
      ratios[i] = (double) profits[i]/weights[i];
    else
      ratios[i] = 0;
    indices[i] = (double) i;
  }

  quick_sort_parallel_lists(ratios, indices, 0, n-1);

  /* Pick items in that order, one by one until picking an item would 
      overfill the knapsack */
  int current_weight = 0;
  int current_profit = 0;
  int i = 0;
  for(i = 0; i < n && weights[(int)indices[i]]+current_weight <= capacity; i++)
  {
    current_weight += weights[(int)indices[i]];
    current_profit += profits[(int)indices[i]];
  }

  /* Then pick the fractional component of that item that you can fit to get
      the dual bound */
  double scale = 0;
  if(i < n)
  {
    scale = (double)(capacity - current_weight) / weights[(int)indices[i]];
    *upper_bound = current_profit + scale * profits[(int)indices[i]];
  }
  else *upper_bound = current_profit;
  *LP_brancher = i;
  
  /* Continue traversing the list until you find the next item that you can
      fit to get the primal bound */

  while (i < n && weights[(int)indices[i]]+current_weight > capacity)
    i++;
  if(i < n)
    *lower_bound = profits[(int)indices[i]]+current_profit;
  else
    *lower_bound = current_profit;
}

void quick_sort_parallel_lists(double *list1, double *list2, int lo, int hi)
{
  /**quick_sort_parallel_lists*************************************************
   * Description                                                              *
   *  Sort according to the first list, but also reflect changes in second    *
   *  list in parallel.                                                       *
   *                                                                          *
   ****************************************************************************/

    // Create an auxiliary stack
    double stack[ hi - lo + 1 ];
 
    // initialize top of stack
    int top = -1;
 
    // push initial values of l and h to stack
    stack[ ++top ] = lo;
    stack[ ++top ] = hi;
 
    // Keep popping from stack while is not empty
    while ( top >= 0 )
    {
        // Pop h and l
        hi = stack[ top-- ];
        lo = stack[ top-- ];
 
        // Set pivot element at its correct position
        // in sorted array
        int p = partition( list1, list2, lo, hi );
 
        // If there are elements on left side of pivot,
        // then push left side to stack
        if ( p-1 > lo )
        {
            stack[ ++top ] = lo;
            stack[ ++top ] = p - 1;
        }
 
        // If there are elements on right side of pivot,
        // then push right side to stack
        if ( p+1 < hi )
        {
            stack[ ++top ] = p + 1;
            stack[ ++top ] = hi;
        }
    }
}

/* swap function from geeksforgeeks.org/iterative-quick-sort/ */
void swap ( double* a, double* b )
{
    double t = *a;
    *a = *b;
    *b = t;
}

/*  partition function from geeksforgeeks.org/iterative-quick-sort/ */
int partition (double arr1[], double arr2[], int l, int h)
{
    double x = arr1[h];
    int i = (l - 1);
 
    for (int j = l; j <= h- 1; j++)
    {
        if (arr1[j] >= x)
        {
            i++;
            swap (&arr1[i], &arr1[j]);
            swap (&arr2[i], &arr2[j]);
        }
    }
    swap (&arr1[i + 1], &arr1[h]);
    swap (&arr2[i + 1], &arr2[h]);
    return (i + 1);
}

// Make min heap
Min_Heap PQ_initialise_min_heap(int size)
{
  Min_Heap heap;
  heap.size = 0;
  return heap;
}

void PQ_enqueue(Min_Heap *hp, Problem_Instance nd, 
              FILE *logging_stream, int logging_rule, int *node_limit_flag)
{
 /**PQ_enqueue*****************************************************************
  * Description                                                               *
  *   Enqueues a given problem instance onto our min heap arranged by parent  *
  *    upper bound values.                                                    *
  *                                                                           *
  *****************************************************************************/
  /* Make space for the new item */
  if(hp->size)
      hp->elem = realloc(hp->elem, (hp->size + 1) * sizeof(Problem_Instance)) ;
  else
      hp->elem = malloc(sizeof(Problem_Instance)) ;
  bytes_allocated += sizeof(Problem_Instance);

  /* Find spot in the heap for this new item */
  int i = (hp->size)++ ;
  while(i && nd.parent_upper_bound < hp->elem[PARENT(i)].parent_upper_bound) {
      hp->elem[i] = hp->elem[PARENT(i)] ;
      i = PARENT(i) ;
  }   
  hp->elem[i] = nd ;

  /* Problem Instance is now in the heap, just check that we haven't gone
      too far */
  if(hp->size >= NODE_OVERFLOW)
  {
    printf("%d nodes in queue! Abandon ship!\n", NODE_OVERFLOW);
    if(logging_rule != NO_LOGGING)
      fprintf(logging_stream, "NODE OVERFLOW AAAAAAAAAAAAAAAAAAAHH-- \n");
    *node_limit_flag = 1;
  }
}

// min heap pop
Problem_Instance *PQ_pop_node(Min_Heap *heap)
{
  Problem_Instance *popped_node = malloc(sizeof(Problem_Instance));

  /* Heap is nonempty */
  if(heap->size)
  {
    memcpy(popped_node, &(heap->elem[0]), sizeof(Problem_Instance));
    heap->elem[0] = heap->elem[--(heap->size)];
    heap->elem = realloc(heap->elem, heap->size *sizeof(Problem_Instance));
    heapify(heap, 0);
    return popped_node;
  }
  /* Heap is empty */
  else
  {
    free(popped_node);
    free(heap->elem);
    return NULL;
  }
}

// Heapify
void heapify(Min_Heap *hp, int i) {
    int smallest =
       (LCHILD(i) < hp->size &&
        hp->elem[LCHILD(i)].parent_upper_bound
          < hp->elem[i].parent_upper_bound ? LCHILD(i) : i );
    if(RCHILD(i) < hp->size && hp->elem[RCHILD(i)].parent_upper_bound 
          < hp->elem[smallest].parent_upper_bound) {
        smallest = RCHILD(i) ;
    }   
    if(smallest != i) {
        heap_swap(&(hp->elem[i]), &(hp->elem[smallest])) ;
        heapify(hp, smallest) ;
    }   
}

// Heap swap, which is the same as the other one but for problem instances
void heap_swap(Problem_Instance *n1, Problem_Instance *n2) {
    Problem_Instance temp = *n1 ;
    *n1 = *n2 ;
    *n2 = temp ;
}


