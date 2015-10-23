#include<stdio.h>
#include<string.h>

int ara[27];
char a[101],b[101];

void clr()
{
    memset(ara,0,sizeof(ara));
}

int main()
{
   // freopen("input.txt","r",stdin);

    int t,k,i,j,len;

    scanf("%d",&t);
    getchar();

    for(k=1;k<=t;k++)
    {
        gets(a);
        gets(b);

        len=strlen(a);

        for(i=0;i<len;i++)
        {
            if(a[i]>='A' && a[i]<='Z')
                a[i]+=32;

            if(a[i]!=' ')
                ara[a[i]-96]++;
        }

        len=strlen(b);

        for(i=0;i<len;i++)
        {
            if(b[i]>='A' && b[i]<='Z')
                b[i]+=32;

            if(b[i]!=' ')
                ara[b[i]-96]--;
        }

        for(i=1;i<27;i++)
        {
            if(ara[i]!=0)
                break;
        }

        clr();

        if(i<27)
            printf("Case %d: No\n",k);
        else
            printf("Case %d: Yes\n",k);
    }

    return 0;
}
