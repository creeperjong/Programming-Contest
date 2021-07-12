#include <stdio.h>
#include <stdint.h>

int main(){
    char c;
    int32_t start = 1;
    int32_t correct = 0;
    int32_t sum = 0;

    c = getchar();

    while(c != '*'){
        while(c != '\n'){
            if(c == '/'){
                if(start){
                    start = 0;
                }else{
                    if(sum == 64){
                        correct++;
                    }
                        sum = 0;
                }
            }
            
            if(c == 'W') sum+=64;
            if(c == 'H') sum+=32;
            if(c == 'Q') sum+=16;
            if(c == 'E') sum+=8;
            if(c == 'S') sum+=4;
            if(c == 'T') sum+=2;
            if(c == 'X') sum+=1;

            c = getchar();
        }
        printf("%d\n",correct);
        start = 1;
        correct = 0;
        c = getchar();
    }

    return 0;
}