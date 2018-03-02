/******************************************************************************
 * TODO:                                                                      *
 *   - This doesn't work with epsilons that are big                           *
 *   - Update the logger so that it logs node IDs so I can locate who is      *
 *      spawning who.                                                         *
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

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include "fptas.c"

/* Structure Declarations */
typedef struct p_instance
{
  struct p_instance *parent;
  int *variable_statuses;
  int lower_bound;
  int upper_bound;
  int ID;
  struct p_instance *on_child;
  struct p_instance *off_child;
} Problem_Instance;

typedef struct queue 
{
  int front, rear, size, capacity;
  struct p_instance** array;
} Problem_Queue;

/* Branch and Bound Declarations */
Problem_Instance *define_root_node(int n);

void branch_and_bound_bin_knapsack(int profits[], int weights[], int x[],
                                   int capacity, int z, int *z_out, int sol_out[],
                                   int n, char *problem_file, 
                                   int branching_strategy, time_t seed,
                                   int DP_method, int logging_rule, 
                                   FILE *logging_stream, double epsilon);

int find_heuristic_initial_GLB(int profits[], int weights[], int x[], int z, 
                               int n, int capacity, char *problem_file);

int find_branching_variable(int n, int z, int *read_only_variables, 
                            int branching_strategy, int *profits);

void generate_and_enqueue_nodes(Problem_Instance *parent, int n,
                          int branching_variable, 
                          Problem_Queue *problems_list, int *count);

Problem_Instance *select_and_dequeue_node(Problem_Queue *node_queue);

void find_bounds(Problem_Instance *current_node, int profits[], int weights[],
                 int x[], int capacity, int n, int z, int *lower_bound_ptr, 
                 int *upper_bound_ptr, char *problem_file, int DP_method,
                 int logging_rule, FILE *logging_stream, double eps);

void post_order_tree_clean(Problem_Instance *root_node);

/* Queue Declarations */
Problem_Queue *create_queue(int capacity);

int is_full(Problem_Queue *queue);

int is_empty(Problem_Queue *queue);

void enqueue(Problem_Queue *queue, Problem_Instance *node);

Problem_Instance *dequeue(Problem_Queue *queue);

Problem_Instance *front(Problem_Queue *queue);

Problem_Instance *rear(Problem_Queue *queue);


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
  pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, problem_file, problem_no);

  /* Output variables */
  int z_out = 0;
  int sol_out[n];

  /* Start timer */
  clock_t t = clock();

  /* Solve the problem */
  branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, 
                                sol_out, n, problem_file, branching_strategy,
                                seed, DP_method, logging_rule, logging_stream, 
                                epsilon); 

  /* Stop timer */
  t = clock() - t;
  double time_taken = ((double)t)/CLOCKS_PER_SEC;

  if(branching_strategy == RANDOM_BRANCHING) printf("Seed: %ld\n", seed);

  printf("Answer: %d/%d (%s), time taken: %lf\n" , z_out, z, z_out == z ? "Pass"
         "!" : "Failure!", time_taken);

  /* Clean up */  
  free(profits);
  free(weights);
  free(x);

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
                                   FILE *logging_stream, double eps)
{ 
  /* Logging functionality */
  if(logging_rule != NO_LOGGING)
    fprintf(logging_stream, "Starting Branch and Bound! Problem: %s\n",
            problem_file);

  int count = 0;
  int branching_variable;
  Problem_Queue *node_queue = create_queue(n);
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
        fprintf(logging_stream, "\tNode bounds established: lower: %d, upper: %d"
                                " (GLB: %d)\n", current_node->lower_bound, 
                                current_node->upper_bound, global_lower_bound);
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
        fprintf(logging_stream, "\tLB > GLB: Improving GLB to %d.\n", global_lower_bound);
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
                                 node_queue, &count);
      if(logging_rule != NO_LOGGING)
        fprintf(logging_stream, "\t Branched on variable %d and put two new no"
                "des in the queue...\n", branching_variable);
    }
  }
  #ifndef TESTING
  printf("No of nodes: %d\n", count);
  #endif
  *z_out = global_lower_bound;

  /* Total clean up */
  free(node_queue->array);
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
  for (int i = 0; i < n; i++) sol_prime[i] = 0; 
  int *profits_prime = (int *) malloc(n * sizeof(*profits_prime));
  int node_statuses[n];
  for (int i = 0; i < n; i++) node_statuses[i] = VARIABLE_UNCONSTRAINED;

  FPTAS(eps, profits, weights, x, sol_prime, n, capacity, z,
        BINARY_SOL, TRIVIAL_BOUND, problem_file, &K, profits_prime, 
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
  root_instance->parent = NULL;
  root_instance->variable_statuses = (int *) malloc(n * sizeof(int));
  for(int i = 0; i < n; i++) 
    root_instance->variable_statuses[i] = VARIABLE_UNCONSTRAINED;
  return root_instance;
}

/* Generation and node enqueuing algorithm */
void generate_and_enqueue_nodes(Problem_Instance *parent, int n, 
                          int branching_variable, Problem_Queue *problems_list,
                          int *count)
{
  /* This will just use the structure Problem_Queue to enqueue it */
  /* Allocate for each node */
  Problem_Instance *generated_node_variable_on = 
                          (Problem_Instance *) malloc(sizeof(Problem_Instance));
  Problem_Instance *generated_node_variable_off = 
                          (Problem_Instance *) malloc(sizeof(Problem_Instance));

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
  for(int i = 0; i < n; i++)
    generated_node_variable_off->variable_statuses[i] = 
                                     parent->variable_statuses[i];  
  generated_node_variable_off->variable_statuses[branching_variable] = 
                                                                  VARIABLE_OFF; 
  generated_node_variable_off->on_child = NULL;
  generated_node_variable_off->off_child = NULL;

  /* Place into priority queue (for now just append) */
  enqueue(problems_list, generated_node_variable_on);
  enqueue(problems_list, generated_node_variable_off);
}

/* Node selection and dequeuing algorithm */
Problem_Instance *select_and_dequeue_node(Problem_Queue *node_queue)
{
  /* This method is largely a placeholder */
  /* It doesn't do much yet, but I made this function to accomodate growth */
  Problem_Instance *selected_node = dequeue(node_queue);
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
  for (int i = 0; i < n; i++) sol_prime[i] = 0;
  int *profits_prime = (int *) malloc(n * sizeof(*profits_prime));

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
      fptas_upper_bound += K * profits_prime[i];
    }
  fptas_upper_bound += n*K; 
  //printf(", LB: %d, UB: %lf, ", fptas_lower_bound, fptas_upper_bound);
  //fptas_upper_bound /= (1-eps);

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

/* Queue Data Structure Methods */
/* Problem Queue method: create_queue */
Problem_Queue *create_queue(int capacity)
{
  Problem_Queue *queue = (Problem_Queue*) malloc(sizeof(Problem_Queue));
  queue->capacity = capacity;
  queue->front = queue->size = 0;
  queue->rear = capacity - 1;
  queue->array = (Problem_Instance **) malloc(queue->capacity * sizeof(Problem_Instance*));
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

