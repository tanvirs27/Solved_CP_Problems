/*
ID: tanvirs2
LANG: C
TASK: friday */
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
    int N, year, YD[400], X, i, j, day;
    int month[12]={1,4,4,0,2,5,0,3,6,1,4,6};
    int sat=0,sun=0,mon=0,tues=0,wed=0,thrus=0,fri=0;
    fscanf(fin, "%d", &N);
    for(i=0;i<N;i++){
        year= 1900+i;
        if(year%100==0){
            if(year%400==0){
                YD[i]= Y_D(year)-1;
            }
            else{
                YD[i]= Y_D(year);
            }
        }
        else{
            if(year%4==0){
                YD[i]= Y_D(year)-1;
            }
            else{
                YD[i]= Y_D(year);
            }
        }
    }
    for(i=0;i<N;i++){
        for(j=0;j<12;j++){
            X= YD[i]+ month[j];
            day= X%7;
            if(day==0) sat++;
            else if(day==1) sun++;
            else if(day==2) mon++;
            else if(day==3) tues++;
            else if(day==4) wed++;
            else if(day==5) thrus++;
            else if(day==6) fri++;
        }
    }
    fprintf(fout, "%d %d %d %d %d %d %d\n",sat,sun,mon,tues,wed,thrus,fri);
    return 0;
}


