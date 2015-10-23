#include<stdio.h>
#include<math.h>

char ara[100010042];

void sieve()
{
    int i, j, root;

    root= (int)sqrt(100010042);

    for(j=4;j<100010042;j+=2)
            ara[j]=1;

    for (i=3; i<=root; i+=2)
    {
        if(!ara[i])
        {
            for(j=i+i;j<100010042;j+=i)
                ara[j]=1;
        }
    }

}

int prime(int n)
{
    int i;
    if (n<2){
        return 1;
    }
    return ara[n];
}

int main()
{
    int n,a,b,count=40,x,y,i,j=1;
    sieve();
    int times[10001];

    for(i=0;i<40;i++)
    {
        times[i]=j++;
    }

    for(i=40;i<=10000;i++)
    {
        n=i*i+i+41;
        if(prime(n)==0)
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


