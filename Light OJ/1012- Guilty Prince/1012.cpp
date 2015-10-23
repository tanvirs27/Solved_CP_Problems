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
ri fx[4]= {1,-1,0,0};
ri fy[4]= {0,0,1,-1};
int m,n;

int bfs(ri sx, ri sy)
{
    int k,ans=0;

    queue<pii>Q;
    Q.push(pii(sx,sy));
    visited[sx][sy]=1;
    ans++;

    while(!Q.empty())
    {
        pii top= Q.front();

        for(k=0;k<4;k++)
        {
            ri tx= top.uu+fx[k];
            ri ty= top.vv+fy[k];

            if(tx>=0 && tx<n && ty>=0 && ty<m && cell[tx][ty]!='#' && visited[tx][ty]==0)
            {
                visited[tx][ty]=1;
                ans++;
                Q.push(pii(tx,ty));
            }
        }
        Q.pop();
    }
    return ans;
}

int main()
{


    int i,j,k,sx,sy,t,ans;

    scanf("%d",&t);

    for(k=1;k<=t;k++)
    {
        scanf("%d%d",&m,&n);

        clr(cell);
        clr(visited);

        getchar();

        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                cell[i][j]=getchar();

                if(cell[i][j]=='@')
                {
                    sx=i;
                    sy=j;
                }
            }
            getchar();
        }

        ans=bfs(sx,sy);

        printf("Case %d: %d\n",k,ans);
    }

    return 0;
}

