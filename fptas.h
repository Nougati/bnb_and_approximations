#define VASIRANI 0
#define WILLIAMSON_SHMOY 1
#define SMART_DP 2
#define INDEX_NOTATION 0
#define BINARY_NOTATION 1
#define HYPER_TRIVIAL_BOUND 1
#define TRIVIAL_BOUND 2
#define TRUE 1
#define VARIABLE_ON 2
#define VARIABLE_UNCONSTRAINED 1
#define VARIABLE_OFF 0

/* Structure definitions */
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
  int solution_array[];
};

/* FTPAS Function Declarations */
int williamson_shmoys_DP(struct problem_item items[], int capacity, int n, 
                         int *solution_array);
void push(struct solution_pair** head_ref, int new_weight, int new_profit, 
          int n);
void remove_dominated_pairs(struct solution_pair** head_ref);
void merge_sort(struct solution_pair** head_ref);
struct solution_pair* sorted_merge(struct solution_pair* a, 
                                   struct solution_pair* b);
void front_back_split(struct solution_pair* source, 
                      struct solution_pair** front_ref, 
                      struct solution_pair** back_ref);
void print_list(struct solution_pair* node);

void DP(const int problem_profits[],
        const int problem_weights[],
        const int x[],
        int sol[],
        const int n,
        const int capacity,
        const int z,
        const int sol_flag,
        const int bounding_method,
        const char *problem_file);

int DP_p_upper_bound(const int problem_profits[],
                     const int n,
                     const int P,
                     const int bounding_method);

void FPTAS(double eps, 
           int *profits,
           int *weights,
           int *x,
           int *sol_prime,
           const int n,
           int capacity,
           const int z,
           const int sol_flag,
           const int bounding_method,
           const char *problem_file,
           double *K,
           int *profits_prime,
           const int DP_method,
           const int *variable_statuses);

int DP_max_profit(const int problem_profits[],
                  const int n);

float define_K(double eps,
               int P,
               int n);

void make_profit_primes(int *profits,
                        int *profits_prime,
                        double K,
                        int n,
                        const int *active_nodes);

void make_symbolic_profit_primes(int *profits,
                        int *profits_prime,
                        double K,
                        int n,
                        const int *active_nodes);

void DP_fill_in_base_cases(const int width,
                           const int n,
                           int ** DP_table, //int DP_table[][width],
                           const int problem_profits[],
                           const int problem_weights[]);

void DP_fill_in_general_cases(const int width,
                              const int n,
                              int ** DP_table, //int DP_table[][width],
                              const int problem_profits[],
                              const int problem_weights[]);

int derive_pinf(const int problem_weights[],
                const int n);

int DP_find_best_solution(const int width,
                          const int n,
                          int ** DP_table, //const int DP_table[][width],
                          const int capacity,
                          const int my_pinf);

int DP_derive_solution_set(int n,
                           const int width,
                           int **, //const int DP_table[][width],
                           const int problem_profits[],
                           int solution[],
                           int p,
                           const int sol_flag);

int p_upper_bound_aux(const int problem_profits[],
                      const int n);

