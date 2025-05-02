#include<stdio.h>
struct comp
{
    float x;
    float y;
};
void print(struct comp x);
struct comp multiply(struct comp x , struct comp y );
struct comp divide (struct comp x , struct comp y );

int main()
{
 struct comp a,b,m,d;
 scanf("%f%f%f%f",&a.x,&a.y,&b.x,&b.y);

    m=multiply(a,b);
    d=divide(a,b);
    print(m);
    print(d);

    return 0;
}
void print(struct comp x)
{
    if(x.y>=0)
    printf("%.2f+%.2fi\n",x.x,x.y);
    else
        printf("%.2f%.2fi\n",x.x,x.y);
}
struct comp multiply(struct comp x , struct comp y )
{
    struct comp ans;
    ans.x=(x.x*y.x)-(x.y*y.y);
    ans.y=(x.x*y.y)+(x.y*y.x);
    return ans;
};
struct comp divide(struct comp x , struct comp y )
{
    struct comp ans,ans2,yc;
    yc.y=y.y*(-1);
    yc.x=y.x;
    ans=multiply(x,yc);
    ans2=multiply(y,yc);
    ans.x=ans.x/ans2.x;
    ans.y=ans.y/ans2.y;
    return ans;
};
