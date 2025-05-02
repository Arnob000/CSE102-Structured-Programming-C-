#include <stdio.h>
#include <string.h>

int main()
{
    int i,j,k,f,s,l;
    char s1[109]= {0},s2[101]= {0},s3[11]= {0};
    gets(s1);
    gets(s2);
    gets(s3);

    for(i=0; i<strlen(s1)+1; i++)
    {
        if(s1[i]==s2[0])
        {
            for(j=1; j<strlen(s2); j++)
            {
                if(s1[i+j]!=s2[j])
                    break;

            }

            if(j==strlen(s2))
            {
                for(s=0; s<strlen(s2); s++)
                {
                    for(f=i; f<strlen(s1); f++)
                        s1[f]=s1[f+1];

                }
                l=strlen(s3);
                for(s=0; s<l; s++)
                {
                    for(f=strlen(s1); f>=i; f--)
                        s1[f]=s1[f-1];
                    puts(s1);
                }
                for(k=0; k<strlen(s3); k++)
                    s1[i+k]=s3[k];

            }
            i=i+strlen(s3);
        }
    }

    puts(s1);

}
