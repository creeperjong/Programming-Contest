#include <stdio.h>
#include <stdint.h>

int main(){
    int32_t cases = 0;
    int32_t input = 0;
    int32_t tmp = 0;
    int32_t isOver = 0;
    int32_t time[10] = {0};
    int32_t digit[5] = {0};

    scanf("%d",&cases);

    for(int32_t i = 0;i < cases;i++){
        scanf("%d",&input);

        for(int32_t j = 1;j <= input;j++){
            tmp = j;
            for(int32_t k = 0;k < 5;k++){
                if(!isOver){
                    digit[k] = tmp % 10;
                    tmp /= 10;
                    if(tmp == 0){
                        isOver = 1;
                    }
                    time[digit[k]]++;
                }
            }
            isOver = 0;
        }

        for(int32_t j = 0;j < 10;j++){
            if(j == 9){
                printf("%d\n",time[j]);
            }else{
                printf("%d ",time[j]);
            }
            time[j] = 0;
        }

        
    }
    return 0;
}