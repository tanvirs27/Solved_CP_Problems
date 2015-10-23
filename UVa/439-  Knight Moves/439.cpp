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
#define row 8
#define col 8

ri cell[row][col], visited[row][col], d[row][col];
ri fx[8]= {1,-1,2,-2,1,-1,2,-2};
ri fy[8]= {2,2,1,1,-2,-2,-1,-1};

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

        rep(k,8)
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
   // READ;
    char a,b,c,d,e;
    int sx,sy,dx,dy;

    while(scanf("%c%c%c%c%c",&a,&b,&c,&d,&e)==5)
    {
        getchar();
        sx=a-'a';
        sy=b-'1';
        dx=d-'a';
        dy=e-'1';

        int ans=bfs(sx,sy,dx,dy);

        printf("To get from %c%c to %c%c takes %d knight moves.\n",a,b,d,e,ans);
    }
    return 0;
}

