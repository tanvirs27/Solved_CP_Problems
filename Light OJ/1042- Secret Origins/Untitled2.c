#include<stdio.h>
int onoroy_value(int N)
{
    int i=32,value=0,a;
    while(i--)
    {
        if(N&1)
            value++;
        N=N>>1;
    }
    return value;
}

int main()
{
    int T,N,i,a,b;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%d",&N);
        a= onoroy_value(N);

        while(1)
        {
            N++;
            b= onoroy_value(N);

            if (a==b){
                printf("Case %d: %d\n",i+1,N);
                break;
            }
        }
    }
    return 0;
}

