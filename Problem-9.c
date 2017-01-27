/**
Problem:9

		A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,

		a^2 + b^2 = c^2
		For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.

		There exists exactly one Pythagorean triplet for which a + b + c = 1000.
		Find the product abc.


**/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

void main()
{
                float i,j,k;
                for(i=1;i<1000;i++)
                                for(j=1;j<1000;j++)
                                                for(k=1;k<1000;k++)
                                                                if((i+j+k)==1000&&(k*k==i*i+j*j))
                                                                {
                                                                                printf("%f\n",(i*j*k));
                                                                               
                                                                                return;
                                                                }
}

