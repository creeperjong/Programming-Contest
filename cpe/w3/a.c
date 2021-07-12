#include <stdio.h>
#include <stdint.h>
#include <string.h>

int main(){

    int32_t input = 0;
    int32_t tmp = 0;
    int32_t index = 0;
    int32_t parity = 0;
    int32_t bi[32] = {0};

    scanf("%d",&input);

    while(input != 0){
        tmp = input;
        while(tmp != 0){
            bi[index] = tmp % 2;
            tmp /= 2;
            index++;
        }
        for(int32_t i = 0;i < index;i++){
            parity += bi[i];
        }
        printf("The parity of ");
        for(int32_t i = index-1;i >= 0;i--){
            printf("%d",bi[i]);
        }
        printf(" is %d (mod 2).\n",parity);
        
        index = 0;
        parity = 0;
        memset(bi,0,32);

        scanf("%d",&input);
    }

    return 0;
}