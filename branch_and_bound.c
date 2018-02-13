/**branch_and_bound_KP.c*******************************************************
 * Goodluck, yo.                                                              *
 * Thought: maintain a static variable to make a low-maintenance DS for       *
 *   a problem instance list                                                  *
 * Using Kprofit'(S') as a replacement to the LP relaxation may have been     *
 *  something that slipped straight past me.                                  *
 * TODO                                                                       *
 *   I don't think we actually need profits and weights for each              *
 *    Problem_Instance                                                        *
 *                                                                            *
 ******************************************************************************/

#define TESTING
#include<stdio.h>
#include "fptas.c"

typedef struct p_solution{
  int profit;
  int sol[];
} Partial_Solution;

typedef struct p_instance {
  int *profits;
  int *weights;
  int capacity;
  int z_opt;
  int *x_opt;
  int *turned_on_variables;
  int *read_only_variables; 
  float epsilon;
} Problem_Instance;

void branch_and_bound_KP(int profits[], int weights[], int capacity, int *z_out,
                         int sol_out[], int n, char *problem_file);

void generate_node(Problem_Instance* current_node, Problem_Instance **problems,
                  int *problem_instance_length, int number_of_nodes_to_generate,
                  float epsilon, int max_profit, int n, int *sol_prime);

void generate_node_v2(Problem_Instance *current_node, 
                      Problem_Instance **problems, int *problem_instance_length, 
                      int number_of_nodes_to_generate, float epsilon,
                      int max_profit, int n, int *sol_prime);

void generate_node_v3(Problem_Instance *current_node, 
                      Problem_Instance **problems, int *problem_instance_length, 
                      int number_of_nodes_to_generate, float epsilon,
                      int max_profit, int n, int *sol_prime, char *problem_name);

Problem_Instance *select_node(Problem_Instance *nodes[], int *end_of_list);

int main(int argc, char *argv[])
{
  int n, capacity, z, opt_profit;
  int *profits, *weights, *x;
  char problem_file[100];
  
  /* Get problem file from argv[1] */
  if(argc != 2)
  { 
    printf("Format:  %s <filename>\n", argv[0]);
    exit(-1);
  }
  strcpy(problem_file, argv[1]);

  /* Define problem */
  pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, problem_file, 1);
  int sol_out[n];

  /* Start timer */
  clock_t t;
  t = clock();

  /* Then run branch and bound */
  branch_and_bound_KP(profits, weights, capacity, &opt_profit, sol_out, n, 
                      problem_file);

  /* End timer */
  t = clock() - t;
  double time_taken = ((double)t)/CLOCKS_PER_SEC;
  
  printf("%d/%d: %s\t Runtime: %f\n", opt_profit, z, opt_profit == z ? "Correc"
         "t Solution!" : "Incorrect Solution!", time_taken);
  return 0;
}

