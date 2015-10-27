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
#define inf         ((1 << 30) - 1)
#define eps         1e-9
#define MOD         100007
#define MAX         200

struct result
{
    int mx,mn;
};

int const M= 1<<17; //log2(MAX)

int L[M], T[M][17], par[M],W[M][17],S[M][17];
vector <int> V[M],cost[M];

void dfs(int u, int from, int weight, int lev)
{
    L[u]=lev;
    par[u]=from;
    W[u][0]=weight;
    S[u][0]=weight;

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
                S[i][j]= min(S[i][j-1],S[T[i][j-1]][j-1]);
            }
        }
    }
}

result lca_query(int p, int q, int n)
{
    int temp,i;
    result A;
    A.mn= inf;
    A.mx=-inf;

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
            A.mx= max(A.mx,W[p][i]);
            A.mn= min(A.mn,S[p][i]);
            p= T[p][i];
        }
    }

   //  pf("DBG %d %d %d %d\n",L[p],L[q],p,q);
    if(p==q)
        return A;

    for(i=log2(n); i>=0; i--)
    {
        if(T[p][i]!=-1 && T[p][i]!=T[q][i])
        {
            A.mx= max(A.mx,max(W[p][i],W[q][i]));
            A.mn= min(A.mn,min(S[p][i],S[q][i]));
            p= T[p][i];
            q= T[q][i];
        }

    }
   // pf("%d \n",max(res,max(W[p][0],W[q][0])));
    A.mx= max(A.mx,max(W[p][0],W[q][0]));
    A.mn= min(A.mn,min(S[p][0],S[q][0]));
   // pf("%d\n",res);
    return A;
}

void clear_all(int n)
{
    FRAE(i,0,n)
    {
        V[i].clear();
        cost[i].clear();
    }
}

int main()
{
    READ;

    int t,n,m,q,a,b,c;
    sf(t);

    FRAE(cas,1,t)
    {
        pf("Case %d:\n",cas);
        sf(n);

        FRA(i,0,n-1)
        {
            sfff(a,b,c);

            a--;b--;

            V[a].push_back(b);
            cost[a].push_back(c);

            V[b].push_back(a);
            cost[b].push_back(c);
        }

        FRA(i,0,n)
            par[i]=-1;

        mem(W,-1);
        mem(S,-1);
        dfs(0,-1,0,0);
        lca_init(n);

        //pf("%d %d\n",W[7][0],W[3][0]);
        sf(q);

        FRA(i,0,q)
        {
            sff(a,b);
            a--;b--;

            result X= lca_query(a,b,n);

            pf("%d %d\n",X.mn,X.mx);
        }
        clear_all(n);
    }

    return 0;
}



