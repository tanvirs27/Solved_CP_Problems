#include<stdio.h>

#define ri long long int

ri ext_euclid(ri a, ri b,ri *s,ri *t)
{
    ri r=1,s0=1,s1=0,t0=0,t1=1,q;

    while(r)
    {
        r=a%b;
        q=a/b;
        a=b;
        b=r;
        *s=s0-q * s1;
        *t=t0-q * t1;

        s0=s1;
        t0=t1;
        s1=*s;
        t1=*t;
    }
    *s=s0;
    *t=t0;

    return a;
}

int main()
{
    ri a,b,s,t;

    while(scanf("%lld%lld",&a,&b)==2)
    {
        ri gcd=ext_euclid(a,b,&s,&t);
        printf("%lld %lld %lld\n",s,t,gcd);
    }
    return 0;
}

