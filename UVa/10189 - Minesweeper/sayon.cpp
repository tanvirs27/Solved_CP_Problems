#include<stdio.h>
char mine[500][500], res[500][500];
void minesweep(char a[][500], int n, int m);
int main()
{
    freopen("input.txt","r",stdin);
    int i,j,k,n,m;
    for(k=1; ;k++)
    {
        scanf("%d%d", &n,&m);
        if(n==0||m==0)
            break;
        getchar();
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                scanf("%c", &mine[i][j]);
                res[i][j]=0;
            }
            getchar();
        }
        minesweep(mine, n, m);
        printf("Field #%d:\n", k);
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
                printf("%c", res[i][j]);
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}

void minesweep(char a[][500], int n, int m)
{
    int i,j;
    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
            if(a[i][j]=='*')
            {
                if(i-1>=0&&j-1>=0&&a[i-1][j-1]!='*')
                    res[i-1][j-1]++;
                if(i-1>=0&&a[i-1][j]!='*')
                    res[i-1][j]++;
                if(i-1>=0&&j+1<m&&a[i-1][j+1]!='*')
                    res[i-1][j+1]++;
                if(j-1>=0&&a[i][j-1]!='*')
                    res[i][j-1]++;
                res[i][j]='*';
                if(j+1<m&&a[i][j+1]!='*')
                    res[i][j+1]++;
                if(i+1<n&&j-1>=0&&a[i+1][j-1]!='*')
                    res[i+1][j-1]++;
                if(i+1<n&&a[i+1][j]!='*')
                    res[i+1][j]++;
                if(i+1<n&&j+1<m&&a[i+1][j+1]!='*')
                    res[i+1][j+1]++;
            }
    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
            if(res[i][j]!='*')
                res[i][j]+=48;
}
