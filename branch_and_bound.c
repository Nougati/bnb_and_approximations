/**branch_and_bound_KP.c*******************************************************
 * Goodluck, yo.                                                              *
 * Thought: maintain a static variable to make a low-maintenance DS for       *
 *   a problem instance list                                                  *
 * Using Kprofit'(S') as a replacement to the LP relaxation may have been     *
 *  something that slipped straight past me.                                  *
 *                                                                            *
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
                  float epsilon, int max_profit, int n);

Problem_Instance *select_node(Problem_Instance *nodes[], int *end_of_list);
int main(int argc, char *argv[])
{
  int n, capacity, z, opt_profit;
  int *profits, *weights, *x;
  char problem_file[100];
  strcpy(problem_file, "knapPI_1_50_1000.csv");

  /* Define problem */
  pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, problem_file, 1);
  int sol_out[n];
  /* Debug notes: It seems to read in the problem correctly */

  /* Then run branch and bound */
  branch_and_bound_KP(profits, weights, capacity, &opt_profit, sol_out, n, 
                      problem_file);
  return 0;
}

void branch_and_bound_KP(int profits[], int weights[], int capacity, int *z_out,
                         int sol_out[], int n, char *problem_file)
{
  /**branch_and_bound_KP
   * Last time I wrote this the computer froze
   * ... Bad omen.*/

  /* 0. Initialise */
  /* Pick a root primal bound which is as high as possible. */
  /*TODO The current bug is the current_node_list_length isn't decreasing*/
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
  /* TODO Replace this with command-line args */

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

  /* 1. Terminate? */
  while (problem_instance_list_length >= 1)
  {
    /* 2. Select node */
    current_node = select_node(problem_list, &problem_instance_list_length);

    /* 3. Bound */
    epsilon *= 0.9; // TODO This reduction of epsilon is ARBITRARY 

    /* Reset sol_prime */
    for(int i = 0; i < n; i++)
      sol_prime[i] = 0;

    /* On first node, we use an eps = n */
    /*if(first_node)
    {
      FPTAS(((float)n/4.0), profits, weights, x, sol_prime, n, capacity, z,
            sol_flag, bounding_method, problem_file, &K, profit_primes,
            DP_method, current_node->turned_on_variables);
      first_node = 0;
      epsilon = 0.99;
    }/*
    else
    {*/
      FPTAS(epsilon, profits, weights, x, sol_prime, n, capacity, z, sol_flag,
            bounding_method, problem_file, &K, profit_primes, DP_method,
            current_node->turned_on_variables);
    /*}*/  

    /* Get profit(S') */
    relaxed_solution->profit = 0;
    for(int i = 0; i < n; i++)
    {
      if (sol_prime[i] == 1)
        relaxed_solution->profit += profits[i];
      relaxed_solution->sol[i] = sol_prime[i];
    }

    /* Make sure the solutions is relaxed-feasible */
    /* I'm commenting all this out because I don't think I need feasibility
     * But I've been wrong before
    if(!is_feasible(relaxed_solution))
      continue; // TODO, elucidate about the requirements of this
    else
    {
      * The LP relaxation has a solution *
      * I'm not sure if we need this*
    }*/

    /* 4. Prune */
    /* If this dual bound is lower than the current global_lower_bound */
    /* If this happens, then that's actually good; it means we've likely found a key player in the solution...? ANyway it'll back out and turn him on.  */
    if(relaxed_solution->profit <= global_lower_bound) continue;
    /* Dual is better, check that it's MILP feasible 
    if(is_MILP_feasible(relaxed_solution))
    {
      global_lower_bound = relaxed_solution->z;
      current_opt_solution_ptr = current_node_sol->sol;
      continue;
    }
    */

    global_lower_bound = relaxed_solution->profit;
    /* 5. Branch*/
    /* We have an LP feasible MILP infeasible solution which is bigger than 
     * global_lower_bound. So, we branch on it. */
    //number_of_nodes_to_generate = decide_how_many_to_branch_on();
    generate_node(current_node, problem_list, &problem_instance_list_length,
                  2, epsilon, max_profit, n);
  }
  printf("Global lower bound: %d\n", global_lower_bound);
}

void generate_node(Problem_Instance* current_node, Problem_Instance **problems,
                  int *problem_instance_length, int number_of_nodes_to_generate,
                  float epsilon, int max_profit, int n)
{
  /* My first method: we're going to branch and turn off the more truncate-able
   * items */
  /* Comb through the current_node instance */
  double max_truncation = 0;
  double this_truncation;
  double K = epsilon * max_profit / n;
  int best_variable;
  for(int i = 0; i < n; i++)
  {
  /* For every variable which is on, maintain which one will make the equation 
   * in my notebook on the page labelled "BOOKMARK" maximised */
    if(!current_node->read_only_variables[i])
    {
      this_truncation = 
        current_node->profits[i] - K*floor(current_node->profits[i] / K);
      if (this_truncation > max_truncation)
      {
        max_truncation = this_truncation;
        best_variable = i;
      }
    }
  }
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
  problems[(*problem_instance_length)++] = generated_node_variable_on;// TODO invalid write of size 8 here
  problems[(*problem_instance_length)++] = generated_node_variable_off;// TODO invalid write of size 8 here
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

