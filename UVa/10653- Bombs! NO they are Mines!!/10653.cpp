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
#define row 1000
#define col 1000

ri cell[row][col], visited[row][col], d[row][col];
ri fx[4]= {1,-1,0,0};
ri fy[4]= {0,0,1,-1};

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

            if(tx>=0 && tx<row && ty>=0 && ty<col && cell[tx][ty]!=-1 && visited[tx][ty]==0)
            {
                visited[tx][ty]=1;
                d[tx][ty]= d[top.uu][top.vv]+1;
                Q.push(pii(tx,ty));
            }
        }
        Q.pop();

    }

    return d[dx][dy];
}

int main()
{
  //  READ;
    int r,c,rn,bomb,r1,c1,i,j,sx,sy,dx,dy;

    while(scanf("%d%d",&r,&c)==2)
    {
        if(r==0)break;

        clr(cell);

        scanf("%d",&rn);

        while(rn--)
        {
            scanf("%d%d",&r1,&bomb);

            while(bomb--)
            {
                scanf("%d",&c1);

                cell[r1][c1]=-1;
            }
        }
        scanf("%d%d%d%d",&sx,&sy,&dx,&dy);

        int ans= bfs(sx,sy,dx,dy);

        printf("%d\n",ans);
    }

    return 0;
}

