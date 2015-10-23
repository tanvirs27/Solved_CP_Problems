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

#define node 202
#define ri int
#define clr(a) memset(a,0,sizeof(a))
#define READ freopen("input.txt","r",stdin)

vector <ri> G[node];
queue <ri> Q;
ri color[node];

int bipartile(ri source)
{
    memset(color,-1,sizeof(color));

    Q.push(source);
    color[source]=0;

    while(!Q.empty())
    {
        ri u= Q.front();

        for(ri i=0;i<G[u].size();i++)
        {
            ri v= G[u][i];

            if(color[v]==-1)
            {
                color[v]=1-color[u];
                Q.push(v);
            }
            else if(color[v]==color[u])
                return 0;
        }
        Q.pop();
    }
    return 1;
}

int main()
{

    int n,i,j,m,x,y,ans;


    while(scanf("%d",&n)==1)
    {
        if(!n)break;

        scanf("%d",&m);

        while(m--)
        {
            scanf("%d%d",&x,&y);

            G[x].push_back(y);
            G[y].push_back(x);
        }

        ans=bipartile(0);

        if(ans==0)
            printf("NOT BICOLORABLE.\n");
        else
            printf("BICOLORABLE.\n");

        for(i=0;i<n;i++)
            G[i].clear();
    }

    return 0;
}

