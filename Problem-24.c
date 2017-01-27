/**



Problem 24
A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4. If all of the permutations are listed numerically or alphabetically, we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:

012   021   102   120   201   210

What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?


**/


#include stdio.h
#include stdlib.h
#include string.h
#include time.h
#include "utilities.h"

#define DIGITS "0123456789"
#define MAX_PERM 1000000

typedef struct
{
    int list_counter;
    int current_index;
    char **list;
} List;

int resort_digits(char *, char *, char);
void append_permutations(List *, int, int, char *);
void append_to_list(List *, char *);
void expand_list(List *);
void runtests(void);

int main (int argc, char *argv[])
{
    char numstr[] = DIGITS;
    int len = strlen(numstr);
    List *list;
    list = malloc(sizeof(List));
    list->list_counter = 1;
    list->current_index = 0;
    list->list = malloc(sizeof(list->list));
   
    time_t t1, t2;
    time(&t1);
    append_permutations(list, 0, len, numstr);
    int i;
    for (i = 0; i <>current_index; i++)
        if (i == MAX_PERM-1) {
            printf("%s\n", list->list[i]);
            break;
        }
    time(&t2);
    int total_time = difftime(t2, t1);

    printf("%d\n", total_time);

    free(list);
    return 0;
}

void expand_list(List *list) {
    list->list_counter *= 2;
    list->list = realloc(list->list, (list->list_counter * sizeof(list->list)));
}

void append_to_list(List *list, char *string) {
    if (list->current_index == list->list_counter)
        expand_list(list);

    list->list[list->current_index] = malloc(strlen(string) + 1);
    strcpy(list->list[list->current_index], string);
    list->current_index++;
}

int resort_digits(char *source, char *dest, char cremove_digit) {
    int len = strlen(source);
    if (find(source, cremove_digit) == -1)
        return -1;
    char removed[len];
    strremove(removed, source, cremove_digit);
    qsort(removed, strlen(removed), sizeof(char), (void *) strcomp);
    strinsert(dest, removed, 0, cremove_digit);

    return 0;
}

void append_permutations(List *list, int start, int strlen, char *numstr) {
    int remove_digit;
    char cremove_digit;

    for (remove_digit = 0; remove_digit < strlen; remove_digit++) {
        cremove_digit = cchar(remove_digit);

        char partial_end[strlen];
        strcopy(partial_end, numstr, start, strlen);
        char resorted[strlen];
        if (resort_digits(partial_end, resorted, cremove_digit) == -1)
            continue;

        char partial_start[start];
        strcopy(partial_start, numstr, 0, start);
        char new_numstr[strlen];
        strcpy(new_numstr, partial_start);
        strcat(new_numstr, resorted);

        if (start == (strlen-1))
            append_to_list(list, new_numstr);

        if (start < strlen)
            append_permutations(list, start+1, strlen, new_numstr);

    }

}
