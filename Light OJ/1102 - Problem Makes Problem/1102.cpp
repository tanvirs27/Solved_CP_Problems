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
#define sff(a,b)    scanf("%lld%lld", &a, &b)
#define sfff(a,b,c) scanf("%d%d%d", &a, &b, &c)
#define pf printf
#define gc getchar()
#define DBG(a) printf("in %d\n",a)
#define all(V) V.begin(),V.end()
#define max(a,b) (a>b) ? (a):(b)
#define min(a,b) (a<b) ? (a):(b)
#define inf         ((1 << 30) - 1)
#define eps         1e-9
#define MOD         1000000007
#define MAX         2000000

ll f[MAX+5];

ll mod(ll b, ll p)
{
    if(!p)
        return 1;
    ll ret;
    if(p%2==0)
    {
        ret= mod(b,p/2);

        return ((ret%MOD)*(ret%MOD))%MOD;
    }
    else
        return ((b%MOD)*(mod(b,p-1)%MOD))%MOD;
}

ll mod_inverse(ll a)
{
    return mod(a,MOD-2);
}

void precalc()
{
    f[1]=1;
    //mif[1]=1;
    f[0]=1;
    //mif[0]=1;

    ll i;
    for(i=2;i<=MAX;i++)
    {
        f[i]= ((i%MOD)*(f[i-1]%MOD))%MOD;
        //mif[i]= mod_inverse(f[i]);
    }
}



int main()
{
  //  READ;
    precalc();

    ll cas,t,n,k,ans;
    sf(t);

    for(cas=1;cas<=t;cas++)
    {
        ans=1;
        sff(n,k);

        k--;
        n=n+k;
     //   pf("%lld %lld %lld %lld %lld\n",f[n],f[k],mif[k],f[n-k],mif[n-k]);

        ll temp= 1;

        temp= ((temp%MOD)*(f[k]%MOD))%MOD;
        temp= ((temp%MOD)*(f[n-k]%MOD))%MOD;

        temp= mod_inverse(temp);

        ans= ((ans%MOD)*(f[n]%MOD))%MOD;
        ans= ((ans%MOD)*(temp%MOD))%MOD;
        //ans= ((ans%MOD)*(mif[k]%MOD))%MOD;
       // ans= ((ans%MOD)*(mif[n-k]%MOD))%MOD;

        //ll ans= ((f[n]%MOD)*(mif[k]%MOD)*(mif[n-k]%MOD))%MOD;

        pf("Case %lld: %lld\n",cas,ans);
    }



    return 0;
}




