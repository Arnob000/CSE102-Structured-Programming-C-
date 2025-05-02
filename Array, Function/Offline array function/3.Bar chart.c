#include<stdio.h>

int main()
{
    int n,i,j;
    scanf("%d",&n);

    int a[100];

    for(i=0;i<n;i++)
        scanf("%d",&a[i]);       //array input

    int max;
    max=a[0];

    for(i=1;i<n;i++){            //find max input
        if(max<a[i])
            max=a[i];
    }

    for(i=max;i>0;i--){          //row=max
        for(j=0;j<n;j++){        //col=n
            if(a[j]<i)           //array value < row then space
                printf("  ");
            else                 //array value >= row then **
                printf("**");

            printf(" ");
        }

        printf("\n");
    }

    return 0;
}
