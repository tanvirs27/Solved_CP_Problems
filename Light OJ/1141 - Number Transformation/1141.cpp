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
#define inf         ((1 << 30) - 1)
#define eps         1e-9
#define MOD         100007
#define MAX         1005

queue <int> Q;
int visited[MAX],d[MAX],prime[MAX];
vector <int> V[MAX];

void sieve()
{
    int i,j;

    prime[1]=1;
    prime[0]=1;

    for(i=4; i<MAX; i+=2)
    {
        prime[i]=1;
        V[i].push_back(2);
    }

    for(i=3; i<MAX; i+=2)
    {
        if(!prime[i])
        {
            for(j=i+i; j<MAX; j+=i)
            {
                prime[j]=1;
                V[j].push_back(i);
            }
        }
    }
}

int bfs(int src, int des)
{
    int i,j;


    for(i=0; i<V[6].size(); i++)
        pf("V %d\n",V[6][i]);

    mem(visited,0);
    mem(d,-1);
    visited[src]=0;
    d[src]=0;
    Q.push(src);

    while(!Q.empty())
    {
        int u= Q.front();
        pf("u= %d\n",u);
        for(i=0; i<V[u].size(); i++)
        {
            int v= u+V[u][i];

            if(!visited[v] && v<=des)
            {
                visited[v]=1;

                d[v]=d[u]+1;

                Q.push(v);
            }
        }
        Q.pop();
    }

    return d[des];
}

int main()
{
    //  READ;

    int t,cas,i,j,k,s,d,ans;
    sieve();

    sf(t);

    for(cas=1; cas<=t; cas++)
    {
        sff(s,d);

        ans= bfs(s,d);

        pf("Case %d: %d\n",cas,ans);
    }

    return 0;
}

