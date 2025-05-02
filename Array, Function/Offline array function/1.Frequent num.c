#include<stdio.h>

int main()
{
    int n,i,x,j,count=0;
    int a[20000]={0};       //for num
    int c[20000]={0};       //for counter

    scanf("%d",&n);
    scanf("%d",&a[0]);
    c[0]++;
    printf("Most frequent number =%d",a[0]);

    for(i=1;i<n;i++){       //input n-1 num
        printf("\n");
        scanf("%d",&x);

        for(j=0;j<i;j++){   //check new num=previous?
            if(x==a[j]){
                c[j]++;
                count++;
                }
        }

        if(count==0){       //new num!=previous?
                a[i]=x;
                c[i]++;
            }

        int max=0,k;
        for(k=1;k<=i;k++){   //max of counter
            if(c[max]<c[k])
                max=k;
        }

        printf("Most frequent number =");
        int f=0;
        for(j=0;j<=i;j++){
            if(c[max]==c[j] && f==0){     //for 1st freq. num
                    printf("%d",a[j]);
                    f++;
            }

            else if(c[max]==c[j] && f)     //for rest others
                    printf(", %d",a[j]);

        }

        count=0;
    }

    return 0;
}
