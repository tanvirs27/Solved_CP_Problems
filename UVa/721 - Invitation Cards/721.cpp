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
#define MAX         1000000

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
vector <data> V[MAX],V1[MAX];

void dijsktra(int src,int n)
{
    int i,d,v,u,d1,w;
    data X;

    for(i=1;i<=n;i++)
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

                if(dis[v]>dis[u]+d1)
                {
                    dis[v]=dis[u]+d1;

                    X.node= v;
                    X.cost= dis[v];
                    Q.push(X);
                }

            }
        }
    }

}

void dijsktra2(int src,int n)
{
    int i,d,v,u,d1,w;
    data X;

    for(i=1;i<=n;i++)
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
            for(i=0;i<V1[u].size();i++)
            {
                v= V1[u][i].node;
                d1= V1[u][i].cost;

                if(dis[v]>dis[u]+d1)
                {
                    dis[v]=dis[u]+d1;

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
    for(int i=1;i<=n;i++)
    {
        V[i].clear();
        V1[i].clear();
    }


}


int main()
{
  //  READ;

    int t,n,m,i,j,k,c,u,v,ans;
    data X;

    sf(t);

    while(t--)
    {
        ans=0;
        sff(n,m);

        for(i=0;i<m;i++)
        {
            sfff(u,v,c);

            X.node=v;
            X.cost=c;
            V[u].push_back(X);

            X.node=u;
            V1[v].push_back(X);
        }

        dijsktra(1,n);

        for(i=1;i<=n;i++)
        {
            ans+=dis[i];
        }

        dijsktra2(1,n);

        for(i=1;i<=n;i++)
        {
            ans+=dis[i];
        }

        pf("%d\n",ans);

        clear_all(n);

    }


    return 0;
}

