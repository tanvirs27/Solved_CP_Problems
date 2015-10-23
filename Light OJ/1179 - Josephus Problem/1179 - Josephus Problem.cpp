#include<stdio.h>

int remain(int n, int k)
{
    if(n==1)
        return 1;
    else
        return ((remain(n-1,k)+k-1)%n)+1;
}

int main()
{
    int n,k,t,i;

    scanf("%d",&t);

    for(i=1;i<=t;i++)
    {
        scanf("%d%d",&n,&k);
        printf("Case %d: %d\n",i,remain(n,k));
    }

    return 0;

}
