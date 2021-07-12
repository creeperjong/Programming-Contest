#include <stdio.h>
#include <stdint.h>

int main(){

    int32_t cases = 0;
    int32_t input = 0;
    int32_t sum = 0;
    
    scanf("%d",&cases);

    for(int32_t i = 0;i < cases;i++){
        scanf("%d",&input);

        for(int32_t j = 1;j < input;j++){
            if(input % j == 0){
                sum += j;
            }
        }

        if(input > sum){
            printf("deficient\n");
        }else if(input == sum){
            printf("perfect\n");
        }else{
            printf("abundant\n");
        }

        sum = 0;
    }
    return 0;
}