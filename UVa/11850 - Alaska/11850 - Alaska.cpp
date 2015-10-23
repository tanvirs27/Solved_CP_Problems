#include<stdio.h>

void sort(int ara[], int n);

int main()
{
    int n;

    while(scanf("%d",&n)==1)
    {
        if(!n)
            break;

        int ara[1500]={0};

        int i,j,flag=1;

        for(i=1;i<=n;i++)
            scanf("%d",&ara[i]);

        ara[i]=1422;

        sort(ara,n+2);
      //  printf("%d\n",ara[i]);

        for(i=1;i<=n+1;i++)
        {
            if(ara[1]-ara[0]!=0 || 2*(ara[n+1]-ara[n])>200)
            {
                flag=0;
                break;
            }
            if(ara[i+1]-ara[i]>200)
            {
                flag=0;
                break;
            }

        }

        if(!flag)
            printf("IMPOSSIBLE\n");
        else
            printf("POSSIBLE\n");
    }
    return 0;
}

void sort(int ara[], int n)
{
    int i,j,flag;

    for(i=0;i<n;i++)
    {
        flag=0;

        for(j=1;j<n-i;j++)
        {
            if(ara[j-1]>ara[j])
            {
                flag=1;
                int temp=ara[j-1];
                ara[j-1]=ara[j];
                ara[j]=temp;
            }
        }
        if(!flag)
            break;
    }
}
