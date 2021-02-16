#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct amarble{
    int32_t val;
    int32_t index;
} num;

int main(){

    int32_t cases = 0;
    int32_t marble = 0;
    int32_t find = 0;
    int32_t searching = 0;
    int32_t left = 0;
    int32_t right = 0;
    int32_t mid = 0;
    int32_t isFailed = -1;
    num tmp;
    num* all = NULL;
    num* ans = NULL;

    do{
        scanf("%d %d",&marble,&find);

        if(marble != 0 && find != 0){
            all = (num*)malloc(sizeof(num) * marble);
            ans = (num*)malloc(sizeof(num) * find);

            for(int32_t i = 0;i < marble;i++){
                scanf("%d",&all[i].val);
            }

            for(int32_t i = 0;i < marble;i++){
                for(int32_t j = i;j < marble;j++){
                    if(all[i].val > all[j].val){
                        tmp = all[i];
                        all[i] = all[j];
                        all[j] = tmp;
                    }
                }
                all[i].index = i;
            }

            for(int32_t i = 0;i < find;i++){
                scanf("%d",&searching);
                left = 0;
                right = marble - 1;
                do{
                    mid = (left + right) / 2;

                    if(searching < all[mid].val){
                        right = mid - 1;
                    }else if(searching > all[mid].val){
                        left = mid + 1;
                    }else{
                        break;
                    }

                    if(right < left){
                        isFailed = searching;
                        break;
                    }
                }while(searching != all[mid].val);

                if(isFailed == -1){
                    ans[i].val = all[mid].val;
                    for(int32_t j = 0;j <= mid;j++){
                        if(all[j].val == all[mid].val){
                            ans[i].index = all[j].index;
                            break;
                        }
                    }
                }else{
                    ans[i].val = isFailed;
                    ans[i].index = -1;
                }
                isFailed = -1;
            }
            printf("CASE# %d:\n",++cases);
            for(int32_t i = 0;i < find;i++){
                if(ans[i].index == -1){
                    printf("%d not found\n",ans[i].val);
                }else{
                    printf("%d found at %d\n",ans[i].val,ans[i].index+1);
                }
            }

            // for(int32_t i = 0;i < marble;i++){
            //     printf("%d ",all[i].val);
            // }
            // printf("\n");

            // for(int32_t i = 0;i < marble;i++){
            //     printf("%d ",all[i].index);
            // }
            // printf("\n");

            free(all);
            free(ans);
        }


    }while(marble != 0 && find != 0);

    return 0;
}