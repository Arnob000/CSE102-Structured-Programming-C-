#include <stdio.h>
#include <math.h>

int main ()
{
    int x,y,r,x1,y1;
    float a;
    printf("Enter center(x,y):");
    scanf("%d%d",&x,&y);
    printf("Enter radius:");
    scanf("%d",&r);
    printf("Enter a point(x,y):");
    scanf("%d%d",&x1,&y1);
    a=sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1));
    if(a>r)
        printf("Outside the circle");
    else if(a==r)
        printf("On the circle");
    else
        printf("Inside the circle");

    return 0;
}
