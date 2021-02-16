#include <stdio.h>
#include <stdint.h>
#include <string.h>

int main(){

    int32_t group = 0;
    int32_t len = 0;
    char word[101] = "";
    char buf[101] = "";

    do{
        scanf("%d",&group);

        if(group != 0){
            scanf("%s",word);
            len = strlen(word) / group;

            for(int32_t i = 0;i < strlen(word);i++){
                for(int32_t j = 0;j < len;j++){
                    if(i % len == j) buf[len-1-j] = word[i];
                }
                if(strlen(buf) == len){
                    for(int32_t j = 0;j < len;j++){
                        word[i + j - len + 1] = buf[j];
                        buf[j] = 0;
                    }
                }
            }

            printf("%s\n",word);
        }
    }while(group != 0);

    return 0;
}