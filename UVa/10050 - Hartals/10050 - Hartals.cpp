#include<stdio.h>

int main()
{
    int t;

    scanf("%d",&t);

    while(t--)
    {
        int day[3651]={0};
        int party[101];
        int count=0,n_day,n_party,i,j;

        scanf("%d%d",&n_day,&n_party);

        for(i=0;i<n_party;i++)
        {
            scanf("%d",&party[i]);
        }

        for(i=0;i<n_party;i++)
        {
            for(j=party[i];j<=n_day;j+=party[i])
            {
                if(j%7!=6 && j%7!=0)
                    day[j]=1;
            }
        }

        for(i=1;i<=n_day;i++)
        {
            if(day[i]==1)
                count++;
        }

        printf("%d\n",count);

    }
    return 0;
}
