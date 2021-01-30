#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(){

    int32_t wentNum = 0;
    int32_t returnNum = 0;
    int32_t* survivor = NULL;
    int32_t* check = NULL;

    while(scanf("%d %d",&wentNum,&returnNum) != EOF){
        survivor = (int32_t*)malloc(returnNum * sizeof(int32_t));
        check = (int32_t*)calloc(wentNum,sizeof(int32_t));

        for(int32_t i = 0;i < returnNum;i++){
            scanf("%d",&survivor[i]);
            check[survivor[i] - 1] = 1;
        }

        if(wentNum == returnNum){
            printf("*");
        }

        for(int32_t i = 0;i < wentNum;i++){
            if(check[i] == 0){
                printf("%d ",i+1);
            }
        }

        printf("\n");

        free(survivor);
        free(check);
    }

    return 0;
}