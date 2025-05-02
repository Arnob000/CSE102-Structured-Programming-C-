#include<stdio.h>
#include<math.h>

int main()
{
    float x,s=0;
    int i,n,j,f=1;
    printf("Enter x:");
    scanf("%f",&x);
    x=3.1416*x/180;

    for(i=1;i<=30;i=i+2){

            for(j=1;j<=i;j++){
            f=f*j;
            }
        s=pow(-1,i-1)*pow(x,i)/f;
    }
    printf("sinx=%f",s);

    return 0;
}
