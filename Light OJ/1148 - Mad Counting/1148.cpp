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
#define DBG(a)  cout << a << endl
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
#define MAX         1000000

int ara[100],M2[100];
map <int,int> M;

int main()
{
    //READ;

    int t,n,ans,a;

    sf(t);

    FRAE(cas,1,t)
    {
        mem(ara,0);
        sf(n);
        int cnt=1;
        FRAE(i,1,n)
        {
            sf(a);
            if(M[a]==0)
            {
                M[a]=cnt++;
                M2[cnt-1]=a;
            }

            ara[M[a]]++;
        }

        ans=0;

        FRA(i,1,cnt)
        {
            int temp= ceil((double)ara[M[M2[i]]]/(M2[i]+1));
            ans+= temp*(M2[i]+1);

        }



        pf("Case %d: %d\n",cas,ans);
        M.clear();
    }


    return 0;
}


