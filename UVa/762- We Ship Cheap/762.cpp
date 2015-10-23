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

#define node 2626
#define ri int
#define clr(a) memset(a,0,sizeof(a))
#define READ freopen("input.txt","r",stdin)
#define rep(i,n) for(ri i=0;i<(ri)n;i++)

vector <ri> G[node];
queue <ri> Q;
ri visited[node],level[node],parent[node];


void bfs(ri source)
{
    clr(visited);
    clr(level);
    clr(parent);

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
 //  READ;
    int n,i,j,ans,x,y,src,des,flag=0;
    char a,b,c,d,e;

    while(scanf("%d",&n)==1)
    {
        if(flag!=0)
           puts("");

        flag=1;

        while(n--)
        {
            getchar();

            scanf("%c%c%c%c%c",&a,&b,&c,&d,&e);

            x= (a-'A')*100 + b-'A';
            y= (d-'A')*100 + e-'A';

            G[x].push_back(y);
            G[y].push_back(x);
        }

        getchar();

        scanf("%c%c%c%c%c",&a,&b,&c,&d,&e);

        src= (a-'A')*100 + b-'A';
        des= (d-'A')*100 + e-'A';

        bfs(src);


        int ans[node];
        i=1;
        x=des;

        if(level[des]!=0)
        {
            while(x!=src)
            {
                ans[i++]=parent[x];

                x=ans[i-1];
            }
            ans[0]=des;

            for(int k=i-1; k>0; k--)
            {
                a=ans[k]/100+'A';
                b=ans[k]%100+'A';
                c=ans[k-1]/100+'A';
                d=ans[k-1]%100+'A';

                printf("%c%c %c%c\n",a,b,c,d);
            }
        }
        else
            printf("No route\n");

        rep(k,node)
            G[k].clear();

        clr(ans);
    }
    return 0;
}
