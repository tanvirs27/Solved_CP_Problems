#include<stdio.h>
int main()
{
    int n1,n2,n3,T,i,ara[3];

    scanf("%d",&T);

    for(i=0;i<T;i++){
        scanf("%d %d %d",&n1,&n2,&n3);

        if(n1<n2 && n1<n3){
            ara[0]=n1;
            if(n2<n3){
                ara[1]=n2;
                ara[2]=n3;
            }
            else{
                ara[1]=n3;
                ara[2]=n2;
            }
        }
        else if(n1>n2 && n1>n3){
            ara[2]=n1;
            if(n2<n3){
                ara[0]=n2;
                ara[1]=n3;
            }
            else{
                ara[0]=n3;
                ara[1]=n2;
            }
        }
        else{
            ara[1]=n1;
            if(n2<n3){
                ara[0]=n2;
                ara[2]=n3;
            }
            else{
                ara[0]=n3;
                ara[2]=n2;
            }
        }

        printf("Case %d: %d %d %d\n",i+1,ara[0],ara[1],ara[2]);
    }

    return 0;
}

