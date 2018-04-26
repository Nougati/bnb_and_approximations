/* Preprocessor definitions */
#define SIMPLE_SUM 2
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

/*WIP*/
typedef struct linked_list_item
{
  struct linked_list_item *in_front;
  struct linked_list_item *behind;
  struct p_instance *problem;
} LL_Node_Queue_Item;

typedef struct linked_list_p_queue
{
  struct linked_list_item *head;
  struct linked_list_item *tail;
  int size;
} LL_Problem_Queue;

/* Branch and Bound Declarations */
Problem_Instance *define_root_node(int n);

void branch_and_bound_bin_knapsack(int profits[], int weights[], int x[],
                                   int capacity, int z, int *z_out, 
                                   int sol_out[], int n, char *problem_file, 
                                   int branching_strategy, time_t seed,
                                   int DP_method, int logging_rule, 
                                   FILE *logging_stream, double epsilon, 
                                   int *number_of_nodes, 
                                   int memory_allocation_limit, clock_t *start_time, 
                                   int timeout);

int find_heuristic_initial_GLB(int profits[], int weights[], int x[], int z, 
                               int n, int capacity, char *problem_file,
                               int DP_method);

int find_branching_variable(int n, int z, int *read_only_variables, 
                            int branching_strategy, int *profits);

void generate_and_enqueue_nodes(Problem_Instance *parent, int n,
                          int branching_variable, 
                          LL_Problem_Queue *problems_list, int *count, 
                          FILE *logging_stream, int logging_rule);

Problem_Instance *select_and_dequeue_node(LL_Problem_Queue *node_queue);

void find_bounds(Problem_Instance *current_node, int profits[], int weights[],
                 int x[], int capacity, int n, int z, int *lower_bound_ptr, 
                 int *upper_bound_ptr, char *problem_file, int DP_method,
                 int logging_rule, FILE *logging_stream, double eps);

void post_order_tree_clean(Problem_Instance *root_node);

int is_boundary_exceeded(int memory_limit, clock_t start_time, int timeout);

/* Queue Declarations */
Problem_Queue *create_queue(int capacity);

int is_full(Problem_Queue *queue);

int is_empty(Problem_Queue *queue);

void enqueue(Problem_Queue *queue, Problem_Instance *node);

Problem_Instance *dequeue(Problem_Queue *queue);

Problem_Instance *front(Problem_Queue *queue);

Problem_Instance *rear(Problem_Queue *queue);

/* LL Queue Declarations */
LL_Problem_Queue *LL_create_queue(void);
void LL_enqueue(LL_Problem_Queue *queue, Problem_Instance *problem, FILE *logging_stream, int logging_rule);
Problem_Instance *LL_dequeue(LL_Problem_Queue *queue);

