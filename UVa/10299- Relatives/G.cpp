#include<stdio.h>

long long int phi (long long int n)
{
    if(n==1)
        return 0;

    long long int ret,i;
    ret = n;
    for ( i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
            {
                n /= i;
            }
            ret -= ret / i;
        }
    }

    if (n > 1) ret -= ret / n;
    return ret;
}

int main()
{
    long long int n;

    while(scanf("%lld",&n)==1)
    {
        if(n==0)break;

        printf("%lld\n",phi(n));
    }

    return 0;
}
