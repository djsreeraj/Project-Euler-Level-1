/**


Problem 17
If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?


NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.


**/

#include <stdio.h>
#include <string.h>

#define HUNDRED_AND 10
#define HUNDRED 7
#define ONE_THOUSAND 11

char *first[10] = { "", "one", "two", "three", "four", "five",
                        "six", "seven", "eight", "nine" };
char *teens[10] = { "ten", "eleven", "twelve", "thirteen", "fourteen", 
                    "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
char *tens[10] = { "", "ten", "twenty", "thirty", "forty", "fifty",
                       "sixty", "seventy", "eighty", "ninety" };

int lesshun(int x)
{
    if (x < 10) return strlen(first[x]);
    else if (x < 20) return strlen(teens[x % 10]);
    else if (x % 10) return strlen(tens[x / 10]) + strlen(first[x%10]);
    else return strlen(tens[x/10]);
}

int main(void)
{
  long answer = 0;

  for (int i = 1; i < 1001; i++) {
    if (i < 100) {
      answer += lesshun(i);
    } else if (i < 1000) {
      if (i % 100) {
        answer += strlen(first[i / 100]) + HUNDRED_AND + lesshun(i % 100);
      } else {
        answer += strlen(first[i / 100]) + HUNDRED;
      }
    } else {
      answer += ONE_THOUSAND;
    }
  }
  printf("Problem 17 Answer: %ld\n", answer);
}