#include<stdio.h>

int main()
{
    int num[55];
    int n,i,j,temp,t;

    scanf("%d",&t);

    while(t--)
    {
        int count=0;

        scanf("%d",&n);

        for(i=0;i<n;i++)
        {
            scanf("%d",&num[i]);
        }

        for(i=0;i<n;i++)
        {
            for(j=0;j<n-1;j++)
            {
                if(num[j]>num[j+1])
                {
                    temp=num[j];
                    num[j]=num[j+1];
                    num[j+1]=temp;
                    count++;
                }
            }
        }

        printf("Optimal train swapping takes %d swaps.\n",count);
    }

    return 0;
}

