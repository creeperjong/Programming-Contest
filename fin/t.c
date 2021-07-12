#include <stdio.h>
#include <stdint.h>

int main(){

    int64_t input = 0;
    int64_t minus = 0;
    int32_t isFirst = 1;

    do{
        scanf("%ld",&input);

        if(input != 0){
            for(int64_t i = 9;i >= 0;i--){

                if((input - i) % 9 == 0){
                    minus = (input - i) / 9;

                    if(!isFirst) printf(" ");
                    else isFirst = 0;

                    printf("%ld",input + minus);

                    minus = 0;
                }

            }
            printf("\n");

            isFirst = 1;
        }
    }while(input != 0);

    return 0;
}