#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(){

    int32_t cases = 0;
    int32_t d = 0;
    int32_t q = 0;
    int32_t isExist = 0;
    int32_t** db = NULL;
    int32_t* query = NULL;
    char** name = NULL;
    char** ans = NULL;
    char* under = "UNDETERMINED";

    scanf("%d",&cases);

    for(int32_t i = 0;i < cases;i++){
        scanf("%d",&d);

        name = (char**)malloc(sizeof(char*) * d);
        db = (int32_t**)malloc(sizeof(int32_t*) * d);
        for(int32_t j = 0;j < d;j++){
            db[j] = (int32_t*)malloc(sizeof(int32_t) * 2);
            name[j] = (char*)malloc(sizeof(char) * 20);
        }

        for(int32_t j = 0;j < d;j++){
            scanf("%s",name[j]);
            scanf("%d %d",&db[j][0],&db[j][1]);
        }

        scanf("%d",&q);

        ans = (char**)malloc(sizeof(char*) * q);
        query = (int32_t*)malloc(sizeof(int32_t) * q);

        for(int32_t j = 0;j < q;j++){
            scanf("%d",&query[j]);
            for(int32_t k = 0;k < d;k++){
                if(query[j] >= db[k][0] && query[j] <= db[k][1]){
                    if(isExist){
                        ans[j] = under;
                        break;
                    }
                    ans[j] = name[k];
                    isExist = 1;
                }else{
                    if(k == d-1 && !isExist){
                        ans[j] = under;
                    }
                }
            }
            isExist = 0;
        }

        for(int32_t j = 0;j < q;j++){
            printf("%s\n",ans[j]);
        }

        if(i != cases - 1){
            printf("\n");
        }

    }

    return 0;
}