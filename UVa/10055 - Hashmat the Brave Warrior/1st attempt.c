#include<stdio.h>
int main()
{
    long long int A, B, dif;

    while(scanf("%lld %lld",&A,&B)!=EOF){
        dif= A-B;
        if(dif<0){
            dif= dif*(-1);
        }
        printf("%lld\n",dif);
    }
    return 0;
}
