/*
ID: tanvirs2
LANG: C
TASK: friday
*/
#include<stdio.h>
int Y_D (int Y)
{
    int m,n,p,q;
    m= Y%100;
    n= m+(m/4);
    q= n%7;
    p= q+13;

    return p;
}

int main()
{
    FILE *fin= fopen ("friday.in","r");
    FILE *fout= fopen ("friday.out","w");
    int N, year, X, i, j, day;
    int month[12]={1,4,4,0,2,5,0,3,6,1,4,6};
    int leap[12]={0,3,4,0,2,5,0,3,6,1,4,6};
    int sat=0,sun=0,mon=0,tues=0,wed=0,thrus=0,fri=0;
    scanf("%d",&N);

    for(i=0;i<N;i++){
        year= 1900+i;
        for(j=0;j<12;j++){

            if(year%100==0){
                if(year%400==0){
                    X= Y_D(year)+ leap[j];
                    day= X%7;
                }
                else{
                    X= Y_D(year)+ month[j];
                    day= X%7;
                }
            }
            else{
                if(year%4==0){
                    X= Y_D(year)+ leap[j];
                    day= X%7;
                }
                else{
                    X= Y_D(year)+ month[j];
                    day= X%7;
                }
            }

            if(day==0) sat++;
            else if(day==1) sun++;
            else if(day==2) mon++;
            else if(day==3) tues++;
            else if(day==4) wed++;
            else if(day==5) thrus++;
            else if(day==6) fri++;
        }
    }
    printf("%d %d %d %d %d %d %d\n",sat,sun,mon,tues,wed,thrus,fri);
    return 0;
}


