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

#define node 25
#define ri int
#define clr(a) memset(a,0,sizeof(a))
#define readf() freopen("input.txt","r",stdin)

vector <ri> G[node];
queue <ri> Q;
ri visited[node],level[node];

ri bfs(ri source, ri destination)
{
    clr(visited);
    clr(level);

    Q.push(source);
    visited[source]=1;
    level[source]=0;

    while(!Q.empty())
    {
        ri u= Q.front();

        for(ri i=0; i<G[u].size(); i++)
        {
            ri v= G[u][i];

            if(!visited[v])
            {
                visited[v]=1;
                level[v]=level[u]+1;
                Q.push(v);
            }
        }
        Q.pop();
    }

    return level[destination];
}

int main()
{
    readf();
    ri a,i,j,x,y,kase=1,b,ans;

    while(scanf("%d",&a)==1)
    {
        printf("Test Set #%d\n",kase++);

        x=1;
        while(a--)
        {
            scanf("%d",&y);

            G[x].push_back(y);
            G[y].push_back(x);
        }

        for(x=2; x<20; x++)
        {
            scanf("%d",&a);

            while(a--)
            {
                scanf("%d",&y);

                G[x].push_back(y);
                G[y].push_back(x);
            }
        }

        ri n;

        scanf("%d",&n);

        while(n--)
        {
            scanf("%d%d",&a,&b);

            ans= bfs(a,b);

            printf("%2d to %2d: %d\n",a,b,ans);
        }

        puts("");

        for(i=1;i<21;i++)
            G[i].clear();
    }


    return 0;
}

