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
#define MAX         30

int dp[MAX+1][3];

int call(int n, int m)
{
    if(n==0 && m==0)
        return 1;
    if(n==0)
        return 0;
    if(n==1 && m==1)
        return 1;
    if(n==1)
        return 0;
    if(n<0)
        return 0;

    if(dp[n][m]!=-1)
        return dp[n][m];

    if(m==0)
        return dp[n][m]=2*call(n-1,1)+call(n-2,0);
    if(m==1)
        return dp[n][m]=call(n-1,0)+call(n-1,2);
    if(m==2)
        return dp[n][m]= call(n-1,1);
}

int main()
{
  //  READ;

    int n;

    mem(dp,-1);

    while(scanf("%d",&n)==1)
    {
        if(n==-1)
            break;

        printf("%d\n",call(n,0));
    }

    return 0;
}


