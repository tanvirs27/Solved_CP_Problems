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
#define MAX         200

vector <int> V[MAX];
int visited[MAX],dis[MAX],save[MAX];
queue <int> Q;

void bfs(int src)
{
    int u,v,i;
    mem(visited,0);
    mem(dis,0);

    visited[src]=1;
    Q.push(src);

    while(!Q.empty())
    {
        u=Q.front();

        for(i=0;i<V[u].size();i++)
        {
            v= V[u][i];

            if(!visited[v])
            {
                visited[v]=1;
                dis[v]=dis[u]+1;
                Q.push(v);
            }
        }
        Q.pop();
    }
    return;
}

int main()
{
  //  READ;

    int cas,t,n,r,u,v,i,j,k,src,des;

    sf(t);

    for(cas=1;cas<=t;cas++)
    {
        sf(n);

        sf(r);

        while(r--)
        {
            sff(u,v);

            V[u].push_back(v);
            V[v].push_back(u);
        }
        sff(src,des);

        bfs(src);

        for(i=0;i<n;i++)
        {
            save[i]=dis[i];
        }

        bfs(des);
        int temp, ans=-inf;

        for(i=0;i<n;i++)
        {
            temp=save[i]+dis[i];

            ans= max(ans,temp);
        }

        pf("Case %d: %d\n",cas,ans);

        for(i=0;i<n;i++)
            V[i].clear();
    }

    return 0;
}

