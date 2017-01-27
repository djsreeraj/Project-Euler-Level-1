/**

Problem 21
Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.

For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.

Evaluate the sum of all the amicable numbers under 10000.**/


#include <stdio.h>
#include <stdlib.h>
 
unsigned int sum_divisors(unsigned int n) {
    unsigned int s = 0, i = 1;
    while(i < n) {
        if(n % i == 0) s = s + i;
        i++;
    }
    return s;
}
 
unsigned int sum_amicable_pairs(unsigned int low, unsigned int high) {
    unsigned int a = low, b, sum = 0;
    while(a <= high) {
        b = sum_divisors(a);
        if(b > a && sum_divisors(b) == a) sum = sum + a + b;
        a++;
    }
    return sum;
}
 
int main(int argc, char **argv) {
    unsigned int ans = sum_amicable_pairs(1,10000);
    printf("result: %d\n",ans);
    return 0;
}