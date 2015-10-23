/*
ID: tanvirs2
LANG: C
PROG: ride
*/
#include<stdio.h>
#include<string.h>

int product (char A[])
{
    int length, i, a, x=1;
    length= strlen(A);
    for(i=0;i<length;i++){
        a= A[i]- 'A'+1;
        x= x*a;
    }
    return x;
}

int main()
{
    freopen ("ride.in","r",stdin);
    freopen ("ride.out","w",stdout);
    int x,y,a,b;
    char comet[7],group[7];
    scanf("%s %s", comet, group);
    x= product(comet);
    y= product(group);
    a= x%47;
    b= y%47;
    if (a==b){
        printf("GO\n");
    }
    else{
        printf("STAY\n");
    }

    return 0;
}
