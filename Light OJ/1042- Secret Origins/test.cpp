#include<stdio.h>

int onoroy_value(int N)
{
    int i=32,value=0,a;
    while(i--)
    {
        if(N&1)
            value++;
        N=N>>1;
       // printf("%d %b\n",N,N);
    }
    return value;
}

int main()
{
    while(1)
    {
        int n;
        scanf("%d",&n);
        printf("%d\n",onoroy_value(n));

    }
    return 0;
}
