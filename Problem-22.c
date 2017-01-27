/**


Problem 22
Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.

For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.

What is the total of all the name scores in the file?**/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#include<string.h>
void sort(char**,int);

int main()
{
                FILE *f;
                char c,**str;
                double sum=0;
                long sum1=0;
                int counter=1,i,j,max=0,flag=0; // counter contains the total number of names in the file
                f=fopen("D:/f.txt","r");
                //here f.txt contains all the names given in names.txt
                if(!f)
                                printf("\nTHE FILE OPERATION WAS NOT SUCCESSFUL !\n");
                else
                {
                                while(!feof(f))
                                {
                                               
                                                fscanf(f," %c",&c);
                                                if(c==',')
                                                {
                                                                if(flag>max)
                                                                                max=flag;
                                                                flag=0;
                                                                counter++;
                                                }
                                                else
                                                                flag++;
                                }
                                max-=2;
                               
                                str=(char**)malloc(sizeof(char*)*counter);
                                for(i=0;i<counter;i++)
                                                str[i]=(char*)malloc(sizeof(char)*max);

                                // counter contains the total number of names in the file
                                // max contains number of characters in the longest name
                               
                                i=0;j=0;
                                rewind(f);
                                while(!feof(f))
                                {
                                                fscanf(f," %c",&c);
                                                if(c==',')
                                                {
                                                                str[i][j]='\0';
                                                                i++;j=0;
                                                                continue;
                                                }
                                                if(c=='\"')
                                                                continue;

                                                str[i][j++]=c;
                                }
                                str[i][j]='\0';
                               
                                sort(str,counter);
                               
                                sum=0;
                                for(i=0,j=0;i<counter;i++,j=0)
                                {
                                                sum1=0;
                                                while(str[i][j])
                                                {
                                                                sum1=sum1+(int)str[i][j]-64;
                                                                j++;
                                                }
                                                sum+=(i+1)*sum1;
                                }

                                printf("Answer = %f",sum);
                }
               
             
}


void sort(char**str,int counter)
{
                int i,j;
                char*tmp;
                for(i=1;i<counter;i++)
                {
                                for(j=0;j<counter-i;j++)
                                {
                                                if(strcmp(str[j],str[j+1])>0)
                                                {
                                                                tmp=str[j];
                                                                str[j]=str[j+1];
                                                                str[j+1]=tmp;
                                                }
                                }
                }
}