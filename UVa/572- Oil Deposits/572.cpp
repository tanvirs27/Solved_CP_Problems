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
#define pii pair<ri,ri>
#define uu first
#define vv second
#define row 105
#define col 105

char cell[row][col];
ri visited[row][col];
ri fx[8]= {1,-1,0,0,1,1,-1,-1};
ri fy[8]= {0,0,1,-1,1,-1,1,-1};
int ans,m,n;

void bfs(ri sx, ri sy)
{
    ans++;
    int k;

    queue<pii>Q;
    Q.push(pii(sx,sy));
    visited[sx][sy]=1;

    while(!Q.empty())
    {
        pii top= Q.front();

        for(k=0;k<8;k++)
        {
            ri tx= top.uu+fx[k];
            ri ty= top.vv+fy[k];

            if(tx>=0 && tx<m && ty>=0 && ty<n && cell[tx][ty]!='*' && visited[tx][ty]==0)
            {
                visited[tx][ty]=1;
                Q.push(pii(tx,ty));
            }
        }
        Q.pop();
    }
}

int main()
{


    int i,j;

    while(scanf("%d%d",&m,&n)==2)
    {
        clr(cell);
        clr(visited);
        ans=0;

        if(m==0)break;

        getchar();

        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                cell[i][j]=getchar();
            }
            getchar();
        }

        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(cell[i][j]== '@' && visited[i][j]==0)
                    bfs(i,j);
            }
        }

        printf("%d\n",ans);
    }

    return 0;
}
