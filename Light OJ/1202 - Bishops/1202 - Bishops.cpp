#include<stdio.h>
#include<math.h>

int main()
{
    int t,i,j,k,r1,c1,r2,c2,m;

    scanf("%d",&t);

    for(i=1;i<=t;i++)
    {
        scanf("%d%d%d%d",&r1,&c1,&r2,&c2);

        int flag=0;
        j=r1+c1;
        k=r2+c2;

        if((j%2==0 && k%2!=0) || (j%2==1 && k%2!=1))
        {
            printf("Case %d: impossible\n",i);
            continue;
        }
        if(c1!=c2)
        {
            j=fabs(r1-r2);
            k=fabs(c1-c2);

            if(j==k)
                flag=1;
        }

        if(flag==1)
            printf("Case %d: 1\n",i);
        else
            printf("Case %d: 2\n",i);
    }
    return 0;
}
