#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(){

    int32_t n = 0;
    int32_t m = 0;
    int32_t close = 0;
    int32_t times = 0;
    int32_t* nArr = NULL;
    int32_t* mArr = NULL;
    int32_t* ans = NULL;

    do{
        scanf("%d",&n);

        if(n != 0){
            nArr = (int32_t*)malloc(sizeof(int32_t) * n);
            for(int32_t i = 0;i < n;i++){
                scanf("%d",&nArr[i]);
            }
        
            scanf("%d",&m);
            
            if(m != 0){
                mArr = (int32_t*)malloc(sizeof(int32_t) * m);
                ans = (int32_t*)malloc(sizeof(int32_t) * m);
                for(int32_t i = 0;i < m;i++){
                    scanf("%d",&mArr[i]);
                    for(int32_t j = 0;j < n;j++){
                        for(int32_t k = j + 1;k < n;k++){
                            if(j == 0 && k == j + 1){
                                close = nArr[j] + nArr[k];
                                continue;
                            }
                            if(abs(nArr[j] + nArr[k] - mArr[i]) < abs(close - mArr[i])){
                                close = nArr[j] + nArr[k];
                            }
                        }
                    }
                    ans[i] = close;
                    close = 0;
                }

                printf("Case %d:\n",++times);

                for(int32_t i = 0;i < m;i++){
                    printf("Closest sum to %d is %d.\n",mArr[i],ans[i]);
                }
            }
        }
        
    }while(n != 0);

    return 0;
}