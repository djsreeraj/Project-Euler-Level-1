/**
Problem 6
The sum of the squares of the first ten natural numbers is,

12 + 22 + ... + 102 = 385
The square of the sum of the first ten natural numbers is,

(1 + 2 + ... + 10)2 = 552 = 3025
Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

**/


#include<stdio.h>
#include<conio.h>
#include<time.h>

int main()
{
                long n=100,a=0,b=0;
                int i;
               
                for(i=1;i<=n;i++)
                                a=a+i;
                a=a*a;

                for(i=1;i<=n;i++)
                                b=b+(i*i);

                printf("Answer = %ld\n",(a-b));
                printf("EXECUTION TIME = %f",clock()/(float)CLK_TCK);
                system("pause");
}