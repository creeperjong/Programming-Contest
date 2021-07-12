#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct number{
    int32_t origin;
    int32_t mod;
} node;

int main(){
    int32_t num = 0;
    int32_t modulo = 0;
    int32_t evenNum = 0;
    int32_t oddNum = 0;
    int32_t evenIdx = 0;
    int32_t oddIdx = 0;
    node tmp;
    node* even = NULL;
    node* odd = NULL;
    node* arr = NULL;

    do{
        scanf("%d %d",&num,&modulo);

        if(num != 0 && modulo != 0){

            printf("%d %d\n",num,modulo);

            arr = (node*)malloc(sizeof(node) * num);

            for(int32_t i = 0;i < num;i++){
                scanf("%d",&arr[i].origin);
                arr[i].mod = arr[i].origin % modulo;
                if(arr[i].origin % 2 == 0) evenNum++;
                else oddNum++;
            }

            even = (node*)malloc(sizeof(node) * evenNum);
            odd = (node*)malloc(sizeof(node) * oddNum);

            for(int32_t i = 0;i < num;i++){
                if(arr[i].origin % 2 == 0) even[evenIdx++] = arr[i];
                else odd[oddIdx++] = arr[i];
            }


            for(int32_t i = 0;i < evenNum;i++){
                for(int32_t j = i + 1;j < evenNum;j++){
                    if(even[i].origin > even[j].origin){
                        tmp = even[i];
                        even[i] = even[j];
                        even[j] = tmp;
                    }
                }
            }

            for(int32_t i = 0;i < oddNum;i++){
                for(int32_t j = i + 1;j < oddNum;j++){
                    if(odd[i].origin < odd[j].origin){
                        tmp = odd[i];
                        odd[i] = odd[j];
                        odd[j] = tmp;
                    }
                }
            }

            // for(int32_t j = 0;j < oddNum;j++){
            //     printf("%d ",odd[j].origin);
            // }
            // printf("\n");
            // for(int32_t j = 0;j < evenNum;j++){
            //     printf("%d ",even[j].origin);
            // }
            // printf("\n");

            evenIdx = 0;

            for(int32_t i = -modulo + 1;i < modulo;i++){
                for(int32_t j = 0;j < oddNum;j++){
                    if(odd[j].mod == i) arr[evenIdx++] = odd[j];
                }
                for(int32_t j = 0;j < evenNum;j++){
                    if(even[j].mod == i) arr[evenIdx++] = even[j];
                }
            }

            for(int32_t i = 0;i < num;i++) printf("%d\n",arr[i].origin);

            evenNum = 0;
            oddNum = 0;
            evenIdx = 0;
            oddIdx = 0;
            
        }else{
            printf("0 0\n");
        }

    }while(num != 0 && modulo != 0);

    return 0;
}