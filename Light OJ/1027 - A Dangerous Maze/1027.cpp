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
#define MAX         200

int gcd(int a, int b)
{
    if(a%b==0)
        return b;

    gcd(b,a%b);
}


int main()
{
    READ;

    int t,cas,n,i,j,val,neg,sum,ans,lob,hor;

    sf(t);

    for(cas=1;cas<=t;cas++)
    {
        sf(n);

        neg=0;
        sum=0;
        bool flag=false;
        for(i=0;i<n;i++)
        {
            sf(val);

            if(val<0)
            {
                neg++;
                sum-=val;
            }
            else
                sum+=val;
        }

        if(n==neg)
        {
            pf("Case %d: inf\n",cas);
            continue;
        }

        hor= n-neg;

        int G= gcd(sum,hor);

        sum/=G;
        hor/=G;

        pf("Case %d: %d/%d\n",cas,sum,hor);

    }


    return 0;
}


