/**

Problem 23
A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.

A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.

As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24. By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers. However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.

Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.

**/



#include<stdio.h>

int factorsum(int);
int main()
{
    int i, j, s = 0, t, m;
    for (i = 24; i <= 28123; i++)   //sum of 2abundant nos start from 24
    {
        for (j = 12; j <= i / 2; j++) {
            t = factorsum(j);
            if (t > j) {
                m = i - j;
                t = factorsum(m);
                if (t > m) {
                    s = s + i;
                    break;
                }
            }
        }

    }
    j = 0;
    for (i = 1; i <= 28123; i++)
        j = j + i;
    printf("\n%d", (j - s));
    return 0;
}

int factorsum(int j)        //checking sum of factors
{
    int k, s = 0;
    for (k = 1; k <= (j / 2); k++) {
        if (j % k == 0) {
            s = s + k;
        }
    }
    return s;
}