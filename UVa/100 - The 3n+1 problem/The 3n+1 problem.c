#include<stdio.h>

int function(int n)
{
    int count=0;

    while(1){
        if(n==1){
            count++;
            break;
        }
        else if(n%2==0){
            n=n/2;
            count++;
        }
        else if(n%2==1){
            n=3*n+1;
            count++;
        }
    }
    return count;
}

int main()
{
   // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);

    int a,b,i,x,y;

    while(scanf("%d%d",&a,&b)!=EOF){
        int max=0;

        if(a<=b)
        {
            x=a;
            y=b;
        }
        else
        {
            x=b;
            y=a;
        }

        for(i=x;i<=y;i++){
            int cnt= function(i);
            if(cnt>max){
                max=cnt;
            }
        }
        printf("%d %d %d\n",a,b,max);

    }
    return 0;

}
