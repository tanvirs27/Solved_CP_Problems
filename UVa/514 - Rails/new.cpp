#include<stdio.h>
#include<string.h>

int stk[1005];
int ara[1005];
int top;

void push(int v)
{
    stk[top]=v;
    top++;
}

void pop()
{
    top--;
}

int main()
{
  //  freopen("input.txt","r",stdin);

    int n,flag,a,i;

    while(scanf("%d",&n)==1)
    {
        if(!n)break;

        while(1){

        for(i=0;i<n;i++)
        {
            scanf("%d",&ara[i]);
            if(ara[0]==0)
                break;
        }
        if(i<n)
        {
            puts("");
            break;
        }

        memset(stk,0,sizeof(stk));
        top=0;
        int index=0;
        flag=ara[index];

        for(i=1;i<=n;i++)
        {
            if(i==flag)
            {
                index++;
                flag=ara[index];

                if(top==0)continue;

                while(top>0 && stk[top-1]==flag)
                {


                    flag=ara[++index];
                    pop();

                }
            }
            else
                push(i);
        }

        if(!top)
            printf("Yes\n");
        else
            printf("No\n");

        }

    }
    return 0;
}
