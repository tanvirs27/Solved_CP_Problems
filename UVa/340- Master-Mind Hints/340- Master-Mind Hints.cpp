#include<stdio.h>

int main()
{
    int code[1001];
    int guess[1001];
    int cpy[1001];
    int n,a,b,i,j,game=1;

    while(EOF)
    {

        scanf("%d",&n);

        if(n==0)break;

        for(i=0;i<n;i++)
        {
            scanf("%d",&code[i]);
        }
        printf("Game %d:\n",game);
        while(1)
        {
            for(i=0;i<n;i++)
            {
                scanf("%d",&guess[i]);
            }
            if(guess[i-1]==0)break;

            int strong=0,weak=0;

            for(i=0;i<n;i++)
            {
                cpy[i]=code[i];
            }

            for(i=0;i<n;i++)
            {
                if(cpy[i]==guess[i])
                {
                    strong++;
                    guess[i]=0;
                    cpy[i]=0;
                }
            }

            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                    if(guess[i]==cpy[j] && guess[i]!=0 && cpy[j]!=0)
                    {
                        weak++;
                        cpy[j]=0;
                        break;
                    }
                }
            }

            printf("    (%d,%d)\n",strong,weak);
        }
        game++;
    }
    return 0;
}
