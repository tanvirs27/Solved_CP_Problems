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

#define node 1005
#define ri int
#define clr(a) memset(a,0,sizeof(a))
#define READ freopen("input.txt","r",stdin)

vector <ri> G[node];
queue <ri> Q;
ri visited[node],ans[node],source[node];

void bfs(ri source)
{
    clr(visited);

    Q.push(source);
    visited[source]=1;
    ans[source]++;

    while(!Q.empty())
    {
        ri u= Q.front();

        for(ri i=0;i<G[u].size();i++)
        {
            ri v= G[u][i];

            if(!visited[v])
            {
                visited[v]=1;
                ans[v]++;
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

    for(i=1;i<=t;i++)
    {
        scanf("%d%d%d",&k,&n,&m);

        for(j=0;j<k;j++)
            scanf("%d",source+j);

        while(m--)
        {
            scanf("%d%d",&x,&y);

            G[x].push_back(y);
        }

        for(j=0;j<k;j++)
            bfs(source[j]);

        int count=0;
        for(j=1;j<=n;j++)
        {
            if(ans[j]==k)
                count++;
        }

        printf("Case %d: %d\n",i,count);

        clr(ans);

        for(j=1;j<=n;j++)
            G[j].clear();
    }

    return 0;
}


