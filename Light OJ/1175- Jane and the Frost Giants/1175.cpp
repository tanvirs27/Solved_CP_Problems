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
#define row 210
#define col 210

ri visited[row][col], d[row][col],nc[row][col],J[row][col];
int FPx[row*col],FPy[row*col];
char cell[row][col];
ri fx[4]= {1,-1,0,0};
ri fy[4]= {0,0,1,-1};
int R,C;

void fire(int f)
{
    clr(visited);

    int i;

    queue<pii>Q;

    for(i=0;i<f;i++)
    {
        Q.push(pii(FPx[i],FPy[i]));
        visited[FPx[i]][FPy[i]]=1;
        d[FPx[i]][FPy[i]]=0;
    }

    while(!Q.empty())
    {
        pii top= Q.front();

        rep(k,4)
        {
            ri tx= top.uu+fx[k];
            ri ty= top.vv+fy[k];

            if(tx>=0 && tx<R && ty>=0 && ty<C && cell[tx][ty]!='#' && visited[tx][ty]==0)
            {
                visited[tx][ty]=1;
                int dis= d[top.uu][top.vv]+1;

                d[tx][ty]=dis;

                Q.push(pii(tx,ty));
            }
        }
        Q.pop();

    }
}

int escape_plan(int sx,int sy)
{
    clr(visited);

    queue<pii>Q;
    Q.push(pii(sx,sy));
    visited[sx][sy]=1;
    J[sx][sy]=0;

    while(!Q.empty())
    {
        pii top= Q.front();

        rep(k,4)
        {
            ri tx= top.uu+fx[k];
            ri ty= top.vv+fy[k];

            int dis= J[top.uu][top.vv]+1;
            if(!(tx>=0 && tx<R && ty>=0 && ty<C))
            {
                return dis;
            }

            else if(visited[tx][ty]==0 && dis<d[tx][ty] && d[tx][ty]!=-1)
            {
                visited[tx][ty]=1;

                J[tx][ty]=dis;

                Q.push(pii(tx,ty));
            }
        }
        Q.pop();

    }
    return -1;
}

int main()
{

    int t,k,i,j,jx,jy;

    scanf("%d",&t);

    for(k=1;k<=t;k++)
    {
        for(i=0;i<row;i++)
        {
            for(j=0;j<col;j++)
            {
                d[i][j]=50000;
            }

        }
        scanf("%d%d",&R,&C);

        int f=0;
        getchar();
        for(i=0;i<R;i++)
        {
            for(j=0;j<C;j++)
            {
                scanf("%c",&cell[i][j]);

                if(cell[i][j]=='F')
                {
                    FPx[f]=i;
                    FPy[f]=j;
                    f++;
                  //  d[i][j]=-1;
                }
                if(cell[i][j]=='#')
                    d[i][j]=-1;

                if(cell[i][j]=='J')
                {
                    jx=i;
                    jy=j;
                }
            }
            getchar();
        }

        fire(f);

        int ans=escape_plan(jx,jy);


        if(ans==-1)
            printf("Case %d: IMPOSSIBLE\n",k);
        else
            printf("Case %d: %d\n",k,ans);
    }

    return 0;
}

