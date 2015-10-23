#include<stdio.h>
#include<string.h>

int stk[1005];
int top;

void push(int v)
{
    stk[top]=v;
    top++;
}

void pop()
{
    stk[top-1];
    top--;
}

int main()
{
    freopen("input.txt","r",stdin);

    int n,flag,a,i;

    while(scanf("%d",&n)==1)
    {
        if(!n)break;





            for(i=1;i<=n;i++)
            {
                scanf("%d",&a);
                if(a==0 && i==1)break;

                if(i==1)
                {
                    memset(stk,0,sizeof(stk));
                    top=0;
                    flag=n;
                }


                if(a==flag)
                {
                    flag--;
                    while(top>0 && stk[top-1]==flag)
                    {
                        pop();
                        flag--;
                    }
                }
                else
                    push(a);
            }

            if(!top)
                printf("Yes\n");
            else
                printf("No\n");

    }

    return 0;
}
