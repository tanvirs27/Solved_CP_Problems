#include<stdio.h>

int main()
{
  //  freopen("input.txt","r",stdin);
    char name[102][22];
    int t,i,a,b,c,j,max,min,in_max,in_min,n, chok[102];

    scanf("%d",&t);

    for(i=1;i<=t;i++)
    {
        scanf("%d",&n);
        getchar();

        for(j=0;j<n;j++)
        {
            scanf("%s%d%d%d",name[j],&a,&b,&c);

            chok[j]=a*b*c;
        }
        max=chok[0];
        min=chok[0];
        in_max=0;
        in_min=0;

        for(j=1;j<n;j++)
        {
            if(chok[j]>max)
            {
                max=chok[j];
                in_max=j;
            }

            if(chok[j]<min)
            {
                min=chok[j];
                in_min=j;
            }
        }

        printf("Case %d: ",i);
        if(in_max==in_min)
            printf("no thief\n");

        else
            printf("%s took chocolate from %s\n",name[in_max],name[in_min]);
    }
    return 0;
}
