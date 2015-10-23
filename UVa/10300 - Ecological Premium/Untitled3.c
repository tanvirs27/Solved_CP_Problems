#include<stdio.h>
int main()
{
    int T, f, a, b, c, i, j;
    long long int sum;

    scanf("%d",&T);

    for(i=0;i<T;i++){
        scanf("%d",&f);
        sum=0;
        for(j=0;j<f;j++){
            scanf("%d %d %d",&a,&b,&c);
            sum= a*c + sum;
        }
        printf("%lld\n",sum);
    }
    return 0;
}
