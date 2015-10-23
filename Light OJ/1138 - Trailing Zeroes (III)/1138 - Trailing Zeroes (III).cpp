#include<stdio.h>

long long int zero(long long int n)
{
    long long int res=0;

    while(n)
    {
        res+=n/5;
        n/=5;
    }
    return res;
}

int main()
{
    int t,i;

    scanf("%d",&t);

    for(i=1;i<=t;i++)
    {
        long long int result=-1,ans,q,low,high,mid;
        scanf("%lld",&q);

        low=1;
        high=1000000000;

        while(low<=high)
        {
            mid=(low+high)/2;
            ans=zero(mid);

            if(ans<q)
                low=mid+1;
            else
            {
                high=mid-1;

                if(ans==q)
                    result=mid;
            }
        }

        if(result==-1)
            printf("Case %d: impossible\n",i);
        else
            printf("Case %d: %lld\n",i,result);

    }
    return 0;
}
