#include <stdio.h>

int main()
{
    int a,b,c,a1,b1,c1;
    float x,y;
    printf("Enter integers(a,b,c):");
    scanf("%d%d%d",&a,&b,&c);
    printf("\nEnter integers(a1,b1,c1):");
    scanf("%d%d%d",&a1,&b1,&c1);

    x=(1.0*b*c1-b1*c)/(a*b1-a1*b);
    y=(1.0*c*a1-a*c1)/(a*b1-a1*b);

    if(a1!=0&&b1!=0&&c1!=0&&(a/a1==b/b1&&a/a1==c/c1))
        printf("Does not intersect.");
    else if(a1!=0&&b1!=0&&c1!=0&&(a/a1==b/b1&&a/a1!=c/c1))
        printf("Does not intersect.");
    else if((a==0&&a1==0)||(b==0&&b1==0))
        printf("Does not intersect.");
    else if((a==0&&b==0)||(a1==0&&b1==0))
        printf("Does not intersect.");

    else{

        printf("x=%.3f\ny=%.3f",x,y);
    }

    return 0;


}
