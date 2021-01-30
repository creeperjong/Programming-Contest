#include <stdio.h>
#include <stdint.h>

int main(){

    int32_t cases = 0;
    int32_t input = 0;
    int32_t tmp = 0;
    int32_t digit = 0;
    int32_t sum = 0;

    scanf("%d",&cases);

    for(int32_t i = 0;i < cases;i++){
        
        scanf("%d",&input);
        tmp = input;
        
        while(tmp != 0){
            tmp /= 10;
            digit++;
        }

        for(int32_t j = input - digit * 9;j < input;j++){
            sum = j;
            tmp = j;
            for(int32_t k = 0;k < digit;k++){
                sum += tmp % 10;
                tmp /= 10;
            }

            if(sum == input){
                printf("%d\n",j);
                break;
            }else if(j == input - 1){
                printf("%d\n",0);
                break;
            }
        }
    }

    return 0;
}