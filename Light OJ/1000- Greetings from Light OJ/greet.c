#include<stdio.h>
int main()
{
    int a,b,ans,T,i;
    scanf("%d",&T);
    for(i=0;i<T;i++){
        scanf("%d %d",&a,&b);
        ans=a+b;
        printf("Case %d: %d\n",i+1,ans);
    }

    return 0;
}
