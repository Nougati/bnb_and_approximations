#include <stdio.h>
#include <math.h>
#define TRUE 1
#define FALSE 0

int main(int argc, char *argv[])
{
  int floor_please = FALSE;
  if (argc > 1)
    floor_please = TRUE;

  double z_lower = 3442;
  double epsilon = 0.142857;
  double one_on_eps = 1.0/epsilon;
  double zeps = z_lower*epsilon;
  double interval, next_interval, subinterval, next_subinterval;
  int n = 10;
  int profits[] = {94, 506, 416, 992, 649, 237, 457, 815, 446, 422};

  printf("lower_bound = %d, (modified) epsilon = %lf\n", (int)z_lower, 
         epsilon);

  /* START Muh slotting mechanism */
  /*
  int n = 50;
  int capacity = 99748;
  int profits[] = {15094, 24506, 94416, 40992, 66649, 49237, 96457, 67815, 19446,
                   63422, 88791, 49359, 45667, 31598, 82007, 20544, 85334, 82766,
                   93994, 59893, 62633, 87131, 5428, 76700, 30617, 15874, 77720, 
                   74419, 69794, 28196, 95997, 83116, 15908, 55539, 45707, 38569,
                   25537, 90931, 55726, 75487, 59772, 67513, 52081, 29943, 88058,
                   84303, 13764, 6536, 90724, 63789};

  int weights[] = {485, 56326, 79248, 45421, 80322, 15795, 58043, 42845, 24955, 
                  49252, 61009, 25901, 81122, 81094, 38738, 88574, 65715, 78882,
                  31367, 59984, 73299, 49433, 15682, 90072, 97874, 138, 53856,
                  87145, 37995, 91529, 36199, 83277, 80097, 59719, 35242, 36107,
                  41122, 41070, 76098, 53600, 36645, 7267, 41972, 9895, 83213, 
                  99748, 89487, 71923, 17029, 2567};
  */

  int intervals[n];
  int subintervals[n];
  for(int i = 0; i < n; i++)
  {
    intervals[i] = 0;
    subintervals[i] = 0;
  }
  /* END Muh slotting mechanism */

  for(int i = 1; i <= one_on_eps-1; i++)
  {
    interval = i*zeps;
    next_interval = (i+1)*zeps;
    if (floor_please)
      printf("Interval #%d: (%d, %d]\n", i, (int)interval, (int)next_interval);
    else
      printf("Interval #%d: (%lf, %lf]\n", i, interval, next_interval);

    /* START Muh slotting mechanism */
    for(int j = 0; j < n; j++)
    {
      if(profits[j] > interval && profits[j] <= next_interval)
        intervals[j] = i;
    }
    /* END Muh slotting mechanism*/

    int k_stop = ceil(1/(i*epsilon))-1;
    int k;
    for(k = 1; k <= k_stop; k++)
    {
      subinterval = i*zeps*(1+(k-1)*epsilon);
      next_subinterval = i*zeps*(1+k*epsilon);
      if (floor_please)
        printf("\tSubinterval #%d: (%d, %d]\n", k,(int) subinterval,
               (int) next_subinterval);
      else
        printf("\tSubinterval #%d: (%lf, %lf]\n", k, subinterval,
               next_subinterval);

      /* START Muh slotting mechanism */
      for(int j = 0; j < n; j++)
      {
        if(profits[j] > subinterval && profits[j] <= next_subinterval)
          subintervals[j] = k;
      }
      /* END Muh slotting mechanism*/
    }
    subinterval = i*zeps*(1+k_stop*epsilon);
    next_subinterval = (i+1)*zeps;
    if (floor_please)
      printf("\tSubinterval #%d: (%d, %d]\n", k_stop+1, (int) subinterval,
             (int) next_subinterval);
    else
      printf("\tSubinterval #%d: (%lf, %lf]\n", k_stop+1, subinterval,
             next_subinterval);
    /* START Muh slotting mechanism */
    for(int j = 0; j < n; j++)
    {
      if(profits[j] > subinterval && profits[j] <= next_subinterval)
        subintervals[j] = k;
    }
    /* END Muh slotting mechanism*/
  }

  /* Print intervals */
  for(int i = 0; i < n; i++)
    printf("%s%d%s", i==0?"Intervals[] = \n\t[":", ", intervals[i],
           i == n-1 ? "]\n" : "");
  /* Print subintervals */
  for(int i = 0; i < n; i++)
    printf("%s%d%s", i==0?"SubIntervals[] = \n\t[":", ", subintervals[i],
           i == n-1 ? "]\n" : "");
  return 0;
}
