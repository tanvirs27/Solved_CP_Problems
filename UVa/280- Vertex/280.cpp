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

#define node 105
#define ri int
#define clr(a) memset(a,0,sizeof(a))
#define READ freopen("input.txt","r",stdin)

vector <ri> G[node];
queue <ri> Q;
ri visited[node],level[node],parent[node],ans[node+1];

int create(int n)
{
    clr(ans);
    int i,k=1;

    for(i=1;i<=n;i++)
    {
        if(visited[i]==0)
        {
            ans[k++]=i;
            ans[0]++;
        }
    }

    return k;
}

void bfs(ri source)
{
    clr(visited);
    clr(level);

    Q.push(source);
    level[source]=0;

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

    int n,i,j,m,k,p,x,y;

    while(scanf("%d",&n)==1)
    {
        if(!n)break;

        while(1)
        {
            scanf("%d",&m);

            if(!m)break;

            while(1)
            {
                scanf("%d",&x);

                if(!x)break;

                G[m].push_back(x);
            }
        }

        scanf("%d",&p);

        for(i=0;i<p;i++)
        {
            scanf("%d",&y);

            bfs(y);
            k=create(n);

            for(j=0;j<k;j++)
            {
                if(j!=0)
                    printf(" ");

                printf("%d",ans[j]);
            }
            puts("");
        }

        for(i=1;i<=n;i++)
            G[i].clear();
    }

    return 0;
}
