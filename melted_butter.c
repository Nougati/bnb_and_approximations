/*melted_butter.c*/

/* Just for testing 2D array passing */
#include <stdio.h>

void fill_in_that_array(int width, 
                        int height, 
                        int two_dimensional_array[][width]);

int main(){
  int height = 4;
  int width = 4;
  int my_big_fat_greek_array[height][width];

  fill_in_that_array(width, height, my_big_fat_greek_array);

  for(int i = 0; i < height; i++){
    for(int j = 0; j < width; j++){
      printf("%d\t", my_big_fat_greek_array[i][j]);
    }printf("\n");
  }

  return 0;
}

void fill_in_that_array(int width, 
                        int height, 
                        int two_dimensional_array[][width]){

  for(int i = 0; i < height; i++){
    for(int j = 0 ; j < width; j++){
      two_dimensional_array[i][j] = i*height+j;
    }
  }

}
