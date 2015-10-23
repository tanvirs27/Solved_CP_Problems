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
#define MAX         35000

struct data
{
    int node,cost;
};

vector <data> V[MAX];
int visited[MAX];
int dis[MAX];
int farthest_node,farthest_dis;

int dfs(int u)
{
    int i;
    visited[u]=1;

    for(i=0;i<V[u].size();i++)
    {
        int v= V[u][i].node;

        if(!visited[v])
        {
            visited[v]=1;
            dis[v]=dis[u]+V[u][i].cost;

            if(dis[v]>farthest_dis)
            {
                farthest_dis=dis[v];
                farthest_node=v;
            }
          //  else if(dis[v]==farthest_dis && V[u][v].cost>)

            dfs(v);
        }
    }
    return farthest_dis;
}

int main()
{
  //  READ;

    int t,i,j,k,cas,u,v,w,n;
    data X;

    sf(t);

    for(cas=1;cas<=t;cas++)
    {
        mem(visited,0);
        mem(dis,0);
        sf(n);

        for(i=1;i<n;i++)
        {
            sfff(u,v,w);

            X.node=v;
            X.cost=w;
            V[u].push_back(X);

            X.node=u;
            X.cost=w;
            V[v].push_back(X);
        }

        farthest_dis=-1;
        farthest_node=-1;
        dfs(0);
       // pf("%d %d\n",farthest_dis,farthest_node);

        u=farthest_node;
        farthest_dis=-1;
        farthest_node=-1;
        mem(visited,0);
        mem(dis,0);

        int ans=dfs(u);

        pf("Case %d: %d\n",cas,ans);

        for(i=0;i<n;i++)
            V[i].clear();
    }


    return 0;
}

