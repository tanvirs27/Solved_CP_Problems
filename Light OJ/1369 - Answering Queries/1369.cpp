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
#define MOD         100007
#define MAX         100005

ll ara[MAX];

int main()
{
  //  READ;

    int t,n,q,a;
    ll  sum,x,v;

    sf(t);

    FRAE(cas,1,t)
    {
        sff(n,q);

        pf("Case %d:\n",cas);
        sum=0;
        FRA(i,0,n)
        {
            scanf("%lld",&ara[i]);

            sum+= (n-1-i)*ara[i];
            sum-= i*ara[i];
        }

        FRA(i,0,q)
        {
            sf(a);

            if(a==1)
            {
                pf("%lld\n",sum);
            }
            else if(a==0)
            {
                scanf("%lld%lld",&x,&v);

                sum+= (n-1-x)*(v-ara[x]);
                sum-= x*(v-ara[x]);

                ara[x]=v;
            }
        }


    }

    return 0;
}


