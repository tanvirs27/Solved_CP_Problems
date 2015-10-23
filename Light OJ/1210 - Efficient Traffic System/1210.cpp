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
#define MAX         20005

struct data
{
    int index,t;

    bool operator < (const data& p ) const
    {
        return t>p.t;
    }
};


vector <int> V1[MAX],V2[MAX];
vector <data> A;
int tm,color[MAX],d[MAX],f[MAX],compo[MAX],new_graph[MAX][MAX],num,indeg[MAX],outdeg[MAX];

void clear_all(int n)
{
    int i;

    for(i=1;i<=n;i++)
    {
        V1[i].clear();
        V2[i].clear();
    }
    A.clear();
    mem(compo,0);
    mem(indeg,0);
    mem(outdeg,0);
}

void visit2(int u)
{
    int i;
    color[u]=0;
    compo[u]=num;

    for(i=0;i<V2[u].size();i++)
    {
        int v=V2[u][i];
        if(color[v]==-1)
        {
            visit2(v);
        }
    }
    color[u]=1;
}


int dfs2()
{
    int i;
    num=0;
    mem(color,-1);
    sort(all(A));

   // for()

    for(i=0;i<A.size();i++)
    {
        int u=A[i].index;

        if(color[u]==-1)
        {
            num++;
            visit2(u);
        }
    }
    return num;
}


void visit(int u)
{
    int i;
    color[u]=0;
    tm++;
    d[u]=tm;

    for(i=0;i<V1[u].size();i++)
    {
        int v=V1[u][i];
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
    X.t=f[u];
    A.push_back(X);
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


int scc(int n,int m)
{
    int i,j,in=0,out=0;

    for(i=1;i<=n;i++)
    {
        for(j=0;j<V1[i].size();j++)
        {
            int v= V1[i][j];

            if(compo[i]!=compo[v])
            {
                int x,y;
                x= compo[i];
                y= compo[v];

                indeg[y]++;
                outdeg[x]++;

            }
        }
    }

    for(i=1;i<=n;i++)
    {
        if(indeg[i]==0)
            in++;
        if(outdeg[i]==0)
            out++;
    }
  //  pf("in->%d  out->%d\n",in,out);
    return max(in,out);
}

int main()
{
   // READ;

    int cas,t,n,m,a,b,i,j,k;

    sf(t);

    for(cas=1;cas<=t;cas++)
    {
        sff(n,m);

        for(i=0;i<m;i++)
        {
            sff(a,b);

            V1[a].push_back(b);
            V2[b].push_back(a);
        }

        dfs(n);
        int cno=dfs2();
        int ans;

        if(cno==1)
            ans=0;
        else
            ans=scc(n,cno);

        pf("Case %d: %d\n",cas,ans);

        clear_all(n);
    }

    return 0;
}


