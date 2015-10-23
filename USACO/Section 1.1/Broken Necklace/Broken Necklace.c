#include<stdio.h>
#include<string.h>

int main()
{
    char neck[100];
    int length, count=1, k=-1, i, m, X[100], Y[100], max;
    scanf("%s",neck);
    length= strlen(neck);

    for(i=0; i<length; i++){
        if(neck[i]==neck[i+1]){
            count++;
        }
        else{
            k++;
            count=m;
            m= X[k];
            count=1;
        }
    }
    for(i=0; i<k+1; i++){
        if(i!=k){
            Y[i]= X[i]+X[i+1];
        }
        else{
            Y[i]=X[i]+X[0];
        }
    }
    max=Y[0];
    for(i=0; i<k+1; i++){
        if(Y[i]>max){
            max=Y[i];
        }
    printf("%d", max);
    return 0;
    }
}



