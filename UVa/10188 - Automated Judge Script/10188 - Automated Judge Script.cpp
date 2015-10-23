#include<stdio.h>
#include<string.h>

int main()
{
   // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);

    char standard[101][125],input[101][125],numeric1[101][125],numeric2[101][125];
    int n1,n2,i,j,k,a=0,n;

    while(scanf("%d",&n1)==1)
    {
        getchar();
        if(!n1)break;

        memset(standard,0,sizeof(standard));
        memset(input,0,sizeof(input));
        memset(numeric1,0,sizeof(numeric1));
        memset(numeric2,0,sizeof(numeric2));

        for(i=0;i<n1;i++)
        {    gets(standard[i]);

        }
        scanf("%d",&n2);
        getchar();
        for(i=0;i<n2;i++)
        {
            gets(input[i]);

        }
        if(n1>n2)
            n=n1;
        else
            n=n2;

        a++;

        for(i=0;i<n;i++)
        {
            if(strcmp(standard[i],input[i])!=0)
                break;
        }

        if(i==n)
        {
            printf("Run #%d: Accepted\n",a);
            continue;
        }


        for(i=0;i<n1;i++)
        {
            k=0;
            for(j=0;j<strlen(standard[i]);j++)
            {
                if(standard[i][j]>='0' && standard[i][j]<='9')
                {
                    numeric1[i][k++]=standard[i][j];
                }
            }
            numeric1[i][k]=0;
        }

        for(i=0;i<n2;i++)
        {
            k=0;
            for(j=0;j<strlen(input[i]);j++)
            {
                if(input[i][j]>='0' && input[i][j]<='9')
                {
                    numeric2[i][k++]=input[i][j];
                }
            }
            numeric2[i][k]=0;
        }

        for(i=0;i<n;i++)
        {
            if(strcmp(numeric1[i],numeric2[i])!=0)
                break;
        }
        if(i==n)
            printf("Run #%d: Presentation Error\n",a);

        else
            printf("Run #%d: Wrong Answer\n",a);
    }
    return 0;
}
