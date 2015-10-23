#include<stdio.h>

int main()
{
    int t,k,n,p,q,i,egg[32],sum[32],ans;
    sum[0]=0;

    scanf("%d",&t);

    for(k=1;k<=t;k++)
    {
        scanf("%d%d%d",&n,&p,&q);

        for(i=1;i<=n;i++)
        {
            scanf("%d",&egg[i]);
            sum[i]=sum[i-1]+egg[i];
        }

        ans=0;
        for(i=n;i>=1;i--)
        {
            if(i<=n && i<=p && sum[i]<=q)
            {
                ans=i;
                break;
            }
        }

        printf("Case %d: %d\n",k,ans);
    }

    return 0;
}
