#include<stdio.h>
#include<string.h>

int que[55],rear=0,frnt=0,discard[55];

void push(int v)
{
    que[frnt]=v;
    frnt++;

    if(frnt==55)
        frnt=0;
}

int pop()
{
    int v=que[rear];
    que[rear]=0;
    rear++;

    if(rear==55)
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
    int n,i;

    while(scanf("%d",&n)==1)
    {
        if(!n)break;

        clr();

        for(i=1;i<=n;i++)
            push(i);

        for(i=0;i<n-1;i++)
        {
            discard[i]=pop();
            push(pop());
        }

        printf("Discarded cards:");

        if(n!=1)
            printf(" ");

        for(i=0;i<n-1;i++)
        {
            if(i==0)
                printf("%d",discard[i]);
            else
                printf(", %d",discard[i]);
        }
        printf("\n");

        printf("Remaining card: %d\n",pop());

    }

    return 0;
}
