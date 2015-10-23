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
#define MAX         200

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
map <string,int> M;

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

    int t,cas,m,n,i,j,k,ans,a,x;
    char city1[60],city2[60];
    data A;

    sf(t);

    for(cas=1;cas<=t;cas++)
    {
        n=0;
        getchar();
        getchar();

        sf(m);

        while(m--)
        {
            scanf("%s%s%d",city1,city2,&a);

            if(M.find(city1)==M.end())
            {
                M[city1]=n++;
            }

            if(M.find(city2)==M.end())
            {
                M[city2]=n++;
            }

            A.u= M[city1];
            A.v= M[city2];
            A.w=a;

            V.push_back(A);
        }

        ans=mst(n);

        if(ans==-1)
            pf("Case %d: Impossible\n",cas);
        else
            pf("Case %d: %d\n",cas,ans);

        V.clear();
        M.clear();
    }

    return 0;
}

