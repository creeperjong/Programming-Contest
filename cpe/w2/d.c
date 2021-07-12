#include <stdio.h>
#include <stdint.h>

int main(){
    char c;
    int32_t cases = 0;
    int32_t Accu = 0;
    int32_t score = 0;
        
    scanf("%d",&cases);

    c = getchar();
    for(int32_t i = 0;i < cases;i++){
        c = getchar();
        while(c != '\n'){
            if(c == 'O'){
                Accu += 1;
                score += Accu;
            }else if(c == 'X'){
                Accu = 0;
            }
            c = getchar();
        }
        printf("%d\n",score);
        Accu = 0;
        score = 0;
    }
    return 0;
}