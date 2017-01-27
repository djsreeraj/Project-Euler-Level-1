/**

Problem 20
n! means n × (n − 1) × ... × 3 × 2 × 1

For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

Find the sum of the digits in the number 100!

**/

#include <stdio.h>

#define MAX 500

int main(){
int vet[MAX]={0};
int i,x,y,v,f,sum;

vet[0]=1;
y=2;

while (y<101){
  v = 0;
  for (i=0;i<MAX;i++){
    x = vet[i]*y + v;
    v = 0;
    if (x > 9){
      f = x % 10;
      v = x / 10;      
    }
    else
      f = x;
    vet[i] = f;
  }
  y++;
}
sum=0;
for (i=MAX-1;i>=0;i--)
  sum=sum+vet[i];
printf("%dn",sum);
return 0;
}