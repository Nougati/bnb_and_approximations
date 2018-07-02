/*****************************************************************************
 *  branch_and_bound_benchmark.c                                             *
 *   Implements a series of benchmarks on instances of KP for my B&B algo    *
 *   Input parameters will decide how this algorithm will function           *
 *   Input parameters to me made:                                            *
 *  argv[0] : filename                                                       *
 *  argv[1] : memory limit                                                   *
 *  argv[2] : timeout                                                        *
 *  argv[3] : file out                                                       *
 *  argv[4] : DP types                                                       *
 *  argv[5] : branching strategy                                             *
 *  argv[6] : instance set                                                   *
 *  argv[7] : n set                                                          *
 *  argv[8] : coefficient set                                                *
 *  argv[9] : problem subset                                                 *
 *  argv[10] : hard instance set                                             *
 *  argv[11] : hard n set                                                    *
 *                                                                           *
 *  TODO                                                                     *
 *    The sanitiser is picking up a memory leak in this!                     *
 *                                                                           *
 *****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <string.h>
#include "branch_and_bound_benchmark.h"
#include "branch_and_bound.h"
#include "fptas.h"
#include "bench_extern.h"
#include "pisinger_reader.h"

/* If memory has been exceeded, bytes_allocated will be -1 (so we write "memory
     exceeeded to log" */
/* If time has been exceeded, start_time will be -1 */


