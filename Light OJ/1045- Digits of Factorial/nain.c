#include<stdio.h>
#include<math.h>
#include<stdlib.h>

double ara[1000010];

int main()
{
    int j, k, T;
    long i, n, base;
    long digit;

    for(k=1; k<=1000000; k++){
        ara[k]= log((k))+ara[k-1];
    }

    scanf("%d",&T);
    for(i=1;i<=T;i++){
        scanf("%ld %ld",&n, &base);

        digit= (ara[n]/(ara[base]-ara[base-1]))+1;
        printf("Case %d: %ld\n",i,digit);
    }
    return 0;
}
