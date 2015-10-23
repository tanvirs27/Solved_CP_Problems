#include<stdio.h>

int main()
{
    int t,k,i,n,ara[12],a,d;
    ara[0]=2;
    scanf("%d",&t);

    for(k=1;k<=t;k++)
    {
        int count=0;
        a=0;
        scanf("%d",&n);

        for(i=1;i<=n;i++)
        {
            scanf("%d",&ara[i]);
        }
        for(i=1;i<=n;i++)
        {
            a=0;
            d=ara[i]-ara[i-1];

            if(d<=5 && d!=0)
                count++;
            else if(d!=0)
            {
                if(d%5!=0)
                    a=1;
                count+=d/5+a;
            }
        }

        printf("Case %d: %d\n",k,count);
    }

    return 0;
}