#ifndef MAIN
#define MAIN
int main(int argc, char *argv[])
{
  /* branch_and_bound_benchmark.c main()
   * Argv should be of the form
   *  [file, benchmark_set, memory_limit, timeout, file_out]
   * where
   *  benchmark_set can be "tiny_n", "small_n", "midlow_n", "medium_n", 
   *                        "midhigh_n", "big_n", "huge_n", "massive_n", "all"
   *                        Which all correspond to different n values.
   *
   *  memory_limit is string version of the max amount bytes
   *  timeout is a string of the number of seconds allowed
   * and
   *  if memory_limit or timeout takes the value -1, then we do not worry.
   * */

  /* First verify the given arguments */
  if(argc == 2)
  {
    if (strcmp("help", argv[1]) == 0)
    {
      printf("To run this benchmark, there are two ways:\n\t1. Input \"%s -w\" t"
             "o run the instance set customisation wizard.\n\t2. Input \"%s <mem"
             "ory limit> <timeout> <file out> <DP types> <branching strategy set"
             "> <instance set> <n set> <coefficient set> <problem subset> <hard "
             "instance set> <hard n set> <dualbounds>\n", argv[0], argv[0]);
      printf("By using the wizard, you can choose all the parameters from questi"
             "on prompts. Following the wizard will give you an input if you wan"
             "t to run that specific configuration again.\n");
      printf("The format for each is:\n"
               "\t branching strats: a string of three bits\n"
               "\t\t Where each respective bit is linear enum, random, then trun"
               "cation branching\n"
             "DP type is first flag VV, second flag WS.\n"
             "Instances, n category, and coefficients have each index in the str"
             "ing as flags for the respective type in ascending order. (1st is 5"
             "0 for n, 2nd is 100, etc).\n"
             "This differs from problen instance where you simply specify, for s"
             "ome input n, the first n problems in a problem file. For example, "
             "for input 1, only the first problem of each file will be run.\n");
      printf("Data formats of inputs:\n");
      printf("Memory limit (bytes):\tint\ntimeout (seconds):\tint\nfile out:\t\tchar "
             "array (any length)\nDP Types:\t\t2 bits\nbranching strategies:\t3 bits"
             "\ninstance set:\t\t7 bits\nn set:\t\t\t8 bits\ncoefficient set:\t5 bits\npr"
             "oblem subset:\t\tinteger in range [1,100]\n<hard instance set:\t6 bit"
             "s\nhard n set:\t\t9 bits\n<dualbounds>:\t\t 4 bits");
      exit(-1);
    }
    else if(strcmp("-w", argv[1]) == 0)
    {
      printf("Wizard!\n");

      printf("Please enter the limit on memory allocation (bytes):\n");
      long long int memory_allocation_limit;
      scanf("%lld", &memory_allocation_limit);

      printf("Please enter the limit on run-time (seconds):\n");
      int timeout;
      scanf("%d", &timeout); 
  
      char input_str[100];

      /* Prompt user for DP types */
      char DP_types[] = "00";  

      printf("Enter the DP types you want to toggle (of vv or ws), and input 0 when done.\n");
      do{
        scanf("%s", input_str);
        if(strcmp(input_str,"vv")==0) DP_types[0] = 
                                            ( DP_types[0] == '0' ? '1' : '0' );
        else if(strcmp(input_str,"ws")==0) DP_types[1] = 
                                            ( DP_types[1] == '0' ? '1' : '0' );
        printf("DP_types: %s\n", DP_types);
      }while(strncmp(input_str, "0", 1) != 0);

      /* Prompt user for branching strats */
      char branch_strats[] = "000";
      printf("Enter the branch strategies you want to toggle (of le, rb, tb)\n");
      do{
        scanf("%s", input_str);
        if(strcmp(input_str,"le")==0) branch_strats[0] = 
                                        ( branch_strats[0] == '0' ? '1' : '0' );
        else if(strcmp(input_str,"rb")==0) branch_strats[1] = 
                                        ( branch_strats[1] == '0' ? '1' : '0' );
        else if(strcmp(input_str,"tb")==0) branch_strats[2] = 
                                        ( branch_strats[2] == '0' ? '1' : '0' );
        printf("branch_strats: %s\n", branch_strats);
      }while(strncmp(input_str, "0", 1) != 0);
      
      /* Prompt user for Instance set */
      char instance_set[] = "0000000";
      printf("Enter the instance types you want to toggle (1-6 and 9)\n");
      do{
        scanf("%s", input_str);
        if(strcmp(input_str,"1")==0) instance_set[0] =
                                        ( instance_set[0] == '0' ? '1' : '0' );
        else if(strcmp(input_str,"2")==0) instance_set[1] = 
                                        ( instance_set[1] == '0' ? '1' : '0' );
        else if(strcmp(input_str,"3")==0) instance_set[2] = 
                                        ( instance_set[2] == '0' ? '1' : '0' );
        else if(strcmp(input_str,"4")==0) instance_set[3] = 
                                        ( instance_set[3] == '0' ? '1' : '0' );
        else if(strcmp(input_str,"5")==0) instance_set[4] = 
                                        ( instance_set[4] == '0' ? '1' : '0' );
        else if(strcmp(input_str,"6")==0) instance_set[5] = 
                                        ( instance_set[5] == '0' ? '1' : '0' );
        else if(strcmp(input_str,"9")==0) instance_set[6] = 
                                        ( instance_set[6] == '0' ? '1' : '0' );
        printf("instance_set: %s\n", instance_set);
      }while(strncmp(input_str, "0", 1) != 0);

      /* Prompt user for n set */
      char n_set[] = "00000000";
      printf("Enter the n-types you want to toggle (50, 100, 200, 500, 1000, 2000, 5000, 10000)\n");
      do{
        scanf("%s", input_str);
        if(strcmp(input_str,"50")==0) n_set[0] =
                                             ( n_set[0] == '0' ? '1' : '0' );
        else if(strcmp(input_str,"100")==0) n_set[1] = 
                                             ( n_set[1] == '0' ? '1' : '0' );
        else if(strcmp(input_str,"200")==0) n_set[2] = 
                                             ( n_set[2] == '0' ? '1' : '0' );
        else if(strcmp(input_str,"500")==0) n_set[3] = 
                                             ( n_set[3] == '0' ? '1' : '0' );
        else if(strcmp(input_str,"1000")==0) n_set[4] =
                                             ( n_set[4] == '0' ? '1' : '0' );
        else if(strcmp(input_str,"2000")==0) n_set[5] = 
                                             ( n_set[5] == '0' ? '1' : '0' );
        else if(strcmp(input_str,"5000")==0) n_set[6] = 
                                             ( n_set[6] == '0' ? '1' : '0' );
        else if(strcmp(input_str,"10000")==0) n_set[7] = 
                                             ( n_set[7] == '0' ? '1' : '0' );
        printf("n_set: %s\n", n_set);
      }while(strncmp(input_str, "0", 1) != 0);

      /* Prompt user for coefficient set */
      char coefficient_set[] = "00000";
      printf("Enter the coefficient types you want to toggle (of 1000, 10000," 
              "100000, 1000000, 10000000)\n");
      do{
        scanf("%s", input_str);
        if(strcmp(input_str,"1000")==0) coefficient_set[0] = 
                                     ( coefficient_set[0] == '0' ? '1' : '0' );
        else if(strcmp(input_str,"10000")==0) coefficient_set[1] = 
                                     ( coefficient_set[1] == '0' ? '1' : '0' );
        else if(strcmp(input_str,"100000")==0) coefficient_set[2] = 
                                     ( coefficient_set[2] == '0' ? '1' : '0' );
        else if(strcmp(input_str,"1000000")==0) coefficient_set[3] = 
                                     ( coefficient_set[3] == '0' ? '1' : '0' );
        else if(strcmp(input_str,"10000000")==0) coefficient_set[4] = 
                                     ( coefficient_set[4] == '0' ? '1' : '0' );
        printf("coefficient_set: %s\n", coefficient_set);
      }while(strncmp(input_str, "0", 1) != 0);

      /* Prompt user for problem subset */
      int problem_subset = 0;
      printf("Enter the first n problems you want to compute of an instance type\n");
      do{
        scanf("%d", &problem_subset);
        /* Make sure they pick a reasonable number! */
      }while(problem_subset < 1 || problem_subset > 100);
      /* Prompt user for hard instance set */
      char hard_instance_set[] = "000000";
      printf("Enter the hard instance types you want to toggle (of 11-16)\n");
      do{
        scanf("%s", input_str);
        if(strcmp(input_str,"11")==0) hard_instance_set[0] = 
                                ( hard_instance_set[0] == '0' ? '1' : '0' );
        else if(strcmp(input_str,"12")==0) hard_instance_set[1] = 
                                ( hard_instance_set[1] == '0' ? '1' : '0' );
        else if(strcmp(input_str,"13")==0) hard_instance_set[2] = 
                                ( hard_instance_set[2] == '0' ? '1' : '0' );
        else if(strcmp(input_str,"14")==0) hard_instance_set[3] = 
                                ( hard_instance_set[3] == '0' ? '1' : '0' );
        else if(strcmp(input_str,"15")==0) hard_instance_set[4] = 
                                ( hard_instance_set[4] == '0' ? '1' : '0' );
        else if(strcmp(input_str,"16")==0) hard_instance_set[5] = 
                                ( hard_instance_set[5] == '0' ? '1' : '0' );
        printf("hard_instance_set: %s\n", hard_instance_set);
      }while(strncmp(input_str, "0", 1) != 0);

      /* Prompt user for hard n set*/
      char hard_n_set[] = "000000000";
      printf("Enter the hard n types you want to toggle (20, 50, 100, 200, 500,"
             " 1000, 2000, 5000, 10000\n");
      do{
        scanf("%s", input_str);
        if(strcmp(input_str,"20")==0) hard_n_set[0] = 
                                ( hard_n_set[0] == '0' ? '1' : '0' );
        else if(strcmp(input_str,"50")==0) hard_n_set[1] = 
                                ( hard_n_set[1] == '0' ? '1' : '0' );
        else if(strcmp(input_str,"100")==0) hard_n_set[2] = 
                                ( hard_n_set[2] == '0' ? '1' : '0' );
        else if(strcmp(input_str,"200")==0) hard_n_set[3] = 
                                ( hard_n_set[3] == '0' ? '1' : '0' );
        else if(strcmp(input_str,"500")==0) hard_n_set[4] = 
                                ( hard_n_set[4] == '0' ? '1' : '0' );
        else if(strcmp(input_str,"1000")==0) hard_n_set[5] = 
                                ( hard_n_set[5] == '0' ? '1' : '0' );
        else if(strcmp(input_str,"2000")==0) hard_n_set[6] = 
                                ( hard_n_set[6] == '0' ? '1' : '0' );
        else if(strcmp(input_str,"5000")==0) hard_n_set[7] = 
                                ( hard_n_set[7] == '0' ? '1' : '0' );
        else if(strcmp(input_str,"10000")==0) hard_n_set[8] = 
                                ( hard_n_set[8] == '0' ? '1' : '0' );
        printf("hard_n_set: %s\n", hard_n_set);
      }while(strncmp(input_str, "0", 1) != 0);

      char dualbound_types_set[] = "0000";
      printf("Enter the dual bound strategies you want to toggle (apriori, +nK,"
             "+nK-omega, roundup).\n");
      do{
        scanf("%s", input_str);
        if(strcmp(input_str,"apriori")==0) dualbound_types_set[0] = 
                                ( dualbound_types_set[0] == '0' ? '1' : '0' );
        else if(strcmp(input_str,"+nK")==0) dualbound_types_set[1] = 
                                ( dualbound_types_set[1] == '0' ? '1' : '0' );
        else if(strcmp(input_str,"+nK-omega")==0) dualbound_types_set[2] = 
                                ( dualbound_types_set[2] == '0' ? '1' : '0' );
        else if(strcmp(input_str,"roundup")==0) dualbound_types_set[3] = 
                                ( dualbound_types_set[3] == '0' ? '1' : '0' );
        printf("dualbound_types_set: %s\n", dualbound_types_set);
      }while(strncmp(input_str, "0", 1) != 0);

      /* Prompt for pure DP solution benchmarking */
      char dp_benchmarking_set[] = "00";
      printf("If you want to benchmark either of the DP's (not b&b) here, togg"
             "le (vv, ws)\n");
      do{
        scanf("%s", input_str);
        if(strcmp(input_str,"ws")==0) dp_benchmarking_set[0] = 
                                ( dp_benchmarking_set[0] == '0' ? '1' : '0' );
        else if(strcmp(input_str,"vv")==0) dp_benchmarking_set[1] = 
                                ( dp_benchmarking_set[1] == '0' ? '1' : '0' );
        printf("dp_benchmarking_set: %s\n", dp_benchmarking_set);
      }while(strncmp(input_str, "0", 1) != 0);
      

      /* Prompt user for output filename */
      printf("Finally, enter the file that you want the benchmark to be written to.\n");
      do{
        scanf("%s", input_str);
      }while(!file_test(input_str)); 

      
      printf("\nYour benchmark parameters are:\n"
             "Memory allocation limit: \t%lld\n"
             "Timeout: \t\t\t%d\n"
             "DP_Set: \t\t\t%s\n"
             "Branching set: \t\t\t%s\n"
             "Instance set: \t\t\t%s\n"
             "n_set: \t\t\t\t%s\n"
             "Coefficient set: \t\t%s\n"
             "Problem subset: \t\t%d\n"
             "hard_instance_set: \t\t%s\n"
             "hard_n_set: \t\t\t%s\n"
             "dualbound_types_set: \t\t%s\n"
             "dp_benchmarking_set: \t\t%s\n\n",
              memory_allocation_limit, timeout, DP_types, branch_strats, 
              instance_set, n_set, coefficient_set, problem_subset, 
              hard_instance_set, hard_n_set, dualbound_types_set, dp_benchmarking_set); 

      FILE *benchmark_stream = fopen(input_str,"a"); 
      fprintf(benchmark_stream, "ass\n");      
      printf("Your seed is:\n%s %lld %d %s %s %s %s %s %s %d %s %s %s %s\n", argv[0], 
            memory_allocation_limit, timeout, input_str, DP_types, 
            branch_strats, instance_set, n_set, coefficient_set, problem_subset, 
            hard_instance_set, hard_n_set, dualbound_types_set, dp_benchmarking_set);

      benchmark(memory_allocation_limit, timeout, DP_types, n_set, 
                coefficient_set, instance_set, branch_strats, benchmark_stream,
                problem_subset, hard_instance_set, hard_n_set, dualbound_types_set, 
                dp_benchmarking_set);

      fclose(benchmark_stream);

      return 0;
    }
  } 


  if(argc != 14)
  {
    printf("This application takes either 2 or 14 arguments.\n");
    printf("Format: \"%s <memory limit> <timeout> <file out> <DP set> <branchi"
           "ng strategy set> <instance set> <n set> <coefficient set> <problem"
           " subset> <hard instance set> <hard n set> <dualbound set> <dp_benc"
           "hmarking_set>\"\nor\n \"%s -w\" for wizard\n Type \"%s help\" for "
           "info on input options.\n", argv[0], argv[0], argv[0]);
    printf("i.e. %s int int char[] char[2] char[3] char[7] char[8] char[5] in"
           "t char[6] char[9] char[4] char[2]\n", argv[0]);
    exit(-1);
  }
  
  /* Validate inputs */
  command_line_validation(argv[1], argv[2], argv[3], argv[4], argv[5],
                          argv[6], argv[7], argv[8], argv[9], argv[10], 
                          argv[11], argv[12], argv[13]);
  
  long long int memory_allocation_limit = atoi(argv[1]);
  int timeout = atoi(argv[2]);
  FILE *file_out = fopen(argv[3],"a");

  int problem_subset = atoi(argv[9]);  

  printf("Memory allocation limit: %s\n"
         "Timeout: %s\n"
         "DP_Set: %s\n"
         "Branching set: %s\n"
         "Instance set: %s\n"
         "n_set: %s\n"
         "Coefficient set: %s\n"
         "Problem subset: %s\n"
         "hard_instance_set: %s\n"
         "hard_n_set: %s\n"
         "dualbound_types_set: %s\n"
         "dp_benchmarking_set: %s\n",
         argv[1], argv[2], argv[4], argv[5], argv[6],
         argv[7], argv[8], argv[9], argv[10], argv[11], argv[12], argv[13]);

  benchmark(memory_allocation_limit, timeout, argv[4], argv[7], argv[8], 
            argv[6], argv[5], file_out, problem_subset,
            argv[10], argv[11], argv[12], argv[13]);
  fclose(file_out);

  return 0;
}
#endif

