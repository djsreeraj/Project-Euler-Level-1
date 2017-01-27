/**

Problem 5
Published on Friday, 30th November 2001, 06:00 pm; Solved by 340353; Difficulty rating: 5%
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

**/

#include<conio.h>
#include<time.h>
long lcm(long, long );

void main()
{
                long upperlimit=20;
                long ans=1;
                long i;
                for(i=1;i<=upperlimit;i++)
                {
                                ans=lcm(i,ans);
                }

                printf("%ld\n",ans);
                printf("%d * %d = %ld\n",x,y,(max));
                system("pause");
}


long lcm(long a, long b)
{
                long min,max,i;
                min=(a>b)?b:a;
                max=(a<b)?b:a;
                               
                for(i=max;i<=min*max;i++)
                {
                                if(i%max==0&&i%min==0)
                                                return i;

                }
}