/**


Problem 10
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.


**/

#include<stdio.h>
#include<time.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

int isprime(long);
int main()
{
                long i;
                double sum=0;
                for (i = 2; i < 2000000; i++)
                {
                                if(isprime(i))
                                                sum+=i;
                }
                printf("\n%f\n",sum);
                printf("EXECUTION TIME = %f",((float)clock()/CLK_TCK));
                system("pause");
}

int isprime(long num)
{
                long i;
                for(i=2;i<=sqrt(num);i++)
                                if(num%i==0)
                                                return 0;
                return 1;
}