#include <stdio.h>
#include <stdint.h>

int main(){

    int32_t input = 0;
    int32_t sum = 0;
    int32_t layer = 0;
    int32_t frontNum = 0;
    int32_t upper = 0;
    int32_t lower = 0;
    int32_t left = 0;

    while(scanf("%d",&input) != EOF){
        for(int32_t i = 1;i > 0;i++){
            for(int32_t j = 1;j <= i;j++){
                sum += j;
            }
            if(sum >= input){
                layer = i;
                break;
            }
            sum = 0;
        }

        for(int32_t i = 1;i < layer;i++){
            frontNum += i;
        }

        left = input - frontNum;

        if(layer % 2 == 1){
            lower = left;
            upper = layer + 1 - lower;
        }else{
            upper = left;
            lower = layer + 1 - upper;
        }

        printf("TERM %d IS %d/%d\n",input,upper,lower);

        sum = 0;
        frontNum = 0;

    }

    return 0;
}