#include<stdio.h>
#include<string.h>

int main()
{
   // freopen("input.txt","r",stdin);

    int t,i,j,k,x,flag,check;
    char ip[40];
    int ara[4];

    scanf("%d",&t);

    for(i=1;i<=t;i++)
    {
        scanf("%d.%d.%d.%d",&ara[0],&ara[1],&ara[2],&ara[3]);
        getchar();
        gets(ip);

        x=128;
        check=0;
        k=0;
        flag=1;

        for(j=1;j<=36;j++)
        {
            if(j!=36)
                check+=(ip[j-1]-48)*x;
            x/=2;

            if(j%9==0)
            {
                if(check!=ara[k])
                {
                    flag=0;
                    break;
                }
                else
                {
                    x=128;
                    check=0;
                    k++;
                }
            }
        }
        printf("Case %d: ",i);
        if(!flag)
            printf("No\n");
        else
            printf("Yes\n");
    }

    return 0;
}
