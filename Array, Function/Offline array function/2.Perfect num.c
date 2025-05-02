#include<stdio.h>

int perfect(int a){      //function for perfect number
    int i,s=0;

    for(i=1;i<a;i++){
        if(a%i==0){
            s=s+i;
        }
    }
    if(a==s)
       return 1;
    else
       return 0;

}

int main()
{
    int n,j,sum=0,p;
    scanf("%d",&n);

    for(j=1;j<=n;j++){
        p=perfect(j);         //send num to function upto n
        if(p==1)
            sum=sum+j;         //sum of perfect num

    }
    printf("%d",sum);

    return 0;
}

