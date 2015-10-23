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
#define inf         ((1 << 30) - 1))
#define eps         1e-9
#define MOD         100007
#define MAX         30005

struct data
{
    int val,idx;

    data(int a, int b)
    {
        val=a;
        idx=b;
    }
};

stack <data> S;
int ara[MAX];

int main()
{
    READ;

    int t,cas,n,i,j,k,ans,area;

    sf(t);

    for(cas=1;cas<=t;cas++)
    {
        sf(n);

        S.push(data(-inf,0));

        ans=-inf;

        for(i=1;i<=n;i++)
        {
            sf(ara[i]);

            data X= S.top();
            if(X.val<=ara[i])
            {
                S.push(data(ara[i],i));
            }
            else
            {
                while(S.top().val>ara[i])
                {
                    data Y= S.top();
                    S.pop();

                    if(!Y.idx)
                        break;

                    area= (i-S.top().idx-1)*Y.val;

                    //if(Y.idx)
                        ans= max(area,ans);



                //    pf("area %d ans %d idx %d val %d\n",area,ans,Y.idx,Y.val);
                }
                S.push(data(ara[i],i));
            }
        }


        while(!S.empty())
        {
            data Y= S.top();
            S.pop();

            if(!Y.idx)
                continue;

            area= (i-S.top().idx-1)*Y.val;
            //pf("%d %d %d %d\n",i,Y.idx,Y.val,area);
         //   pf("# area %d ans %d idx %d val %d\n",area,ans,Y.idx,Y.val);
                ans= max(area,ans);
        }
        pf("Case %d: %d\n",cas,ans);
    }

    return 0;
}