void branch_and_bound_KP(int profits[], int weights[], int capacity, int *z_out,
                         int sol_out[], int n, char *problem_file)
{
  /**branch_and_bound_KP
   * Last time I wrote this the computer froze
   * ... Bad omen.*/
  //TODO change turned_on_nodes to node_status
  /* 0. Initialise */
  /* Pick a root primal bound which is as high as possible. */
  Partial_Solution *root_problem_sol;

  /* Read in an instance and define all FPTAS stuff */
  float epsilon;
  float K;
  char output_file[100];
  int *x, *profit_primes;
  int z, sol_flag, bounding_method, DP_method;
  int all_instances = 0;
  int output_flag = 0;
  FILE *fp_out;

  /* Read in instance. */
  epsilon = n;
  int sol_prime[n];
  Problem_Instance *root_node = 
                         malloc(sizeof(root_node)+n*5*sizeof(int));
  for (int i = 0; i < n; i++) sol_prime[i] = 0;
  bounding_method = TRIVIAL_BOUND;
  profit_primes = (int *) malloc(n * sizeof(*profit_primes));  
  DP_method = WILLIAMSON_SHMOY;
  sol_flag = BINARY_NOTATION;
  int max_profit = DP_max_profit(profits, n);

  /* Now, define root_problem structure */
  int root_vars[n];
  for(int i = 0; i < n; i++) root_vars[i] = 1;
  int root_read_only_vars[n];
  for(int i = 0; i < n; i++) root_read_only_vars[i] = 0;
  //*root_node = { profits, weights, capacity, z, x, 
  //                  root_vars, root_read_only_vars, epsilon };

  root_node->profits = profits;
  root_node->weights = weights;
  root_node->capacity = capacity;
  root_node->z_opt = z;
  root_node->x_opt = x;
  root_node->turned_on_variables = root_vars;
  root_node->read_only_variables = root_read_only_vars; 
  root_node->epsilon = epsilon;

  /* Put this root node in the list */
  int number_of_nodes_to_generate = 2;
  //int global_lower_bound = root_node->profits;
  int global_lower_bound = -1;
  Problem_Instance **problem_list = malloc(sizeof(root_node)*n);
 // TODO make a better length for this
  int problem_instance_list_length = 0;
  problem_list[problem_instance_list_length++] = root_node;
 
  /* Prep for loop*/
  Partial_Solution *relaxed_solution = malloc(sizeof(int) + n*sizeof(int));
  Problem_Instance *current_node;

  /* This is just a flag so that the first iteration is treated differently */
  int first_node = 1;
  int iterations = 0;
  /* 1. Terminate? */
  while (problem_instance_list_length >= 1)
  {
    /*Debug variable*/
    iterations++;

    /* 2. Select node */
    current_node = select_node(problem_list, &problem_instance_list_length);

    /* 3. Bound */
    epsilon *= 0.9; // TODO This reduction of epsilon is ARBITRARY 

    /* Reset sol_prime */
    for(int i = 0; i < n; i++)
      sol_prime[i] = 0;

    /* On first node, we use an eps = n */
    if(first_node)
    {
      FPTAS(((float)n/4.0), profits, weights, x, sol_prime, n, capacity, z,
            sol_flag, bounding_method, problem_file, &K, profit_primes,
            DP_method, current_node->turned_on_variables);
      first_node = 0;
      epsilon = 0.99;
    }
    else
    {
      FPTAS(epsilon, profits, weights, x, sol_prime, n, capacity, z, sol_flag,
            bounding_method, problem_file, &K, profit_primes, DP_method,
            current_node->turned_on_variables);
    }  

    /* Get profit(S') */
    relaxed_solution->profit = 0;
    for(int i = 0; i < n; i++)
    {
      if (sol_prime[i] == 1)
        relaxed_solution->profit += profits[i];
      relaxed_solution->sol[i] = sol_prime[i];
    }

    /* Plant any variables which were constrained to be on in */
    for(int i = 0; i < n; i++)
    {
      if (current_node->turned_on_variables[i] == 2) 
      //TODO replace 2 with a symbolic constant
      {
        relaxed_solution->profit += profits[i];
        relaxed_solution->sol[i] = sol_prime[i];
      }
    }

    if(relaxed_solution->profit <= global_lower_bound) continue;

    global_lower_bound = relaxed_solution->profit;

    generate_node(current_node, problem_list, &problem_instance_list_length,
                  1, epsilon, max_profit, n, sol_prime);
   
    generate_node_v2(current_node, problem_list, &problem_instance_list_length,
                  1, epsilon, max_profit, n, sol_prime);
    // TODO FOR WEDNESDAY NELSON: Put generate_node_v3 in!
  }
  *z_out = global_lower_bound;
  printf("Iterations: %d\n", iterations); 
}

