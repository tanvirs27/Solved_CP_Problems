#include<stdio.h>
#include<math.h>

int ara[1000007];
int prime[100005];


int sieve()
{
    int i, j, root,k=1;

    root= (int)sqrt(1000007);

    ara[0]=ara[1]=1;
    prime[0]=2;

    for(j=4;j<1000007;j+=2)
            ara[j]=1;

    for (i=3; i<=root; i+=2)
    {
        if(!ara[i])
        {
            prime[k++]=i;
            for(j=i+i;j<1000007;j+=i)
                ara[j]=1;
        }
    }

    for(;i<1000007;i++)
    {
        if(!ara[i])
        {
            prime[k++]=i;
        }
    }
    return k;

}


int main()
{
    int n,i,j;

    int input[200005]={0};
    int total=sieve();
    char ch;

    while(1)
    {
        int fact[100005]={0};
        int x=0;
        scanf("%d",&input[x++]);
        if(input[x-1]==0)
            break;

        while(1)
        {
            scanf("%d",&input[x++]);

            ch=getchar();
            if(ch=='\n')break;
        }
        int ans=1;

        for(i=0;i<x-1;i+=2)
        {
            for(j=0;j<input[i+1];j++)
                ans*=input[i];
        }
       // printf("%d\n",ans);
        n=ans-1;


        for(i=0;i<total;i++)
        {
            while(n%prime[i]==0)
            {
                n/=prime[i];
                fact[i]++;
            }
            if(n==1)
                break;
        }
        int a=0;

        for(i=100000;i>=0;i--)
        {
            if(fact[i]!=0)
            {
                if(a==0)
                {
                    a=1;
                    printf("%d %d",prime[i],fact[i]);
                }
                else
                    printf(" %d %d",prime[i],fact[i]);
            }

        }
        printf("\n");

    }

    return 0;
}


