#include<stdio.h>
#include<string.h>

int mat[11][11],n;
char in[11][11];

void input()
{
    int i,j;

    for(i=0;i<n;i++)
        scanf("%s",in[i]);

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            mat[i][j]=in[i][j]-48;
        }
    }
}

void swap(int a, int b, int c, int d)
{
    int temp=mat[a][b];
    mat[a][b]=mat[c][d];
    mat[c][d]=temp;
}

void transpose()
{
    int i,j;

    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++)
            swap(i,j,j,i);
    }
}

void row(int a, int b)
{
    int i,j;

    for(i=0;i<n;i++)
    {
        swap(a-1,i,b-1,i);
    }
}

void col(int a, int b)
{
    int i,j;

    for(i=0;i<n;i++)
    {
        swap(i,a-1,i,b-1);
    }
}

void inc()
{
    int i,j;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            mat[i][j]++;

            if(mat[i][j]==10)
                mat[i][j]=0;
        }
    }
}

void dec()
{
    int i,j;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            mat[i][j]--;

            if(mat[i][j]==-1)
                mat[i][j]=9;
        }
    }
}

int main()
{
  //  freopen("input.txt","r",stdin);

    int t,m,i,j,k,l,a,b;
    char command[10];

    scanf("%d",&t);

    for(k=1;k<=t;k++)
    {
        scanf("%d",&n);

        input();

        scanf("%d",&m);
        getchar();

        while(m--)
        {
            scanf("%s",command);

            if(strcmp(command,"row")==0)
            {
                scanf("%d%d",&a,&b);
                getchar();

                row(a,b);
            }

            else if(strcmp(command,"col")==0)
            {
                scanf("%d%d",&a,&b);
                getchar();

                col(a,b);
            }

            else if(strcmp(command,"inc")==0)
            {
                inc();
            }

            else if(strcmp(command,"dec")==0)
            {
                dec();
            }
            else if(strcmp(command,"transpose")==0)
            {
                transpose();
            }
        }

        printf("Case #%d\n",k);
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                printf("%d",mat[i][j]);
            }
            printf("\n");
        }
        puts("");
    }

    return 0;
}
