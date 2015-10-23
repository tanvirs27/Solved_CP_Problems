#include<stdio.h>
#include<string.h>

int que[155],rear=0,frnt=0;

void push(int v)
{
    que[frnt]=v;
    frnt++;

    if(frnt==155)
        frnt=0;
}

int pop()
{
    int v=que[rear];
    que[rear]=0;
    rear++;

    if(rear==155)
        rear=0;

    return v;
}

void clr()
{
    memset(que,0,sizeof(que));
    frnt=0;
    rear=0;
}

int main()
{
  //  freopen("input.txt","r",stdin);

    int n,i,m,v;

    while(scanf("%d",&n)==1)
    {
        if(!n)break;

        for(m=2;;m++)
        {
            clr();

            for(i=1;i<=n;i++)
                push(i);

            for(i=1;;i++)
            {
                if((i%m==1))
                    v=pop();
                else
                    push(pop());

                if((rear-frnt==1) || ((frnt-rear)==1) )
                   break;
            }

            if(pop()==2)
                break;
        }
        printf("%d\n",m);

    }
    return 0;
}

