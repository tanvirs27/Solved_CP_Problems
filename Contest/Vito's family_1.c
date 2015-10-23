#include<stdio.h>

int main()
{
    int T, ara[500], i, R, j, min, k, index, min_index, l, sum;
    int ara2[500];

    scanf("%d", &T);

    for(i=0;i<T;i++){

        scanf("%d",&R);
        for(j=0; j<R; j++){
            scanf("%d", &ara[j]);
        }
            for(index=0; index<R; index++){
                min=30000;
                for(k=0; k<R; k++){
                    if(ara[k]<min){
                        min= ara[k];
                        min_index=k;
                    }
                }
            ara[min_index]= 30000;
            ara2[index]= min;
            }
        sum=0;
        for(l=1;l<R;l++){
            sum= sum+ ara2[l]- ara2[l-1];
        }
        printf("%d\n",sum);
    }
    return 0;
}

