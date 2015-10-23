#include<stdio.h>
#include<math.h>

int num[1005],dif[1005];

int gcd(int a,int b)
{
    if(a%b==0)
        return b;

    gcd(b,a%b);
}

int main()
{
    int n,i,j,k;

    while(scanf("%d",&num[0])==1)
    {
        if(num[0]==0)
            break;

        i=1;

        do
        {
            scanf("%d",&num[i++]);
        }while(num[i-1]!=0);

        j=0;
        for(k=0;k<i-2;k++)
        {
            int temp=fabs(num[k]-num[k+1]);

            if(temp!=0)
                dif[j++]=temp;
        }

        int ans=dif[0];

        for(k=1;k<j;k++)
        {
            ans=gcd(ans,dif[k]);
        }

        printf("%d\n",ans);
    }
    return 0;
}
