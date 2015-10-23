#include<stdio.h>
#include<string.h>

int cakes[32],ans[64],j;

int ulta_check(int n)
{
    int i,k;
    for(i=0;i<n;i++)
    {
        int x=cakes[i];
        int flag=0;

        for(k=i+1;k<n;k++)
        {
            if(x<cakes[k])
                flag=1;
        }
        if(flag==1)
            break;
    }
    if(i<n)
        return 0;
    return 1;
}

void clr()
{
    memset(cakes,0,sizeof(cakes));
    memset(ans,0,sizeof(ans));
    j=0;
}

void flip(int a,int n)
{
    int i;

    for(i=0;i<=a/2;i++)
    {
        int temp=cakes[i];
        cakes[i]=cakes[a-i];
        cakes[a-i]=temp;
    }
    ans[j++]=n-a;

    if(ulta_check(n)==1)flip(4,n);
}

int finder(int i,int n)
{
    int min_p=0;
    int min=cakes[0];
    int x=i;
    for(i=1;i<n-x;i++)
    {
        if(cakes[i]<min)
        {
            min=cakes[i];
            min_p=i;
        }
    }

    return min_p;
}

int check(int n)
{
    int i,k;
    for(i=0;i<n;i++)
    {
        int x=cakes[i];
        int flag=0;

        for(k=i+1;k<n;k++)
        {
            if(x>cakes[k])
                flag=1;
        }
        if(flag==1)
            break;
    }
    if(i<n)
        return 0;
    return 1;
}

int main()
{
    freopen("input.txt","r",stdin);

    int i,n,k;
    char ch;

    while(scanf("%d",&cakes[0])==1)
    {
        i=1;

        while(scanf("%d%c",&cakes[i++],&ch)==2)
        {
            if(ch=='\n')break;
        }

        n=i;

        for(i=0;i<n;i++)
        {
            if(i!=0)printf(" ");
            printf("%d",cakes[i]);
        }
        puts("");
        k=0;

        for(i=0;i<n && check(n)==0;i++)
        {
            int b=finder(i,n);
            if(b!=i)
                flip(b,n);

            if(b!=i && check(n)==0)
                flip(n-1-i,n);
            k=1;
        }
        if(check(n)==0)
            flip(n-1,n);

        int a=0;

        for(i=0;i<j;i++)
        {
            if(ans[i]!=0)
            {
                if(a!=0)printf(" ");

                printf("%d",ans[i]);
                a=1;
            }
        }
        if(k==1)printf(" ");

        printf("0\n");

        clr();
    }
    return 0;
}
