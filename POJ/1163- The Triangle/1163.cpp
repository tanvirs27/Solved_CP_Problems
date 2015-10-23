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
#define MAX         110

int num[MAX][MAX],dp[MAX][MAX],n;

int call(int i, int j)
{
    if(i>n || j<0 || j>=i)
        return 0;

    if(dp[i][j]!=-1)
        return dp[i][j];

    int ret1,ret2;

    ret1= num[i][j]+ call(i+1,j);
    ret2= num[i][j]+ call(i+1,j+1);

    return dp[i][j]= max(ret1,ret2);
}

int main()
{
   // READ;
    int i,j;

    while(sf(n)==1)
    {
        mem(dp,-1);

        for(i=1;i<=n;i++)
        {
            for(j=0;j<i;j++)
            {
                sf(num[i][j]);
            }
        }
        pf("%d\n",call(1,0));
    }

    return 0;
}