void benchmark(long long int memory_allocation_limit, int timeout, char *DP_set, 
               char *n_set, char *coefficient_set, char *instance_set, 
               char *branching_strategies, FILE *benchmark_stream, 
               int problem_subset, char *hard_instance_set, char *hard_n_set,
               char *dualbound_types_set, char *dp_benchmarking_set)
{
  /* Parameterisations to enumerate through */
  char file_name_holder[30];
  const char *instance_types_1[] = { "1", "2", "3", "4", "5", "6", "9" };
  const char *coefficient_types[] = {"1000", "10000", "100000", "1000000", 
                                     "10000000"};
  const char *n_types[] = {"50", "100", "200", "500", "1000", "2000", "5000",
                           "10000"};
  /* Second instance types */
  const char *instance_types_2[] = {"11", "12", "13", "14", "15", "16"};
  const char *n_types_2[] = {"20", "50", "100", "200", "500", "1000", "2000",
                             "5000", "10000"}; 

  /* Parameterisation names */
  const char *DP_method_names[] = {"Vazirani", "Williamson & Shmoys"};
  const char *branching_strat_names[] = {"Linear Enumeration branching",
                                         "Random Branching",
                                         "Truncation branching"};
  const char *dualbound_type_names[] = {"A priori", "+nK", "+nK - ω", "roundup"};

  fprintf(benchmark_stream, "File name, DP method, branching strategy, dual bou"
                            "nd strategy, problem #, runtime, memory allocated,"
                            " node count, ave. time per node, true ave. time pe"
                            "r node\n");


  /* Filetype enumeration begin */
  /* For each DP method */
  for(int DP_method = VASIRANI; DP_method <= WILLIAMSON_SHMOY; DP_method++)
  {
    if(strncmp(&DP_set[DP_method],"0", 1)==0)
      continue;  

    /* For each branching_strategy */
    for(int branching_strategy = LINEAR_ENUM_BRANCHING; 
        branching_strategy <= TRUNCATION_BRANCHING;
        branching_strategy++)
    {
      if(strncmp(&branching_strategies[branching_strategy],"0", 1)==0)
        continue;  

      /* For each instance type*/
      for(int j = 0; j < 7; j++)
      {
        if(strncmp(&instance_set[j],"0", 1)==0)
          continue;

        /* For each n (easy instances) */
        for(int k = 0; k < 8; k++)
        {
          if(strncmp(&n_set[k],"0", 1)==0)
            continue;

          /* For each coefficient type */
          for(int l = 0; l < 5; l++)
          {
            if(strncmp(&coefficient_set[l],"0", 1)==0)
              continue;

            /* For each dual bounding method */
            for(int dualbounding_method = APRIORI_DUAL;
                dualbounding_method <= APOSTERIORI_DUAL_ROUNDUP;
                dualbounding_method++)
            {
              if(strncmp(&dualbound_types_set[dualbounding_method], "0", 1) ==0)
                continue;

              /* For each problem instance */
              for(int m = 1; m <= problem_subset; m++)
              {
                snprintf(file_name_holder, 30, "knapPI_%s_%s_%s.csv", 
                         instance_types_1[j], n_types[k], coefficient_types[l]);
              
                time_t t = time(NULL);
                struct tm tm = *localtime(&t);
                /* Run the benchmark */
                printf("%d:%d:%d - Running on %s with %s, %s, %s... \n", tm.tm_hour, tm.tm_min, 
                       tm.tm_sec, file_name_holder, DP_method_names[DP_method], 
                       branching_strat_names[branching_strategy],
                       dualbound_type_names[dualbounding_method]);
                benchmark_instance(file_name_holder, m, timeout, DP_method,
                                  memory_allocation_limit, benchmark_stream,
                                  branching_strategy, dualbounding_method);
                
              }
            }
          }
        }
      }
      /* For each instance type (hard)*/
      for(int j = 0; j < 6; j++)
      {
        if(strncmp(&hard_instance_set[j],"0", 1)==0)
          continue;

        /* For each n (hard instances) */
        for(int k = 0; k < 9; k++)
        {
          if(strncmp(&hard_n_set[k],"0", 1)==0)
            continue;
          /* For each dual bounding method */
          for(int dualbounding_method = APRIORI_DUAL;
              dualbounding_method <= APOSTERIORI_DUAL_ROUNDUP;
              dualbounding_method++)
          {
            if(strncmp(&dualbound_types_set[dualbounding_method], "0", 1) ==0)
              continue;
            /* For each problem instance */
            for(int m = 1; m <= problem_subset; m++)
            {
              snprintf(file_name_holder, 30, "knapPI_%s_%s_1000.csv", 
                       instance_types_2[j], n_types_2[k]);

              time_t t = time(NULL);
              struct tm tm = *localtime(&t);
              printf("%d:%d:%d - Running on %s with %s, %s, %s... \n", tm.tm_hour, tm.tm_min, 
                     tm.tm_sec, file_name_holder, DP_method_names[DP_method], 
                     branching_strat_names[branching_strategy],
                     dualbound_type_names[dualbounding_method]);

              /* Run the benchmark */
              benchmark_instance(file_name_holder, m, timeout, DP_method,
                                memory_allocation_limit, benchmark_stream,
                                branching_strategy, dualbounding_method);
            }
          }
        }
      }
    }
  }
   
  /* For Pure DP benchmarks: For each instance type*/
  for(int j = 0; j < 7; j++)
  {
    if(strncmp(&instance_set[j],"0", 1)==0)
      continue;

    /* For each n (easy) */
    for(int k = 0; k < 8; k++)
    {
      if(strncmp(&n_set[k],"0", 1)==0)
        continue;

      /* For each coefficient type */
      for(int l = 0; l < 5; l++)
      {
        if(strncmp(&coefficient_set[l],"0", 1)==0)
          continue;

        /* For each DP method, if it's active, benchmark it*/
        for(int pure_DP = VASIRANI; 
            pure_DP <= WILLIAMSON_SHMOY; pure_DP++)
        {
          if(strncmp(&dp_benchmarking_set[pure_DP], "0", 1) == 0)
            continue;

          /* For each problem instance */
          for(int m = 1; m <= problem_subset; m++)
          {
            snprintf(file_name_holder, 30, "knapPI_%s_%s_%s.csv", 
                     instance_types_1[j], n_types[k], coefficient_types[l]);
            time_t t = time(NULL);
            struct tm tm = *localtime(&t);
            printf("%d:%d:%d - Running on %s... (Pure DP)\n", tm.tm_hour, tm.tm_min, 
                   tm.tm_sec, file_name_holder);
            benchmark_dp(file_name_holder, m, timeout, pure_DP, memory_allocation_limit,
                         benchmark_stream);
          }
        }
      }
    }
  }
 
  /* For each instance type (hard)*/
  for(int j = 0; j < 6; j++)
  {
    if(strncmp(&hard_instance_set[j],"0", 1)==0)
      continue;

    /* For each n (hard instances) */
    for(int k = 0; k < 9; k++)
    {
      if(strncmp(&hard_n_set[k],"0", 1)==0)
        continue;
      /* For each DP method, if it's active, benchmark it*/
      for(int pure_DP = VASIRANI; 
          pure_DP <= WILLIAMSON_SHMOY; pure_DP++)
      {
        if(strncmp(&dp_benchmarking_set[pure_DP], "0", 1) == 0)
          continue;

        /* For each problem instance */
        for(int m = 1; m <= problem_subset; m++)
        {
          snprintf(file_name_holder, 30, "knapPI_%s_%s_1000.csv", 
                   instance_types_2[j], n_types_2[k]);
          /* Run the benchmark */
          time_t t = time(NULL);
          struct tm tm = *localtime(&t);
          printf("%d:%d:%d - Running on %s... (Pure DP)\n", tm.tm_hour, tm.tm_min, 
                 tm.tm_sec, file_name_holder);
          benchmark_dp(file_name_holder, m, timeout, pure_DP, memory_allocation_limit,
                       benchmark_stream);
        }
      }
    }
  }
}


