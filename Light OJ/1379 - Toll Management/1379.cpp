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
#define inf         ((1 << 30) - 1)
#define eps         1e-9
#define MOD         100007
#define MAX         600

struct data
{
    int node, cost;

    bool operator < (const data& p) const
    {
        return cost>p.cost;
    }
};

int dis[MAX];
priority_queue <data> Q;
vector <data> V[MAX];

void dijstra(int src)
{
    int i,d,v,u,d1,w,c;
    data X;

    for(i=0;i<MAX;i++)
        dis[i]=inf;

    dis[src]=0;


    X.cost=0;
    X.node=src;
    Q.push(X);

    while(!Q.empty())
    {
        data Y= Q.top();
        Q.pop();

        d= Y.cost;
        u= Y.node;



        if(d<=dis[u])
        {
            for(i=0;i<V[u].size();i++)
            {
                v= V[u][i].node;
                d1= V[u][i].cost;
                c= max(d1,dis[u]);

                if(c<dis[v])
                {
                    dis[v]=c;

                    X.node= v;
                    X.cost= dis[v];
                    Q.push(X);
                }

            }
        }
    }

}

void clear_all(int n)
{
    for(int i=0;i<n;i++)
        V[i].clear();

}

int main()
{
    READ;

    int t,cas,i,j,k,u,v,n,m,src,w;
    data X;
    sf(t);

    for(cas=1;cas<=t;cas++)
    {
        gc;

        sff(n,m);

        for(i=0;i<m;i++)
        {
            sfff(u,v,w);

            X.cost=w;
            X.node=v;

            V[u].push_back(X);

            X.node=u;
            V[v].push_back(X);
        }
        sf(src);

        dijstra(src);

        pf("Case %d:\n",cas);
        for(i=0;i<n;i++)
        {
            if(dis[i]==inf)
                pf("Impossible\n");
            else
                pf("%d\n",dis[i]);
        }

        clear_all(n);
    }


    return 0;
}


