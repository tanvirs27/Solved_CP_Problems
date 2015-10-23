#include<stdio.h>
#include<string.h>

int coin[101];
int times[21];
int dp[101][1001];
int make,n,k;

int func(int i,int amount)
{

    if(i==n)
    {
        if(!amount)
            return 1;
        return 0;
    }
    int way1=0,way2=0;

    if(dp[i][amount]!=-1) return dp[i][amount];

    int take;
    for(take=1;take<=times[i];take++)
    {
    if(amount-coin[i]*take>=0)
        way1=func(i+1,amount-coin[i]*take);
    else break;
    }
    way2=func(i+1,amount);

    return dp[i][amount]=way1+way2;

}

int main()
{
    freopen("input.txt","r",stdin);
    int i,t,j;
    scanf("%d",&t);

    for(i=1;i<=t;i++)
    {
        k=0;
        memset(dp,-1,sizeof(dp));
        scanf("%d%d",&n,&make);
        for(j=0;j<n;j++)
            scanf("%d",&coin[j]);

        for(j=0;j<n;j++)
            scanf("%d",&times[j]);



        printf("Case %d: %d\n",i,func(0,make));
    }
    return 0;
}

