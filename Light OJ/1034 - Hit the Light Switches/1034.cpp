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
#define all(V) V.begin(),V.end()
#define max(a,b) (a>b) ? (a):(b)
#define min(a,b) (a<b) ? (a):(b)
#define inf         ((1 << 30) - 1))
#define eps         1e-9
#define MOD         100007
#define MAX         100005

struct data
{
    int index,time2;

    bool operator < (const data& p) const
    {
        return time2>p.time2;
    }
};

int tm;
vector <int> V[MAX];
int color[MAX],d[MAX],f[MAX];
vector <data> Q;

void clear_all(int n)
{
    int i;

    for(i=1;i<=n;i++)
        V[i].clear();

    Q.clear();
}

void visit2(int u)
{
    int i;
    color[u]=0;

    for(i=0;i<V[u].size();i++)
    {
        int v=V[u][i];
        if(color[v]==-1)
        {
            visit2(v);
        }
    }
    color[u]=1;
}


int dfs2()
{
    int i,ans=0;
    mem(color,-1);
    sort(all(Q));

    for(i=0;i<Q.size();i++)
    {
        int u=Q[i].index;

        //pf("%d\n",u);

        if(color[u]==-1)
        {
            ans++;
            visit2(u);
        }
    }
    return ans;
}


void visit(int u)
{
    int i;
    color[u]=0;
    tm++;
    d[u]=tm;

    for(i=0;i<V[u].size();i++)
    {
        int v=V[u][i];
        if(color[v]==-1)
        {
            visit(v);
        }
    }
    color[u]=1;
    tm++;
    f[u]=tm;

    data X;
    X.index=u;
    X.time2=f[u];

 //   pf("%d %d %d %d\n",u,f[u],X.index,X.time);

    Q.push_back(X);
}

void dfs(int n)
{
    int i;
    mem(color,-1);
    tm=0;

    for(i=1;i<=n;i++)
    {
        if(color[i]==-1)
            visit(i);
    }

}


int main()
{
    READ;

    int t,cas,n,m,i,j,k,ans,a,b;

    sf(t);

    for(cas=1;cas<=t;cas++)
    {
        gc;
        gc;

        sff(n,m);

        for(i=0;i<m;i++)
        {
            sff(a,b);

            V[a].push_back(b);
        }

        dfs(n);
        ans=dfs2();

        pf("Case %d: %d\n",cas,ans);

        clear_all(n);
    }


    return 0;
}

