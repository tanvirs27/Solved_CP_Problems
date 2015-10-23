#include<stdio.h>
#include<string.h>

int fibo[47]= {0,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765,10946,17711,28657,46368,75025,121393,196418,317811,514229,832040,1346269,2178309,3524578,5702887,9227465,14930352,24157817,39088169,63245986,102334155,165580141,267914296,433494437,701408733,1134903170,1836311903,2971215073};

void kothai_aso(int a[],int n)
{
    int x,i,j=0;

    for(i=0;i<n;i++)
    {
        for(j=1;j<47;j++)
        {
            if(a[i]==fibo[j])
            {
                a[i]=j;
                break;
            }
        }
    }

}

int main()
{
   // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);

    int t;
    scanf("%d",&t);

    while(t--)
    {
        int n,i,j,num[50],x,len;
        char text[105],ans[105];
        memset(num,0,sizeof(num));
        memset(text,0,sizeof(text));
        memset(ans,0,sizeof(ans));

        scanf("%d",&n);

        for(i=0;i<n;i++)
            scanf("%d",&num[i]);

        getchar();
        gets(text);

        kothai_aso(num,n);

      //  for(i=0;i<n;i++)
       //     printf("%d",num[i]);
      //  puts(text);

        len=strlen(text);
        j=0;
        if(j<n)
            x=num[j++];
        for(i=0;i<len && j<=n;i++)
        {
            if(text[i]>='A' && text[i]<='Z')
            {
                ans[x-1]=text[i];
                if(j<=n)
                    x=num[j++];
            }
        }

        int flag=0;
        for(i=50;i>=0;i--)
        {
            if(ans[i]>='A' && ans[i]<='Z')
            {
                if(!flag)
                {
                    flag=1;
                    ans[i+1]=0;
                }
            }
            else
            {
                if(flag)
                    ans[i]=' ';
            }
        }
        puts(ans);
    }

    return 0;
}
