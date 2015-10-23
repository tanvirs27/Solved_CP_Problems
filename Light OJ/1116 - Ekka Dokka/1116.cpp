#include<stdio.h>

int main()
{
    long long int w,n,j;
    int t,i;

    scanf("%d",&t);

    for(i=1;i<=t;i++)
    {
        scanf("%lld",&w);
        j=1;
        if(w%2==0)
        {
            for(j=2;j<=w/2;j+=2)
            {
                n=w/j;
                if(w%j==0 && n%2==1)
                    break;
            }
        }
        if(j==1)
            printf("Case %d: Impossible\n",i);
        else
            printf("Case %d: %lld %lld\n",i,n,j);
    }
    return 0;
}
