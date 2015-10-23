#include<stdio.h>

int main()
{
    int n,t,x,max,min;

    scanf("%d",&t);

    while(t--)
    {
        max=0,min=100;
        scanf("%d",&n);

        while(n--)
        {
            scanf("%d",&x);

            if(x>max)
                max=x;
            if(x<min)
                min=x;
        }
        printf("%d\n",(max-min)*2);
    }

    return 0;
}
