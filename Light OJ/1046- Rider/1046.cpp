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
#define all(V) V.begin(),V.end()
#define max(a,b) (a>b) ? (a):(b)
#define min(a,b) (a<b) ? (a):(b)
#define inf         ((1 << 30) - 1)
#define eps         1e-9
#define MOD         100007
#define MAX         15

struct node
{
    int r,c;
};

vector <int> V;
vector <node> knight;
queue <node> Q;
int visited[MAX][MAX], dis[MAX][MAX];
int fx[8]={1,2,1,-2,-1,2,-1,-2};
int fy[8]={2,1,-2,1,2,-1,-2,-1};
int n,m;
char ara[MAX][MAX];

void all_clear()
{
    V.clear();
    knight.clear();


}

int bfs(node src, node des)
{
    if(src.r==des.r && src.c==des.c)
        return 0;
    node X,Y;
    mem(visited,0);
    mem(dis,0);

    while(!Q.empty())
        Q.pop();

    visited[src.r][src.c]=1;
    Q.push(src);

    while(!Q.empty())
    {
        int tx,ty,i;

        X=Q.front();

        for(i=0;i<8;i++)
        {
            tx=X.r+fx[i];
            ty=X.c+fy[i];

            if(tx>=0 && tx<n && ty>=0 && ty<m && visited[tx][ty]==0)
            {
                visited[tx][ty]=1;
                dis[tx][ty]=dis[X.r][X.c]+1;

            //    pf("bfs= %d %d %d\n",tx,ty,dis[tx][ty]);

                Y.r=tx;
                Y.c=ty;

                if(Y.r==des.r && Y.c==des.c)
                    return dis[tx][ty];

                Q.push(Y);
            }
        }
        Q.pop();
    }
    return -1;
}

int main()
{
    READ;

    int t,cas,i,j,k,ans,result,mov;
    node X,Y;

    sf(t);

    for(cas=1;cas<=t;cas++)
    {
        sff(n,m);
        gc;

        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                ara[i][j]=gc;

                if(ara[i][j]>='1' && ara[i][j]<='9')
                {
                    X.r=i;
                    X.c=j;
                    V.push_back(ara[i][j]-'0');
                    knight.push_back(X);
                }
            }
            gc;
        }

        for(i=0,result=inf;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                X.r=i;
                X.c=j;

                for(k=0,ans=0;k<knight.size();k++)
                {
                   // if(k==2)
                   //     pf("start\n");
                  //  pf("%d %d %d\n",knight[k].r,knight[k].c,V[k]);
                    Y=knight[k];

                    mov=bfs(Y,X);

                 //   pf("%d %d %d\n",X.r,X.c,mov);

                    if(mov==-1)
                    {
                        ans=inf;
                        break;
                    }

                    if(mov%V[k]==0)
                    {
                        mov=mov/V[k];
                    }
                    else
                        mov=mov/V[k]+1;

                    ans+=mov;
                }
                result=min(ans,result);

            }

        }

        if(result==inf)
            pf("Case %d: -1\n",cas);
        else
            pf("Case %d: %d\n",cas,result);

        all_clear();
    }

    return 0;
}

