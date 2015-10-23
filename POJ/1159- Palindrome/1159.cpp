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
#define MAX         5005

short int dp[MAX][MAX];
char word[MAX];

int call(int i,int j)
{
    if(i>=j)
        return 0;

    if(dp[i][j]!=-1)
        return dp[i][j];

    short int ret1,ret2;

    if(word[i]==word[j])
        return dp[i][j]=call(i+1,j-1);

    ret1= 1+ call(i,j-1);
    ret2= 1+ call(i+1,j);

    return dp[i][j]= min(ret1,ret2);
}

int main()
{
    int n;

    while(sf(n)==1)
    {
        mem(dp,-1);
        scanf("%s",word);

        pf("%d\n",call(0,n-1));
    }

    return 0;
}


