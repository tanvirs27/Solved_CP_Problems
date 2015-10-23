#include<stdio.h>
#include<string.h>

char for_stk[105][55], back_stk[105][55];
int for_top,back_top;

void for_push(char url[55])
{
    strcpy(for_stk[for_top],url);
    for_top++;
}

void for_pop(char url[55])
{
    strcpy(url,for_stk[for_top-1]);
    for_top--;
}

void for_clr()
{
    memset(for_stk,0,sizeof(for_stk));
    for_top=0;
}

void back_push(char url[55])
{
    strcpy(back_stk[back_top],url);
    back_top++;
}

void back_pop(char url[55])
{
    strcpy(url,back_stk[back_top-1]);
    back_top--;
}

void back_clr()
{
    memset(back_stk,0,sizeof(back_stk));
    back_top=0;
}

int main()
{
   // freopen("input.txt","r",stdin);

    int t,i;
    char command[15],input[55],current[55];

    scanf("%d",&t);
    getchar();

    for(i=1;i<=t;i++)
    {
        strcpy(current,"http://www.lightoj.com/");
        for_clr();
        back_clr();

        printf("Case %d:\n",i);

        while(1)
        {
            scanf("%s",command);
           // puts(command);

            if(strcmp(command,"VISIT")==0)
            {
                scanf("%s",input);
              //  puts(input);

                back_push(current);
                for_clr();

                strcpy(current,input);
                puts(current);
            }

            else if(strcmp(command,"BACK")==0)
            {
                if(back_top==0)
                {
                    printf("Ignored\n");
                    continue;
                }
                else
                {
                    for_push(current);
                    back_pop(current);
                }
                puts(current);
            }
            else if(strcmp(command,"FORWARD")==0)
            {
                if(for_top==0)
                {
                    printf("Ignored\n");
                    continue;
                }
                else
                {
                    back_push(current);
                    for_pop(current);
                }
                puts(current);
            }
            else if(strcmp(command,"QUIT")==0)
            {
                break;
            }
        }
    }
    return 0;
}
