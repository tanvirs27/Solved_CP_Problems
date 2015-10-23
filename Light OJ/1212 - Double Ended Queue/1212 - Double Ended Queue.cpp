#include<stdio.h>
#include<string.h>

int que[24],left=12,right=13;

void left_push(int v)
{
    que[left]=v;
    left--;
}

int left_pop()
{
    int v=que[left+1];
    left++;

    return v;
}

void right_push(int v)
{
    que[right]=v;
    right++;
}

int right_pop()
{
    int v=que[right-1];
    right--;

    return v;
}

void clr()
{
    memset(que,0,sizeof(que));
    left=12;
    right=13;
}

int main()
{
   // freopen("input.txt","r",stdin);

    int t,n,m,a,i,j;
    char command[15];

    scanf("%d",&t);

    for(i=1;i<=t;i++)
    {
        scanf("%d%d",&n,&m);
        getchar();

        printf("Case %d:\n",i);

        for(j=0;j<m;j++)
        {
            scanf("%s",command);

          //  printf("left= %d, right= %d\n",left,right);

            if(strcmp(command,"pushLeft")==0)
            {
                scanf("%d",&a);
                if(right-left==n+1)
                    printf("The queue is full\n");
                else
                {
                    left_push(a);
                    printf("Pushed in left: %d\n",a);
                }
            }
            else if(strcmp(command,"pushRight")==0)
            {
                scanf("%d",&a);
                if(right-left==n+1)
                    printf("The queue is full\n");
                else
                {
                    right_push(a);
                    printf("Pushed in right: %d\n",a);
                }
            }
            else if(strcmp(command,"popLeft")==0)
            {
                if(right-left==1)
                    printf("The queue is empty\n");
                else
                    printf("Popped from left: %d\n",left_pop());
            }
            else if(strcmp(command,"popRight")==0)
            {
                if(right-left==1)
                    printf("The queue is empty\n");
                else
                    printf("Popped from right: %d\n",right_pop());
            }

        }
        clr();
    }
    return 0;
}
