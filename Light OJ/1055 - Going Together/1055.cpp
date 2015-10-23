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
#define inf         ((1 << 30) - 1))
#define eps         1e-9
#define MOD         100007
#define MAX         100

struct data
{
    int x,y;
};

char cell[MAX][MAX];
vector <data> robot;
vector <data> destination;
int visit_A[MAX][MAX],visit_B[MAX][MAX],visit_C[MAX][MAX];
int level[MAX][MAX];
queue <data> QA;
queue <data> QB;
queue <data> QC;
int fx[4]={1,0,-1,0};
int fy[4]={0,1,0,-1};
int n;

bool check(int a, int b)
{
    int i;
    for(i=0;i<3;i++)
    {
        if(a==destination[i].x && b==destination[i].y)
        {
            cell[a][b]='#';
            return true;
        }


    }
    return false;
}

int bfs()
{
    int tx_A,tx_B,tx_C,ty_A,ty_B,ty_C,i;
    data X;
    mem(visit_A,0);
    mem(visit_B,0);
    mem(visit_C,0);

    visit_A[robot[0].x][robot[0].y]=1;
    visit_B[robot[1].x][robot[1].y]=1;
    visit_C[robot[2].x][robot[2].y]=1;

    QA.push(robot[0]);
    QB.push(robot[1]);
    QC.push(robot[2]);

    bool flag_A=true;
    bool flag_B=true;
    bool flag_C=true;
    int count=0;

    while(!QA.empty() || !QB.empty() || !QC.empty())
    {
        data A,B,C;

        if(!QA.empty())
            A= QA.front();
        if(!QB.empty())
            B= QB.front();
        if(!QC.empty())
            C= QC.front();

        for(i=0;i<4;i++)
        {
            tx_A= A.x+fx[i];
            ty_A= A.y+fy[i];

            tx_B= B.x+fx[i];
            ty_B= B.y+fy[i];

            if(tx_B==tx_A && ty_A==ty_B)
            {
                tx_B=MAX-1;
                ty_B=MAX-1;
            }

            tx_C= C.x+fx[i];
            ty_C= C.y+fy[i];

            if((tx_C==tx_A && ty_C==ty_A) || (tx_C==tx_B && ty_C==ty_B))
            {
                tx_C=MAX-1;
                ty_C=MAX-1;
            }

            if(tx_A>=0 && tx_A<n && ty_A>=0 && ty_A<n && cell[tx_A][ty_A]!='#' && visit_C[tx_A][ty_A]==0 && flag_A)
            {
                visit_A[tx_A][ty_A]=1;
                level[tx_A][ty_A]= level[A.x][A.y]+1;

                if(check(tx_A,ty_A))
                {
                     count++;
                     flag_A=false;
                }

                if(count==3)
                    return level[tx_A][ty_A];

                X.x=tx_A;
                X.y=ty_A;
                QA.push(X);
            }
            else
            {
                tx_A=A.x;
                ty_A=A.y;
            }


            if(tx_B!=MAX-1 && ty_B!=MAX-1 && tx_B>=0 && tx_B<n && ty_B>=0 && ty_B<n && cell[tx_B][ty_B]!='#' && visit_C[tx_B][ty_B]==0 && flag_B)
            {
                visit_B[tx_B][ty_B]=1;
                level[tx_B][ty_B]= level[B.x][B.y]+1;

                if(check(tx_B,tx_B))
                {
                     count++;
                     flag_B=false;
                }

                if(count==3)
                    return level[tx_B][ty_B];

                X.x=tx_B;
                X.y=ty_B;
                QB.push(X);
            }
            else
            {
                tx_B=B.x;
                ty_B=B.y;
            }

            if(tx_C!=MAX-1 && ty_C!=MAX-1 && tx_C>=0 && tx_C<n && ty_C>=0 && ty_C<n && cell[tx_C][ty_C]!='#' && visit_C[tx_C][ty_C]==0 && flag_C)
            {
                visit_C[tx_C][ty_C]=1;
                level[tx_C][ty_C]= level[C.x][C.y]+1;

                if(check(tx_C,tx_C))
                {
                     count++;
                     flag_C=false;
                }

                if(count==3)
                    return level[tx_C][ty_C];

                X.x=tx_C;
                X.y=ty_C;
                QC.push(X);
            }
            else
            {
                tx_C=C.x;
                ty_C=C.y;
            }


        }

        if(!QA.empty())
            QA.pop();
        if(!QB.empty())
            QB.pop();
        if(!QC.empty())
            QC.pop();    }
    return -1;
}

int main()
{
//    READ;

    int cas,t,i,j,k,ans;
    data X;

    sf(t);

    for(cas=1;cas<=t;cas++)
    {
        sf(n);
        gc;

        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%c",&cell[i][j]);

                if(cell[i][j]=='A' ||  cell[i][j]=='B' || cell[i][j]=='C')
                {
                    X.x=i;
                    X.y=j;
                    robot.push_back(X);
                }
                else if(cell[i][j]=='X')
                {
                    X.x=i;
                    X.y=j;
                    destination.push_back(X);
                }
            }
            gc;
        }

        ans=bfs();

        pf("%d\n",ans);
    }

    return 0;
}

