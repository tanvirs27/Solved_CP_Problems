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

#define ll long long int
#define db double
#define mem(a,b) memset((a),b,sizeof(a))
#define READ freopen("c:\\Users\\Rifat\\Desktop\\in.txt", "r", stdin)
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d%d", &a, &b)
#define sfff(a,b,c) scanf("%d%d%d", &a, &b, &c)
#define pf printf
#define gc getchar()
#define DBG(a) printf("in %d\n",a)
#define all(V) V.begin(),V.end()
#define max(a,b) (a>b) ? (a):(b)
#define min(a,b) (a<b) ? (a):(b)
#define inf         ((1 << 30) - 1)
#define eps         1e-9
#define MOD         100007
#define MAX         35

struct node
{
    int xx,yy,zz;
};

int G[MAX][MAX][MAX],dis[MAX][MAX][MAX],visited[MAX][MAX][MAX];
int L,R,C;
queue <node> Q;

int fx[]= {1,-1,0,0,0,0};
int fy[]= {0,0,0,0,1,-1};
int fz[]= {0,0,1,-1,0,0};

void bfs(node src)
{
    mem(dis,-1);
    mem(visited,0);

    visited[src.xx][src.yy][src.zz]=1;
    dis[src.xx][src.yy][src.zz]=0;
    Q.push(src);

    while(!Q.empty())
    {
        node V= Q.front();
        Q.pop();

        int vx,vy,vz;

        for(int i=0;i<6;i++)
        {
            vx= fx[i]+ V.xx;
            vy= fy[i]+ V.yy;
            vz= fz[i]+ V.zz;

            if(vx>=0 && vx<L && vy>=0 && vy<R && vz>=0 && vz<C && G[vx][vy][vz]!='#' && visited[vx][vy][vz]==0)
            {
                visited[vx][vy][vz]=1;
                dis[vx][vy][vz]=dis[V.xx][V.yy][V.zz]+1;

                node X;
                X.xx=vx;
                X.yy=vy;
                X.zz=vz;
                Q.push(X);
            }
        }
    }
}

int main()
{
   // READ;

    int i,j,k;
    node S,D;

    while(sfff(L,R,C)==3 && L && R && C)
    {
        gc;

        for(i=0;i<L;i++)
        {
            for(j=0;j<R;j++)
            {
                for(k=0;k<C;k++)
                {
                    G[i][j][k]=gc;

                    if(G[i][j][k]=='S')
                    {
                        S.xx=i;
                        S.yy=j;
                        S.zz=k;
                    }
                    if(G[i][j][k]=='E')
                    {
                        D.xx=i;
                        D.yy=j;
                        D.zz=k;
                    }

                }
                gc;
            }
            gc;
        }
        bfs(S);

        if(dis[D.xx][D.yy][D.zz]!=-1)
            pf("Escaped in %d minute(s).\n",dis[D.xx][D.yy][D.zz]);
        else
            pf("Trapped!\n");
    }

    return 0;
}


