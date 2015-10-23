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

#define node 20005
#define ri int
#define clr(a) memset(a,0,sizeof(a))
#define READ freopen("input.txt","r",stdin)

vector <ri> G[node];
queue <ri> Q;
ri color[node],color_sum[2];

int bipartile(ri source)
{
    memset(color_sum,0,sizeof(color_sum));

    Q.push(source);
    color[source]=0;
    color_sum[0]++;

    while(!Q.empty())
    {
        ri u= Q.front();

        for(ri i=0;i<G[u].size();i++)
        {
            ri v= G[u][i];

            if(color[v]==-1)
            {
                color[v]=1-color[u];
                color_sum[color[v]]++;
                Q.push(v);
            }
        }
        Q.pop();
    }
    if(color_sum[0]>color_sum[1])
        return color_sum[0];
    return color_sum[1];
}


int main()
{

    int i,n,F,t,src,max,x,y,k;

    scanf("%d",&t);

    for(i=1;i<=t;i++)
    {
        memset(color,-1,sizeof(color));
        max=0;
        scanf("%d",&n);

        while(n--)
        {
            scanf("%d%d",&x,&y);

            if(x>max)
                max=x;
            if(y>max)
                max=y;

            G[x].push_back(y);
            G[y].push_back(x);
        }

        int ans=0;
        for(k=1;k<=max;k++)
        {
            if(color[k]==-1 && G[k].size()!=0)
                ans+=bipartile(k);
        }

        printf("Case %d: %d\n",i,ans);

        for(k=0;k<=max;k++)
        {
            G[k].clear();
        }


    }

    return 0;
}
