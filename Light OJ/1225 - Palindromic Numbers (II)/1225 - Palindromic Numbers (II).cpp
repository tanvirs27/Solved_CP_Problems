#include<stdio.h>
#include<string.h>

char num[15],pal[15];

void rev()
{
    int i,len;

    strcpy(pal,num);
    len=strlen(pal);

    for(i=0;i<len/2;i++)
    {
        char t=pal[i];
        pal[i]=pal[len-i-1];
        pal[len-i-1]=t;
    }
}

int main()
{
    int t,k;

    scanf("%d",&t);
    getchar();

    for(k=1;k<=t;k++)
    {
        scanf("%s",num);
        getchar();

        rev();

        if(strcmp(pal,num)==0)
            printf("Case %d: Yes\n",k);
        else
            printf("Case %d: No\n",k);
    }

    return 0;
}
