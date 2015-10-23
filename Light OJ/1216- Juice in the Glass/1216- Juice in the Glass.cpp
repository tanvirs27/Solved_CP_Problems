#include<stdio.h>
#include<math.h>

int main()
{
    double T,i,r1,r2,r3,h,p,b,c,z,x;
    double ans;
    scanf ("%lf",&T);
    for (i=0;i<T;i++)
    {
        scanf ("%lf%lf%lf%lf",&r1,&r2,&h,&p);
        b= h*r1-p*r1+p*r2;
        printf("%lf\n",b);
        c= (r1+r2)*(h*r2+p*r1-p*r2);
        printf("%lf\n",c);
        z= sqrt(-b*b+4*h*c);
        printf("%lf\n",z);
        r3= (-b+z)/(2*h);
        printf("%lf\n",r3);
        x= r3*r3+r3*r2+r2*r2;
        printf("%lf\n",x);
        ans= (3.1416*p*x)/3;
        printf("Case %0.0lf: %lf\n",i+1,ans);
    }
    return 0;
}
