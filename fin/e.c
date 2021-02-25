#include <stdio.h>
#include <stdint.h>

int main(){

    int32_t l = 0;
    int32_t r = 0;
    int32_t h = 0;
    int32_t isFirst = 1;
    int32_t line[20000] = {0};

    while(scanf("%d %d %d",&l,&h,&r) != EOF){
        for(int32_t i = l * 2;i <= r * 2;i++){
            if(h > line[i]) line[i] = h;
        }
    }

    for(int32_t i = 0;i < 20000;i++){
        if(i != 0){
            if(line[i] == line[i-1]){
                continue;
            }else if(line[i] > line[i-1]){
                if(!isFirst) printf(" ");
                printf("%d %d",i/2,line[i]);
                isFirst = 0;
            }else{
                if(!isFirst) printf(" ");
                printf("%d %d",(i-1)/2,line[i]);
                isFirst = 0;
            }
        }
    }
    printf("\n");

    // for(int32_t i = 0;i < 60;i++){
    //     printf("%2d ",line[i]);
    // }
    // printf("\n");
    // for(int32_t i = 0;i < 60;i++){
    //     printf("%2d ",i);
    // }
    // printf("\n");

    return 0;
}