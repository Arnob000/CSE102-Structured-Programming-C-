#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <string.h>

typedef unsigned int type_t;

void printBits(char *prefix, type_t x, char *suffix)
{
    int i;
    int nBits = sizeof(x)*8;
    type_t mask = ((type_t)1 << (nBits-1));
    printf("%s", prefix);
    for (i = 0; i < nBits; i++)
    {
        printf("%d", ((x & mask) ? 1 : 0));
        x <<= 1;
    }
    printf("%s", suffix);
}

int main()
{
    char cmd[10];
    int iVal, *pInt;
    float fVal, *pFloat;
    int exp, sign, mantissa;

    while (EOF != scanf("%s", cmd) || 0 != strcmp(cmd, "quit")) {
        if (0 == strcmp(cmd, "int")) {
            scanf("%u", &iVal);
            pInt = &iVal;
            pFloat = (float*)&iVal;
        } else if (0 == strcmp(cmd, "float")) {
            scanf("%f", &fVal);
            pInt = (int*)&fVal;
            pFloat = &fVal;
        } else {
            printf("Unknown command!!\n");
            continue;
        }

        mantissa = *pInt & ((unsigned)~0 >> 9) | ((!!(*pInt<<1))<<23);
        mantissa = *pInt & ((unsigned)~0 >> 9) | (1<<23);
        sign = *pInt & 1<<31;
        exp = *pInt & ((unsigned char)~0 << 23);

        printBits("Bits    : ", *pInt, "\n");
        printBits("SignBit : ", sign, "\n");
        printBits("Exponent: ", exp, "\n");
        printBits("Mantissa: ", mantissa, "\n");

        sign = !!sign;
        exp  = (exp>>23) - 127;
        printf("%d %d %d\n", sign, exp, mantissa);

        float computed = pow(-1, sign) * pow(2, exp - 23) * mantissa;
        printf("Original float: %g\n", *pFloat);
        printf("Computed float: %g\n", computed);
    }

    return 0;
}
