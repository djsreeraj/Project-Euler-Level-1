/**

Problem 19
You are given the following information, but you may prefer to do some research for yourself.

1 Jan 1900 was a Monday.
Thirty days has September,
April, June and November.
All the rest have thirty-one,
Saving February alone,
Which has twenty-eight, rain or shine.
And on leap years, twenty-nine.
A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?



**/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

long count_sunday(long,long,long);

void main()
{
       long i,j,counter=0;
       for(i=1901;i<2001;i++)
              for(j=1;j<=12;j++)
                     if(count_sunday(1,j,i))
                           counter+=count_sunday(1,j,i);
       printf("\nNumber of sundays = %ld\n",counter);
       printf("\nEXECUTION TIME = %f\n",clock()/(float)CLK_TCK);
       system("pause");
}


long count_sunday(long d2,long m2,long y2)
{
       long int d,m,y,d1,m1,y1,tot,lavish,i,counter=0;

       d1=1;
       m1=1;
       y1=0;

       y=y2-y1;
       m=m2-m1;
       d=d2-d1;

       tot=y*365+m*30+d;

       if(m2>2)
       {
              for(i=y1;i<=y2;i++)
              {
                     if(i%4==0)
                           tot++;

                     if(i%100==0)
                           if(i%400!=0)
                                  tot--;
              }
       }
       else
       {
              for(i=y1;i<y2;i++)
              {
                     if(i%4==0)
                           tot++;

                     if(i%100==0)
                           if(i%400!=0)
                                  tot--;
              }
       }


       if(m2>m1)
       {
              for(i=m1;i<m2;i++)
              {
                     if(i==1||i==3||i==5||i==7||i==8||i==10||i==12)
                           tot++;

                     if(i==2)
                           tot=tot-2;
              }
       }

       lavish=tot%7;

       if(lavish==1)
       {
              return 1;
       }
       return 0;
}