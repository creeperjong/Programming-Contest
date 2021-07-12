#include <stdio.h>
#include <stdint.h>

int main(){

    char c = 0;
    int32_t max = 0;
    int32_t count[128 - 'A' + 1] = {0};

    do{
        c = getchar();

        if(c != EOF){
            if(c != '\n'){
                if((c >= 'A' && c <= 'Z')||(c >= 'a' && c <= 'z')){
                    count[c - 'A']++;
                }
            }else{
                for(int32_t i = 0;i < 128 - 'A' + 1;i++){
                    if(count[i] > max){
                        max = count[i];
                    }
                }
                for(int32_t i = 0;i < 128 - 'A' + 1;i++){
                    if(count[i] == max){
                        printf("%c",i + 'A');
                    }
                    count[i] = 0;
                }
                printf(" %d\n",max);
                max = 0;
            }
        }

    }while(c != EOF);

    return 0;
}