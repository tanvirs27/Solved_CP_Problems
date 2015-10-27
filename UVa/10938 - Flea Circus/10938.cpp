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
#define FRA(i,a,b) for(int i=a; i<b; i++)
#define FRAE(i,a,b) for(int i=a; i<=b; i++)
#define FRD(i,a,b) for(int i=a; i>b; i--)
#define FRDE(i,a,b) for(int i=a; i>=b; i--)
#define all(V) V.begin(),V.end()
#define max(a,b) (a>b) ? (a):(b)
#define min(a,b) (a<b) ? (a):(b)
#define inf         ((1 << 30) - 1)
#define eps         1e-9
#define MOD         100007
#define MAX         1<<14

int const M= 1<<15;

vector <int> V[M];
int L[M], T[M][15], par[M],dis[M];

void dfs(int u, int from, int lev)
{
    L[u]=lev;
    par[u]=from;

    FRA(i,0,V[u].size())
    {
        int v= V[u][i];

        if(v==from)continue;

        dis[v]=dis[u]+1;
        dfs(v,u,lev+1);
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
            }
        }
    }
}

int lca_query(int p, int q, int n)
{
    int temp,i;

    if(L[p]<L[q])
    {
        temp= p;
        p= q;
        q= temp;
    }

    for(i=log2(n); i>=0; i--)
    {
        if(L[p]- (1<<i) >= L[q])
            p= T[p][i];
    }

    // pf("DBG %d %d\n",L[p],L[q]);
    if(p==q)
        return p;

    for(i=log2(n); i>=0; i--)
    {
        if(T[p][i]!=-1 && T[p][i]!=T[q][i])
        {
            p= T[p][i];
            q= T[q][i];
        }

    }

    return par[p];
}

int up(int p, int y,int n)
{
    int i;

    for(i=log2(n); i>=0; i--)
    {
        if(L[p]- (1<<i) >= y)
            p= T[p][i];
    }

    return p;
}

int find_kth(int a, int b, int u, int n, int k)
{
    if(L[a]-L[u]+1 >= k)
    {
        return up(a,L[a]-k+1,n);
    }
    else
    {
        return up(b,k-L[a]+2*L[u]-1,n);
    }
}

void clear_all(int n)
{
    FRAE(i,0,n)
    {
        V[i].clear();
    }
}

int main()
{
    //  READ;

    int t,a,b,q,c,n,k;
    char choice[50];

    while(sf(n)==1 && n)
    {
        FRA(i,0,n-1)
        {
            sff(a,b);

            a--;
            b--;
            V[a].push_back(b);
            V[b].push_back(a);
        }

        FRA(i,0,n)
        {
            dis[i]=0;
            par[i]=-1;
        }

        dfs(0,-1,0);
        lca_init(n);

        sf(q);
        FRA(i,0,q)
        {
            sff(a,b);
            a--;
            b--;
            int u= lca_query(a,b,n);
            int d= dis[a]+dis[b]-2*dis[u];

            if(d%2==0)
            {
                k=d/2;

                int ans= find_kth(a,b,u,n,k+1);

                pf("The fleas meet at %d.\n",ans+1);
            }
            else
            {
                k= (d+1)/2;
                int ans1= find_kth(a,b,u,n,k);
                int ans2= find_kth(a,b,u,n,k+1);

                if(ans1>ans2)
                    swap(ans1,ans2);

                pf("The fleas jump forever between %d and %d.\n",ans1+1,ans2+1);
            }
        }
        clear_all(n);
    }




    return 0;
}

