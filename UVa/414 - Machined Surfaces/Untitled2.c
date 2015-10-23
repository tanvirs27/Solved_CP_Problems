#include<stdio.h>

int main()
{
    int N,i,j,k;
    char machine[25];

    while(scanf("%d",&N)!=EOF){
        printf("\n");
        int max=0, sum=0;
        int ara[15]={0};
        if(N==0){
            break;
        }
        for(i=0;i<N;i++){
            gets(machine);
            int X=0;
            for(j=0;j<25;j++){
                if(machine[j]=='x'){
                    X= X+1;
                }
            }
            ara[i]= X;
            printf("%d %d %d\n", i, X, ara[i]);
        }
        /*for(k=0;k<N;k++){
            if(ara[k]>max){
                max= ara[k];
                sum=sum+ara[k];
            }
        }
        int ans= N*max-sum;
        printf("%d\n",ans);*/
    }

    return 0;

}
