#include<stdio.h>
#include<math.h>

char ara[100010042];

void sieve()
{
    int i, j, root;
    for(i=2; i<100010042; i++){
        ara[i]= 1;
    }
    root= (int)sqrt(100010042);

    for (i=2; i<=root; i++){
        if(ara[i]== 1){
            for(j=2; i*j<=100010042; j++){
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
    int n,a,b,count=0,x,y,i;
    sieve();
    int times[10001];

    for(i=0;i<=10000;i++)
    {
        n=i*i+i+41;
        if(prime(n)==1)
            count++;

        times[i]=count;
    }

    while(scanf("%d%d",&a,&b)==2)
    {
        if(a==0)
            y=times[b];
        else
            y=times[b]-times[a-1];

        x=b-a+1;


        double per= (double)y/x*100;

        printf("%.2lf\n",per+1e-7);
    }
    return 0;
}

