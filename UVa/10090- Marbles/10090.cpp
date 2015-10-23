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
#define MOD         100007
#define MAX         200

ll ext_euclid(ll a, ll b,ll *s,ll *t)
{
    ll r=1,s0=1,s1=0,t0=0,t1=1,q;

    while(r)
    {
        r=a%b;
        q=a/b;
        a=b;
        b=r;
        *s=s0-q * s1;
        *t=t0-q * t1;

        s0=s1;
        t0=t1;
        s1=*s;
        t1=*t;
    }
    *s=s0;
    *t=t0;

    return a;
}



int main()
{
  //  READ;

    ll n,c1,c2,n1,n2,i,j,k,ans1,ans2;

    while(sf(n)==1 && n)
    {
        sff(c1,n1);
        sff(c2,n2);

        ll G=ext_euclid(n1,n2,&ans1,&ans2);

        pf("debug1 %lld %lld %lld\n",G,ans1,ans2);

        if(n%G!=0)
        {
            pf("failed\n");
        }
        else
        {
            ll mul= n/G;
            ans1*=mul;
            ans2*=mul;

         //   pf("debug %lld %lld %lld %lld %lld\n\n",G,ans1,ans2,c1,c2);

            if(ans1<0 && c1<c2)
            {
                ll temp= ans2/(n1/G);
                ans2= ans2%(n1/G);

                ans1+= temp*(n2/G);
            }
            else if(ans1<0 && c1>=c2)
            {
                ans1*=-1;

                ll temp= ans1/(n2/G);
                ans1= ans1%(n2/G);
                ans1*=-1;
                ans1+= (n2/G);
             //   pf("temp %lld ans1 %lld n2/G %lld\n",temp,ans1,n2/G);

                ans2-= temp*(n1/G);
                ans2-= n1/G;
            }
            else if(ans2<0 && c2<c1)
            {
                ll temp= ans1/(n2/G);
                ans1= ans1%(n2/G);

                ans2+= temp*(n1/G);
            }
            else if(ans2<0 && c2>=c1)
            {
                ans2*=-1;

                ll temp= ans2/(n1/G);
                ans2= ans2%(n1/G);
                ans2*=-1;
                ans2+= (n1/G);

                ans1-= temp*(n2/G);
                ans1-= (n2/G);
            }
            else
            {
                ll temp1= n/n1;
                temp1*= c1;

                ll temp2= n/n2;
                temp2*= c2;

                if(temp1<temp2)
                {
                    ans1=n/n1;
                    ans2=0;
                }
                else
                {
                    ans2=n/n2;
                    ans1=0;
                }
            }

            if(ans1<0 || ans2<0)
                pf("failed\n");
            else
                pf("%lld %lld\n",ans1,ans2);
        }


    }

    return 0;
}


