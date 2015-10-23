#include<stdio.h>
#include<string.h>

int main()
{
    char sen[10000];
    int i, len, word, word_started;

    while(gets(sen)!=NULL){
        len= strlen(sen);
        word_started=0;
        word=0;
        for(i=0;i<len;i++){

            if(word_started==0){
                if(sen[i]>='A' && sen[i]<='Z'){
                    word_started=1;
                    word= word+1;
                }
                else if(sen[i]>='a' && sen[i]<='z'){
                    word_started=1;
                    word= word+1;
                }
            }

            else if(word_started==1){
                if(sen[i]>='A' && sen[i]<='Z'){
                    word_started=1;
                }
                else if(sen[i]>='a' && sen[i]<='z'){
                    word_started=1;
                }
                else{
                    word_started=0;
                }
            }
        }
        printf("%d\n",word);
    }
    return 0;
}
