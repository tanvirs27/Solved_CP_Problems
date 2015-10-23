#include<stdio.h>
#include<math.h>

int main()
{
    double T,i,r1,r2,r3,h,p,b,c,z,x;
    double ans;
    scanf ("%lf",&T);
    for (i=0;i<T;i++)
    {
        scanf ("%lf %lf %lf %lf",&r1,&r1,&h,&p);
        b= h*r1-p*r1+p*r2;
        c= (r1+r2)*(h*r2+p*r1-p*r2);
        z= sqrt(b*b-4*h*c);
        r3= (-b+z)/2*h;
        x= r3*r3+r3*r2+r2*r2;
        ans= (3.1416*p*x)/3;
        printf("Case %0.0lf: %lf\n",i+1,ans+1e-7);
    }
    return 0;
}
