#include<stdio.h>
#include<string.h>

int que[105],rear=0,frnt=0;

void push(int v)
{
    que[frnt]=v;
    frnt++;

    if(frnt==105)
        frnt=0;
}

int pop()
{
    int v=que[rear];
    que[rear]=0;
    rear++;

    if(rear==105)
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
    int n,i,m,v;

    while(scanf("%d",&n)==1)
    {
        if(!n)break;

        for(m=1;m<=n;m++)
        {
            clr();

            for(i=1;i<=n;i++)
                push(i);

            for(i=1;;i++)
            {
                if((i%m==1) || m==1)
                    v=pop();
                else
                    push(pop());

                if((rear-frnt==1) || ((frnt-rear)==1) )
                   break;
            }

            if(pop()==13)
                break;
        }
        printf("%d\n",m);

    }
    return 0;
}