void benchmark_instance(char *file_name_holder, int problem_no, int timeout, 
                        int DP_method, long long int memory_allocation_limit,
                        FILE *benchmark_stream, int branching_strategy, 
                        int dualbounding_method)
{
  /* Problem variables */
  double epsilon = 0.0;
  FILE *logging_stream  = stdout;
  int logging_rule = NO_LOGGING;
  int seed = 0;
  if(branching_strategy == RANDOM_BRANCHING)
  {
    seed = time(NULL);
  }
  int n, capacity, z;
  int *profits, *weights, *x;
  int z_out = 0;
  int number_of_nodes = 1;

  /* Initialise dynamic array */
  initialise_dynamic_array(&times_per_node, 1000);

  pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, file_name_holder,
                  problem_no);
  int sol_out[n];
  clock_t t = clock();
  branch_and_bound_bin_knapsack(profits, weights, x, capacity, z, 
                                &z_out, sol_out, n, file_name_holder,
                                branching_strategy, seed, DP_method, 
                                logging_rule, logging_stream, epsilon,
                                &number_of_nodes, 
                                memory_allocation_limit, &t, timeout,
                                dualbounding_method);

  char stringified_time[30];
  double average_time_per_node;
  if (t == -1.0)
  {
    strcpy(stringified_time, "TIMEOUT");
    average_time_per_node = 0.0;
  }
  else
  {
    clock_t elapsed = clock() - t;
    double time_taken = ((double) elapsed)/CLOCKS_PER_SEC;
    sprintf(stringified_time, "%lf", time_taken);
    average_time_per_node = time_taken/(double)number_of_nodes;
  }

  /* True average time per node */  
  double true_average_time_per_node = 0;
  for(int i = 0; i < times_per_node->used; i++)
    true_average_time_per_node += times_per_node->array[i];
  true_average_time_per_node /= times_per_node->used;

  free_dynamic_array(times_per_node);
  free(times_per_node);

  char stringified_memory[30];
  if(bytes_allocated == -1)
    strcpy(stringified_memory, "MEMORY LIMIT EXCEEDED");
  else
    sprintf(stringified_memory, "%lld", bytes_allocated);

  char *DP_str_arr[] = {"Vazirani", "Williamson Shmoy"}; 
  char *branching_strats[] = {"Linear Enum", "Random", "Truncation"};
  char *dualbound_methods_array[] = {"Basic a priori", "+nK", "+nK-ω", 
                                     "Profits roundup"};

  fprintf(benchmark_stream, "%s, %s, %s, %s, %d, %s, %s, %d, %lf, %lf\n", 
          file_name_holder, DP_str_arr[DP_method], 
          branching_strats[branching_strategy], 
          dualbound_methods_array[dualbounding_method], problem_no,
          stringified_time, stringified_memory, number_of_nodes, 
          average_time_per_node, true_average_time_per_node);
  printf("%s problem #%d: Performance logged.(Result: %d/%d - %s)\n", file_name_holder, problem_no, z_out, z, z_out==z ? "Pass!" : "Failure-- WAIT SHIT SHIT!\n"
                    "   ______ _____  _____   ____  _____   \n"
                    "  |  ____|  __ \\|  __ \\ / __ \\|  __ \\  \n"
                    "  | |__  | |__) | |__) | |  | | |__) | \n"
                    "  |  __| |  _  /|  _  /| |  | |  _  /  \n"
                    "  | |____| | \\ \\| | \\ \\| |__| | | \\ \\  \n"
                    "  |______|_|  \\_\\_|  \\_\\____/|_|  \\_\\ \n"
                    "                                       \n");
}

