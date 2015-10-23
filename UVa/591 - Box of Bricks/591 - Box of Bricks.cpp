#include<stdio.h>

int main()
{
   // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);

    int brick[55];
    int n,i,j,sum,set=1;

    while(scanf("%d",&n)==1)
    {
        if(n==0)break;

        sum=0;
        int ans=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&brick[i]);
            sum+=brick[i];
        }

        sum/=n;

        for(i=0;i<n;i++)
        {
            if(brick[i]>sum)
                ans+=brick[i]-sum;
        }

        printf("Set #%d\nThe minimum number of moves is %d.\n\n",set,ans);
        set++;

    }

    return 0;
}


