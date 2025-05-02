#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *prepend(char *s,char *t,int pos);


int main()
{
    char *a,*b,*c;
    a=(char*)malloc(100*sizeof(char));
    b=(char*)malloc(100*sizeof(char));

    gets(a);
    gets(b);
    int n;
    scanf("%d",&n);



    c=prepend(a,b,n);
    puts(c);


    free(a);
    free(b);
    free(c);

    return 0;
}
char *prepend(char *s,char *t,int pos)
{
    int i;
    i=strlen(s)+strlen(t)-pos;
    char *z;
    z=(char*)malloc((i+1)*sizeof(char));

    z=(s+pos);
    s=s+strlen(s);
    while(*t)
    {
        *s++=*t++;
    }
    *s='\0';



    return z;
}

