#include<stdio.h>
#include<string.h>

int ara[500005];

int bubble(int n)
{
    int count=0,i,j,temp;
    for(i=0;i<n;i++)
    {
        int flag=0;
        for(j=1;j<n-i;j++)
        {
            if(ara[j-1]>ara[j])
            {
                temp=ara[j-1];
                ara[j-1]=ara[j];
                ara[j]=temp;
                flag=1;
                count++;
            }

        }
        if(!flag)
                break;
    }
    return count;
}

int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        if(!n)
            break;

        memset(ara,0,sizeof(ara));
        int i,j,k,ans;

        for(i=0;i<n;i++)
        {
            scanf("%d",&ara[i]);
        }

        ans=bubble(n);

        printf("%d\n",ans);
    }

    return 0;
}
