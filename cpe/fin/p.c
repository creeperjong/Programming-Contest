#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(){

    int32_t primeIdx = 1;
    int32_t endIdx = 0;
    int32_t input = 0;
    int32_t count = 0;
    int prime[3600] = {0};
    
    prime[0] = 2;
    for(int32_t i = 2;i < 32768;i++){
        for(int32_t j = 2;j < i;j++){
            if(i % j == 0){
                break;
            }
            if(j == i-1 && primeIdx != 3600) prime[primeIdx++] = i;
        }
    }

    do{
        scanf("%d",&input);

        if(input != 0){
            for(int32_t i = 0;i < 3600;i++){
                if(prime[i] > input){
                    endIdx = i;
                    break;
                }else if(prime[i] == 0){
                    endIdx = i;
                    break;
                }
            }

            for(int32_t i = 0;i < endIdx;i++){
                for(int32_t j = endIdx - 1;j >= 0;j--){
                    //printf("%d %d\n",i,j);
                    if(j >= i){
                        if(prime[j] + prime[i] == input) count++;
                    }
                }
            }

            printf("%d\n",count);

            count = 0;
        }

    }while(input != 0);

    return  0;
}