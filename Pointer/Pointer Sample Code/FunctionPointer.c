//
// Author: Saifur Rahman
// Last Modified: 22 DEC 2015
//
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct _Student
{
    int roll;
    double score;
} Student;

//
// Comparison function that is passed as the 4th parameter
// to qsort() function
//
int cmp(const void *pA, const void *pB)
{
    return (*((Student*)pA)).roll - (*((Student*)pB)).roll;
}

int main()
{
    int i;

    Student a[] = {
        {15, 80},
        {68, 82},
        {112, 80},
        {85, 70},
        {77, 80},
        {99, 68}
    };

    Student b = {77, 0};
    Student *p = NULL;

    qsort(a, sizeof(a)/sizeof(a[0]), sizeof(a[0]), cmp);  
    for (i = 0; i < sizeof(a)/sizeof(a[0]); i++)
        printf("<%d, %0.2lf> ", a[i].roll, a[i].score);

    

    p = bsearch(&b, a, sizeof(a)/sizeof(a[0]), sizeof(a[0]), cmp);
    if (p)
        printf("\nFOUND: <%d, %0.2lf> ", p->roll, p->score);

    getch();
    return 0;
}

