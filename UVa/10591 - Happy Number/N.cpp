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
    // READ;

    int n,t,k,sum;

    scanf("%d",&t);

    for(k=1; k<=t; k++)
    {
        scanf("%d",&n);



        sum=n;

        while(1)
        {
            sum=sq(sum);

            if(sum==1)
            {
                printf("Case #%d: %d is a Happy number.\n",k,n);
                break;
            }
            else if(sum<10)
            {
                printf("Case #%d: %d is an Unhappy number.\n",k,n);
                break;
            }
        }

    }

    return 0;
}
