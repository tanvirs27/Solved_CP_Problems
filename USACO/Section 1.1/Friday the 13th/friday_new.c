/*
ID: tanvirs2
LANG: C
TASK: friday
*/
#include<stdio.h>

int main()
{
    freopen ("friday.in","r",stdin);
    freopen ("friday.out","w",stdout);
    int i, j, N, day=-3;
    int sat=0,sun=0,mon=0,tues=0,wed=0,thrus=0,fri=0;
    scanf("%d", &N);
    for(i=1900;i<N+1900;i++){
        for(j=0;j<12;j++){
            if(j==4 || j==6 || j==9 || j==11){
                day= (day+2)%7;
            }
            else if (j==0 || j==1 || j==3 || j==5 || j==7 || j==8 || j==10){
                day= (day+3)%7;
            }
            else if (i%100==0 && i%400!=0){
                day= day;
            }
            else if (i%100==0 && i%400==0){
                day= (day+1)%7;
            }
            else if (i%100!=0 && i%4!=0){
                day= day;
            }
            else if (i%100!=0 && i%4==0){
                day= (day+1)%7;
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
