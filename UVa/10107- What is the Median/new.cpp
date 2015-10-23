#include<stdio.h>

long long int ara[10005];

void sort(long long int low,long long int high)
{
    long long int mid,ans,q,i;
    ans=high+1;
    q=ara[ans];


    while(low<=high)
    {
        mid=(low+high)/2;

        if(ara[mid]<ara[ans])
            low=mid+1;
        else
            high=mid-1;
    }

    for(i=ans-1;i>=mid;i--)
    {
        ara[i+1]=ara[i];
    }
    ara[mid]=q;
}

long long int median(long long int n)
{
    if(n!=1)
    {
        if(n==2)
        {
            if(ara[1]>ara[2])
            {
                long long int temp=ara[1];
                ara[1]=ara[2];
                ara[2]=temp;
            }
        }
        else
        {
            sort(1,n-1);
        }
    }

    if(n&1)
        return ara[(n+1)/2];

    return (ara[n/2]+ara[n/2+1])/2;
}

int main()
{
    long long int n,i,j=0,k,ans;
    i=1;

    while(scanf("%lld",&n)==1)
    {
        ara[i]=n;

        ans=median(i);

        printf("%lld\n",ans);

        i++;

        for(j=0;j<i;j++)
            printf("%d ",ara[j]);
        printf("\n");
    }

    return 0;
}

