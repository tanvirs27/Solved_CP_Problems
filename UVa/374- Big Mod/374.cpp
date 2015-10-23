#include<stdio.h>

long long int M;

long long int mod(long long int b, long long int p)
{
    if(!p)
        return 1;
    long long int ret;
    if(p%2==0)
    {
        ret= mod(b,p/2);
        return ((ret%M)*(ret%M))%M;
    }
    else
        return ((b%M)*(mod(b,p-1)%M))%M;
}

int main()
{
    long long B,P;

    while(scanf("%lld%lld%lld",&B,&P,&M)==3)
    {
        printf("%lld\n",mod(B,P));
    }
    return 0;
}
