/******************************************************************************
 * TODO:                                                                      *
 *   - Unit tests                                                              *
 *   - Then problem instance testing                                          *
 *   - Then customise to suit me minutely                                     *
 *                                                                            *
 ******************************************************************************/
#define INCLUDE_FPTAS
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
  struct p_instance** array;
} Problem_Queue;

/* Branch and Bound Declarations */
Problem_Instance *define_root_node(int n);
void branch_and_bound_bin_knapsack(int profits[], int weights[], int x[],
                                int capacity, int z, int *z_out, int sol_out[],
                                   int n, char *problem_file);

int find_heuristic_initial_GLB(int profits[], int weights[], int x[], int z, 
                               int n, int capacity, char *problem_file);

int find_branching_variable(int *profits, int *weights, int n, int z,  
                            int *read_only_variables);

void generate_and_enqueue_nodes(Problem_Instance *parent, int n,
                          int branching_variable, 
                          Problem_Queue *problems_list);

Problem_Instance *select_and_dequeue_node(Problem_Queue *node_queue);

void find_bounds(Problem_Instance *current_node, int profits[], int weights[],
                 int x[], int capacity, int n, int z, int *lower_bound_ptr, 
                 int *upper_bound_ptr, char *problem_file);

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
  /* Static Input variables 
  int profits[] = {94, 506, 416, 992, 649, 237, 457, 815, 446, 422, 791, 359, 
                  667, 598, 7, 544, 334, 766, 994, 893, 633, 131, 428, 700, 617,
                  874, 720, 419, 794, 196, 997, 116, 908, 539, 707, 569, 537, 
                  931, 726, 487, 772, 513, 81, 943, 58, 303, 764, 536, 724, 789};
  int weights[] = {485, 326, 248, 421, 322, 795, 43, 845, 955, 252, 9, 901, 122,
                   94, 738, 574, 715, 882, 367, 984, 299, 433, 682, 72, 874, 138,
                   856, 145, 995, 529, 199, 277, 97, 719, 242, 107, 122, 70, 98,
                   600, 645, 267, 972, 895, 213, 748, 487, 923, 29, 674}; 
  int x[] = {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
             0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
             1, 0};
  int n = 50;
  int z = 8373;
  int capacity = 995;
  char problem_file[] = "knapPI_1_50_1000.csv";*/


  /* Dynamic Input variable support */
  int n, capacity, z, opt_profit;
  int *profits, *weights, *x;
  char problem_file[100];

  /* Command line args support */
  if(argc != 2)
  { 
    printf("Format: %s <filename>\n", argv[0]);
    exit(-1);
  }
  strcpy(problem_file, argv[1]);

  /* Read problem */
  pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, problem_file, 1);

  /* Output variables */
  int z_out = 0;
  int sol_out[n];

  /* Start timer */
  clock_t t = clock();

  /* Solve the problem */
  printf("Computing...\n");
  branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, &z_out, sol_out, n, problem_file); 
  printf("Computed.\n");
  /* Stop timer */
  t = clock() - t;
  double time_taken = ((double)t)/CLOCKS_PER_SEC;

  printf("Answer: %d/%d (%s)\n", z_out, z, z_out == z ? "Pass!" : "Failure!");
  return 0;
}
#endif