void generate_node(Problem_Instance *current_node, Problem_Instance **problems,
                  int *problem_instance_length, int number_of_nodes_to_generate,
                  float epsilon, int max_profit, int n, int *sol_prime)
{
  /* My first method: we're going to branch and turn off the more truncate-able
   * items */
  /* Comb through the current_node instance */
  double max_truncation = 0;
  double this_truncation;
  double K = epsilon * max_profit / n;
  int best_variable;
  /* workshopping begins */
  //int this_read_only_variables[n];
  //for (int i = 0; i < n; i++) this_read_only_variables[i] = 0;

  //for(int i = 0; i < number_of_nodes_to_generate; i++)
  //{
  /* workshopping ends */
  for(int i = 0; i < n; i++)
  { //TODO try only looking at variables that are in the current partial sol
  /* For every variable which is on, maintain which one will make the equation 
   * in my notebook on the page labelled "BOOKMARK" maximised */
    //if(!current_node->read_only_variables[i])// First idea
    if((!current_node->read_only_variables[i]) && !(sol_prime[i])) //Second idea
    {
      this_truncation = 
        current_node->profits[i] - K*floor(current_node->profits[i] / K);
      if (this_truncation > max_truncation)
      {
        max_truncation = this_truncation;
        best_variable = i;
        //this_read_only_variables[i] = 1;
      }
    }
  }

  /* Debug */
  printf("Branching on: %d\n", best_variable);

  /* Then for the node that has the most, create a problem_instance where it
   * is on and another where it is off */
  Problem_Instance *generated_node_variable_on = 
                         malloc(sizeof(current_node)+n*5*(sizeof(int)));
  Problem_Instance *generated_node_variable_off = 
                         malloc(sizeof(current_node)+n*5*(sizeof(int)));
  
  generated_node_variable_on->profits = current_node->profits;
  generated_node_variable_on->weights = current_node->weights;
  generated_node_variable_on->capacity = current_node->capacity;
  generated_node_variable_on->z_opt = current_node->z_opt;
  generated_node_variable_on->x_opt = current_node->x_opt;
  generated_node_variable_on->turned_on_variables =
                                             current_node->turned_on_variables;
  generated_node_variable_on->read_only_variables = 
                                             current_node->read_only_variables; 
  generated_node_variable_on->epsilon = current_node->epsilon;

  generated_node_variable_on->turned_on_variables[best_variable] = 2;
  generated_node_variable_on->read_only_variables[best_variable] = 1;

  generated_node_variable_off->profits = current_node->profits;
  generated_node_variable_off->weights = current_node->weights;
  generated_node_variable_off->capacity = current_node->capacity;
  generated_node_variable_off->z_opt = current_node->z_opt;
  generated_node_variable_off->x_opt = current_node->x_opt;
  generated_node_variable_off->turned_on_variables =
                                             current_node->turned_on_variables;
  generated_node_variable_off->read_only_variables = 
                                             current_node->read_only_variables; 
  generated_node_variable_off->epsilon = current_node->epsilon;
  generated_node_variable_off->turned_on_variables[best_variable] = 0;
  generated_node_variable_off->read_only_variables[best_variable] = 1;
  problems[(*problem_instance_length)++] = generated_node_variable_on;
  problems[(*problem_instance_length)++] = generated_node_variable_off;
  /* Okay this should be all g */ 
}

void generate_node_v2(Problem_Instance *current_node, 
                      Problem_Instance **problems, int *problem_instance_length, 
                      int number_of_nodes_to_generate, float epsilon,
                      int max_profit, int n, int *sol_prime)
{
  /* My second method: we're going to branch and turn on the least truncate-able
   * items */

  /* Comb through the current_node instance */
  double this_truncation;
  double K = epsilon * max_profit / n;
  double min_truncation = K*2;
  int best_variable;

  /* For every variable which is on, maintain which one will make the equation 
   * in my notebook on the page labelled "BOOKMARK" maximised */
  for(int i = 0; i < n; i++)
  { 
    //if(!current_node->read_only_variables[i])// First idea
    if((!current_node->read_only_variables[i]) && sol_prime[i]) //Second idea
    {
      this_truncation = 
        current_node->profits[i] - K*floor(current_node->profits[i] / K);
      if (this_truncation < min_truncation)
      {
        min_truncation = this_truncation;
        best_variable = i;
      }
    }
  }


  /* Debug */
  printf("Branching on: %d\n", best_variable);

  /* Then for the node that has the most, create a problem_instance where it
   * is on and another where it is off */
  Problem_Instance *generated_node_variable_on = 
                         malloc(sizeof(current_node)+n*5*(sizeof(int)));
  Problem_Instance *generated_node_variable_off = 
                         malloc(sizeof(current_node)+n*5*(sizeof(int)));
  
  /* Generate the first node */
  generated_node_variable_on->profits = current_node->profits;
  generated_node_variable_on->weights = current_node->weights;
  generated_node_variable_on->capacity = current_node->capacity;
  generated_node_variable_on->z_opt = current_node->z_opt;
  generated_node_variable_on->x_opt = current_node->x_opt;
  generated_node_variable_on->turned_on_variables =
                                             current_node->turned_on_variables;
  generated_node_variable_on->read_only_variables = 
                                             current_node->read_only_variables; 
  generated_node_variable_on->epsilon = current_node->epsilon;
  generated_node_variable_on->read_only_variables[best_variable] = 1;

  /* Generate the second node */
  generated_node_variable_off->profits = current_node->profits;
  generated_node_variable_off->weights = current_node->weights;
  generated_node_variable_off->capacity = current_node->capacity;
  generated_node_variable_off->z_opt = current_node->z_opt;
  generated_node_variable_off->x_opt = current_node->x_opt;
  generated_node_variable_off->turned_on_variables =
                                             current_node->turned_on_variables;
  generated_node_variable_off->read_only_variables = 
                                             current_node->read_only_variables; 
  generated_node_variable_off->epsilon = current_node->epsilon;
  generated_node_variable_off->turned_on_variables[best_variable] = 0;
  generated_node_variable_off->read_only_variables[best_variable] = 1;

  /* Put them on the top */
  problems[(*problem_instance_length)++] = generated_node_variable_off;
  problems[(*problem_instance_length)++] = generated_node_variable_on;
  /* Okay this should be all g */ 
}

