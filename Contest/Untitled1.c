#include<stdio.h>
int main()
{
    int T, N,i;

    scanf("%d",&T);

    for(i=0; i<T; i++){
        scanf("%d",&N);
        if(N%3==0){
            printf("%d is a multiple of 3\n", N);
        }
        else{
            printf("%d is not a multiple of 3\n", N);
        }
    }
    return 0;
}
