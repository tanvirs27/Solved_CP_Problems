#include<stdio.h>
#include<string.h>
#include<math.h>

char num[1000000];

int mod(int n)
{
    int m=0,len,i;

    len=strlen(num);

    for(i=0;i<len;i++)
    {
        m=((num[i]-48)+m*10)%n;
       // printf("%d\n",m);
    }

    if(m==0)
        return 0;
    else
        return 1;
}


int main()
{
  //  freopen("input.txt","r",stdin);

    int q=0;

    while(scanf("%s",num)==1)
    {
        if(q!=0)
            printf("\n");
        else
            q=1;

        int leap=0, hulu=0, bulu=0;
   //     printf("%s\n",num);

    if(mod(400)==0 || (mod(4)==0 && mod(100)!=0))
    {
        leap=1;
        printf("This is leap year.\n");
    }
    if(mod(15)==0)
    {
        hulu=1;
        printf("This is huluculu festival year.\n");
    }
    if(leap==1 && mod(55)==0)
    {
        bulu=1;
        printf("This is bulukulu festival year.\n");
    }
    if(leap==0 && hulu==0)
    {
        printf("This is an ordinary year.\n");
    }


    }
    return 0;
}

