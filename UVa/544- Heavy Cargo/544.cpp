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
#define inf         (1 << 30 - 1)
#define eps         1e-9
#define MOD         100007
#define MAX         100000

struct data
{
    int value,w;

    bool operator < (const data& p)const
    {
        return w<p.w;
    }
};


map <string,int> city;
vector <int> cost[MAX];
vector <int> node[MAX];
priority_queue <data> Q;
int visited[MAX];

int mst(int src,int des)
{
    int i,ans=inf,count=0,u,v;
    bool flag=true;


    u=src;
    while(flag)
    {

        visited[u]=1;

        for(i=0; i<node[u].size(); i++)
        {
            v=node[u][i];

            if(!visited[v])
            {
                data X;
                X.value=v;
                X.w=cost[u][i];

                Q.push(X);
            }

        }

        if(Q.empty())
        {
            ans=0;
            break;
        }
        data Y= Q.top();
        Q.pop();

        v=Y.value;

        if(!visited[v])
            ans=min(ans,Y.w);

        if(v==des)
            flag=false;

        u=v;
    }
    return ans;
}

void clear_all(int n)
{
    int i;
    mem(visited,0);

    for(i=1; i<=n; i++)
        node[i].clear();
    for(i=1; i<=n; i++)
        cost[i].clear();
    city.clear();
    while(!Q.empty())
        Q.pop();
}

int main()
{
    READ;

    int n,m,i,j,k,w0,count,cas=1;
    char city1[40],city2[40];

    while(sff(n,m)==2 && n)
    {

        getchar();
        count=1;

        FR0(i,m)
        {
            scanf("%s%s%d",city1,city2,&w0);
            getchar();

            if(city.find(city1)==city.end())
            {
                city[city1]=count++;
            }

            if(city.find(city2)==city.end())
            {
                city[city2]=count++;
            }

            node[city[city1]].push_back(city[city2]);
            cost[city[city1]].push_back(w0);

            node[city[city2]].push_back(city[city1]);
            cost[city[city2]].push_back(w0);
        }

        scanf("%s%s",city1,city2);

        pf("Scenario #%d\n",cas++);
        pf("%d tons\n\n",mst(city[city1],city[city2]));

        clear_all(n);
    }

    return 0;
}

