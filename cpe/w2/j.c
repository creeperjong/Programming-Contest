#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(){
    int32_t cases = 0;
    int32_t num = 0;
    int32_t tmp = 0;
    int32_t step = 0;
    int32_t* carr = NULL;

    scanf("%d",&cases);

    for(int32_t i = 0;i < cases;i++){
        scanf("%d",&num);

        carr = (int32_t*)malloc(num * sizeof(int32_t));

        for(int32_t j = 0;j < num;j++){
            scanf("%d",&carr[j]);
        }

        for(int32_t j = 0;j < num-1;j++){
            for(int32_t k = j+1;k < num;k++){
                if(carr[k] < carr[j]){
                    tmp = carr[j];
                    carr[j] = carr[k];
                    carr[k] = tmp;
                    step++;
                }
            }
        }

        printf("Optimal train swapping takes %d swaps.\n",step);

        free(carr);
        step = 0;
    }
    return 0;
}