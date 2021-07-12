#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int32_t cases = 0;
    int32_t en = 0;
    int32_t num = 0;
    char plate[8] = "";

    scanf("%d",&cases);

    for(int32_t i = 0;i < cases;i++){
        scanf("%s",plate);

        for(int32_t j = 0;j < 3;j++){
            en += (plate[j] - 'A') * pow(26,2-j);
        }

        for(int32_t j = 4;j < 8;j++){
            num += (plate[j] - '0') * pow(10,7-j);
        }

        if(abs(en - num) <= 100){
            printf("nice\n");
        }else{
            printf("not nice\n");
        }

        en = 0;
        num = 0;
    }
    return 0;
}