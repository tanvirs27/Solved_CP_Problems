#include<stdio.h>

int main()
{
  //  freopen("input.txt","r",stdin);

    long long t,n,b,k,ans,x,sum;

    scanf("%lld",&t);

    while(t--)
    {
        scanf("%lld%lld",&n,&b);

        sum=0;
        while(b--)
        {
            scanf("%lld",&k);

            ans=1;
            while(k--)
            {
                scanf("%lld",&x);
                ans=((ans%n)*(x%n))%n;
            }
            sum=((sum%n)+(ans%n))%n;
        }
        printf("%lld\n",sum);
    }
    return 0;
}
