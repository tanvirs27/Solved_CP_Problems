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
#define FRA(i,a,b) for(int i=a; i<b; i++)
#define FRAE(i,a,b) for(int i=a; i<=b; i++)
#define FRD(i,a,b) for(int i=a; i>b; i--)
#define FRDE(i,a,b) for(int i=a; i>=b; i--)
#define all(V) V.begin(),V.end()
#define max(a,b) (a>b) ? (a):(b)
#define min(a,b) (a<b) ? (a):(b)
#define inf         ((1 << 30) - 1)
#define eps         1e-9
#define MOD         10056
#define MAX         1000

int ara[MAX+5][MAX+5],dp[MAX+5];


int nCr(int n, int r)
{
    if(r==0 || r==n)
        return 1;
    if(r==1 || r==n-1)
        return n;

    if(ara[n][r]!=-1)
        return ara[n][r];
    else
    {
        ara[n][r]=(nCr(n-1,r)%MOD+nCr(n-1,r-1)%MOD)%MOD;
        return ara[n][r];
    }
}

int call(int i)
{
    if(i==1 || i==0)
        return 1;
    if(i<0)
        return 0;

    if(dp[i]!=-1)
        return dp[i];
    int ret=0;

    FRAE(k,1,i)
    {
        ret= (ret%MOD+nCr(i,k)%MOD*call(i-k)%MOD)%MOD;
    }
    return dp[i]=ret;
}


int main()
{
  //  READ;

    int t,n,ans;
    mem(ara,-1);
    mem(dp,-1);

    sf(t);

    FRAE(cas,1,t)
    {
        sf(n);

        ans= call(n);

        pf("Case %d: %d\n",cas,ans);
    }



    return 0;
}