void command_line_validation(const char argv1[], const char argv2[], 
                             const char argv3[], const char argv4[], 
                             const char argv5[], const char argv6[],
                             const char argv7[], const char argv8[],
                             const char argv9[], const char argv10[],
                             const char argv11[], const char argv12[],
                             const char argv13[])
{
  /* Check argv[1]: memory limit */
  long int memory_limit = atoi(argv1);
  if (memory_limit < 1)
  {
    printf("Memory limit (argv[1]) makes no sense! Exiting...\n");
    exit(-1);
  }
  /* Check argv[2]: timeout */
  int timeout = atoi(argv2);
  if (timeout < 1)
  {
    printf("Timeout (argv[2]) makes no sense! Exiting...\n");
    exit(-1);
  }
  int n;
  /* Check argv[3]: file out */
  n = strlen(argv3);
  if(argv3[n-3] != 'c' ||
     argv3[n-2] != 's' ||
     argv3[n-1] != 'v')
  {
    printf("File out (argv[3]) should be a csv! Exiting...\n");
    exit(-1);
  } 
  
  /* Check argv[4]: DP types */
  n = strlen(argv4);
  if(n != 2)
  {
    printf("DP types (argv[4]) should be of length 2! Exiting...\n");
    exit(-1);
  }  
  for(int i = 0; i < n; i++)
  {
    if(argv4[i] != '0' && argv4[i] != '1')
    {
      printf("DP_types (argv[4]) should only contain 1's and 0's! Exiting..\n");
      exit(-1);
    }
  }

  /* Check argv[5]: Branching strategy */
  n = strlen(argv5);
  if(n != 3)
  {
    printf("Branching strategies (argv[5]) should be of length 3! Exiting...\n");
    exit(-1);
  }
  for(int i = 0; i < n; i++)
  {
    if(argv5[i] != '0' && argv5[i] != '1')
    {
      printf("Branching strategies string (argv[5]) should only contain 1's and 0's! Exiting..\n");
      exit(-1);
    }
  } 

  /* Check argv[6]: Instance set */
  n = strlen(argv6);
  if(n != 7)
  {
    printf("Instance set string (argv[6]) should be of length 7! Exiting...\n");
    exit(-1);
  }

  /* Check argv[7]: n set */
  n = strlen(argv7);
  if(n != 8)
  {
    printf("n set (argv[6]) should be of length 8! Exiting...\n");
    exit(-1);
  }


  /* Check argv[8]: coefficient set */
  n = strlen(argv8);
  if(n != 5)
  {
    printf("n set (argv[8]) should be of length 5! Exiting...\n");
    exit(-1);
  }
  for(int i = 0; i < n; i++)
  {
    if(argv8[i] != '0' && argv8[i] != '1')
    {
      printf("n set string (argv[8]) should only contain 1's and 0's! Exiting..\n");
      exit(-1);
    }
  }

  /* Check argv[9]: problem subset */
  int problem_subset = atoi(argv9);
  if(problem_subset < 1 || problem_subset > 100)
  {
    printf("Inappropriate problem subset (argv[9]). Exiting...\n");
    exit(-1);
  }
  
  /* Check argv[10]: hard instance set */
  n = strlen(argv10);
  if(n != 6)
  {
    printf("n set (argv[10]) should be of length 6! Exiting...\n");
    exit(-1);
  }

  /* Check argv[11]: hard n set */
  n = strlen(argv11);
  if(n != 9)
  {
    printf("n set (argv[11]) should be of length 9! Exiting...\n");
    exit(-1);
  }

  /* Check argv[12]: dual bounding methods */
  n = strlen(argv12);
  if(n != 4)
  {
    printf("Dual bounding methods (argv[12]) should be of length 4! Exiting..."
           "\n");
    exit(-1);
  }
  for(int i = 0; i < n; i++)
  {
    if(argv12[i] != '0' && argv12[i] != '1')
    {
      printf("Branching strategies string (argv[12]) should only contain 1's an"
             "d 0's! Exiting..\n");
      exit(-1);
    }
  }

  /* Check argv[13]: dp benchmarking set*/
  n = strlen(argv13);
  if(n != 2)
  {
    printf("Dual bounding methods (argv[12]) should be of length 4! Exiting..."
           "\n");
    exit(-1);
  }
  for(int i = 0; i < n; i++)
  {
    if(argv12[i] != '0' && argv12[i] != '1')
    {
      printf("Branching strategies string (argv[12]) should only contain 1's an"
             "d 0's! Exiting..\n");
      exit(-1);
    }
  }
}

