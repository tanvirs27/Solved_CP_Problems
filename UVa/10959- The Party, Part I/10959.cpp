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

#define node 1001
#define ri int
#define clr(a) memset(a,0,sizeof(a))
#define READ freopen("input.txt","r",stdin)

vector <ri> G[node];
queue <ri> Q;
ri visited[node],level[node],parent[node],ans[node+1];

void bfs(ri source)
{
    clr(visited);
    clr(level);

    Q.push(source);
    level[source]=0;
    visited[source]=1;

    while(!Q.empty())
    {
        ri u= Q.front();

        for(ri i=0;i<G[u].size();i++)
        {
            ri v= G[u][i];

            if(!visited[v])
            {
                visited[v]=1;
                parent[v]=u;
                level[v]=level[u]+1;
                Q.push(v);
            }
        }
        Q.pop();
    }
    return;
}

int main()
{

    int t,n,i,j,m,k=0,p,x,y;

    scanf("%d",&t);

    while(t--)
    {
        getchar();
        getchar();

        scanf("%d%d",&n,&m);

        if(k==1)
            puts("");
        k=1;

        while(m--)
        {
            scanf("%d%d",&x,&y);

            G[x].push_back(y);
            G[y].push_back(x);
        }

        bfs(0);

        for(i=1;i<n;i++)
            printf("%d\n",level[i]);

        for(i=0;i<n;i++)
            G[i].clear();
    }

    return 0;
}

