#include<stdio.h>
#include<math.h>

int ara[20000001];

void sieve()
{
    int i, j, root;

    root= (int)sqrt(20000001);

    for(j=4;j<20000001;j+=2)
            ara[j]=1;

    for (i=3; i<=root; i+=2)
    {
        if(!ara[i])
        {
            for(j=i+i;j<20000001;j+=i)
                ara[j]=1;
        }
    }
}

int prime(int n)
{
    int i;

    return ara[n];
}

int main()
{
    int n,i,j=1;
    sieve();
    int twin[100001]={0};

    for(i=3;i<20000000-2;i+=2)
    {
        if(prime(i)==0 && prime(i+2)==0)
        {
            twin[j]=i;
            j++;
            if(j>100000)break;
        }
    }

    while(scanf("%d",&n)==1)
    {
        printf("(%d, %d)\n",twin[n],twin[n]+2);
    }

    return 0;
}
