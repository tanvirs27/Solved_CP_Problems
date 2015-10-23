#include<stdio.h>
#include<math.h>

int ara[1000007];
int prime[100005];


int sieve(int x)
{
    int i, j, root,k=1;

    root= (int)sqrt(1000007);

    ara[0]=ara[1]=1;
    prime[0]=2;

    for(j=4;j<1000007;j+=2)
            ara[j]=1;

    for (i=3; i<=root; i+=2)
    {
        if(!ara[i])
        {
            prime[k++]=i;
            for(j=i+i;j<1000007;j+=i)
                ara[j]=1;
        }
    }

    for(;i<1000007;i++)
    {
        if(!ara[i])
        {
            prime[k++]=i;
        }
    }
    return prime[x-1];
}

int main()
{
    freopen("output.txt","w",stdout);
    int n;
    scanf("%d",&n);
    printf("%d\n",sieve(n));

    return 0;
}

