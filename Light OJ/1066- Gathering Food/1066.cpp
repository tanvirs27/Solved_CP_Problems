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

#define ri int
#define clr(a) memset(a,0,sizeof(a))
#define READ freopen("input.txt","r",stdin)
#define rep(i,n) for(ri i=0;i<(ri)n;i++)
#define pii pair<ri,ri>
#define uu first
#define vv second
#define row 11
#define col 11

ri  visited[row][col], d[row][col];
char cell[row][col];
ri fx[4]= {1,-1,0,0};
ri fy[4]= {0,0,1,-1};
int sx[26];
int sy[26];
int n;

ri bfs(ri sx, ri sy, ri dx, ri dy)
{
    clr(visited);
    clr(d);

    queue<pii>Q;
    Q.push(pii(sx,sy));
    visited[sx][sy]=1;

    while(!Q.empty())
    {
        pii top= Q.front();

        rep(k,4)
        {
            ri tx= top.uu+fx[k];
            ri ty= top.vv+fy[k];

            if(tx>=0 && tx<n && ty>=0 && ty<n && (cell[tx][ty]=='.' || (tx==dx && ty==dy)) && visited[tx][ty]==0)
            {
                visited[tx][ty]=1;
                d[tx][ty]= d[top.uu][top.vv]+1;
                Q.push(pii(tx,ty));
            }
        }
        Q.pop();

    }

    cell[dx][dy]='.';
    cell[sx][sy]='.';
    return d[dx][dy];
}

int main()
{

    int t,i,j,alpha,kase;

    scanf("%d",&t);
    getchar();

    for(kase=1;kase<=t;kase++)
    {
        alpha=0;
        getchar();

        scanf("%d",&n);
        getchar();

        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                scanf("%c",&cell[i][j]);

                int tmp=cell[i][j];

                if(tmp>='A' && tmp<='Z')
                {
                    if(tmp>alpha)
                        alpha=tmp;

                    sx[tmp-'A']=i;
                    sy[tmp-'A']=j;
                }
            }
            getchar();
        }

        int k=alpha-'A';

        int flag=1,ans=0,dis;
        for(i=0; i<k; i++)
        {
            dis=bfs(sx[i],sy[i],sx[i+1],sy[i+1]);

            if(dis==0)
            {
                flag=0;
                break;
            }
            else
                ans+=dis;
        }

        if(!flag)
            printf("Case %d: Impossible\n",kase);
        else
            printf("Case %d: %d\n",kase,ans);

        clr(sx);
        clr(sy);
        clr(cell);
    }

    return 0;
}
