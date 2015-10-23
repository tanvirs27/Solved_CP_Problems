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
#define sf(n)       scanf("%lld", &n)
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
#define MAX         201

ll n,dp[MAX][MAX],ara[MAX][MAX];

ll call(ll i, ll j)
{
    if(i>2*n-1 || j<0)
        return 0;
    if(i<=n && j>=i)
        return 0;
    if(i>n && j>=n-i+n)
        return 0;

    if(dp[i][j]!=-1)
        return dp[i][j];

    ll ret1, ret2;

    if(i<n)
    {
        ret1= ara[i][j]+ call(i+1,j);
        ret2= ara[i][j]+ call(i+1,j+1);
    }
    else
    {
        ret1= ara[i][j]+ call(i+1,j);
        ret2= ara[i][j]+ call(i+1,j-1);
    }


    return dp[i][j]= max(ret1,ret2);

}
int main()
{
 //   READ;

    ll t,cas,i,j,k;

    sf(t);

    for(cas=1;cas<=t;cas++)
    {
        mem(dp,-1);
        sf(n);

        for(i=1;i<=n;i++)
        {
            for(j=0;j<i;j++)
                sf(ara[i][j]);
        }


        for(i=n+1;i<=2*n-1;i++)
        {
            for(j=0;j<n-i+n;j++)
                sf(ara[i][j]);
        }

        pf("Case %lld: %lld\n",cas,call(1,0));
    }

    return 0;
}


