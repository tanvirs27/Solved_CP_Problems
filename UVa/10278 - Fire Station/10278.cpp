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
#define MAX         505

struct data
{
    int node, cost;

    bool operator < (const data& p) const
    {
        return cost>p.cost;
    }
};

int dis[MAX],fire[105],dis2[MAX];
priority_queue <data> Q;
vector <data> V[MAX],V1[MAX];

void dj(int src,int n)
{
    int i,d,v,u,d1,w;
    data X;

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


void clear_all(int n)
{
    for(int i=1;i<=n;i++)
    {
        V[i].clear();

    }


}


int main()
{
 //   READ;

    int cas,t,n,m,i,j,k,c,u,v,ans,F,I;
    data X;
    string line;
    sf(t);

    for(cas=1;cas<=t;cas++)
    {
        if(cas!=1)
            puts("");

        ans=0;
        sff(F,I);

        for(i=0;i<F;i++)
        {
            sf(fire[i]);
        }

        cin.ignore();
		while(getline(cin,line) && line.size())
        {
           // pf("%d yes\n",line.size());
            stringstream ss(line);

            ss >> u >> v >> c;

          //  pf("%d %d %d\n",u,v,c);

            X.node=v;
            X.cost=c;
            V[u].push_back(X);

            X.node=u;
            V[v].push_back(X);

          //  pf("%d yes\n",line.size());
        }
      //  pf("yes\n");
        for(i=1;i<=I;i++)
            dis[i]=inf;

        for(i=0;i<F;i++)
        {
          //  pf("yes1\n");
            dj(fire[i],I);
           // pf("yes2\n");
        }

        int mx=-inf;
        for(i=1;i<=I;i++)
        {
            dis2[i]=dis[i];
          //  pf("%d %d\n",i,dis[i]);
            mx=max(mx,dis[i]);
          //  pf("%d\n",mx);
        }



        int mn=inf;
        for(i=1;i<=I;i++)
        {
            dj(i,I);


            mx=-inf;
            for(j=1;j<=I;j++)
            {
                mx=max(mx,dis[j]);
              //  pf("%d %d\n",j,dis[j]);
            }
           // puts("");
          //  pf("%d\n",mx);

            if(mx<mn)
            {
                mn=mx;
                ans=i;
            }

            for(k=1;k<=I;k++)
                dis[k]=dis2[k];
        }
        pf("%d\n",ans);

        clear_all(I);
    }


    return 0;
}

