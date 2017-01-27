/**

Problem 18
By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.

3
7 4
2 4 6
8 5 9 3

That is, 3 + 7 + 4 + 9 = 23.

Find the maximum total from top to bottom of the triangle below:

75
95 64
17 47 82
18 35 87 10
20 04 82 47 65
19 01 23 75 03 34
88 02 77 73 07 63 67
99 65 04 28 06 16 70 92
41 41 26 56 83 40 80 70 33
41 48 72 33 47 32 37 16 94 29
53 71 44 65 25 43 91 52 97 51 14
70 11 33 28 77 73 17 78 39 68 17 57
91 71 52 38 17 14 91 43 58 50 27 29 48
63 66 04 68 89 53 67 30 73 16 69 87 40 31
04 62 98 27 23 09 70 98 73 93 38 53 60 04 23

NOTE: As there are only 16384 routes, it is possible to solve this problem by trying every route. However, Problem 67, is the same challenge with a triangle containing one-hundred rows; it cannot be solved by brute force, and requires a clever method! ;o)

**/



#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

int get_sum(int *);

int main()
{
       FILE *f;
       int arr[15][15],max1[15],max2[15],i=0,j=0,maximum=0;
      
       f=fopen("D:/d.txt","r");
       i=0;
       for(i=0;i<15;i++)
              for(j=0;j<=i;j++)
              {
                     fscanf(f,"%d",&arr[i][j]);
              }

       for(i=0;i<15;i++)
       {
              for(j=0;j<=i;j++)
              {
                     if(i==0)
                     {
                           max1[j]=arr[i][j];
                           continue;
                     }
                     else if((j-1)<0)
                     {
                           max2[j]=arr[i][j]+max1[j];
                     }
                     else if(j==i)
                           max2[j]=arr[i][j]+max1[j-1];
                     else
                           max2[j]=arr[i][j]+((max1[j-1]>max1[j])?max1[j-1]:max1[j]);          
              }

              if(i==0)
                     continue;
                    
              for(j=0;j<=i;j++)
                     max1[j]=max2[j];

       }
      
       for(i=0;i<15;i++)
              if(maximum<max2[i])
                     maximum=max2[i];
       printf("Answer = %d\n\n",maximum);
      
       printf("\nEXECUTION TIME = %f\n",clock()/(float)CLK_TCK);
       system("pause");
}