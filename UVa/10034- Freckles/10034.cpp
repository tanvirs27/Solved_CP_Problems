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
#define FR1(i,k) for(i=1;i<=k;i++)
#define FR0(i,k) for(i=0;i<k;i++)
#define pf printf
#define sq(a) (a*a)
#define inf         (1 << 30 - 1)
#define eps         1e-9
#define MOD         100007
#define MAX         100000


struct aaa
{
    int u,v;
    db w;
};
typedef struct aaa data;

struct bbb
{
    db x,y;
};
typedef struct bbb point;

bool compare(data a, data b)
{
    return a.w<b.w;
}

int par[MAX];
vector <data> A;
vector <point> B;

int find_mother(int r)
{
    if(par[r]==r)
        return r;

    par[r]=find_mother(par[r]);

    return par[r];
}

db mst(int n)
{
    sort(A.begin(),A.end(),compare);

    int i,u1,v1,m,count=0;
    db cost=0;

    for(i=0;i<n;i++)
        par[i]=i;

    for(i=0;i<A.size();i++)
    {
        u1= find_mother(A[i].u);
        v1= find_mother(A[i].v);

        if(u1!=v1)
        {
            par[u1]=v1;
            count++;
            cost+=A[i].w;
            if(count==n-1)
                break;
        }
    }
    return cost;
}

db dis(point T, point S)
{
    return sqrt(sq((T.x-S.x))+sq((T.y-S.y)));
}

int main()
{
   // READ;

    int t,i,j,k,m,flag=0;
    db x,y;
    point Z;

    sf(t);

    while(t--)
    {
        getchar();
        getchar();

        sf(m);

        if(flag)
            puts("");
        flag=1;

        for(i=0;i<m;i++)
        {
            scanf("%lf%lf",&Z.x,&Z.y);

           B.push_back(Z);
        }

        for(i=0;i<m;i++)
        {
            for(j=i+1;j<m;j++)
            {
                db d= dis(B[i],B[j]);

                data X;
                X.u=i;
                X.v=j;
                X.w=d;

                A.push_back(X);
            }
        }
        pf("%.2lf\n",mst(m));

        A.clear();
        B.clear();
        mem(par,0);
    }

    return 0;
}

