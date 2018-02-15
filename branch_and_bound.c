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
#define VARIABLE_ON 2
#define VARIABLE_UNCONSTRAINED 1
#define VARIABLE_OFF 0
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
  int branched_variable;
  int branched_variable_status;
  int depth;
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
                      int max_profit, int n, int *sol_prime, 
                      char *problem_name);

Problem_Instance *select_node(Problem_Instance *nodes[], int *end_of_list);

Problem_Instance *select_node_priority_to_upnodes(Problem_Instance *nodes[],
                                                  int *end_of_list);

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
  for (int i = 0; i < n; i++) sol_prime[i] = 0;
  bounding_method = TRIVIAL_BOUND;
  profit_primes = (int *) malloc(n * sizeof(*profit_primes));  
  DP_method = WILLIAMSON_SHMOY;
  sol_flag = BINARY_NOTATION;
  int max_profit = DP_max_profit(profits, n);

  /* Now, define root_problem structure */
  //int root_vars[n];
  //for(int i = 0; i < n; i++) root_vars[i] = ;
  //int root_read_only_vars[n];
  //for(int i = 0; i < n; i++) root_read_only_vars[i] = 0;
  //*root_node = { profits, weights, capacity, z, x, 
  //                  root_vars, root_read_only_vars, epsilon };

  Problem_Instance *root_node = (Problem_Instance *)malloc(sizeof(Problem_Instance));
  //Problem_Instance *root_node;
  root_node->profits = profits;
  root_node->weights = weights;
  root_node->capacity = capacity;
  root_node->z_opt = z;
  root_node->x_opt = x;
  //root_node->turned_on_variables = root_vars;
  if((root_node->turned_on_variables = (int *) calloc(n, sizeof(int)))==NULL)
  {
    printf("Allocation of root_node->turned_on_variables failed!\n");
    exit(-1);
  }
  for (int i = 0; i < n; i++) 
    (root_node->turned_on_variables)[i] = VARIABLE_UNCONSTRAINED;
  //root_node->read_only_variables = root_read_only_vars; 
  root_node->read_only_variables = (int *) calloc(n, sizeof(int));
  // TODO make sure calloc actually puts these to zero as advertised
  root_node->epsilon = epsilon;
  root_node->branched_variable = -1;
  root_node->branched_variable_status = VARIABLE_ON;
  root_node->depth = 0;

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
    /* Debug */
    iterations++;
    printf("Iteration!\n");

    /* 2. Select node */
    //current_node = select_node(problem_list, &problem_instance_list_length);
    current_node = select_node_priority_to_upnodes(problem_list, &problem_instance_list_length);
    printf("Problem_instance_list_length: %d\n", problem_instance_list_length);
    if (current_node == NULL) printf("Here it is!\n");
    /* Debug */
    //printf("Depth: %d\n", current_node->depth);
    /* 3. Bound */
    epsilon *= 0.9; // TODO This reduction of epsilon is ARBITRARY 

    /* Tentative changes: only solve for on-constrained instances */
    if(current_node->branched_variable_status == VARIABLE_ON)//read_only_variables are ok
    {
      /* Debug */
      //printf("Variable on!\n");
      
      /* Reset sol_prime */
      for(int i = 0; i < n; i++)
        sol_prime[i] = 0;

      /* On first node, we use an eps = n */
      if(first_node)
      {
    printf("First FPTAS!\n");
        FPTAS(((float)n/4.0), profits, weights, x, sol_prime, n, capacity, z,
              sol_flag, bounding_method, problem_file, &K, profit_primes,
              DP_method, current_node->turned_on_variables, 
              current_node->read_only_variables);
        first_node = 0;
    printf("First FPTAS done!\n");
        epsilon = 0.99;
      }
      else 
      { // TODO During the FPTAS, current_node->read_only_variables goes to garbage
    printf("Nonfirst FPTAS!\n");
        FPTAS(epsilon, profits, weights, x, sol_prime, n, capacity, z, sol_flag,
              bounding_method, problem_file, &K, profit_primes, DP_method,
              current_node->turned_on_variables, 
              current_node->read_only_variables);
      }  

      /* Get profit(S') */
      relaxed_solution->profit = 0;
    printf("Getting profit!\n");
      for(int i = 0; i < n; i++)
      {
        if (sol_prime[i] == 1)
          relaxed_solution->profit += profits[i];
        relaxed_solution->sol[i] = sol_prime[i];
      }

      /* Plant any variables which were constrained to be on in */
    printf("Planting variables!\n");
      for(int i = 0; i < n; i++)
      {
        if (current_node->turned_on_variables[i] == 2) 
        //TODO replace 2 with a symbolic constant
        {
          relaxed_solution->profit += profits[i];
          relaxed_solution->sol[i] = sol_prime[i];
        }
      }

    printf("Planted variables!\n");
      if(relaxed_solution->profit <= global_lower_bound){
       printf("%d%s children pruned.\n", current_node->branched_variable, current_node->branched_variable_status ? "-ON" : "-OFF");
       continue;
      }
      global_lower_bound = relaxed_solution->profit;
      /* Tentative change if statement close */
    }//else printf("Variable off!\n");

    //generate_node(current_node, problem_list, &problem_instance_list_length,
    //              1, epsilon, max_profit, n, sol_prime);
   