/* Branch and bound methods*/
/* Branch and bound algorithm */
void branch_and_bound_bin_knapsack(int profits[], int weights[], int x[],
                                   int capacity, int z, int *z_out, int sol_out[],    
                                   int n, char *problem_file)
{
  int iterations = 0;
  int lower_bound, upper_bound;
  Problem_Instance *root_node = define_root_node(n);

  //printf("Finding heuristics intial GLB on problem with FPTAS\n");
  /* Find heuristic initial GLB on problem with FPTAS */
  int global_lower_bound = find_heuristic_initial_GLB(profits, weights, x, z, 
                                                    n, capacity, problem_file);

  /* Choose a variable to branch on by some criteria, and generate the 
   * constrained problems known as 'nodes'. Then, places these nodes in a node
   * queue. */
  time_t seed = time(NULL); 
  srand(seed);
  printf("Seed: %ld\n", seed);
  int *initial_variable_statuses = (int *) malloc(sizeof(int)*n);
  for(int i = 0; i < n; i++) initial_variable_statuses[i] = VARIABLE_UNCONSTRAINED;
  //printf("Finding branching variable\n");
  int branching_variable = find_branching_variable(profits, weights, n, z,
                                                  initial_variable_statuses);
  Problem_Queue *node_queue = create_queue(n);
  //printf("Generating and enqueuing nodes\n");
  generate_and_enqueue_nodes(root_node, n, branching_variable, node_queue);

  Problem_Instance *current_node;

  /* Then, while our node queue is not empty: */
  while(node_queue->size >= 1)
  {
    //printf("Looping\n");
    /* Take node N off queue by some node selection scheme */
    current_node = select_and_dequeue_node(node_queue);

    /* Derive the LB and UB for node N with the FPTAS */
    //printf("Finding bounds\n");
    find_bounds(current_node, profits, weights, x, capacity, n, z,
                &current_node->lower_bound, &current_node->upper_bound,
                problem_file);

    /* If UB < GLB, we safely prune this branch and continue to loop */
    if (upper_bound < global_lower_bound)
      continue;

    /* If LB > GLB, we set GLB = LB */
    if (current_node->lower_bound > global_lower_bound)
      global_lower_bound = current_node->lower_bound;

    /* If for N's parent's upper bound, UB_p, UB > UB_p, UB = UB_p */
    if (current_node->upper_bound > current_node->parent->upper_bound)
      current_node->upper_bound = current_node->parent->upper_bound;

    /* If UB > GLB, we branch on the variable */
    //printf("Branching... %d\n", iterations);
    if (current_node->upper_bound > global_lower_bound)
    {
      branching_variable = find_branching_variable(profits, weights, n, z, 
                                                  current_node->variable_statuses);
      generate_and_enqueue_nodes(current_node, n, branching_variable, 
                                node_queue);
    }
    iterations++;
  }
  *z_out = global_lower_bound;
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

/* Branching algorithm RANDOM NUMBER HERE*/
int find_branching_variable(int *profits, int *weights, int n, int z, 
                            int *variable_statuses)
{
  int r = rand() % n;
  while (variable_statuses[r] == VARIABLE_OFF || variable_statuses[r] == VARIABLE_ON)
    r = rand() % n;
  return r;
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
                          int branching_variable, Problem_Queue *problems_list)
{
  /* This will just use the structure Problem_Queue to enqueue it */
  /* Allocate for each node */
  Problem_Instance *generated_node_variable_on = 
                          (Problem_Instance *) malloc(sizeof(Problem_Instance));
  Problem_Instance *generated_node_variable_off = 
                          (Problem_Instance *) malloc(sizeof(Problem_Instance));


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

  /* Second node */
  generated_node_variable_off->parent = parent;
  generated_node_variable_off->variable_statuses =
                                    (int *) malloc(sizeof(int) * n);
  for(int i = 0; i < n; i++)
    generated_node_variable_off->variable_statuses[i] = 
                                     parent->variable_statuses[i];  
  generated_node_variable_off->variable_statuses[branching_variable] = 
                                                                  VARIABLE_OFF; 

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
                 int *upper_bound_ptr, char *problem_file)
{ 
  /* lower_bound_ptr and upper_bound_ptr are both output parameters */
  /* Solve the FPTAS with current node */
  float eps = 1.0;
  float K;
  int sol_prime[n];
  for (int i = 0; i < n; i++) sol_prime[i] = 0;
  int *profits_prime = (int *) malloc(n * sizeof(*profits_prime));

  FPTAS(eps, profits, weights, x, sol_prime, n, capacity, z,
        BINARY_SOL, SIMPLE_SUM, problem_file, &K, profits_prime, 
        WILLIAMSON_SHMOY, current_node->variable_statuses);

  int fptas_lower_bound = 0;
  int fptas_upper_bound = 0;
  for (int i = 0; i < n; i++)
    if (sol_prime[i] == 1)
    {
      fptas_lower_bound += profits[i];
      fptas_upper_bound += K * profits_prime[i];
    }
  fptas_upper_bound += n*K;

  *lower_bound_ptr = fptas_lower_bound;
  *upper_bound_ptr = fptas_upper_bound;

  free(profits_prime);
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

