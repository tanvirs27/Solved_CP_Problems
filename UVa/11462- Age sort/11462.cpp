#include<stdio.h>

int main()
{
    int n;

    while(scanf("%d",&n)==1)
    {
        if(!n)
            break;

        int a[101]={0};
        int b,i,flag=0;

        for(i=0;i<n;i++)
        {
            scanf("%d",&b);
            a[b]++;
        }

        for(i=1;i<=100;i++)
        {
            while(a[i])
            {
                if(!flag)
                {
                    printf("%d",i);
                    flag=1;
                }
                else
                    printf(" %d",i);

                a[i]--;
            }
        }
        printf("\n");
    }
    return 0;
}
