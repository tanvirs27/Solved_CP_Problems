#include<stdio.h>
#include<math.h>

#define ri long long int

void ext_euclid(ri a, ri b,ri *s,ri *t)
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

    return;
}

int main()
{
    ri a,b,s,t,fl,cl,kase;
    double x,k;

    scanf("%lld",&t);


    while(kase--)
    {
        scanf("%lf%lf",&x,&k);
        fl= (ri)floor(x/k);
        cl= (ri)ceil(x/k);

        printf("%lld %lld\n",fl,cl);

        ext_euclid(fl,cl,&s,&t);
        printf("%lld %lld\n",s,t);
    }
    return 0;
}



