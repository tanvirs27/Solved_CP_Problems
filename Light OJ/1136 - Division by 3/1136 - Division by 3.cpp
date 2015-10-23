#include<stdio.h>

int main()
{
    int i,a,b,t,x,y;

    scanf("%d",&t);

    for(i=1;i<=t;i++)
    {
        scanf("%d%d",&a,&b);

        a-=1;

        x=a-a/3;
        y=b-b/3;

        if(a%3!=0)
            x-=1;

        if(b%3!=0)
            y-=1;

        printf("Case %d: %d\n",i,y-x);
    }
    return 0;
}
