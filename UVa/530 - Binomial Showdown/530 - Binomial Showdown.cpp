#include<stdio.h>
#include<string.h>

int ara[65539][65539];

int nCr(int n, int r)
{
    if(r==0 || r==n)
        return 1;
    if(r==1 || r==n-1)
        return n;

    if(ara[n][r]!=-1)
        return ara[n][r];
    else
    {
        ara[n][r]=nCr(n-1,r)+nCr(n-1,r-1);
        return ara[n][r];
    }
}

int main()
{
    int i,j,n,r;

    memset(ara,-1,sizeof(ara));

    while(scanf("%d%d",&n,&r)==2)
    {
        if(n==0 || r==0)break;

        printf("%d\n",nCr(n,r));
    }

    return 0;
}
