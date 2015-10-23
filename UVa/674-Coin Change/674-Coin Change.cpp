#include<stdio.h>
#include<string.h>

int coin[5]={50,25,10,5,1};
int dp[6][7490];
int make;

int func(int i,int amount)
{
    if(i>4)
    {
        if(!amount)
            return 1;
        return 0;
    }
    int way1=0,way2=0;

    if(dp[i][amount]!=-1) return dp[i][amount];

    if(amount-coin[i]>=0)
        way1=func(i,amount-coin[i]);

    way2=func(i+1,amount);

    return dp[i][amount]=way1+way2;
}

int main()
{
    memset(dp,-1,sizeof(dp));
    while(scanf("%d",&make)==1)
    {
        printf("%d\n",func(0,make));
    }
    return 0;
}
