#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

int32_t ascend(int32_t input);
int32_t descend(int32_t input);

int32_t ascend(int32_t input){
    char num[10] = "";
    int32_t idx = 0;
    int32_t tmp = 0;

    while(input != 0){
        num[idx++] = input % 10 + '0';
        input /= 10;
    }

    for(int32_t i = 0;i < idx;i++){
        for(int32_t j = i + 1;j < idx;j++){
            if(num[i] > num[j]){
                tmp = num[i];
                num[i] = num[j];
                num[j] = tmp;
            }
        }
    }
    
    return atoi(num);
}

int32_t descend(int32_t input){
    char num[10] = "";
    int32_t idx = 0;
    int32_t tmp = 0;

    while(input != 0){
        num[idx++] = input % 10 + '0';
        input /= 10;
    }

    for(int32_t i = 0;i < idx;i++){
        for(int32_t j = i + 1;j < idx;j++){
            if(num[i] < num[j]){
                tmp = num[i];
                num[i] = num[j];
                num[j] = tmp;
            }
        }
    }

    return atoi(num);
}

int main(){

    int32_t input = 0;
    int32_t chain[1000] = {0};
    int32_t chainLen = 0;
    int32_t isRepeat = 0;
    int32_t tmp = 0;
    int32_t a = 0;
    int32_t d = 0;
    int32_t c = 0;

    do{
        scanf("%d",&input);


        if(input != 0){
            printf("Original number was %d\n",input);
            tmp = input;
            while(!isRepeat){

                 a = ascend(tmp);
                 d = descend(tmp);
                 c = d - a;


                for(int32_t i = 0;i < chainLen;i++){
                    if(c == chain[i]){
                        isRepeat = 1;
                        break;
                    }
                }

                printf("%d - %d = %d\n",d,a,c);

                tmp = c;
                chain[chainLen++] = c;

            }

            printf("Chain length %d\n\n",chainLen);
            
            isRepeat = 0;
            chainLen = 0;
            memset(chain,0,sizeof(int32_t) * 1000);

        }
    }while(input != 0);

    return 0;
}