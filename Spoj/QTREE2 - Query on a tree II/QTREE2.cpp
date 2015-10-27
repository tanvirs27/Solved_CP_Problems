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

vector <int> V[M],cost[M];
int L[M], T[M][15], par[M],dis[M];

void dfs(int u, int from, int lev)
{
    L[u]=lev;
    par[u]=from;

    FRA(i,0,V[u].size())
    {
        int v= V[u][i];

        if(v==from)continue;

        dis[v]=dis[u]+cost[u][i];
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

    for(j=1;(1<<j)<n;j++)
    {
        for(i=0;i<n;i++)
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

    for(i=log2(n);i>=0;i--)
    {
        if(L[p]- (1<<i) >= L[q])
            p= T[p][i];
    }

   // pf("DBG %d %d\n",L[p],L[q]);
    if(p==q)
        return p;

    for(i=log2(n);i>=0;i--)
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

    for(i=log2(n);i>=0;i--)
    {
        if(L[p]- (1<<i) >= y)
            p= T[p][i];
    }

    return p;
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
  //  READ;

    int t,a,b,c,n,k;
    char choice[50];

    sf(t);
  //  gc;

    FRAE(cas,1,t)
    {
      //  if(cas!=1)
       //     pf("\n");

      //  mem(dis,0);
     //   mem(par,-1);
    //    gc;



        sf(n);

        FRA(i,0,n)
        {
            dis[i]=0;
            par[i]=-1;
        }

        FRA(i,0,n-1)
        {
            sfff(a,b,c);

            V[a-1].push_back(b-1);
            cost[a-1].push_back(c);

            V[b-1].push_back(a-1);
            cost[b-1].push_back(c);
        }

        dfs(0,-1,0);
        lca_init(n);

        while(1)
        {
            scanf("%s",&choice);

            if(choice[1]=='O')
                break;
            else if(choice[0]=='D')
            {
                sff(a,b);

                int u=lca_query(a-1,b-1,n);

              //  pf("%d %d %d\n",a,b,u);
                int ans= dis[a-1]+dis[b-1]-2*dis[u];

                pf("%d\n",ans);

            }
            else
            {
                sfff(a,b,k);
                int node;
                a--;
                b--;
                int u= lca_query(a,b,n);

                if(L[a]-L[u]+1 >= k)
                {
                    node=up(a,L[a]-k+1,n);


                }
                else
                {
                    node= up(b,k-L[a]+2*L[u]-1,n);

                }
                pf("%d\n",node+1);
            }
        }
        printf("\n");
        clear_all(n);
    }

    return 0;
}
