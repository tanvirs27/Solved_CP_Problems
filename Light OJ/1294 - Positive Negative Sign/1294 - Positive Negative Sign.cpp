#include<stdio.h>

int main()
{
    long long int t,k,m,n;

    scanf("%lld",&t);

    for(k=1;k<=t;k++)
    {
        scanf("%lld%lld",&m,&n);

        printf("Case %lld: %lld\n",k,m/2*n);
    }
    return 0;
}
