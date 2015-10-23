#include<stdio.h>

long long int nCk(long long n, long long k)
{
    long long int pascal[100][100]={{0},{0}};
    long long int i,j;


    for(i=0;i<50;i++)
    {
        pascal[i][0]=1;
    }

    for(i=1;i<50;i++)
    {
        for(j=1;j<100;j++)
        {
            pascal[i][j]=pascal[i-1][j]+pascal[i-1][j-1];
        }
    }
    return pascal[n][k];
}

int main()
{
    freopen("output.txt","w",stdout);

    printf("%lld\n",nCk(40,20));

    return 0;
}

