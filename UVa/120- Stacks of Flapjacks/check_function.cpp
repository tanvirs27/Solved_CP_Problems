#include<stdio.h>
#include<strings.h>

int cakes[32],ans[50],j;

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
    int i;

    for(i=0;i<5;i++)
    {
        scanf("%d",&cakes[i]);
    }
    printf("%d\n",check(5));

    return 0;
}
