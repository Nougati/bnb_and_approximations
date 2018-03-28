#include "pisinger_reader.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* Pisinger reader */
void pisinger_reader(int *n, int *c, int *z, int **p, int **w, int **x, 
                     char *problem_file, int problem_number)
{ 
  /* 
   * Description:
   *   Reads pisinger's csv knapsack instances into arrays. This does not work 
   *    on his automatically generated instances.
   * Inputs:
   *
   * Notes:
   *   This has been edited to support dynamic allocation error catching.  
   */
  /* Make sure the reader was given a valid problem index */
  if (problem_number <= 0 || problem_number > 100)
  {
    printf("Bad problem number. Exiting...\n");
    exit(EXIT_FAILURE);
  }
  FILE *fp;
  char str[256];
  char *pch;
  char problem_number_str[100];

  /* Get data about the instance itself
   * TODO Get this supporting instance types of more than one digit */
  int coefficient_size;
  int instance_type;
  sscanf(problem_file, "knapPI_%d_%d_%d.csv", &instance_type, n, &coefficient_size);
  int ndigits = floor(log10(abs(*n)))+1;
  int cdigits = floor(log10(abs(coefficient_size)))+1;
  int pnodigits = floor(log10(abs(problem_number)))+1;

  /* From this, we deduce the length of the instance name */
  int instance_name_width = 11+ndigits+cdigits+pnodigits;
  if (instance_type > 9) instance_name_width++;

  /* Problem number needs to be concatenated onto char array instance_name */
  /* So, we convert it to a string. */
  sprintf(problem_number_str, "%d", problem_number);

  /* Create the instance name of form knapPI_<instance>_<n>_<coeff>_<pno>*/
  char instance_name[50];
  strncpy(instance_name, problem_file, instance_name_width-pnodigits-1);
  //strcat(instance_name, "_");
  instance_name[instance_name_width-pnodigits-1] = '_';
  instance_name[instance_name_width-pnodigits] = '\0';
  strcat(instance_name, problem_number_str);

  /* Open file */
  char path[80];
  strcpy(path, "./problems/");
  strcat(path, problem_file);
  fp = fopen(path, "r");
  if (fp == NULL)
  {
    printf("Unable to open file. Exiting...\n");
    exit(EXIT_FAILURE);
  }

  /* Find instance in file */
  while(strncmp(fgets(str, sizeof(str), fp), instance_name, instance_name_width) != 0) //TODO This is where its segfaulting w/ instance type 11
    ;

  /* Extract n */
  while (fgets(str, sizeof(str), fp)){
    if (str[0] == 'n'){
      pch = strtok(str, " ");
      pch = strtok(NULL, " ");
      *n = atoi(pch);
      break;
    }
  }

  /* Allocate profits array */
  int *tmp_p;
  if((tmp_p = (int *)malloc(*n * sizeof(*tmp_p)))==NULL)
  {  //tperror("Error allocating space for profits\n");
    fprintf(stderr, "Cannot malloc tmp_x!\n");
    exit(1);
  }

  /* Allocate weights array */
  int *tmp_w;
  if((tmp_w = (int *)malloc(*n * sizeof(*tmp_w)))==NULL)
  {  //perror("Error allocating space for weights\n");
    fprintf(stderr, "Cannot malloc tmp_x!\n");
    exit(1);
  }

  /* Allocate solution array x */
  int *tmp_x;
  if ((tmp_x = (int *)malloc(*n * sizeof(*tmp_x)))==NULL)
  {  //perror("Error allocating space for solution\n");
    fprintf(stderr, "Cannot malloc tmp_x!\n");
    exit(1);
  }

  int counter=0;
  if (fp == NULL) exit(EXIT_FAILURE);

  /* Read in all the values into the arrays */
  while ((fgets(str, sizeof(str), fp))&&(counter<*n)){
    if(str[0] == 'c'){
        pch = strtok(str, " ");
        pch = strtok(NULL, " ");
        *c = atoi(pch);
    }else if (str[0] == 'z'){
        pch = strtok(str, " ");   
        pch = strtok(NULL, " ");
        *z = atoi(pch);
    }else if (!((str[0] == 'n')
              ||(str[0] == 'z')
              ||(str[0] == 'k')
              ||(str[0] == 't'))){

        pch = strtok(str, ",");
        pch = strtok(NULL, ",");

        tmp_p[counter] = atoi(pch);

        pch = strtok(NULL, ",");

        tmp_w[counter] = atoi(pch);

        pch = strtok(NULL, ",");

        tmp_x[counter] = atoi(pch);

        counter += 1;

    }
  }
  fclose(fp);

  *p = tmp_p;
  *w = tmp_w;
  *x = tmp_x;
}

