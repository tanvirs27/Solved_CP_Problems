#include<stdio.h>

int main()
{
   // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);

    int a,b;

    while(scanf("%d%d",&a,&b)==2)
    {
        int sum=a;
        int reminder=0;

        while(a+reminder>=b)
        {
            a+=reminder;
            reminder=a%b;
            a=a/b;
            sum+=a;

        }
        printf("%d\n",sum);
    }

    return 0;
}


