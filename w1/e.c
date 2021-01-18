#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(){

    int32_t cases = 0;
    int32_t num = 0;
    int32_t* wall = NULL;
    int32_t high = 0;
    int32_t low = 0;

    scanf("%d",&cases);

    for(int32_t i = 0;i < cases;i++){
        low = 0;
        high = 0;
        scanf("%d",&num);
        wall = (int32_t*)malloc(num * sizeof(int32_t));
        for(int32_t j = 0;j < num;j++){
            scanf("%d",&wall[j]);
        }
        for(int32_t j = 0;j < num - 1;j++){
            if(wall[j] > wall[j+1]){
                low++;
            }else if(wall[j] < wall[j+1]){
                high++;
            }
        }
        printf("Case %d: %d %d\n",i+1,high,low);
        free(wall);
    }

    return 0;
}