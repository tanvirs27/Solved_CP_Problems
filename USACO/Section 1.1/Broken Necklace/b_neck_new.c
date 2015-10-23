#include<stdio.h>

int forward(char X[],int i)
{
    int c_length=0;
   // if(X[i]=='w'){
     //   X[i]=X[i+1];
    //}

    if(X[i]=='r'){
        while(X[i]=='r' || X[i]=='w'){
            i++;
            c_length++;
        }
    }
    else if(X[i]=='b'){
        while(X[i]=='b' || X[i]=='w'){
            i++;
            c_length++;
        }
    }

    return c_length;
}

int back(char X[],int i)
{
    int c_length=0;
    if (i==0) return c_length=0;

    if(X[i-1]=='w'){
        X[i-1]=X[i-2];
    }

    if(X[i-1]=='r'){
        while(X[i-1]=='r' || X[i-1]=='w'){
            i--;
            c_length++;
        }
    }
    else if(X[i-1]=='b'){
        while(X[i-1]=='b' || X[i-1]=='w'){
            i--;
            c_length++;
        }
    }

    return c_length;
}


int main()
{
    int i, j, N, total, max=0;
    char A[400], B[800];
    scanf("%d", &N);
    scanf("%s", A);

    for(i=0,j=0;i<N;i++,j++){
        B[j]=A[i];
    }
    for(i=0;i<N;i++,j++){
        B[j]=A[i];
    }
    B[j]='\0';

    for(i=0;i<N*2;i++){
        total= forward(B,i)+back(B,i);
        if(total>max){
            max=total;
        }
    }
    printf("%d\n",max);

    return 0;
}