void generate_node_v3(Problem_Instance *current_node, 
                      Problem_Instance **problems, int *problem_instance_length, 
                      int number_of_nodes_to_generate, float epsilon,
                      int max_profit, int n, int *sol_prime, char *problem_name)
{
  /* My third method: we're going to branch on the variables with the highest 
   * FPTAS with some high epsilon */

  /* TODO make this more efficient (it can easily be done)*/
  // For each i in n
  int temp_read_only_variables[n];
  int a_sol_prime[n];
  int profits_prime[n];
  float K = epsilon * max_profit / n;
  int this_profit, best_variable;

  for (int i = 0; i < n; i++)
  {
    
  //   Set read only variables to all 0
    for (int j = 0; j < n; i++)
      temp_read_only_variables[i] = 0;
  //   Turn on just i
    temp_read_only_variables[i] = 2;
  //   solve with just i forced on
    FPTAS(15.0, current_node->profits, current_node->weights, 
          current_node->x_opt, a_sol_prime, n, current_node->capacity, 
          current_node->z_opt, 1, 2, problem_name, &K, profits_prime, 1,
          temp_read_only_variables);
        /* Get profit(S') */
    this_profit = 0;
    for(int i = 0; i < n; i++)
    {
      if (a_sol_prime[i] == 1)
        this_profit += current_node->profits[i];
    }

    /* Plant any variables which were constrained to be on in */
    for(int i = 0; i < n; i++)
    {
      if (current_node->turned_on_variables[i] == 2) 
      //TODO replace 2 with a symbolic constant
      {
        this_profit += current_node->profits[i];
      }
    }
    if (this_profit > max_profit)
      best_variable = i;
  }
  /* Debug */
  printf("Branching on: %d\n", best_variable);

  /* We have our variable chosen... */
  Problem_Instance *generated_node_variable_on = 
                         malloc(sizeof(current_node)+n*5*(sizeof(int)));
  Problem_Instance *generated_node_variable_off = 
                         malloc(sizeof(current_node)+n*5*(sizeof(int)));
  
  /* Generate the first node */
  generated_node_variable_on->profits = current_node->profits;
  generated_node_variable_on->weights = current_node->weights;
  generated_node_variable_on->capacity = current_node->capacity;
  generated_node_variable_on->z_opt = current_node->z_opt;
  generated_node_variable_on->x_opt = current_node->x_opt;
  generated_node_variable_on->turned_on_variables =
                                             current_node->turned_on_variables;
  generated_node_variable_on->read_only_variables = 
                                             current_node->read_only_variables; 
  generated_node_variable_on->epsilon = current_node->epsilon;
  generated_node_variable_on->read_only_variables[best_variable] = 1;

  /* Generate the second node */
  generated_node_variable_off->profits = current_node->profits;
  generated_node_variable_off->weights = current_node->weights;
  generated_node_variable_off->capacity = current_node->capacity;
  generated_node_variable_off->z_opt = current_node->z_opt;
  generated_node_variable_off->x_opt = current_node->x_opt;
  generated_node_variable_off->turned_on_variables =
                                             current_node->turned_on_variables;
  generated_node_variable_off->read_only_variables = 
                                             current_node->read_only_variables; 
  generated_node_variable_off->epsilon = current_node->epsilon;
  generated_node_variable_off->turned_on_variables[best_variable] = 0;
  generated_node_variable_off->read_only_variables[best_variable] = 1;

  /* Put them on the top */
  problems[(*problem_instance_length)++] = generated_node_variable_off;
  problems[(*problem_instance_length)++] = generated_node_variable_on;
  /* Okay this should be all g */ 
}

Problem_Instance *select_node(Problem_Instance *nodes[], int *end_of_list)
{
  /* My first method: I wanna have a bit of a stack mentality to this
   * So, pick the one at the top of the stack. (Assuming I maintain the stack 
   * so that the next generated node with a variable turned off is at the head
   *  of the stack). This is sort of depth-first ish */
  Problem_Instance *output_problem_instance = nodes[*end_of_list - 1];
  nodes[(*end_of_list)--] = NULL;
  return output_problem_instance;
}

