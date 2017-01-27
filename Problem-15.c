/***


		Problem 15
Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.


How many such routes are there through a 20×20 grid?



**/


#include <stdio.h>

int main(){
  int i,j,x,y;
  long long int mat[21][21]; 

  i=0;
  for (j=0;j<21;j++) 
    mat[i][j]=1; 

  j=0;
  for (i=0;i<21;i++)
    mat[i][j]=1; 

  for (i=1;i<21;i++)
    for (j=1;j<21;j++)
      mat[i][j]=mat[i-1][j]+mat[i][j-1]; 

  for (i=0;i<21;i++){
    for (j=0;j<21;j++)
      printf("%lld ",mat[i][j]); 
    printf("n");
    }

  return 0;
}