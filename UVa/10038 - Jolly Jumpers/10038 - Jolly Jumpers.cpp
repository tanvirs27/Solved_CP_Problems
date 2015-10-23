#include<stdio.h>

int main()
{
    int input[3001];

    int n,a,i,d,not_jolly;

    while(scanf("%d",&n)!=EOF)
    {
        int jolly[3001]={0};
        not_jolly=0;

        for(i=0;i<n;i++)
        {
            scanf("%d",&input[i]);
        }

        for(i=1;i<n;i++)
        {
            d=input[i]-input[i-1];
            if(d<0)d*=-1;

            if(jolly[d]==0 && d<3001)
                jolly[d]=1;
            else if(jolly[d]==1 || d==0)
                not_jolly=1;
        }

        for(i=1;i<n;i++)
        {
            if(jolly[i]==0)
            {
                not_jolly=1;
                break;
            }
        }

        if(not_jolly==0 || n<=1)
            printf("Jolly\n");
        else
            printf("Not jolly\n");
    }

    return 0;

}
