#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(){

    int32_t cases = 0;
    int32_t n = 0;
    int32_t p = 0;
    int32_t count = 0;
    int32_t* day = NULL;
    int32_t* list = NULL;

    scanf("%d",&cases);

    for(int32_t i = 0;i < cases;i++){
        scanf("%d %d",&n,&p);
        list = (int32_t*)malloc(sizeof(int32_t) * (n+1));
        for(int32_t j = 0;j < n+1;j++){
            list[j] = 0;
        }
        day = (int32_t*)malloc(sizeof(int32_t) * p);
        for(int32_t j = 0;j < p;j++){
            scanf("%d",&day[j]);
        }

        for(int32_t j = 1;j <= n;j++){
            for(int32_t k = 0;k < p;k++){
                if(j % day[k] == 0 && list[j] != 1){
                    list[j] = 1;
                }
            }

            if(j % 7 == 0 || j % 7 == 6){
                list[j] = 0;
            }
            if(list[j] == 1){
                count++;
            }
        }

        printf("%d\n",count);
        count = 0;
        free(list);
        free(day);
    }

    return 0;
}