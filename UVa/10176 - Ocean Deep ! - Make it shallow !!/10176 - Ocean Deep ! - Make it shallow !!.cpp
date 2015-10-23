#include<stdio.h>
#include<string.h>

int main()
{
    char ch;
    long long int prime=131071,b=0;

    while(scanf("%c",&ch)==1)
    {
        if(ch=='0' || ch=='1')
        {
            b*=2;
            b+=ch-'0';
            b%=prime;
        }

        else if(ch=='#')
        {
            if(b==0)
                printf("YES\n");
            else
                printf("NO\n");

            b=0;
        }
    }
    return 0;
}

