#include<stdio.h>
#include<string.h>


int StrSec(char a[],int a1,char b[], int b1,int sc,int i)
{
    int t=0;
    if(sc==b1)
    {
        t=1;
        return t;
    }
    else
        for(i; i<a1; i++)
        {
            if(a[i]==b[sc])
            {
                t=StrSec(a,a1,b,b1,sc+1,i+1);
            }
            else if(a[i]!=b[sc])
                return;
        }

}

int main()
{
    char s1[30],s2[30];
    gets(s1);
    gets(s2);
    int r=0;

    r=StrSec(s1,strlen(s1),s2,strlen(s2),0,0);

    printf("%d",r);



}
