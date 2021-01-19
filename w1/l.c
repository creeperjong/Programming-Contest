#include <stdio.h>
#include <stdint.h>

int main(){
    char c;
    int32_t isWord = 0;
    int32_t time = 0;
    c = getchar();
    
    while(c != EOF){
        while(c != '\n'){
            if(!isWord && c >=65 && c <= 122){
                isWord = 1;
                time++;
            }else if(isWord && c < 65 || c > 122){
                isWord = 0;
            }
            c = getchar();
        }
        isWord = 0;
        printf("%d\n",time);
        time = 0;
        c = getchar();
    }

    return 0;
}