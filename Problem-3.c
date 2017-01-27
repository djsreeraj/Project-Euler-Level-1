/**

Problem 3
The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?


**/
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<time.h>
int isprime(long);

int main()
{
                long i;
                for(i=(long)sqrt(600851475143);i>=2;i--)
                {
                                if(isprime(i)&&(600851475143%i==0))
                                {
                                                printf("%ld\n",i);
                                                break;
                                }
                }
                printf("EXECUTION TIME = %f",clock()/(float)CLK_TCK);
                system("pause");
}

int isprime(long num)
{
                long i;
                for(i=2;i<=(long)sqrt(num);i++)
                                if(num%i==0)
                                                return 0;
                return 1;

}