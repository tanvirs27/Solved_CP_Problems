#include<stdio.h>
#include<string.h>

char mine[105][105];

int main()
{
  //  freopen("input.txt","r",stdin);
  //  freopen("output.txt","w",stdout);

    int m,n,i,j,kase=1,x,y;

    while(scanf("%d%d",&m,&n)==2)
    {
        getchar();
        if(!m) break;

        if(kase!=1)
            puts("");

        memset(mine,0,sizeof(mine));

        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%c",&mine[i][j]);

                if(mine[i][j]=='.')
                    mine[i][j]=48;
            }
            getchar();
        }


    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(mine[i][j]=='*')
            {
                if(i+1<m)
                {
                    x=i+1;
                    y=j;
                    if(mine[x][y]!='*')
                        mine[x][y]++;

                }

                if(i-1>=0)
                {
                    x=i-1;
                    y=j;
                    if(mine[x][y]!='*')
                        mine[x][y]++;
                }

                if(j+1<n)
                {
                    x=i;
                    y=j+1;
                    if(mine[x][y]!='*')
                        mine[x][y]++;
                }

                if(j-1>=0)
                {
                    x=i;
                    y=j-1;
                    if(mine[x][y]!='*')
                        mine[x][y]++;
                }

                if(i+1<m && j+1<n)
                {
                    x=i+1;
                    y=j+1;
                    if(mine[x][y]!='*')
                        mine[x][y]++;
                }

                if(i+1<m && j-1>=0)
                {
                    x=i+1;
                    y=j-1;
                    if(mine[x][y]!='*')
                        mine[x][y]++;
                }

                if(i-1>=0 && j-1>=0)
                {
                    x=i-1;
                    y=j-1;
                    if(mine[x][y]!='*')
                        mine[x][y]++;
                }

                if(i-1>=0 && j+1<n)
                {
                    x=i-1;
                    y=j+1;
                    if(mine[x][y]!='*')
                        mine[x][y]++;
                }


            }
        }
    }

    printf("Field #%d:\n",kase++);

    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%c",mine[i][j]);

        }
        printf("\n");
    }

    }
    return 0;
}
