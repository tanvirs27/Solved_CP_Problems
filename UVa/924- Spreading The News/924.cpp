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

#define node 2550
#define ri int
#define clr(a) memset(a,0,sizeof(a))
#define READ freopen("input.txt","r",stdin)

vector <ri> G[node];
queue <ri> Q;
ri visited[node],level[node],parent[node],level_sum[node];
int E;

void bfs(ri source)
{
    clr(visited);
    clr(level);
    clr(level_sum);

    Q.push(source);
    visited[source]=1;
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
                level_sum[level[v]]++;
                Q.push(v);
            }
        }
        Q.pop();
    }
    return;
}

void boom(int *day,int *max)
{
    for(int i=1;i<=E;i++)
    {
        if(level_sum[i]>*max)
        {
            *day=i;
            *max=level_sum[i];
        }
    }
    return;
}

int main()
{
  //  READ;
    int i,n,F,t,src;

    scanf("%d",&E);

    for(i=0;i<E;i++)
    {
        scanf("%d",&n);

        while(n--)
        {
            scanf("%d",&F);

            G[i].push_back(F);
        }
    }

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&src);
        bfs(src);

        int day=0,max=0;

        boom(&day,&max);

        if(!day)
            printf("0\n");
        else
            printf("%d %d\n",max,day);
    }
    return 0;
}
