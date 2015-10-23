#include<stdio.h>

int main()
{
    int n;

    while(scanf("%d",&n)==1)
    {
        if(!n)break;

        int count=0,i,j;

        while(n>1)
        {
            if(n&1)
            {
                n=(n+1)/2;
            }
            else if(n==2)
                n=1;
            else
                n=n/2+1;

            count++;
        }
        if(count&1)
            puts("Alice");
        else
            puts("Bob");
    }
    return 0;
}
