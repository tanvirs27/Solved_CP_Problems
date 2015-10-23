#include<stdio.h>

long long int ara[10005];

long long int partition(long long int p,long long int r)
{
    long long int x,i,j,temp;

    x=ara[r];
    i=p;

    for(j=i;j<r;j++)
    {
        if(ara[j]<x)
        {
            temp=ara[i];
            ara[i]=ara[j];
            ara[j]=temp;
			i=i+1;
        }
    }
    temp=ara[i];
    ara[i]=ara[r];
    ara[r]=temp;

    return i;
}

void quicksort(long long int p,long long int r)
{
    long long int q;
    if(p<r)
    {
        q=partition(p,r);
        quicksort(p,q-1);
        quicksort(q+1,r);

    }
}

long long int median(long long int n)
{
    quicksort(1,n);

    if(n&1)
        return ara[(n+1)/2];

    return (ara[n/2]+ara[n/2+1])/2;
}

int main()
{
    long long int n,i,j,k,ans;
    i=1;

    while(scanf("%lld",&n)==1)
    {
        ara[i]=n;

        ans=median(i);

        printf("%lld\n",ans);

        i++;

    }

    return 0;
}
