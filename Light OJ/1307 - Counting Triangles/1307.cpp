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
#define MAX         2005

int ara[MAX];

int bs(int i,int n, int val)
{
    int low,hi,mid=0,ans=0;

    low=i;
    hi=n-1;

    while(low<=hi)
    {
        mid=(low+hi)/2;

        if(ara[mid]<val)
        {
            ans=mid;
            low=mid+1;
        }
        else
            hi=mid-1;
    }
  //  pf("mid=%d %d\n",mid,ara[mid]);
    return ans;
}

int triangle(int n)
{
    int i,j,k,ans=0;

    sort(ara,ara+n);

    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            int temp=bs(j+1,n,ara[i]+ara[j]);

            if(temp>0)
                ans+=temp-j;

//            pf("i=%d j=%d ans=%d\n",ara[i],ara[j],ans);
        }
    }
    return ans;
}

int main()
{
    //READ;

    int n,t,cas,i,j,k;

    sf(t);

    for(cas=1;cas<=t;cas++)
    {
        sf(n);

        for(i=0;i<n;i++)
        {
            sf(ara[i]);
        }
        int ans= triangle(n);

        pf("Case %d: %d\n",cas,ans);
    }

    return 0;
}

