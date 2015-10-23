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
int level_A[MAX][MAX],level_B[MAX][MAX],level_C[MAX][MAX];
queue <data> QA;
queue <data> QB;
queue <data> QC;
int fx[4]={1,0,-1,0};
int fy[4]={0,1,0,-1};
int row,col;
int ans[3];

bool check(int a, int b)
{
    int i;

    if(a==destination[0].x && b==destination[0].y)
    {
        return true;
    }

    return false;
}

void all_clear()
{
    while(!QA.empty())
        QA.pop();
    while(!QB.empty())
        QB.pop();
    while(!QC.empty())
        QC.pop();

    robot.clear();
    destination.clear();
}

void bfs()
{
    int tx_A,tx_B,tx_C,ty_A,ty_B,ty_C,i;
    data X;
    mem(visit_A,0);
    mem(visit_B,0);
    mem(visit_C,0);
    mem(level_A,0);
    mem(level_B,0);
    mem(level_C,0);

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



    while(flag_A || flag_B || flag_C)
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


            tx_C= C.x+fx[i];
            ty_C= C.y+fy[i];



            if(tx_A>=0 && tx_A<row && ty_A>=0 && ty_A<col && cell[tx_A][ty_A]!='#' && cell[tx_A][ty_A]!='m' && visit_A[tx_A][ty_A]==0 && flag_A)
            {
                visit_A[tx_A][ty_A]=1;
                level_A[tx_A][ty_A]= level_A[A.x][A.y]+1;

             //   pf("A %d %d %d\n",tx_A,ty_A,level_A[tx_A][ty_A]);

                if(check(tx_A,ty_A))
                {
               //     pf("A %d %d %d yes\n",tx_A,ty_A,level_A[tx_A][ty_A]);
                     ans[count++]=level_A[tx_A][ty_A];
                     flag_A=false;
                }

                if(count==3)
                    return;

                X.x=tx_A;
                X.y=ty_A;
                QA.push(X);
            }

            if(tx_B>=0 && tx_B<row && ty_B>=0 && ty_B<col && cell[tx_B][ty_B]!='#' && cell[tx_B][ty_B]!='m' && visit_B[tx_B][ty_B]==0 && flag_B)
            {
                visit_B[tx_B][ty_B]=1;
                level_B[tx_B][ty_B]= level_B[B.x][B.y]+1;

            //    pf("B %d %d %d\n",tx_B,ty_B,level_B[tx_B][ty_B]);

                if(check(tx_B,ty_B))
                {
                  //  pf("B %d %d %d yes\n",tx_B,ty_B,level_B[tx_B][ty_B]);

                     ans[count++]=level_B[tx_B][ty_B];
                     flag_B=false;
                }

                if(count==3)
                    return;

                X.x=tx_B;
                X.y=ty_B;
                QB.push(X);
            }


            if(tx_C>=0 && tx_C<row && ty_C>=0 && ty_C<col && cell[tx_C][ty_C]!='#' && cell[tx_C][ty_C]!='m'&& visit_C[tx_C][ty_C]==0 && flag_C)
            {
                visit_C[tx_C][ty_C]=1;
                level_C[tx_C][ty_C]= level_C[C.x][C.y]+1;

             //   pf("C %d %d %d\n",tx_C,ty_C,level_C[tx_C][ty_C]);

                if(check(tx_C,ty_C))
                {
                //    pf("C %d %d %d yes\n",tx_C,ty_C,level_C[tx_C][ty_C]);

                     ans[count++]=level_C[tx_C][ty_C];
                     flag_C=false;
                }

                if(count==3)
                    return;

                X.x=tx_C;
                X.y=ty_C;
                QC.push(X);
            }

        }

        if(!QA.empty())
            QA.pop();
        if(!QB.empty())
            QB.pop();
        if(!QC.empty())
            QC.pop();
    }
    //pf("%d\n",count);
    return;
}

int main()
{
    READ;

    int cas,t,i,j,k;
    data X;

    sf(t);

    for(cas=1;cas<=t;cas++)
    {

        sff(row,col);
        gc;

        for(i=0;i<row;i++)
        {
            for(j=0;j<col;j++)
            {
                scanf("%c",&cell[i][j]);

                if(cell[i][j]=='a' ||  cell[i][j]=='b' || cell[i][j]=='c')
                {
                    X.x=i;
                    X.y=j;
                    robot.push_back(X);
                }
                else if(cell[i][j]=='h')
                {
                    X.x=i;
                    X.y=j;
                    destination.push_back(X);
                }
            }
            gc;
        }

        bfs();
        sort(ans,ans+3);

        pf("Case %d: %d\n",cas,ans[2]);

        all_clear();
    }

    return 0;
}


