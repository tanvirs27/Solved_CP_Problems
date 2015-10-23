#include<stdio.h>

int find_max(int ara[], int n)
{
    int max= ara[0];
    int i;
    for (i=0;i<n;i++){
        if(ara[i]>max){
            max=ara[i];
        }
    }
    return max;
}

int find_min(int ara[], int n)
{
    int min= ara[0];
    int i;
    for (i=0;i<n;i++){
        if(ara[i]<min){
            min=ara[i];
        }
    }
    return min;
}

int main()
{
    int T, ara[500], i, R, j;

    scanf("%d", &T);

    for(i=0;i<T;i++){

        scanf("%d",&R);
        for(j=0; j<R; j++){
            scanf("%d", &ara[j]);
        }

        int max= find_max(ara, R);
        int min= find_min(ara, R);

        int ans= max-min;
        printf("%d\n",ans);
    }
    return 0;
}
