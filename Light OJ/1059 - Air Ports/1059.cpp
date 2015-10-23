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
#define all(V) V.begin(),V.end()
#define max(a,b) (a>b) ? (a):(b)
#define min(a,b) (a<b) ? (a):(b)
#define inf         ((1 << 30) - 1))
#define eps         1e-9
#define MOD         100007
#define MAX         10005

struct aaa
{
    int u,v,w;
};
typedef struct aaa data;

bool compare (data a, data b)
{
    return a.w<b.w;
}

vector <data> V;
int par[MAX];
int airport;

int find_mother(int r)
{
    if(r==par[r])
        return r;

    return par[r]=find_mother(par[r]);
}

int mst(int n, int a)
{
    airport=0;
    int total_set=n;
    int count=0,cost=0,i,j,u1,v1;

    sort(all(V),compare);

    for(i=1;i<=n;i++)
        par[i]=i;

    for(i=0;i<V.size();i++)
    {
        u1= find_mother(V[i].u);
        v1= find_mother(V[i].v);

        if(u1!=v1)
        {
            count++;


            if(V[i].w>=a)
            {
                airport++;
                cost+=a;

            }
            else
            {
                cost+=V[i].w;
                total_set--;
                par[u1]=v1;
            }




            if(count==n-1)
                break;
        }
    }

    int q=total_set-airport;

    if(q<=0)
        return cost;

    airport=total_set;
    return (cost+(q*a));
}



int main()
{
    READ;

    int cas,t,n,m,a,i,j,k,ans;
    data A;

    sf(t);

    for(cas=1;cas<=t;cas++)
    {
        sfff(n,m,a);

        while(m--)
        {
            sfff(A.u,A.v,A.w);

            V.push_back(A);

        }
        ans= mst(n,a);

        pf("Case %d: %d %d\n",cas,ans,airport);

        V.clear();
    }

    return 0;
}

