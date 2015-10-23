#include<stdio.h>
#include<math.h>

int ara[20000001];

void sieve()
{
    int i, j, root;

    root= (int)sqrt(20000001);

    for(j=4;j<=20000001;j+=2)
            ara[j]=1;

    for (i=3; i<=root; i+=2)
    {
        if(!ara[i])
        {
            for(j=i+i;j<=20000001;j+=i)
                ara[j]=1;
        }
    }
}

int prime(int n)
{
    int i;
    if (n<2)
    {
        return 1;
    }
    return ara[n];
}

int main()
{
    int n,i,j=1;
    sieve();

    while(scanf("%d",&n)==1)
    {
        int count=0;
        for(i=3;i<20000001-2;i++)
        {
            if(prime(i)==0 && prime(i+2)==0)
            {
                count++;
                if(count==n)
                    break;
            }
        }
        printf("(%d, %d)\n",i,i+2);
    }

    return 0;
}

