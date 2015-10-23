#include<stdio.h>

int main()
{
    long long n,count,a;

    while(scanf("%lld",&n)==1)
    {
        a=0;
        count=0;

        while(1)
        {
            a*=10;
            a+=1;
            a%=n;
            count++;

            if(a==0)
                break;
        }
        printf("%lld\n",count);
    }
    return 0;
}
