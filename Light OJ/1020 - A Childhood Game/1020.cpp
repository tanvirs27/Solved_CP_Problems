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
#define MAX         200



int main()
{
    //READ;

    int t,n;
    char check[2][20]={"Alice","Bob"};
    char name[20];
    sf(t);

    FRAE(cas,1,t)
    {
        scanf("%d%s",&n,name);

        if(strcmp(name,check[0])==0)
        {
            if(n%3==1)
            {
                pf("Case %d: %s\n",cas,check[1]);
            }
            else
                pf("Case %d: %s\n",cas,check[0]);
        }
        else
        {
            if(n%3==0)
            {
                pf("Case %d: %s\n",cas,check[0]);
            }
            else
                pf("Case %d: %s\n",cas,check[1]);
        }
    }


    return 0;
}


