/*TODO FiX COMPILER ERRORS*/
#define TESTING
#define nP 1
#define SIMPLE_SUM 2
#define RATIO_BOUND 3
#define BINARY_SOL 1
#define VARIABLE_ON 2
#define VARIABLE_UNCONSTRAINED 1
#define VARIABLE_OFF 0
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fptas.c"

/* Structure Declarations */
typedef struct p_instance
{
  struct p_instance *parent;
  int *variable_statuses;
  int lower_bound;
  int upper_bound;
} Problem_Instance;

typedef struct queue 
{
  int front, rear, size, capacity;
  struct p_instance* array[];
} Problem_Queue;

/* Branch and Bound Declarations */
Problem_Instance *define_root_node(int n);
void branch_and_bound_bin_knapsack(int profits[], int weights[], int x[],
                                int capacity, int z, int *z_out, int sol_out[],
                                   int n, char *problem_file);

int find_heuristic_initial_GLB(int profits[], int weights[], int x[], int z, 
                               int n, int capacity, char *problem_file);

int find_branching_variable(int *profits, int *weights, int n, 
                            int *read_only_variables);

void generate_and_enqueue_nodes(Problem_Instance *parent, int n,
                          int branching_variable, 
                          Problem_Queue *problems_list);

void find_bounds(Problem_Instance *current_node, int profits[], int weights[],
                 int x[], int capacity, int n, int z, int *lower_bound_ptr, 
                 int *upper_bound_ptr);

/* Queue Declarations */
Problem_Queue *create_queue(int capacity);

Problem_Instance *select_and_dequeue_node(Problem_Queue *node_queue);

int is_full(Problem_Queue *queue);

int is_empty(Problem_Queue *queue);

void enqueue(Problem_Queue *queue, Problem_Instance *node);

Problem_Instance *dequeue(Problem_Queue *queue);

Problem_Instance *front(Problem_Queue *queue);

Problem_Instance *rear(Problem_Queue *queue);


int main(int argc, char *argv[])
{
  return 0;
}

/* Branch and bound algorithm */
void branch_and_bound_bin_knapsack(int profits[], int weights[], int x[],
                                int capacity, int z, int *z_out, int sol_out[],                                int n, char *problem_file)
{
  int lower_bound, upper_bound;
  Problem_Instance *root_node = define_root_node(n);

  /* Find heuristic initial GLB on problem with FPTAS */
  int global_lower_bound = find_heuristic_initial_GLB(profits, weights, x, z, 
                                                    n, capacity, problem_file);

  /* Choose a variable to branch on by some criteria, and generate the 
   * constrained problems known as 'nodes'. Then, places these nodes in a node
   * queue. */
  srand(time(NULL));
  int *read_only_variables = (int *) calloc(n, sizeof(int));
  int branching_variable = find_branching_variable(profits, weights, n, 
                                                  read_only_variables);
  Problem_Queue *node_queue = create_queue(n);
  generate_and_enqueue_nodes(root_node, n, branching_variable, node_queue);

  Problem_Instance *current_node;
  /* Then, while our node queue is not empty: */
  while(node_queue->size >= 1)
  {
    /* Take node N off queue by some node selection scheme */
    current_node = select_and_dequeue_node(node_queue);

    /* Derive the LB and UB for node N with the FPTAS */
    find_bounds(current_node, profits, weights, x, capacity, n, z,
                &current_node->lower_bound, &current_node->upper_bound);

    /* If UB < GLB, we safely prune this branch and continue to loop */
    if (upper_bound < global_lower_bound)
      continue;

    /* If LB > GLB, we set GLB = LB */
    if (current_node->lower_bound > global_lower_bound)
      global_lower_bound = lower_bound;

    /* If for N's parent's upper bound, UB_p, UB > UB_p, UB = UB_p */
    if (current_node->upper_bound > current_node->parent->upper_bound)
      current_node->upper_bound = current_node->parent->upper_bound;

    /* If UB > GLB, we branch on the variable */
    if (current_node->upper_bound > global_lower_bound)
    {
      branching_variable = find_branching_variable(profits, weights, n, z, 
                                                  read_only_variables);
      generate_and_enqueue_nodes(current_node, n, branching_variable, node_queue);
    }
  }
}

