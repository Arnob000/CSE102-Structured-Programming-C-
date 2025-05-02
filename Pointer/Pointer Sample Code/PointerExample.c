//
// %p. Can you put value in pointer without first assigning it?
// +, ++, -, --
// p++, *p++, (*p)++
// *p++ increments the pointer, not the value
// Using array indexing like approach.
// pointer comparison, using relop
// pass and return pointer to/from function
// dynamic memory allocation



#include <stdio.h>

int isPalindrome(int *start, int *end)
{
    //
    // Home work.
    // Detect whether an passed in integer array is palindrome or not.
    // A palindrome is a set of elements that look the same from either directions.
    // (E.g.: {1 2 8 4 8 2 1}, {9, 7, 4, 2, 2, 4, 7, 9}.
    //
    // Pass from main the address of first and last position of the array.
    // Then implement this function, so that it returns 1 if the array is a palindrome.
    //
    return 0;
}

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
        // Can you change the below line to use the array indexing style?
        // x++ --> x = x+1;
        printf("%d ", *x++);
    }
    printf("\n");
}

int main()
{
    int x, y[15]={0}, z[10] = {1,2,3,4,5,6,7,8,9,10};
    int *p = NULL;

    printf("Size of pointer is %d bytes\n", sizeof p);
    printf("%p\n", p);
    p = &x;
    printf("%p %p\n", p, p+1);

    print(y, sizeof(y)/sizeof(y[0])); // Why are we using the sizeof operators and the division?
    print(&z[0], 10);
    print(z+5, 3);

    return 0;
}
