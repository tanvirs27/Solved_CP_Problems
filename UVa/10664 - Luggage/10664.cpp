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

int ara[21];
int dp[21][105];
int n;

int coin(int i, int amount)
{
    if(i>=n)
    {
        if(amount==0)
            return 1;
        else
            return 0;
    }
    if(dp[i][amount]!=-1)
        return dp[i][amount];

    int ret1=0,ret2=0;

    if(amount-ara[i]>=0)
        ret1= coin(i+1,amount-ara[i]);
    ret2= coin(i+1,amount);

    return ret1 | ret2;

}

int main()
{
    READ;

    int t,i,j,k,sum;

    sf(t);

    while(t--)
    {
        i=0;
        sum=0;

        while(1)
        {
            sf(ara[i++]);

            sum+=ara[i-1];
            char ch=getchar();

            if(ch=='\n')
                break;
        }

        n=i;
        if(sum%2==1)
        {
            pf("NO\n");
            continue;
        }


        mem(dp,-1);
        int flag=coin(0,sum/2);

        if(flag==1)
            pf("YES\n");
        else
            pf("NO\n");
    }

    return 0;
}

