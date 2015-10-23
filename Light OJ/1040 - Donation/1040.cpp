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
#define inf         ((1 << 30) - 1))
#define eps         1e-9
#define MOD         100007
#define MAX         100000

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

int find_mother(int r)
{
    if(r==par[r])
        return r;

    return par[r]=find_mother(par[r]);
}

int mst(int n)
{
    int count=0,cost=0,i,j,u1,v1;

    sort(all(V),compare);

    for(i=0;i<n;i++)
        par[i]=i;

    for(i=0;i<V.size();i++)
    {
        u1= find_mother(V[i].u);
        v1= find_mother(V[i].v);

        if(u1!=v1)
        {
            count++;
            cost+=V[i].w;
            par[u1]=v1;

            if(count==n-1)
                break;
        }
    }
    if(count==n-1)
        return cost;
    return -1;
}

int main()
{
    READ;

    int n,t,cas,i,j,total,min,a;
    data A;

    sf(t);

    for(cas=1;cas<=t;cas++)
    {
        total=0;
        getchar();
        getchar();

        sf(n);

        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                sf(a);
                total+=a;

                if(a)
                {
                   A.u=i;
                   A.v=j;
                   A.w=a;

                   V.push_back(A);
                }
            }
        }

        min= mst(n);

        if(min==-1)
            pf("Case %d: -1\n",cas);
        else
            pf("Case %d: %d\n",cas,total-min);

        V.clear();
    }

    return 0;
}

