#include<stdio.h>

int a[10005];

int main()
{
    int n,max,i,sum;

    while(scanf("%d",&n)==1)
    {
        if(n==0)break;

        for(i=0;i<n;i++)
            scanf("%d",a+i);

        max=0;
        sum=0;

        for(i=0;i<n;i++)
        {
            sum+=a[i];

            if(sum>max)
                max=sum;

            if(sum<0)
                sum=0;
        }

        if(max==0)
            printf("Losing streak.\n");
        else
            printf("The maximum winning streak is %d.\n",max);
    }

    return 0;
}
