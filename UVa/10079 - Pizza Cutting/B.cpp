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

#define ri long long int
#define clr(a) memset(a,0,sizeof(a))
#define READ freopen("input.txt","r",stdin)

ri ans(ri n)
{
    if(n==0)
        return 1;
    if(n==1)
        return 2;

    return ans(n-1)+n;

}

int main()
{
    ri n;

    while(scanf("%lld",&n)==1)
    {
        if(n<0)break;

        printf("%lld\n",ans(n));
    }


    return 0;
}

