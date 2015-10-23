#include<stdio.h>
#include<math.h>

int ara[10005];


void sieve()
{
    int i, j, root;

    root= (int)sqrt(10005);

    for(j=4;j<10005;j+=2)
            ara[j]=1;

    for (i=3; i<=root; i+=2)
    {
        if(!ara[i])
        {
            for(j=i+i;j<10005;j+=i)
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
   // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);

    int n,a,b,count=40,x,y,i,j,k,p=0;
    int times[10005]={0};
    int plist[10005]={0};
    sieve();


    for(i=2;i<10005;i++)
    {
        if(prime(i)==0)
        {
            plist[p]=i;
            p++;
        }
    }
    j=1;

    for(i=0;i<40;i++)
    {
        times[i]=j++;
    }

    for(i=40;i<=10000;i++)
    {
        n=i*i+i+41;
        int falsed=0;
        for(k=0;k<p;k++)
        {
            if(n%plist[k]==0 && plist[k]!=n)
            {
                falsed=1;
                break;
            }
        }
        if(falsed==0)
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



