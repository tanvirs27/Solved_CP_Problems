#include<stdio.h>
#include<math.h>

double ara[1000005];

int main()
{
    int j, k, T,n,base,digit;
    long long int i;

    for(k=1; k<=1000000; k++)
    {
        ara[k]= log10(k)+ara[k-1];
    }

    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%d%d",&n,&base);

        printf("%d %d\n",(int)ara[n],(int)log10(base));
        int a=(int)ara[n];
        int b=(int)log10(base);
        digit= ((int)ara[n]/(int)log10(base))+1;
        printf("Case %d: %d\n",i,(a/b)+1);
    }
    return 0;
}
