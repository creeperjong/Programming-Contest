#include <stdio.h>
#include <stdint.h>
#include <math.h>

int main(){

    int32_t num = 0;
    int32_t time = 0;

    for(int32_t i = 0;i < 2000;i++){
        scanf("%d",&num);
        if(num < 0){
            break;
        }else{
            if(log2(num) == (int32_t)log2(num)){
                time = log2(num);
            }else{
                time = (int32_t)log2(num) + 1;
            }
            printf("Case %d: %d\n",i+1,time);
        }
    }
    return 0;
}