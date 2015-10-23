#include<stdio.h>
#include<math.h>

char ara[32769];

void sieve()
{
    int i, j, root;
    for(i=2; i<32769; i++){
        ara[i]= 1;
    }
    root= (int)sqrt(32769);

    for (i=2; i<=root; i++){
        if(ara[i]== 1){
            for(j=2; i*j<=32769; j++){
                ara[i*j]=0;
            }
        }
    }
}

int prime(int n)
{
    int i;
    if (n<2){
        return 0;
    }
    return ara[n];
}



int main()
{
    int n,i;
    sieve();

    while(scanf("%d",&n)==1)
    {
        if(n==0)break;

        int count=0;
        for(i=2;i<=n/2;i++)
        {
            if(prime(i)==1 && prime(n-i)==1)
                count++;
        }
        printf("%d\n",count);
    }
    return 0;
}

