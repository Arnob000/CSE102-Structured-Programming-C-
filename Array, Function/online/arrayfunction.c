#include<stdio.h>

int binary(int a);
int factor(int a);

int main()
{
    int n,i,t,f,g;
    scanf("%d",&n);
    int a[1000];
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int b[1000],x;
    for(i=0;i<n;i++){
        x=a[i];
        b[i]=binary(x);
    }
    for(i=0;i<n;i++){
        int min,j;
        min=i;
        for(j=1;j<n;j++){
            if(b[min]>b[j])
                min=j;
            else if(b[min]=b[j]){
                    int y,z;
                    y=b[min];
                    z=b[j];
                    f=factor(y);
                    g=factor(z);
                    if(f<g)
                        min=j;
                    else if(f=g){
                        if(b[min]>b[j])
                                min=j;

                    }

                    }

    }
        t=a[min];
        a[min]=a[i];
        a[i]=a[min];

    }

    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}

int binary(int a){
    int c=0;
    while(a!=0){
        if(a%2)
            c++;
        a=a/2;
    }
    return c;

}

int factor(int a){
    int i,c=0,d=0;
    for (i=1;i<=a;i++){
        if(a%i==0)
            c++;
    }
    return c;
}
