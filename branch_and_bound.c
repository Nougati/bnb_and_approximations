/******************************************************************************
 * TODO:                                                                      *
 *   - This doesn't work if the algo needs to just exhaustively search.       *
 *                                                                            *
 ******************************************************************************/
/* Preprocessor definitions */
#define INCLUDE_FPTAS
#define nP 1
#define SIMPLE_SUM 2
#define RATIO_BOUND 3
#define BINARY_SOL 1
#define VARIABLE_ON 2
#define VARIABLE_UNCONSTRAINED 1
#define VARIABLE_OFF 0
#define LINEAR_ENUM_BRANCHING 0
#define RANDOM_BRANCHING 1
#define TRUNCATION_BRANCHING 2
#define TRUE 1
#define FALSE 0
#define NO_LOGGING 0 
#define PARTIAL_LOGGING 1
#define FULL_LOGGING 2
#define FILE_LOGGING 3
#define MEMORY_EXCEEDED 1
#define TIMEOUT 2
#define NODE_OVERFLOW 1500000

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include "bench_extern.h"
#include "branch_and_bound.h"
#include "pisinger_reader.h"
#include "fptas.c"


/*TODO Make benchmarking program that will define this as an external variable.
 * In addition, we need to make a makefile for benchmarking that will compile 
 * both the benchmarking program and this one so that the variable is 
 * guaranteed to be known about. */
int bytes_allocated;

/* Main function */
#ifndef TESTING
int main(int argc, char *argv[]) {
  /* Dynamic Input variable support */
  int n, capacity, z, opt_profit;
  int *profits, *weights, *x;
  char problem_file[100];

  /* Command line args support */
  if(argc == 2 && (strcmp(argv[1], "help") == 0))
  {
    printf("Branch strategy flags:\n\t-rb: random branching\n\t-le: linear enu"
           "meration\n\t-tb: truncation branching \nDP Options:\n\t-ws: force "
           "Williamson & Shmoy's DP\n\t-vv: force Vasirani's DP\n\t-smart: let"
           " the program decide.\n\tLogging rule:\n\t-off: do not log anything"
           ".\n\t-console_some: log the big actions of the program to console."
           "\n\t-console_all: log basically all actions to console\n\t<filenam"
           "e>: specify a file to write to.\nEpsilon:\n\t0 to leave it to algo"
           "rithm, else input an eps > 0.\n");
    exit(0);
  }
  if(argc != 7 && argc != 8)
  { 
    printf("Format:\n %s <filename> <problem_no> <DP> <logging rule> <epsilon> <branching strategy>\n", argv[0]);
    printf("or\n %s <filename> <problem_no> <DP> <logging rule> <epsilon> -rb <seed>\n", argv[0]);
    exit(0);
  }
  
  int problem_no = atoi(argv[2]);

  /* Specify DP method */
  int DP_method = -1;
  if(strcmp(argv[3], "-ws") == 0)
    DP_method = WILLIAMSON_SHMOY;
  else if (strcmp(argv[3], "-vv") == 0)
    DP_method = VASIRANI;
  else if (strcmp(argv[3], "-smart") == 0)
    DP_method = SMART_DP; 
  else
  {
    printf("Unrecognised DP flag!\nExiting...\n");
    exit(-1);
  }
  
  /* Specify logging */
  int logging_rule = -1;
  FILE * logging_stream;
  if(strcmp(argv[4], "-off") == 0)
  {  
    logging_rule = NO_LOGGING;
    logging_stream = NULL;
  }
  else if(strcmp(argv[4], "-console_some") == 0)
  {
    logging_rule = PARTIAL_LOGGING;
    logging_stream = stdout;
  }
  else if(strcmp(argv[4], "-console_all") == 0)
  { 
    logging_rule = FULL_LOGGING; 
    logging_stream = stdout;
  }
  else
  {
    logging_rule = FULL_LOGGING;
    logging_stream = fopen(argv[4], "a");
  }

  /* Epsilon choice */
  double epsilon = 0.02;
  sscanf(argv[5], "%lf", &epsilon);

  /* Designate branching strategy variable */
  int branching_strategy;
  time_t seed;
  if(strcmp(argv[6], "-rb") == 0)
  {
    branching_strategy = RANDOM_BRANCHING;
    if (argc != 8)
    {
      printf("Please define a seed!\n For random branching after the -rb flag,"
             " or input \"auto\"\n to allow the program to generate one based "
             "on time(NULL).\n");
      exit(-1);
    }
    if (strcmp(argv[7], "auto") == 0)
      seed = time(NULL);
    else seed = (time_t) atoi(argv[3]);
  }
  else if(strcmp(argv[6], "-le") == 0)
  {
    branching_strategy = LINEAR_ENUM_BRANCHING;
    seed = 0;
  }
  else if(strcmp(argv[6], "-tb") == 0)
  {
    branching_strategy = TRUNCATION_BRANCHING;
    seed = 0;
  }
  else
  {
    printf("Branching strategy flag not recognised!\n");
    exit(-1);
  }
  
  strcpy(problem_file, argv[1]);

  /* Read problem */
  pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, problem_file,
                  problem_no);

  /* Output variables */
  int z_out = 0;
  int number_of_nodes = -1;
  int sol_out[n];

  /* Turn off limits */
  int memory_allocation_limit = -1;
  int timeout = -1;

  /* Start timer */
  clock_t t = clock();

  /* Solve the problem */
  branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, problem_file, branching_strategy,
                                seed, DP_method, logging_rule, logging_stream, 
                                epsilon, &number_of_nodes, 
                                memory_allocation_limit, &t, timeout);

  /* Stop timer */
  t = clock() - t;
  double time_taken = ((double)t)/CLOCKS_PER_SEC;

  printf("No of nodes: %d\n", number_of_nodes);

  if(branching_strategy == RANDOM_BRANCHING) printf("Seed: %ld\n", seed);

  printf("Answer: %d/%d (%s), time taken: %lf\nBytes allocated: %d\n" , z_out,
         z, z_out == z ? "Pass!" : "Failure!", time_taken, bytes_allocated);

  /* Clean up */  
  free(profits);
  free(weights);
  free(x);

  fclose(logging_stream);
  return 0;
}
#endif