//    generate_node_v2(current_node, problem_list, &problem_instance_list_length,
//                  1, epsilon, max_profit, n, sol_prime);
    // TODO read_only_variables not okay anymore (21845)
    printf("Generating nodes!\n");
    generate_node_v3(current_node, problem_list, &problem_instance_list_length,
                     1, epsilon, max_profit, n, sol_prime, problem_file);
    printf("Generated nodes!\n");
    /* Debug */
    //if(iterations >= 3) exit(-1);

  }
  *z_out = global_lower_bound;
  printf("Iterations: %d\n", iterations); 
}

void generate_node(Problem_Instance *current_node, Problem_Instance **problems,
                  int *problem_instance_length, int number_of_nodes_to_generate,
                  float epsilon, int max_profit, int n, int *sol_prime)
{
  /* My first method: we're going to branch and turn off the more truncate-able
   * items TODO UPDATE THIS FUNCTION TO SUPPORT THE NEW ALLOCATION TECHNIQUE*/
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
                         malloc(sizeof(Problem_Instance));
  Problem_Instance *generated_node_variable_off = 
                         malloc(sizeof(Problem_Instance));
  
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
   * items TODO UPDATE THIS TO SUPPORT NEW ALLOCATION TECHNIQUE also update 
   * the method for the way turned_on_variables is defined for the 'on' 
   * case */

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

  /* TODO make this more efficient (it can probably be easily done)*/
  // For each i in n
  int temp_variable_statuses[n];
  int a_sol_prime[n];
  int profits_prime[n];
  int best_variables[n];
  int list_of_these_profits[n];
  float K = epsilon * max_profit / n;
  int this_profit;
  int best_found_profit = 0;
  int best_variable = -1;

  /* Debug */
  int iterations = 0;

  /* Tentative list of best variables initialisation*/
  for (int i = 0; i < n; i++)
    best_variables[i] = -1;

  for (int i = 0; i < n; i++)
  {
    if (!current_node->read_only_variables[i])
    {
      for (int j = 0; j < n; j++)
        temp_variable_statuses[j] = current_node->turned_on_variables[i];


      temp_variable_statuses[i] = 2;
      FPTAS(5.0, current_node->profits, current_node->weights, 
            current_node->x_opt, a_sol_prime, n, current_node->capacity, 
            current_node->z_opt, 1, 2, problem_name, &K, profits_prime, 1,
            temp_variable_statuses, current_node->turned_on_variables);
      /* Get profit(S') */
      this_profit = 0;
      for(int j = 0; j < n; j++)
        if (a_sol_prime[j] == 1)
          this_profit += current_node->profits[j];
    
      /* Plant any variables which were constrained to be on in */
      for(int j = 0; j < n; j++)
      //TODO replace 2 with a symbolic constant
        if (temp_variable_statuses[j] == 2) 
          this_profit += current_node->profits[j];
      
      /* Check if this is the highest profit so far */
      if (this_profit > best_found_profit)
      {
        best_variable = i;
        best_found_profit = this_profit;
      }
      
      /* Add it to a list of profits */
      list_of_these_profits[i] = this_profit;

      /* Debug */
      iterations++;
    }
  }
  /* Add all the best variables to a list */
  int best_variables_counter = 0;
  for (int i = 0; i < n; i++)
    if(list_of_these_profits[i] == best_found_profit)
      best_variables[best_variables_counter++] = i;

  /* Debug */
  if(best_variable == -1)
  {
    printf("No best variable found?\n");
    return;
  }

  for(int i = 0; i < best_variables_counter; i++)
  {
    best_variable = best_variables[i];
    printf("Variable %d%s branches on %d\n", current_node->branched_variable,
           current_node->branched_variable_status ? "-ON" : "-OFF",
           best_variable);

    /* We have our variable chosen... */
    Problem_Instance *generated_node_variable_on;
    if((generated_node_variable_on = 
        malloc(sizeof(Problem_Instance)))==NULL)
    {
      printf("Failure to allocate for an 'on' instance.\n");
      continue;
    }
    Problem_Instance *generated_node_variable_off;
    if((generated_node_variable_off = 
                           malloc(sizeof(Problem_Instance)))==NULL)
    {
      printf("Failure to alloacte for an 'off' instance.\n");
      continue;
    }
  
    /* Generate the first node */
    generated_node_variable_on->profits = current_node->profits;
    generated_node_variable_on->weights = current_node->weights;
    generated_node_variable_on->capacity = current_node->capacity;
    generated_node_variable_on->z_opt = current_node->z_opt;
    generated_node_variable_on->x_opt = current_node->x_opt;
    //TODO Dynamically allocate pointers to list for the stuff
    /* Make the turned_on_variable list */
    generated_node_variable_on->read_only_variables = 
      (int *) calloc(n, sizeof(int *));
    for (int j = 0; j < n; j++) 
      generated_node_variable_on->read_only_variables[j] = 
        current_node->read_only_variables[j];
    generated_node_variable_on->turned_on_variables = 
      (int *) calloc(n, sizeof(int *));
    for (int j = 0; j < n; j++) 
      generated_node_variable_on->turned_on_variables[j] = 
        current_node->turned_on_variables[j];
    generated_node_variable_on->epsilon = current_node->epsilon;
    generated_node_variable_on->read_only_variables[best_variable] = 1;
    generated_node_variable_on->turned_on_variables[best_variable] =
      VARIABLE_ON;
    generated_node_variable_on->branched_variable = best_variable;
    generated_node_variable_on->branched_variable_status = VARIABLE_ON;
    generated_node_variable_on->depth = current_node->depth + 1;

    /* Generate the second node */
    generated_node_variable_off->profits = current_node->profits;
    generated_node_variable_off->weights = current_node->weights;
    generated_node_variable_off->capacity = current_node->capacity;
    generated_node_variable_off->z_opt = current_node->z_opt;
    generated_node_variable_off->x_opt = current_node->x_opt;
    //TODO Make sure allocation actually works
    generated_node_variable_off->read_only_variables = 
      (int *) calloc(n, sizeof(int *));
    for (int j = 0; j < n; j++) 
      generated_node_variable_off->read_only_variables[j] = 
        current_node->read_only_variables[j];
    generated_node_variable_off->turned_on_variables = 
      (int *) calloc(n, sizeof(int *));
    for (int j = 0; j < n; j++) 
      generated_node_variable_off->turned_on_variables[j] = 
        current_node->turned_on_variables[j]; 
    generated_node_variable_off->epsilon = current_node->epsilon;
    generated_node_variable_off->turned_on_variables[best_variable] = 
      VARIABLE_OFF;
    generated_node_variable_off->read_only_variables[best_variable] = 1;
    generated_node_variable_off->branched_variable = best_variable;
    generated_node_variable_off->branched_variable_status = VARIABLE_OFF;
    generated_node_variable_off->depth = current_node->depth + 1;
  
    /* Put them on the top */
    problems[(*problem_instance_length)++] = generated_node_variable_off;
    problems[(*problem_instance_length)++] = generated_node_variable_on;
    /* Okay this should be all g */ 
  }
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

Problem_Instance *select_node_priority_to_upnodes(Problem_Instance *nodes[],
                                                  int *end_of_list)
{
  /* My first method: I wanna have a bit of a stack mentality to this
   * So, pick the one at the top of the stack. (Assuming I maintain the stack 
   * so that the next generated node with a variable turned off is at the head
   *  of the stack). This is sort of depth-first ish */
  Problem_Instance *output_problem_instance;
  for (int i = *end_of_list; i > 0; i--)
  {
    if(nodes[i]->branched_variable_status == VARIABLE_ON)
    {
      *end_of_list--;
      output_problem_instance = nodes[i];
      for (int j = i; j < *end_of_list; i++)
        nodes[j] = nodes[j+1];
      return output_problem_instance; 
    }
  }
  /* Otherwise just pop the top */
  nodes[(*end_of_list)--] = NULL;
  return output_problem_instance;
}
