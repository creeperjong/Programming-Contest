#include <stdio.h>
#include <stdint.h>

int main(){
    int32_t line = 0;
    int32_t arr[10] = {0};
    int32_t isAscendOrdered = 1;
    int32_t isDescendOrdered = 1;

    scanf("%d",&line);
    printf("Lumberjacks:\n");

    for(int32_t i = 0;i < line;i++){
        isAscendOrdered = 1;
        isDescendOrdered = 1;
        for(int32_t j = 0;j < 10;j++){
            scanf("%d",&arr[j]);
        }
        for(int32_t j = 0;j < 9;j++){
            if(arr[j] > arr[j+1]){
                isAscendOrdered = 0;
            }
        }
        for(int32_t j = 0;j < 9;j++){
            if(arr[j] < arr[j+1]){
                isDescendOrdered = 0;
            }
        }
        if(isDescendOrdered || isAscendOrdered){
            printf("Ordered\n");
        }else{
            printf("Unordered\n");
        }
        
    }
    return 0;
}