#include<stdio.h>

int main()
{
    int h,w,i,j;
    scanf("%d",&h);
    scanf("%d",&w);

    for(i=1;i<=2*h;i++){

        for(j=1;j<=w;j++)
            printf("*");
            printf("\n");

    }
}

