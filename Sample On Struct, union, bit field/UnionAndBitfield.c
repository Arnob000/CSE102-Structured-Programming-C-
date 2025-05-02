//
// Author: Saifur Rahman
// Last Modified: 25 NOV 2019
//
#include <stdio.h>
#include <string.h>

typedef struct {
    unsigned roll: 20;
    unsigned subject: 4;
    unsigned score: 8;
} Encoding;

typedef union {
    Encoding x;
    int y;
} U;

int main()
{
    printf("%d\n", sizeof(Encoding));

    U u;

    u.x.roll = 98002;
    u.x.score = 248;
    u.x.subject = 14;
    printf("%u\n", u.y);

    return 0;
}
