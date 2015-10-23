#include<stdio.h>

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int t;
    scanf("%d",&t);

    while(t--)
    {
       // printf("\n");
        getchar();

        int coins[101];

        int weight[101];
        int i,j,n,p,ans1,ans2,k;

        for(j=0;j<101;j++)coins[j]=2;

        scanf("%d%d",&n,&k);

        while(k--)
        {
            scanf("%d",&p);
            for(i=0;i<2*p;i++)
            {
                scanf("%d",&weight[i]);
            }

            getchar();
            char relation=getchar();


            if(relation=='<' || relation=='>')
            {
                for(i=0;i<2*p;i++)
                {
                    if(coins[weight[i]]!=0)
                        coins[weight[i]]=1;
                }
            }

            else if(relation=='=')
            {
                for(i=0;i<2*p;i++)
                {
                    coins[weight[i]]=0;
                }
            }

        }
        int count1=0,count2=0;

        for(i=1;i<=n;i++)
        {
            if(coins[i]==1)
            {
                count1++;
                ans1=i;
            }
            else if(coins[i]==2)
            {
                count2++;
                ans2=i;
            }
        }

        if(count1==1)
            printf("%d\n",ans1);
        else if(count2==1 && count1==0)
            printf("%d\n",ans2);
        else
            printf("0\n");

        printf("\n");

    }

    return 0;
}


