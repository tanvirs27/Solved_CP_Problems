#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
using namespace std;

#define ri int
#define clr(a) memset(a,0,sizeof(a))
#define READ freopen("input.txt","r",stdin)

char name[105][55];
int cell[105][105];
int ans[105];

void top_sort(int n)
{
    int got=0,i,j;

    for(i=1; i<=n && got!=n; i++)
    {
        if(cell[0][i]==0)
        {
            cell[0][i]=-1;

            ans[got++]=i;

            for(j=1; j<=n; j++)
            {
                if(cell[i][j]!=0)
                {
                    cell[0][j]--;
                }
            }
            i=0;
        }
    }

    clr(cell);
}

int num_value(char a[])
{
    int i;

    for(i=1; i<105; i++)
    {
        if(strcmp(a,name[i])==0)
            return i;
    }
}

int main()
{
  //  READ;
    int n,i,j,m,kase=0,x,y;
    char a[55],b[55];

    while(scanf("%d",&n)==1)
    {
        kase++;

        i=1;
        int v=n;
        while(v--)
        {
            scanf("%s",name[i++]);
        }

        scanf("%d",&m);

        while(m--)
        {
            scanf("%s%s",a,b);

            x=num_value(a);
            y=num_value(b);

            if(cell[x][y]==0)
            {
                cell[x][y]=1;
                cell[0][y]++;
            }
        }

        top_sort(n);

        printf("Case #%d: Dilbert should drink beverages in this order:",kase);

        for(i=0; i<n; i++)
            printf(" %s",name[ans[i]]);

        puts(".");
        puts("");
    }
    return 0;
}

