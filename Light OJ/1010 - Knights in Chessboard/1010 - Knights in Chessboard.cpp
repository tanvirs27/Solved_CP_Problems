#include<stdio.h>

int main()
{
    int t,k,i,j,m,n,ans;

    scanf("%d",&t);

    for(k=1;k<=t;k++)
    {
        scanf("%d%d",&m,&n);

        if(m==1)
            ans=n;
        else if(n==1)
            ans=m;
        else if(m==2 && n==2)
            ans=4;
        else if(m==2)
        {
            ans=(n/4)*4+((n%4)*2);
            if(n%4==3)ans-=2;
        }
        else if(n==2)
        {
            ans=(m/4)*4+((m%4)*2);
            if(m%4==3)ans-=2;
        }
        else
            ans= (m*n+1)/2;

        printf("Case %d: %d\n",k,ans);
    }
    return 0;
}
