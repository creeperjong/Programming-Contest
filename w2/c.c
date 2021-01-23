#include <stdio.h>
#include <stdint.h>

int main(){

    int32_t cases = 0;
    int32_t duo = 0;
    int32_t unduo = 0;
    int32_t num[4] = {0};
    int32_t thou = 0;
    int32_t ten = 0;

    scanf("%d",&cases);

    for(int32_t i = 0;i < cases;i++){
        for(int32_t j = 0;j < 4;j++){
            scanf("%d",&num[j]);

            unduo += (num[j] - num[j] / 1000 * 1000) / 100 + (num[j] - num[j] / 10 * 10) / 1;

            thou = num[j] / 1000 * 2;
            ten = (num[j] - num[j] / 100 * 100) / 10 * 2;

            duo += thou / 10 + thou % 10 + ten / 10 + ten % 10;
        }

        if((duo + unduo) % 10 == 0){
            printf("Valid\n");
        }else{
            printf("Invalid\n");
        }
        
        duo = 0;
        unduo = 0;
    }

    return 0;
}