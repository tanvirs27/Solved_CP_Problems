#include<stdio.h>
#include<string.h>
#include<math.h>

char num[250];
long long int i,a,len;

void clr()
{
    memset(num,0,sizeof(num));
    i=0;
    a=0;
    len=0;
}

void rev()
{
    long long j;

    for(j=0;j<strlen(num)/2;j++)
    {
        char temp=num[j];
        num[j]=num[strlen(num)-j-1];
        num[strlen(num)-j-1]=temp;
    }
}

long long digit(long long int z)
{
    long long int j,k,digit=0;

    while(z)
    {
        z/=10;
        digit++;
    }
    return digit;
}
long long create()
{
    long long m=0,j=1,b,r;

    for(r=1;r<a;r++)
        j*=10;

    b=i;

   // if(b+a>=len)
    //    return -1;

    for(;i<b+a && i<len;i++,j/=10)
    {
        m+=(num[i]-48)*j;
    }

    return m;
}

long long remainder(long long int n, long long int m)
{
    long long int x,y;

    x=n/m;
    y=x*m;

    return n-y;
}

int mod(long long int n)
{
    long long int x,j,m=0;

    len=strlen(num);
    a=digit(n);

    m=create();
  //  printf("1: m=%lld i=%lld\n",m,i);

    while(1)
    {
        m=remainder(m,n);
     //   printf("2: m=%lld i=%lld\n",m,i);
        if(i>=len)break;

        if(m==0)
        {
            m=create();
        //    printf("3: m=%lld i=%lld\n",m,i);
            long long z=(digit(m));
      //      printf("a= %lld %lld\n",a,z);
            if(digit(m)!=a)break;
        }

        else
        {
            m*=10;
            m+=(num[i++]-48);
         //   printf("4: m=%lld i=%lld\n",m,i);
        }
    }

  //  printf("5: m=%lld i=%lld\n",m,i);
    if(m==0)
        return 1;
    else
        return 0;

}

int main()
{
    freopen("input.txt","r",stdin);

    int t,k;
    long long n;

    scanf("%d",&t);

    for(k=1;k<=t;k++)
    {
        getchar();
        scanf("%s%lld",num,&n);


        if(num[0]=='-')
        {
            rev();
            num[strlen(num)-1]=0;
            rev();
        }
      //  printf("%s %lld\n",num,n);

        if(n<0)
            n*=-1;

        if(mod(n)==1)
            printf("Case %d: divisible\n",k);
        else
            printf("Case %d: not divisible\n",k);

        clr();
    }

    return 0;
}

