#include<stdio.h>

int a[8005];

int main()
{
    int n,max,i,sum,d,b,c,x;

    scanf("%d",&n);

    while(n--)
    {

        scanf("%d",&x);

        for(i=1;i<x;i++)
            scanf("%d",a+i);

        max=0;
        sum=0;
        range=0;

        for(i=1;i<x;i++)
        {
            sum+=a[i];

            if(sum>max)
            {
                max=sum;
                c=i;
            }

            if(sum<0)
            {
                sum=0;
                b=i+1;
            }

        }

        printf("%d %d %d\n",b,c,max);

        if(max==0)
            printf("Losing streak.\n");
        else
            printf("The maximum winning streak is %d.\n",max);
    }

    return 0;
}

