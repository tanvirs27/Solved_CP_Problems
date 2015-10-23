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
#define node 105

int cell[node][node];

int main()
{
 //   READ;

    int n,m,i,j,a,b;

    while(scanf("%d%d",&n,&m)==2)
    {
        if(n==0)break;

        while(m--)
        {
            scanf("%d%d",&a,&b);

            if(cell[a][b]!=1)
            {
                cell[a][b]=1;
                cell[0][b]++;
            }
        }

        int print=0;


        for(i=1; i<=n && print!=n; i++)
        {
            if(cell[0][i]==0)
            {
                cell[0][i]=-1;

                if(print!=0)
                    printf(" ");
                printf("%d",i);

                for(j=1; j<=n; j++)
                {
                    if(cell[i][j]!=0)
                    {
                        cell[0][j]--;
                    }
                }
                i=0;
                print++;
            }
        }
        puts("");

        clr(cell);
    }


    return 0;
}
