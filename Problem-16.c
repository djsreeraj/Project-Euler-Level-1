/**



	Problem 16
215 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

What is the sum of the digits of the number 21000?



**/


#include <stdio.h>
#define SIZE  500
#define POWER  1000


int main (void)
{
 int digits[SIZE] = {0};
 int high_order = 0;
 int i = 1;
 int sum = 0;


 /* 
  Could start from the maximum 64 bit integer to save 
  some calculations but I do not do so here.
 */


 digits[0] = 1;


 for (i = 1; i <= POWER; i++)
 {
  int j;
  int carry = 0;
  int product = 1;


  for (j = 0;  j <= high_order; j++)
  {
   product = (digits[j] << 1) + carry; 
   digits[j] = product % 10;
   carry = product / 10; 


   if ( ( carry != 0 ) && ( j == high_order ) )
    high_order++;
  }
 }


 for (i = 0; i <= high_order; i++)
  sum += digits[i];


 printf("Sum is %d\n", sum);
 return 1;
}