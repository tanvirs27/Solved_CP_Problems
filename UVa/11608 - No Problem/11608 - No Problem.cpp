#include<stdio.h>

int main()
{
    int Case=1;
    int made[13];

    while(scanf("%d",&made[0])==1)
    {
        if(made[0]<0)break;

        printf("Case %d:\n",Case);

        int need[12];
        int i,j;

        for(i=1;i<13;i++)
        {
            scanf("%d",&made[i]);
        }

        for(i=0;i<12;i++)
        {
            scanf("%d",&need[i]);
        }

        for(i=0;i<12;i++)
        {
            if(made[i]>=need[i])
            {
                printf("No problem! :D\n");
                made[i+1]+=made[i]-need[i];
            }
            else
            {
                printf("No problem. :(\n");
                made[i+1]+=made[i];
            }
        }
        Case++;


    }
    return 0;
}