int file_test(const char file_name[])
{
  int n = strlen(file_name);
  if(file_name[n-4] != '.' ||
     file_name[n-3] != 'c' ||
     file_name[n-2] != 's' ||
     file_name[n-1] != 'v') 
  {
    printf("Filename should end with .csv!\n");
    return 0;
  }
  return 1;
}

/* Important! I need to adapt the DPs to allow for timeout and overallocation */
void benchmark_dp(char *file_name_holder, int problem_no, int timeout,
                  int DP_method, long long int allocation_limit,
                  FILE *benchmark_stream)
{
  /* Read in file */
  int n, capacity, z;
  int *profits, *weights, *x;
  char problem_file[100];
  pisinger_reader(&n, &capacity, &z, &profits, &weights, &x, file_name_holder,
                  problem_no);
  int z_out = 0;
  int number_of_nodes = -1;
  int sol_out[n];
  for (int i = 0; i < n; i++) sol_out[i] = 0;

  /* Set bytes allocated */
  bytes_allocated = 0;

  /* Start timer */
  clock_t start_time = clock();

  /* Then solve it */
  if (DP_method == VASIRANI)
  {
    DP(profits, weights, x, sol_out, n, capacity, z, BINARY_SOL, 
       SIMPLE_SUM, problem_file, allocation_limit, timeout, &start_time);
  }
  else if (DP_method == WILLIAMSON_SHMOY)
  {
    struct problem_item items[n];
    for(int i = 0; i < n; i++)
    {
      items[i].weight = weights[i];
      items[i].profit = profits[i];
    }
    int result = williamson_shmoys_DP(items, capacity, n,
                                      sol_out, allocation_limit, 
                                      timeout, &start_time);
  }

  char stringified_time[30];
  char average_time_per_node[] = "N/A";
  if (start_time == -1.0)
    strcpy(stringified_time, "TIMEOUT");
  else
  {
    clock_t elapsed = clock() - start_time;
    double time_taken = ((double) elapsed)/CLOCKS_PER_SEC;
    sprintf(stringified_time, "%lf", time_taken);
  }
  char stringified_memory[30];
  if(bytes_allocated == -1)
    strcpy(stringified_memory, "MEMORY LIMIT EXCEEDED");
  else
    sprintf(stringified_memory, "%lld", bytes_allocated);

  char *DP_str_array[] = {"Vazirani (DP only)", "Williamson Shmoy (DP only)"};

  /* Write to benchmark_stream */
  fprintf(benchmark_stream, "%s, %s, %s, %s, %d, %s, %s, %s, %s, %s\n",
          file_name_holder, DP_str_array[DP_method], "N/A", "N/A", problem_no, 
          stringified_time, stringified_memory, "N/A", "N/A", "N/A");
  printf("%s problem #%d: (Pure DP) Performance logged.\n", file_name_holder, 
         problem_no);
}

