#include <stdio.h>
#include <conio.h>

void printBits(int x)
{
    int i;
    int mask = (1 << 31);
    for (i = 0; i < 32; i++)
    {
        printf("%d", ((x & mask) ? 1 : 0));
        x <<= 1;
    }
}

int main()
{
    while(EOF != scanf("%d", &x))
    {
        printBits((unsigned)~0 >> 1);
        printf("\n%d\n", (unsigned)~0 >> 1);
    }

    return 0;
}
