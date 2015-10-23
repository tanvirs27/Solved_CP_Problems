#include<stdio.h>
#include<string.h>

#define N 1000
#define G 100
#define W 30

int dp[N+1][W+1];
int price[N+1];
int weight[N+1];
int man[G+1];
int n,k;

int max(int a, int b)
{
    if(a>b)
        return a;
    return b;
}

int func(int i,int w)
{
    if(i>n)
        return 0;

    int profit1=0,profit2=0;

    if(dp[i][w]!=-1) return dp[i][w];

    if(w+weight[i]<=man[k])
        profit1=price[i]+func(i+1,w+weight[i]);

    profit2=func(i+1,w);

    dp[i][w]=max(profit1,profit2);

    return dp[i][w];
}

int main()
{
  //  freopen("input.txt","r",stdin);
    int t;
    scanf("%d",&t);

    while(t--)
    {
        int sum=0;
        scanf("%d",&n);

        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&price[i],&weight[i]);
        }

        int people;
        scanf("%d",&people);
        for(k=1;k<=people;k++)
        {
            memset(dp,-1,sizeof(dp));
            scanf("%d",&man[k]);
            sum+=func(1,0);
        }
        printf("%d\n",sum);
    }
    return 0;
}


