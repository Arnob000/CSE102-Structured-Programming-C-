#include<stdio.h>

int main()
{
    int n,j,i;
    scanf("%d",&n);
    printf("*");
    for(i=1;i<n;i++){

        printf("\n*");
        for(j=0;j<i;j=j+2)
            printf("-");
        printf("*");
    }
    for(i=n-1;i>0;i--){
         printf("\n*");
        for(j=0;j<i;j=j-2)
            printf("-");
        printf("*");
    }

    printf("\n*");
    return 0;
}
