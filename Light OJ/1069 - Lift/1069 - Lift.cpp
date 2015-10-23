#include<stdio.h>

int main()
{
    int t,a,b,k,time;

    scanf("%d",&t);

    for(k=1;k<=t;k++)
    {
        scanf("%d%d",&a,&b);

        time=19;
        int z=a-b;

        if(z<0)z*=-1;

        time+=(z+a)*4;

        printf("Case %d: %d\n",k,time);
    }

    return 0;
}
