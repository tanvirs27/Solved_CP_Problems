#include<stdio.h>
#include<string.h>
#include<math.h>

char encryp[10005];
char ans[10005];

int main()
{
  //  freopen("input.txt","r",stdin);
  //  freopen("output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    getchar();

    while(t--)
    {
        int i,j,m,n,k,len;
        gets(encryp);

        len=strlen(encryp);
        m=(int)sqrt(len);
        if(m*m!=len)
        {
            printf("INVALID\n");
            continue;
        }
        k=0;

        for(i=0;i<m;i++)
        {
           for(j=i;j<len;j+=m)
           {
                ans[k++]=encryp[j];
           }
        }
        ans[len]=0;

        puts(ans);
    }
    return 0;
}
