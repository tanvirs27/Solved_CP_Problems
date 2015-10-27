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
#define FRA(i,a,b) for(int i=a; i<b; i++)
#define FRAE(i,a,b) for(int i=a; i<=b; i++)
#define FRD(i,a,b) for(int i=a; i>b; i--)
#define FRDE(i,a,b) for(int i=a; i>=b; i--)
#define all(V) V.begin(),V.end()
#define inf         ((1 << 30) - 1))
#define eps         1e-9
#define MOD         100007
#define MAX         200

struct data
{
    int u,v,w;
};

bool compare (data a, data b)
{
    return a.w<b.w;
}

int const M= 1<<16; //log2(MAX)

int L[M], T[M][16], par[M],W[M][16];
vector <data> V1;
vector <int> V[M],cost[M];

int find_mother(int r)
{
    if(r==par[r])
        return r;

    return par[r]=find_mother(par[r]);
}

void mst(int n)
{
    int count=0,i,j,u1,v1;

    sort(all(V1),compare);

    for(i=0;i<n;i++)
        par[i]=i;

    for(i=0;i<V1.size();i++)
    {
        u1= find_mother(V1[i].u);
        v1= find_mother(V1[i].v);

        if(u1!=v1)
        {
            count++;
            V[V1[i].u].push_back(V1[i].v);
            cost[V1[i].u].push_back(V1[i].w);

            V[V1[i].v].push_back(V1[i].u);
            cost[V1[i].v].push_back(V1[i].w);

            par[u1]=v1;

            if(count==n-1)
                break;
        }
    }
    return;
}

void dfs(int u, int from, int weight, int lev)
{
    L[u]=lev;
    par[u]=from;
    W[u][0]=weight;

    FRA(i,0,V[u].size())
    {
        int v= V[u][i];

        if(v==from)continue;

        dfs(v,u,cost[u][i],lev+1);
    }
}

void lca_init(int n)
{
    mem(T,-1);

    int i,j;

    FRA(i,0,n)
    {
        T[i][0]=par[i];
    }

    for(j=1; (1<<j)<n; j++)
    {
        for(i=0; i<n; i++)
        {
            if(T[i][j-1]!=-1)
            {
                T[i][j]= T[T[i][j-1]][j-1];
                W[i][j]= max(W[i][j-1],W[T[i][j-1]][j-1]);
            }
        }
    }
}

int lca_query(int p, int q, int n)
{
    int temp,i;
    int res = -999999;

    if(L[p]<L[q])
    {
        temp= p;
        p= q;
        q= temp;
    }

    for(i=log2(n); i>=0; i--)
    {
        if(L[p]- (1<<i) >= L[q])
        {
            res= max(res,W[p][i]);
            p= T[p][i];
        }
    }

   //  pf("DBG %d %d %d %d\n",L[p],L[q],p,q);
    if(p==q)
        return res;

    for(i=log2(n); i>=0; i--)
    {
        if(T[p][i]!=-1 && T[p][i]!=T[q][i])
        {
            res= max(res,max(W[p][i],W[q][i]));
            p= T[p][i];
            q= T[q][i];
        }

    }
   // pf("%d \n",max(res,max(W[p][0],W[q][0])));
    res= max(res,max(W[p][0],W[q][0]));
   // pf("%d\n",res);
    return res;
}

void clear_all(int n)
{
    FRAE(i,0,n)
    {
        V[i].clear();
        cost[i].clear();
    }
    V1.clear();
}

int main()
{
    READ;

    int t,n,m,q,a,b,c;
    data X;
    sf(t);

    FRAE(cas,1,t)
    {
        pf("Case %d:\n",cas);
        sff(n,m);

        FRA(i,0,m)
        {
            sfff(a,b,c);

            a--;b--;
            X.u=a;
            X.v=b;
            X.w=c;

            V1.push_back(X);
        }

        mst(n);

        FRA(i,0,n)
            par[i]=-1;

        mem(W,-1);
        dfs(0,-1,0,0);
        lca_init(n);

        //pf("%d %d\n",W[7][0],W[3][0]);
        sf(q);

        FRA(i,0,q)
        {
            sff(a,b);
            a--;b--;
            pf("%d\n",lca_query(a,b,n));
        }
        clear_all(n);
    }

    return 0;
}


