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

#define ri int
#define clr(a) memset(a,0,sizeof(a))
#define READ freopen("input.txt","r",stdin)

int happy[100001];

int sq(int n)
{
    int sum=0,x;

    while(n)
    {
        x=n%10;
        sum+=x*x;
        n/=10;
    }

    return sum;
}


int main()
{
    READ;

    int i,j,k,n,sum,cnt;

    for(n=1; n<100000; n++)
    {
        sum=n;
        cnt=1;

        while(1)
        {
            sum=sq(sum);
            cnt++;

            if(n==1)
            {
                happy[n]=1;
                break;
            }

            if(sum==1)
            {
                happy[n]=cnt;
                break;
            }
            else if(cnt>10)
            {
                happy[n]=0;
                break;
            }
        }

    }

    int l,h,kase=0;

    while(scanf("%d%d",&l,&h)==2)
    {
        if(kase!=0)
            puts("");

        if(h<l)
        {
            int temp=h;
            h=l;
            l=temp;
        }
        kase=1;
        for(i=l;i<=h;i++)
        {
            if(happy[i]!=0)
                printf("%d %d\n",i,happy[i]);
        }
    }

    return 0;
}
