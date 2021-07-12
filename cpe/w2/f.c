#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(){

    int32_t cases = 0;
    int32_t storeNum = 0;
    int32_t min = 100;
    int32_t max = 0;
    int32_t dis = 0;
    int32_t ans = 2147483647;
    int32_t* store = NULL;

    scanf("%d",&cases);

    for(int32_t i = 0;i < cases;i++){
        scanf("%d",&storeNum);

        store = (int32_t*)malloc(storeNum * sizeof(int32_t));

        for(int32_t j = 0;j < storeNum;j++){
            scanf("%d",&store[j]);
        }

        for(int32_t j = 0;j < storeNum;j++){
            if(store[j] > max){
                max = store[j];
            }
            if(store[j] < min){
                min = store[j];
            }
        }

        //printf("%d %d\n",max,min);

        for(int32_t j = 0;j < storeNum;j++){
            dis = (store[j] - min) * 2 + (max - store[j]) * 2;
            if(dis < ans){
                ans = dis;
            }
        }

        printf("%d\n",ans);
        
        max = 0;
        min = 100;
        ans = 2147483647;
        free(store);
    }
    return 0;
}