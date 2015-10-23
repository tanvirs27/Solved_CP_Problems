#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
using namespace std;

#define ll long long int
#define db double
#define mem(a,b) memset((a),b,sizeof(a))
#define READ freopen("c:\\Users\\Rifat\\Desktop\\in.txt", "r", stdin)
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d%d", &a, &b)
#define sfff(a,b,c) scanf("%d%d%d", &a, &b, &c)
#define pf printf
#define gc getchar()
#define DBG(a) printf("in %d\n",a)
#define all(V) V.begin(),V.end()
#define max(a,b) (a>b) ? (a):(b)
#define min(a,b) (a<b) ? (a):(b)
#define inf         ((1 << 30) - 1)
#define eps         1e-9
#define MAX         250
#define COIN        100

int n,coin[COIN+1],make;
int dp[COIN+1][COIN*MAX+1];

int change(int i, int amount)
{
    if(i>=n)
    {
        return 0;
    }

    if(dp[i][amount]!=-1)
        return dp[i][amount];

    int ret1=0,ret2=0;

    if(amount+coin[i]<=make)
        ret1= coin[i]+change(i+1,amount+coin[i]);

    ret2= change(i+1,amount);

    return dp[i][amount]= max(ret1,ret2);
}

int main()
{
   // READ;

    int t,i,j,k,ans,sum;

    sf(t);

    while(t--)
    {
        mem(dp,-1);
        sum=0;
        ans=0;
        sf(n);

        for(i=0;i<n;i++)
        {
            sf(coin[i]);
            sum+=coin[i];
        }

        make=sum/2;
        ans=change(0,0);

        pf("%d\n",sum-2*ans);
    }

    return 0;
}


