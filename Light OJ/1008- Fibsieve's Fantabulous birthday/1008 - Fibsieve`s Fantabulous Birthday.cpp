#include<stdio.h>
#include<math.h>

int main()
{
    int t,k;
    long long int s,r,c,top,mid,bottom,n;

    scanf("%d",&t);

    for(k=1;k<=t;k++)
    {
        scanf("%lld",&s);

        n=(long long int)ceil(sqrt((double)s));

        if(n%2==0)
        {
            top=(n-1)*(n-1)+1;
            mid=n*n-(n-1);
            bottom=n*n;

            if(s>=top && s<=mid)
            {
                r=n;
                c=n-(mid-s);
            }
            else
            {
                c=n;
                r=n-(s-mid);
            }
        }
        else
        {
            top=n*n;
            mid=n*n-(n-1);
            bottom=(n-1)*(n-1)+1;

            if(s<=top && s>=mid)
            {
                r=n;
                c=n-(s-mid);
            }
            else
            {
                c=n;
                r=n-(mid-s);
            }
        }

        printf("Case %d: %lld %lld\n",k,c,r);
    }
    return 0;
}
