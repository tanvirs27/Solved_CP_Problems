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
#define sff(a,b)    scanf("%lld%lld", &a, &b)
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
#define MOD         100000007
#define MAX         204480

vector <ll> perfect;
map <ll,int> M;

ll f[MAX+1],mif[MAX+10];

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
    mif[1]=1;
    f[0]=1;
    mif[0]=1;

    ll i;
    for(i=2;i<=MAX;i++)
    {
        f[i]= ((i%MOD)*(f[i-1]%MOD))%MOD;
        mif[i]= mod_inverse(f[i]);
    }
}

void square()
{
    ll i,j,cnt=1;

    for(i=2;i<=100000;i++)
    {
        for(j=i*i;j<=10000000000L;j*=i)
        {
            if(M[j]==0)
            {
                M[j]=cnt++;
                perfect.push_back(j);
            }
        }

    }

    sort(all(perfect));
}

int BS(ll x)
{
    if(x<4)
        return 0;
    int mid,hi,lo,ans;
    lo= 0;
    hi= perfect.size();

    while(lo<=hi)
    {
        mid= (lo+hi)/2;

        if(perfect[mid]<=x)
        {
            lo=mid+1;

            ans=mid;
        }
        else
            hi=mid-1;
    }
    return ans+1;
}

int main()
{
    READ;
    ll n,a,b,ans;
    int t;
    square();
    precalc();

    sf(t);

    FRAE(cas,1,t)
    {
        sff(a,b);

        n= BS(b)-BS(a-1);

      //  pf("%d %d\n",BS(b),BS(a-1));
        ans=1;
      //  pf("n= %d\n",perfect.size());

        ans= ((ans%MOD)*(f[2*n]%MOD))%MOD;
        ans= ((ans%MOD)*(mif[n]%MOD))%MOD;
        ans= ((ans%MOD)*(mif[n]%MOD))%MOD;
        ans= ((ans%MOD)*(mod_inverse(n+1)%MOD))%MOD;

        //ans= ((f[2*n]%MOD)*(mif[n]%MOD)*(mif[n]%MOD)*(mod_inverse(n+1)%MOD))%MOD;

       // pf("%lld %lld %lld\n",f[2*n],mif[n],mod_inverse(n+1));

        if(n==0)
            ans=0;

        pf("Case %d: %lld\n",cas,ans);
    }

    return 0;
}


