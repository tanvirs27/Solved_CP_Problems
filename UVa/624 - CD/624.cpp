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
#define all(V) V.begin(),V.end()
#define max(a,b) (a>b) ? (a):(b)
#define min(a,b) (a<b) ? (a):(b)
#define inf         ((1 << 30) - 1)
#define eps         1e-9
#define MOD         100007
#define MAX         200

int CAP,n,len[21],dp[21][10000],dir[21][10000];
bool flag;

void print(int i, int w)
{
    if(dir[i][w]==-1)
        return;

    if(dir[i][w]==1)
    {
        if(flag)
            pf(" ");

        pf("%d",len[i]);
        flag=true;
        print(i+1,w+len[i]);

    }
    else
        print(i+1,w);
}

int knapsack(int i, int taken)
{
    if(i>=n)
        return 0;

    if(dp[i][taken]!=-1)
        return dp[i][taken];

    int ret1=0,ret2=0;

    if(taken+len[i]<=CAP)
    {
        ret1= len[i]+ knapsack(i+1,taken+len[i]);
    }

    ret2= knapsack(i+1,taken);

    if(ret1>ret2)
    {
        dir[i][taken]=1;
        return dp[i][taken]=ret1;
    }
    else
{
        dir[i][taken]=2;
        return dp[i][taken]=ret2;
    }
}


int main()
{
    READ;

    int i,j,k,ans;

    while(sff(CAP,n)==2)
    {
        for(i=0; i<n; i++)
        {
            sf(len[i]);
        }

        mem(dp,-1);
        mem(dir,-1);
        flag=false;

        ans= knapsack(0,0);
        print(0,0);

        pf(" sum:%d\n",ans);
    }

    return 0;
}


