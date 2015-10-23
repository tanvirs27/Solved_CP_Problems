#include<stdio.h>
#include<string.h>

char stk[150];
int top;

void push(char v)
{
    stk[top]=v;
    top++;
   // printf("push top %d\n",top);
}

char pop()
{
    char v=stk[top-1];
    top--;
 //   printf("pop top %d\n",top);
    return v;
}

int main()
{
  //  freopen("input.txt","r",stdin);

    int t,i;
    char c;
    scanf("%d",&t);
    getchar();

    for(i=1;i<=t;i++)
    {
        memset(stk,0,sizeof(stk));
        top=0;
        int flag=1;

        while(1)
        {
            char v=getchar();

            if(v=='\n')break;

            if(top==0 && (v==')' || v==']'))
            {
                flag=0;
            }

            else if(v=='(' || v=='[')
            {
                push(v);
            }
            else if(v==')')
            {
                c=pop();

                if(c!='(')
                    flag=0;
            }
            else if(v==']')
            {
                c=pop();

                if(c!='[')
                    flag=0;
            }

            if(top<0)
                top=100;
        }
        if(top!=0) flag=0;


  //      printf("top=%d flag=%d\n",top,flag);

        if(!flag)
            puts("No");
        else
            puts("Yes");
    }

    return 0;
}
