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
#define MOD         100007
#define MAX         30000
#define n           5

int coin[n]= {1,5,10,25,50};
long long int dp[n][MAX+1];

long long int func(int i, int amount)
{
    if(i>=n)
    {
        if(amount==0)
            return 1;
        else
            return 0;
    }

    if(dp[i][amount]!=-1)
        return dp[i][amount];

    ll ret1=0,ret2=0;

    if(amount-coin[i]>=0)
        ret1= func(i,amount-coin[i]);

    ret2= func(i+1,amount);

    return dp[i][amount]= ret1+ret2;
}

int main()
{
   // READ;

    int i,j,k,a,b;
    int make;
    ll ans;

    mem(dp,-1);

    while(scanf("%d",&make)==1)
    {

        ans= func(0,make);

        if(ans!=1)
            pf("There are %lld ways to produce %d cents change.\n",ans,make);
        else
            pf("There is only 1 way to produce %d cents change.\n",make);

    }

    return 0;
}



