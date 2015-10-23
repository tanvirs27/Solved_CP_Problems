#include<stdio.h>
#include<math.h>

int ara[1005];
int sort[1005];

void sieve()
{
    int i,j;

    for(i=1;i<1005;i++)
    {
        for(j=i;j<1005;j+=i)
            ara[j]++;
    }
}

void order()
{
    int i,j,min,index;

    for(i=1;i<=1000;i++)
    {
        min=2010;
        index=0;
        for(j=1;j<=1000;j++)
        {
            if(ara[j]<=min)
            {
                min=ara[j];
                index=j;
            }
        }
        sort[i]=index;
        ara[index]=3010;
    }
}

int main()
{
   // freopen("input.txt","r",stdin);

    sieve();
    order();

    int t,k,n;

    scanf("%d",&t);

    for(k=1;k<=t;k++)
    {
        scanf("%d",&n);

        printf("Case %d: %d\n",k,sort[n]);
    }

    return 0;
}
