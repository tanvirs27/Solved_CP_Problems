/*
ID: tanvirs2
LANG: C
PROG: gift1
*/
#include<stdio.h>
#include<string.h>
struct friends{
    int spend;
    int receive;
    char name[20];
} A[12]={0,0,0};

int main()
{
    freopen ("gift1.in","r",stdin);
    freopen ("gift1.out","w",stdout);
    int N, i, j, k, money, person;
    char giver[20],receiver[20];
    scanf("%d", &N);
    for(i=0;i<N;i++){
        scanf("%s",A[i].name);
    }
    for(i=0;i<N;i++){
        scanf("%s",giver);
        scanf("%d",&money);
        j=0;
        while(strcmp(A[j].name,giver)!=0) j++;
        A[j].spend+=money;

        scanf("%d",&person);
        if(person==0){
            A[j].receive+= money;
        }
        else{
            A[j].receive+= money%person;
        }

        for(k=0;k<person;k++){
            scanf("%s",receiver);
            j=0;
            while(strcmp(A[j].name,receiver)!=0) j++;
            A[j].receive+= money/person;
        }
    }
    for(i=0;i<N;i++){
        printf("%s %d\n",A[i].name, A[i].receive-A[i].spend);
    }
    return 0;
}

