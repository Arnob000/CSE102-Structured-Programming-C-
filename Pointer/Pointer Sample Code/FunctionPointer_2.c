//
// Author: Saifur Rahman
// Last Modified: 10 JUL 2019
//
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void print(int x[], int count)
{
    int i;

    for (i = 0; i < count; i++)
    {
        printf("%d ", *x++);
    }
    printf("\n");
}

int larger(int a, int b) {
    return a > b;
}

int smaller(int a, int b) {
    return a < b;
}

//
// Returns true if
//  a is odd and b is even OR
//  a and b are both odd (or even) but a is larger than b
//
// This is a comparator function for sorting such that
//  All odd numbers come at the front of the array.
//  Within odd (or even) number blocks, increasing order is maintained
//
int customcmp(int a, int b) {
    if (a%2 == 0 && b%2 != 0)
        return 1;
    if (a%2 != 0 && b%2 == 0)
        return 0;

    return larger(a, b);
}

//
// Implements bubble sort algorithm.
// The ordering criteria is decided by the passed in comparison function
//
void sort(int x[], int n, int (*cmp)(int, int)) {
    int i, j;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (cmp(x[j], x[j+1])) {
                swap(&x[j], &x[j+1]);
            }
        }
    }
}

//
// Comparator for qsort library function for increasing order sorting
// Home work: Find out how it works.
//
int qsort_cmp(const void *a, const void *b) {
    return *((int *)a) - *((int *)b);
}

int main()
{
    int i, n, data[100], j = 0;
    int a, b;

    int (*cmp[])(int, int) = {
        smaller,
        larger,
        customcmp
    };

    while(1 == scanf("%d", &n)) {
        for (i = 0; i < n; i++) {
            scanf("%d", &data[i]);
        }
//        sort(data, n, cmp[j++%3]);
//        print(data, n);

        //
        // Comment out the above 2 lines and uncomment the below 2 lines
        // This is using the qsort library function for efficient sorting.
        // But the comparator is provided by the caller. Investigate how
        // it works, what are the parameters etc. Then try to do the custom sorting
        // (i.e. odd numbers come ahead in the array, then odd and even blocks within
        // themselves are sorted in increasing order) using the qsort() function call
        //

        qsort(data, n, sizeof(data[0]), qsort_cmp);
        print(data, n);
    }
    return 0;
}
