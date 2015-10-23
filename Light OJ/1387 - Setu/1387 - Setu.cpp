#include<stdio.h>
#include<string.h>

char command[10];

int main()
{
    int t,k,n,i,j,fund;

    scanf("%d",&t);

    for(k=1;k<=t;k++)
    {
        scanf("%d",&n);
        getchar();

        printf("Case %d:\n",k);
        fund=0;

        while(n--)
        {
            scanf("%s",command);

            if(strcmp(command,"donate")==0)
            {
                scanf("%d",&i);
                getchar();
                fund+=i;
            }
            else
                printf("%d\n",fund);
        }

    }
    return 0;
}
