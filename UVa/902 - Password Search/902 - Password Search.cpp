#include<stdio.h>
#include<string.h>

char sen[1000000];
char word[1000000][20];
int count[1000000];

int partition(int p,int r)
{
    char dummy[20];
    char checker[20];

    int i,j;

    strcpy(checker,word[r]);
    i=p;

    for(j=i;j<r;j++)
    {
        if(strcmp(word[j],checker)<0)
        {

            strcpy(dummy,word[i]);
            strcpy(word[i],word[j]);
            strcpy(word[j],dummy);
			i=i+1;
        }
    }
    strcpy(dummy,word[i]);
    strcpy(word[i],word[r]);
    strcpy(word[r],dummy);

    return i;
}

void quicksort(int p, int r)
{
    int q;
    if(p<r)
    {
        q=partition(p,r);
        quicksort(p,q-1);
        quicksort(q+1,r);

    }
}

int main()
{
	int n;
	char c;

	while(scanf("%d%c%s",&n,&c,sen)!=EOF)
	{
		memset(count,0,sizeof(count));

		int len,i,j,k,m,x;
		len=strlen(sen);

		for(i=0;i<len-n+1;i++)
		{
		    k=0;
			for(j=i;j<i+n;j++)
			{
				word[i][k++]=sen[j];
			}
            word[i][k]=0;
		}

        x=i-1;
        quicksort(0,x);

        for(i=0;i<=x;)
        {
            k=i;
            while(strcmp(word[i],word[k++])==0)
            {
                count[i]++;
            }
            i=k-1;
        }

        int max=count[0],index=0;
        for(i=1;i<=x;i++)
        {
            if(count[i]>max)
            {
                max=count[i];
                index=i;
            }
        }
        puts(word[index]);
    }

	return 0;
}
