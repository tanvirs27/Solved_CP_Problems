#include<stdio.h>

int main()
{
    int T,i;
    double v1,v2,v3,a1,a2,s1,s2,s,d,t,t1,t2;

    scanf("%d",&T);

    for(i=1;i<=T;i++)
    {
        scanf("%lf%lf%lf%lf%lf",&v1,&v2,&v3,&a1,&a2);

        t1=v1/a1;
        s1=v1*t1-.5*a1*t1*t1;
        t2=v2/a2;
        s2=v2*t2-.5*a2*t2*t2;
        s=s1+s2;
        if(t1>t2)t=t1;
        else t=t2;

        d=v3*t;

        printf("Case %d: %.8lf %.8lf\n",i,s,d);
    }
    return 0;
}
