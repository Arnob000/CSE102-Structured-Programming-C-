#include<stdio.h>
#include<string.h>

void Out(int arr[][5],int r,int c);
void Add(int a1[][5],int r,int c,int a2[][5]);
void Sub(int a1[][5],int r,int c,int a2[][5]);
void Div(int ar[][5],int r,int c,int n);
void Trans (int arr[][5],int r,int c);
void Mul(int r,int m,int c,int arr[][5],int brr[][5]);
void Det(int arr[][5],int r);

int main()
{
    int a[5][5]= {0};
    int b[5][5]= {0};
    int i,j,ar=0,ac=0,br=0,bc=0,n=0;
    char s[10];

    do
    {
        gets(s);
        strlwr(s);

        for(i=0; i<=strlen(s); i++)
        {
            if(s[i]==' ')
            {
                for(j=i+1; j<=strlen(s); j++)
                    s[j-1]=s[j];
            }

        }

        if(!strcmp(s,"ina"))
        {
            scanf("%d%d",&ar,&ac);
            for(i=0; i<ar; i++)
                for(j=0; j<ac; j++)
                    scanf("%d",&a[i][j]);
        }
        else if(!strcmp(s,"inb"))
        {
            scanf("%d%d",&br,&bc);
            for(i=0; i<br; i++)
                for(j=0; j<bc; j++)
                    scanf("%d",&b[i][j]);
        }
        else if(!strcmp(s,"outa"))
        {

            Out(a,ar,ac);
        }

        else if(!strcmp(s,"outb"))
        {
            Out(b,br,bc);
        }
        else if(!strcmp(s,"a+b"))
        {
            if(ar==0&&ac==0)
            {
                printf("MAT A not found,");
                continue;

            }
            else if(br==0&&bc==0)
            {
                printf("MAT B not found,");
                continue;

            }


            else if((ar!=br) || (ac!=bc))
            {

                printf("Addition not possible");
                continue;

            }
            else
                Add(a,ar,ac,b);
        }
        else if(!strcmp(s,"b+a"))
        {
            if(ar==0&&ac==0)
            {
                printf("MAT A not found,");
                continue;

            }
            else   if(br==0&&bc==0)
            {
                printf("MAT B not found,");
                continue;

            }

            else  if((ar!=br) || (ac!=bc))
            {
                printf("Addition not possible");
                continue;

            }
            else
                Add(b,br,bc,a);
        }
        else if(!strcmp(s,"a-b"))
        {
            if(ar==0&&ac==0)
            {
                printf("MAT A not found,");
                continue;

            }
            else if(br==0&&bc==0)
            {
                printf("MAT B not found,");
                continue;

            }

            else  if((ar!=br) || (ac!=bc))
            {
                printf("Subtraction not possible");
                continue;

            }
            else
                Sub(a,br,bc,b);
        }
        else if(!strcmp(s,"b-a"))
        {
            if(ar==0&&ac==0)
            {
                printf("MAT A not found,");
                continue;

            }
            else if(br==0&&bc==0)
            {
                printf("MAT B not found,");
                continue;

            }
            else  if((ar!=br) || (ac!=bc))
            {
                printf("Subtraction not possible");
                continue;

            }
            else
                Sub(b,br,bc,a);
        }
        else if(!strcmp(s,"a/n"))
        {
            scanf("%d",&n);
            if(n)
                Div(a,ar,ac,n);
            else printf("Division not possible");
        }
        else if(!strcmp(s,"b/n"))
        {
            scanf("%d",&n);
            if(n)
                Div(b,br,bc,n);
            else printf("Division not possible");
        }

        else if(!strcmp(s,"a*b"))
        {
            if(ac!=br)
            {

                printf("Multiplication not possible ");
                continue;
            }
            else
                Mul(ar,ac,bc,a,b);
        }
        else if(!strcmp(s,"b*a"))
        {
            if(bc!=ar)
            {
                printf("Multiplication not possible ");
                continue;
            }
            else
                Mul(br,bc,ac,b,a);
        }
        else if(!strcmp(s,"transa"))
        {
            Trans(a,ar,ac);
        }
        else if(!strcmp(s,"transb"))
        {
            Trans(b,br,bc);
        }
        else if(!strcmp(s,"deta"))
        {
            if(ar!=ac)
            {

                printf("Determinant not possible ");
                continue;
            }
            else
                Det(a,ar);
        }
        else if(!strcmp(s,"detb"))
        {
            if(br!=bc)
            {
                printf("Determinant not possible ");
                continue;
            }
            else
                Det(b,br);
        }


    }
    while(strcmp(s,"exit"));

    return 0;

}

void Out(int arr[][5],int r,int c)
{
    int i,j;
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
            printf("%d ",arr[i][j]);
        printf("\n");
    }

}


void Add(int a1[][5],int r,int c,int a2[][5])
{
    int i,j;
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
            printf("%d ",a1[i][j]+a2[i][j]);

        printf("\n");
    }
}

void Sub(int a1[][5],int r,int c,int a2[][5])
{
    int i,j;
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
            printf("%d ",a1[i][j]-a2[i][j]);

        printf("\n");
    }
}

void Div(int ar[][5],int r,int c,int n)
{
    int i,j;

    float dr[5][5]= {0};
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            dr[i][j]=1.0*ar[i][j]/n;
            printf("%0.2f ",dr[i][j]);

        }
        printf("\n");
    }
}


void Trans (int arr[][5],int r,int c)
{
    int brr[5][5],i,j;
    for(i=0; i<r; i++)
        for(j=0; j<c; j++)
            brr[j][i]=arr[i][j];
    if(r==c)
    {
        for(i=0; i<r; i++)
        {
            for(j=0; j<c; j++)
                printf("%d ",brr[i][j]);
            printf("\n");
        }
    }
    else
    {
        for(i=0; i<c; i++)
        {
            for(j=0; j<r; j++)
                printf("%d ",brr[i][j]);
            printf("\n");
        }
    }
}

void Mul(int r,int m,int c,int arr[][5],int brr[][5])
{
    int i,j,k;
    int z[5][5]= {0};

    for(i=0; i<r; i++)
        for(j=0; j<c; j++)
            for(k=0; k<m; k++)
                z[i][j]=z[i][j]+arr[i][k]*brr[k][j];


    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
            printf("%d ",z[i][j]);

        printf("\n");
    }

}

void Det(int arr[][5],int r)
{
    int i,j,m=1,s=0,ss=0,x;
    for(j=0; j<r; j++)
    {
        x=j;
        for(i=0; i<r; i++)
        {
            if((i+x)>=r)
            {
                m=m*arr[i][i+x-r];
            }
            else
                m=m*arr[i][i+x];
        }
        s+=m;
        m=1;
    }

    for(j=0; j<3; j++)
    {
        x=j;
        for(i=0; i<r; i++)
        {
            if((i+x)>=r)
            {
                m=m*arr[r-1-i][i+x-r];
            }
            else
                m=m*arr[r-1-i][i+x];
        }
        ss+=m;
        m=1;
    }

    printf("%d",s-ss);

}
