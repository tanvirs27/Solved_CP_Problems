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
#define FR1(i,k) for(i=1;i<=k;i++)
#define FR0(i,k) for(i=0;i<k;i++)
#define pf printf
#define inf         (1 << 30 - 1)
#define eps         1e-9
#define MOD         100007
#define MAX         100000

struct aaa
{
    int u,v,w;
};
typedef struct aaa data;

bool compare1(data a, data b)
{
    return a.w>b.w;
}

bool compare2(data a, data b)
{
    return a.w<b.w;
}

vector <data> V;

int par[MAX];

int find_mother(int r)
{
    if(par[r]==r)
        return r;

    return par[r]=find_mother(par[r]);
}

int mst(int n, bool flag)
{
    if(flag)
        sort(V.begin(),V.end(),compare1);
    else
        sort(V.begin(),V.end(),compare2);

    int i,cost=0,count=0;

    for(i=0;i<=n;i++)
        par[i]=i;

    for(i=0;i<V.size();i++)
    {
        int u1= find_mother(V[i].u);
        int v1= find_mother(V[i].v);

        if(u1!=v1)
        {
            par[u1]=v1;

            cost+=V[i].w;

            count++;

            if(count==n)
                break;
        }

    }
    return cost;
}

void clear_all()
{
    mem(par,0);
    V.clear();
}

int main()
{
    READ;

    int cas,n,m,i,j,k,w0,min,max,t,ans;

    data X;
    sf(t);

    for(cas=1;cas<=t;cas++)
    {
        getchar();
        getchar();

        sf(n);

        while(sfff(X.u,X.v,X.w)==3 )
        {
            if(!X.v && !X.u && !X.w)
                break;

            V.push_back(X);
        }
        min=mst(n,false);
        max=mst(n,true);

        ans=(min+max);

        if(ans%2==0)
            pf("Case %d: %d\n",cas,ans/2);
        else
            pf("Case %d: %d/2\n",cas,ans);

        clear_all();
    }




    return 0;
}


