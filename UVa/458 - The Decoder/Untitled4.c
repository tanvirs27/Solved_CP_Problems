#include<stdio.h>
#include<string.h>
int main()
{
    char s[10000];
    int i;
    while(gets(s)!=NULL){

        int len= strlen(s);

        for(i=0;i<len;i++){

            s[i]= s[i]-7;
        }
        printf("%s\n",s);
    }
    return 0;
}