/* Initial global lower bound heuristic */
int find_heuristic_initial_GLB(int profits[], int weights[], int x[], int z, 
                               int n, int capacity, char *problem_file)
{
  /* Run the FPTAS on the original problem with high epsilon */
  float eps = 1.0;
  float K;
  int sol_prime[n]; 
  for (int i = 0; i < n; i++) sol_prime[i] = 0; 
  int *profits_prime = (int *) malloc(n * sizeof(*profits_prime));
  int node_statuses[n];
  for (int i = 0; i < n; i++) node_statuses[i] = 0;
  int read_only_variables[n];
  for (int i = 0; i < n; i++) read_only_variables[i] = 0;

  FPTAS(eps, profits, weights, x, sol_prime, n, capacity, z,
        BINARY_SOL, TRIVIAL_BOUND, problem_file, &K, profits_prime, 
        WILLIAMSON_SHMOY, node_statuses, read_only_variables);

  int fptas_profit = 0;
  for (int i = 0; i < n; i++)
    if (sol_prime[i] == 1)
      fptas_profit += profits[i];
  
  free(profits_prime);

  return fptas_profit;
}

/* Branching algorithm */
int find_branching_variable(int *profits, int *weights, int n, 
                            int *read_only_variables)
{
  int r = rand()%n;
  return r;
}

/* Node generation and enqueuing algorithm */
Problem_Instance *define_root_node(int n)
{
  Problem_Instance *root_instance = &(Problem_Instance) 
        { .parent = NULL,
          .variable_statuses = (int *) malloc(n * sizeof(int))};
  for(int i = 0; i < n; i++) 
    root_instance->variable_statuses[i] = VARIABLE_UNCONSTRAINED;
  return root_instance;
}

void generate_and_enqueue_nodes(Problem_Instance *parent, int n, 
                          int branching_variable, Problem_Queue *problems_list)
{
  /* This will just use the structure Problem_Queue to enqueue it */
  /* Allocate for each node */
  Problem_Instance *generated_node_variable_on = 
                                            malloc(sizeof(Problem_Instance));
  Problem_Instance *generated_node_variable_off = 
                                            malloc(sizeof(Problem_Instance));

  /* Inherit parent's traits */
  /* First node */
  generated_node_variable_on->parent = parent;
  generated_node_variable_on->variable_statuses =
                                    (int *) calloc(n, sizeof(int));
  for(int i = 0; i < n; i++)
    generated_node_variable_on->variable_statuses[i] = 
                                     parent->variable_statuses[i];  

  /* Second node */
  generated_node_variable_off->parent = parent;
  generated_node_variable_off->variable_statuses =
                                    (int *) calloc(n, sizeof(int));
  for(int i = 0; i < n; i++)
    generated_node_variable_off->variable_statuses[i] = 
                                     parent->variable_statuses[i];  
  
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
                 int *upper_bound_ptr)
{ 
  /* lower_bound_ptr and upper_bound_ptr are both output parameters */
  /* Solve the FPTAS with current node */
  float eps = 1.0;
  float K;
  int sol_prime[n];
  for (int i = 0; i < n; i++) sol_prime[i] = 0;
  int *profits_prime = (int *) malloc(n * sizeof(*profits_prime));
  int active_nodes[n];
  for (int i = 0; i < n; i++) active_nodes[i] = 0;
  int read_only_variables[n];
  for (int i = 0; i < n; i++) read_only_variables[i] = 0;

  FPTAS(eps, profits, weights, x, sol_prime, SIMPLE_SUM, capacity, z,
        BINARY_SOL, problem_file, &K, profits_prime, WILLIAMSON_SHMOY, 
        acitve_nodes, read_only_variables);

  int fptas_lower_bound = 0;
  int fptas_upper_bound = 0;
  for (int i = 0; i < n; i++)
    if (sol_prime[i] == 1)
    {
      fptas_lower_bound += profits[i];
      fptas_upper_bound += K * profits_prime[i];
    }
  *lower_bound_ptr = fptas_lower_bound;
  *upper_bound_ptr = fptas_upper_bound;

  free(profits_prime);
}


/* Queue Data Structure Methods */
Problem_Queue *create_queue(int capacity)
{
  Problem_Queue *queue = (Queue*) malloc(sizeof(Queue));
  queue->capacity = capacity;
  queue->front = queue->size = 0;
  queue->read = capacity - 1;
  queue->array = (int *) malloc(queue->capacity * sizeof(Problem_Instance*));
  return queue;
}

int is_full(Problem_Queue *queue)
{
  return (queue->size == queue->capacity);
}

int is_empty(Problem_Queue *queue)
{
  return (queue->size == 0);
}

void enqueue(Problem_Queue *queue, Problem_Instance *node)
{
  if(is_full(queue))
    return;
  queue->rear = (queue->rear + 1)%queue->capacity;
  queue->array[queue->read] = problem;
  queue->size = queue->size + 1;
}

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

Problem_Instance *front(Problem_Queue *queue)
{
  if(is_empty(queue))
    return NULL;
  return queue->array[queue->front];
}

Problem_Instance *rear(Problem_Queue *queue)
{
  if (is_empty(queue))
    return NULL;
  return queue->array[queue->rear];
}