/* Branch and bound methods */
/* Branch and bound algorithm */
void branch_and_bound_bin_knapsack(int profits[], int weights[], int x[],
                                   int capacity, int z, int *z_out, 
                                   int sol_out[], int n, char *problem_file, 
                                   int branching_strategy, time_t seed, 
                                   int DP_method, int logging_rule, 
                                   FILE *logging_stream, double eps, 
                                   int *number_of_nodes,
                                   int memory_allocation_limit, clock_t *start_time, 
                                   int timeout)
{ 
  /* Branch and bound algorithm for 0,1 Knapsack!
   *  profits: array of profits
   *  weights: array of weights
   *  x: solution array
   *  capacity: problem capacity
   *  z: solution optimal
   *  z_out: computed optimal (output parameter)
   *  sol_out: computed optimal solution (output parameter)
   *  n: number of items for the instance
   *  problem_file: string of the problem file reading from (I think this is 
   *                only here because of the badly designed VV DP
   *  branching_strategy:
   *    -tb, -rb, or -le
   *  seed: only relevant for -rb 
   *  DP_method: -vv or -ws
   *  logging_rule: NO_LOGGING, PARTIAL_LOGGING, FULL_LOGGING, FILE_LOGGING
   *  logging_stream: either stdio or a file
   *  eps: epsilon for the problem
   *  number of nodes: how many nodes are generated through the algorithm 
   *                  (output parameter)
   * */
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

  int count = 0;
  int branching_variable;
  //Problem_Queue *node_queue = create_queue(n);
  LL_Problem_Queue *node_queue = LL_create_queue(); 
  Problem_Instance *root_node = define_root_node(n);
  srand(seed);
  Problem_Instance *current_node;
  int first_iteration = TRUE;
  int global_lower_bound;
  int iterations = 0;

  /* While our node queue is not empty: */
  while((first_iteration) || (node_queue->size >= 1))
  {
    iterations++;

    /* Logging functionality */
    if(logging_rule != NO_LOGGING)
      fprintf(logging_stream, "\nStarting loop iteration %d (Node queue size: %d"
              ")\n", iterations, node_queue->size);

    /* Get next node */
    if(first_iteration)
    {
      current_node = root_node;
      current_node->upper_bound = INT_MAX;
      current_node->ID = count;
      global_lower_bound = find_heuristic_initial_GLB(profits, weights, x, z, 
                                                  n, capacity, problem_file);
      current_node->lower_bound = global_lower_bound;
      first_iteration = FALSE;
      if(logging_rule != NO_LOGGING)
        fprintf(logging_stream, "\tRoot node bounds established. GLB: %d", 
                global_lower_bound);
    }
    else
    {
      /* Take node N off queue by some node selection scheme */
      current_node = select_and_dequeue_node(node_queue);

      /* Derive the LB and UB for node N with the FPTAS */
      find_bounds(current_node, profits, weights, x, capacity, n, z,
                  &current_node->lower_bound, &current_node->upper_bound,
                  problem_file, DP_method, logging_rule, logging_stream, eps);

      if(logging_rule != NO_LOGGING)
        fprintf(logging_stream, "\tNode %d (parent: %d) - bounds established: "
                                "lower: %d, upper: %d (GLB: %d)\n", 
                current_node->ID, current_node->parent->ID, 
                current_node->lower_bound, current_node->upper_bound,
                global_lower_bound);
    }

    /* If UB < GLB, we safely prune this branch and continue to loop */
    if ((current_node->ID != 0) && 
        ((current_node->upper_bound <= global_lower_bound) || 
         (current_node->upper_bound > current_node->parent->upper_bound)))  
    {
      if(logging_rule != NO_LOGGING)
        fprintf(logging_stream, "\tUpper bound is lower that GLB! Pruning node b"
                "ranch.\n");
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
        current_node->upper_bound > current_node->parent->upper_bound)
    {
      if(logging_rule != NO_LOGGING)
        fprintf(logging_stream, "\tParent's upper bound is lower; reducing thi"
                "s node's upper bound from %d to %d\n",
                current_node->upper_bound, current_node->parent->upper_bound);

      current_node->upper_bound = current_node->parent->upper_bound;
    }

    /* If UB > GLB, we branch on the variable */
    if (current_node->upper_bound > global_lower_bound)
    {
      if(logging_rule != NO_LOGGING)
        fprintf(logging_stream, "\tUB > GLB; branching on variable.\n");

      branching_variable = find_branching_variable(n, z, 
                                              current_node->variable_statuses,
                                              branching_strategy, profits);
      if (branching_variable == -1) 
      {
        if(logging_rule != NO_LOGGING)
          fprintf(logging_stream, "\tNo variables left to constrain. Continuin"
                  "g...\n");
        continue;
      }
      generate_and_enqueue_nodes(current_node, n, branching_variable, 
                                 node_queue, &count, logging_stream, logging_rule);
      if(logging_rule != NO_LOGGING)
        fprintf(logging_stream, "\t Node %d branched on variable %d\n",
                current_node->ID, branching_variable);

      /* Check for overallocation */
      int overallocation = is_boundary_exceeded(memory_allocation_limit, *start_time, timeout);
      if(overallocation)
        /* Exit, returning current best guess */
        if(overallocation == MEMORY_EXCEEDED)
        {
          bytes_allocated = -1;
          *z_out = global_lower_bound;
          return;
        }
        else if (overallocation == TIMEOUT)
        {
          *start_time = -1;
          return;
        }
      /* Else, loop again */
    }
  }
  *z_out = global_lower_bound;
  *number_of_nodes = count;
  if(logging_rule != NO_LOGGING)
    fprintf(logging_stream, "\nAlgorithm finished! Result: %d / %d, %d nodes g"
                            "enerated.\n▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄"
                            "▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄\n\n", *z_out, 
            z, count);
  /* Total clean up */
  free(node_queue);
  post_order_tree_clean(root_node);
}

