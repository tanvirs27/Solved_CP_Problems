#include<stdio.h>

int main()
{
    int num[1005];
    int n,i,j,temp,t;


    while(scanf("%d",&n)==1)
    {
        int count=0;

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

        printf("Minimum exchange operations : %d\n",count);
    }

    return 0;
}


