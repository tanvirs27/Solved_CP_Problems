#include<stdio.h>
#include<string.h>

int ara[105],n;

void add(int x)
{
    int i;

    for(i=0;i<n;i++)
        ara[i]+=x;
}

void multiple(int x)
{
    int i;

    for(i=0;i<n;i++)
        ara[i]*=x;
}

void division(int x)
{
    int i;

    for(i=0;i<n;i++)
        ara[i]/=x;
}

void swap(int x, int y)
{
    int temp= ara[x];
    ara[x]=ara[y];
    ara[y]=temp;
}

void rev()
{
    int i;

    for(i=0;i<n/2;i++)
    {
        swap(i,n-i-1);
    }
}

int main()
{
    int t,m,i,j,x,y;
    char ch;

    scanf("%d",&t);

    for(i=1;i<=t;i++)
    {
        scanf("%d%d",&n,&m);

        for(j=0;j<n;j++)
            scanf("%d",&ara[j]);

        while(m--)
        {
            getchar();
            ch=getchar();

            if(ch=='S')
            {
                scanf("%d",&x);
                add(x);
            }
            else if(ch=='M')
            {
                scanf("%d",&x);
                multiple(x);
            }
            else if(ch=='D')
            {
                scanf("%d",&x);
                division(x);
            }
            else if(ch=='R')
            {
                rev();
            }
            else if(ch=='P')
            {
                scanf("%d%d",&x,&y);
                swap(x,y);
            }
        }
        printf("Case %d:\n",i);

        for(j=0;j<n;j++)
        {
            if(j!=0)
                printf(" ");
            printf("%d",ara[j]);
        }
        puts("");
    }
    return 0;
}
