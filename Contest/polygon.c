#include<stdio.h>
#include<math.h>
double pi= 3.141592;
int main()
{
    double n, r;

    while(scanf("%lf %lf", &r, &n)!=EOF){


        printf("%0.3lf\n",(n*r*r*sin(2*pi/n))/2);
    }
    return 0;
}
