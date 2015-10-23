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
#define MAX         100000

char sen[MAX];
int dp[MAX],n;

int call(int i)
{
    if(i>=n-1)
        return 1;

    if(dp[i]!=-1)
        return dp[i];

    int a,b,c=-1;
    a=sen[i]-48;
    b=sen[i+1]-48;

    if(i+2<n)
        c=sen[i+2]-48;

    if(b==0)
    {
        if(a<3)
            return dp[i]=call(i+2);
    }

    if(a==1 && c!=0)
        return dp[i]= call(i+1)+call(i+2);
    if(a>2 || b>6)
        return dp[i]= call(i+1);
    if(a<3 && c==0)
        return dp[i]= call(i+1);
    if(b<7)
        return dp[i]= call(i+2)+ call(i+1);
}

int main()
{
    READ;

    while(scanf("%s",sen)==1)
    {
        mem(dp,-1);
        if(strcmp(sen,"0")==0)
            break;

        n= strlen(sen);

        pf("%d\n",call(0));
    }

    return 0;
}


