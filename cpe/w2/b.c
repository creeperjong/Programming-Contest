#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(){
    int32_t num = 0;
    int32_t* wall = NULL;
    int32_t avg = 0;
    int32_t step = 0;
    int32_t set = 0;

    scanf("%d",&num);

    while(num != 0){

        wall = (int32_t*)malloc(num * sizeof(int32_t));

        for(int32_t i = 0;i < num;i++){
            scanf("%d",&wall[i]);
            avg += wall[i];
        }
        avg /= num;

        for(int32_t i = 0;i < num;i++){
            if(wall[i] > avg){
                step += wall[i] - avg;
            }
        }

        printf("Set #%d\n",set+1);
        printf("The minimum number of moves is %d.\n\n",step);

        free(wall);
        avg = 0;
        step = 0;
        set++;
        scanf("%d",&num);
    }
    return 0;
}