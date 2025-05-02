#include<stdio.h>

int main()
{
    int a,b,lcm,c;
    scanf("%d",&a);
    scanf("%d",&b);
    lcm=a*b;
    while(lcm<10000){
            c=lcm;
        scanf("%d",&b);
        while(lcm%b!=0&&lcm%c!=0){

        lcm++;
        printf("lcm=%d",lcm);
    }

}
}
