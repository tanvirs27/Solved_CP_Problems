#include<stdio.h>
#include<math.h>

int main()
{
    long long int n,m,x;

    while(scanf("%lld",&n)==1)
    {
        if(n==0)break;

        m=sqrt(n);
        x=m*m;
        if(x==n)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}
