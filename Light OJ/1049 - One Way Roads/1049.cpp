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
vector <int> cost[MAX];
int visited[MAX];
queue <int> Q;
int n;

int bfs(int src,int flag)
{
    while(!Q.empty())
        Q.pop();

    int ans=0;
    int counter=0;
    mem(visited,0);

    visited[src]++;
    Q.push(src);

    while(!Q.empty())
    {
        int u=Q.front();

        for(int i=0; i<V[u].size(); i++)
        {
            int v=V[u][i];

            if(u==src && i==flag)
                continue;

            visited[v]++;

            if(visited[v]==1 || (v==1 && visited[v]==3) )
            {


               // if(cost[u][i]<0)
                    ans+=cost[u][i];

                counter++;

              //  if(counter==n-1)
                //    visited[src]=0;

                Q.push(v);
            }
        }
        Q.pop();
    }
    return ans;
}

int main()
{
    READ;

    int t,cas,i,j,k,ans1,ans2,ans,a,b,c;

    sf(t);

    for(cas=1; cas<=t; cas++)
    {
        sf(n);

        for(i=0; i<n; i++)
        {
            sfff(a,b,c);

            V[a].push_back(b);
            cost[a].push_back(0);

            V[b].push_back(a);
            cost[b].push_back(c);
        }

        ans1=bfs(1,0);
        ans2=bfs(1,1);

        ans=min(ans1,ans2);

        pf("Case %d: %d\n",cas,ans);

        for(i=0; i<=n; i++)
        {
            V[i].clear();
            cost[i].clear();
        }
    }

    return 0;
}

