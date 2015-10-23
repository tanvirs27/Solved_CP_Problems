#include<stdio.h>

int main()
{
    int t,i,j,k,n;

    scanf("%d",&t);

    for(i=1;i<=t;i++)
    {
        int ara[10001]={0};

        scanf("%d%d%d%d%d%d%d",&ara[0],&ara[1],&ara[2],&ara[3],&ara[4],&ara[5],&n);

        for(j=6;j<=n;j++)
        {
            for(k=1;k<=6;k++)
            {
                ara[j]+=ara[j-k];
                if(ara[j]>=10000007)
                    ara[j]%=10000007;
            }
        }

        printf("Case %d: %d\n",i,ara[n]%10000007);

    }
    return 0;

}
