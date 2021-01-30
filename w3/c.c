#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(){

    int32_t cases = 0;
    int32_t num = 0;
    int32_t isZero = 0;
    int32_t isLoop = 0;
    int32_t step = 0;
    int32_t* ducci = NULL;
    int32_t tmp = 0;

    scanf("%d",&cases);

    for(int32_t i = 0;i < cases;i++){
        scanf("%d",&num);

        ducci = (int32_t*)malloc(num * sizeof(int32_t));

        for(int32_t j = 0;j < num;j++){
            scanf("%d",&ducci[j]);
        }

        while(!(isZero || isLoop)){
            tmp = ducci[0];
            for(int32_t j = 0;j < num-1;j++){
                ducci[j] = abs(ducci[j] - ducci[j+1]);
            }
            ducci[num - 1] = abs(ducci[num - 1] - tmp);
            
            isZero = 1;
            for(int32_t j = 0;j < num-1;j++){
                if(ducci[j] != 0){
                    isZero = 0;
                }
            }
            step++;
            if(step > 1000){
                isLoop = 1;
            }
        }

        if(isLoop){
            printf("LOOP\n");
        }else if(isZero){
            printf("ZERO\n");
        }

        isZero = 0;
        isLoop = 0;
        step = 0;
        free(ducci);
    }

    return 0;
}