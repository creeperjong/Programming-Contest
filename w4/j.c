#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(){

    int32_t n = 0;
    int32_t absolute = 0;
    int32_t notJolly = 0;
    int32_t* check = NULL;
    int32_t* sequence = NULL;

    while(scanf("%d",&n) != EOF){
    
        
        sequence = (int32_t*)malloc(sizeof(int32_t) * n);
        check = (int32_t*)malloc(sizeof(int32_t) * n);
        for(int32_t i = 0;i < n;i++){
            scanf("%d",&sequence[i]);
            check[i] = 0;
        }

        for(int32_t i = 1;i < n;i++){
            absolute = abs(sequence[i-1] - sequence[i]); 
            if(absolute < 1 || absolute > n - 1){
                notJolly = 1;
                break;
            }else{
                check[absolute] = 1;
            }
        }

        for(int32_t i = 1;i < n;i++){
            if(check[i] == 0){
                notJolly = 1;
            }
        }

        if(notJolly) printf("Not jolly\n");
        else printf("Jolly\n");

        free(sequence);
        free(check);
        notJolly = 0;
        
    }

    return 0;
}