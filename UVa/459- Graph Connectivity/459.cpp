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
#define READ freopen("c:\\Users\\User\\Desktop\\in.txt", "r", stdin)
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

int par[30];
int ans;

void makeSet(int n)
{
    ans=n+1;
    int i;
    for(i=0;i<=n;i++)
        par[i]=i;

    return;
}

int find(int a)
{
    if(par[a]==a)
        return a;

    return par[a]=find(par[a]);
}

void Union(int a, int b)
{
    int u= find(a);
    int v= find(b);

    if(u!=v)
    {
        par[u]=v;
        ans--;
    }

    return;
}


int main()
{
  //  READ;

    int t,i,j,k;
    char a,b,c,dummy,s[10];

    sf(t);

    getchar();
    getchar();

    for(k=0;k<t;k++)
    {
        if(k!=0)
            puts("");

        mem(par,0);

        gets(s);
       // getchar();

        makeSet(s[0]-65);

        while(gets(s) && s[0])
        {
           // getchar();
            Union(s[0]-65,s[1]-65);

        }


        pf("%d\n",ans);
    }

    return 0;
}