/* Initial global lower bound heuristic */
int find_heuristic_initial_GLB(int profits[], int weights[], int x[], int z, 
                               int n, int capacity, char *problem_file)
{
  /* Run the FPTAS on the original problem with high epsilon */
  double eps = 1.0;
  double K;
  int sol_prime[n]; 
  int *profits_prime = (int *) malloc(n * sizeof(*profits_prime));
  bytes_allocated += n * sizeof(*profits_prime);
  int node_statuses[n];
  for (int i = 0; i < n; i++) node_statuses[i] = VARIABLE_UNCONSTRAINED;

  FPTAS(eps, profits, weights, x, sol_prime, n, capacity, z,
        BINARY_SOL, SIMPLE_SUM, problem_file, &K, profits_prime, 
        WILLIAMSON_SHMOY, node_statuses);

  int fptas_profit = 0;
  for (int i = 0; i < n; i++)
    if (sol_prime[i] == 1)
      fptas_profit += profits[i];
  
  free(profits_prime);

  return fptas_profit;
}

/* Branching algorithm */
int find_branching_variable(int n, int z, int *variable_statuses, 
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
    double max_truncation = 0;
    double this_truncation;
    double epsilon = 0.8;
    double K = epsilon * max_profit / n;
    int best_variable = -1;
   
    for(int i = 0; i < n; i++)
    {
      if(variable_statuses[i] == VARIABLE_UNCONSTRAINED)
      {
        this_truncation = profits[i] - K*floor(profits[i] / K);
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
  root_instance->parent = NULL;
  root_instance->variable_statuses = (int *) malloc(n * sizeof(int));
  bytes_allocated += n*sizeof(int);
  for(int i = 0; i < n; i++) 
    root_instance->variable_statuses[i] = VARIABLE_UNCONSTRAINED;
  return root_instance;
}

/* Generation and node enqueuing algorithm */
void generate_and_enqueue_nodes(Problem_Instance *parent, int n, 
                          int branching_variable, LL_Problem_Queue *problem_queue,
                          int *count, FILE *logging_stream, int logging_rule)
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
  generated_node_variable_on->parent = parent;
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

  /* Second node */
  generated_node_variable_off->parent = parent;
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

  /* Place into priority queue (for now just append) */
  //enqueue(problems_list, generated_node_variable_on);
  LL_enqueue(problem_queue, generated_node_variable_on, logging_stream, logging_rule);
  //enqueue(problems_list, generated_node_variable_off);
  LL_enqueue(problem_queue, generated_node_variable_off, logging_stream, logging_rule);
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
                 int x[], int capacity, int n, int z, int *lower_bound_ptr, 
                 int *upper_bound_ptr, char *problem_file, int DP_method, 
                 int logging_rule, FILE *logging_stream, double eps)
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
  else
  {
    if(logging_rule == FULL_LOGGING)
      fprintf(logging_stream, "\t\tCalling FPTAS for bounds (epsilon: %f, meth"
              "od: %s\n", eps, DP_method==VASIRANI ? "Vasirani" : "Williamson "
              "& Shmoys)");

    FPTAS(eps, profits, weights, x, sol_prime, n, capacity, z,
          BINARY_SOL, SIMPLE_SUM, problem_file, &K, profits_prime, 
          DP_method, current_node->variable_statuses);
  }

  /* Then, from the solution sets returned from the FPTAS, derive bounds */
  int fptas_lower_bound = 0;
  double fptas_upper_bound = 0;
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

  *lower_bound_ptr = fptas_lower_bound;
  *upper_bound_ptr = (int) fptas_upper_bound;

  free(profits_prime);
}

/* Post order node freeing algorithm */
void post_order_tree_clean(Problem_Instance *node)
{
  /* Todo this I need the pointers to the children too */
  if (node == NULL)
    return;
  
  post_order_tree_clean(node->on_child);
  
  post_order_tree_clean(node->off_child);

  free(node->variable_statuses);
  free(node);
}

/* Bechmarking auzax: Boundary checking method */
int is_boundary_exceeded(int memory_limit, clock_t start_time, int timeout)
{

  /* First check if memory limit has been exceeded */
  if (memory_limit != -1 && bytes_allocated > memory_limit)
    return MEMORY_EXCEEDED;

  /* Then check if timeout is reached */
  clock_t elapsed = clock() - start_time;
  double time_taken = ((double)elapsed)/CLOCKS_PER_SEC;
  if (timeout != -1 && time_taken > timeout)
    return TIMEOUT;

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
void LL_enqueue(LL_Problem_Queue *queue, Problem_Instance *problem, FILE *logging_stream, int logging_rule)
{
  LL_Node_Queue_Item *new_item = (LL_Node_Queue_Item *) malloc(sizeof(LL_Node_Queue_Item));
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
    exit(-1);
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

