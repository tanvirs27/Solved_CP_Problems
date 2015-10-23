/*
    ID: tanvirs2
    LANG: C
    TASK: beads
*/
#include<stdio.h>


int forward(char X[],int i)
{
    int c_length=0;

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


/*int back(char X[], int i)
{
    int c_length=0;


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
}*/

int main()
{
   // freopen("beads.in","r",stdin);
   // freopen("beads.out","w",stdout);

    int i, j, N, total, firstlen, secondlen, max=0;
    char A[400], B[800];
    scanf("%d", &N);
    scanf("%s", A);

    for(i=0,j=0;i<N;i++,j++){
        B[j]=A[i];
    }
    for(i=0;i<N;i++,j++){
        B[j]=A[i];
    }
   // B[j]='\0';

    for(i=0;i<2*N;i++){
        firstlen= forward(B,i);
        max=firstlen;

        while(i<2*N){
            if(B[i]=='r'){
                B[i]='b';
            }
            else{
                B[i]='r'
            }
            secondlen= forward(B,i);
            if(firstlen+secondlen>max){
                firstlen+secondlen=max;
            }
        }

    }
    if(max>N || max==0){
            max=N;
        }
    printf("%d\n",max);
    return 0;
}
//rwrwrwrwrwrwrwrwrwrwrwrwbwrwbwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrw
        //rwrwrwr
