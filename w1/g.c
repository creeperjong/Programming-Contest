#include <stdio.h>
#include <stdint.h>

int main(){
    int32_t time = 0;
    int32_t amp = 0;
    int32_t fre = 0;
    
    scanf("%d",&time);

    for(int32_t i = 0;i < time;i++){
        scanf("%d",&amp);
        scanf("%d",&fre);

        for(int32_t j = 0;j < fre;j++){
            for(int32_t k = 1;k <= amp;k++){
                for(int32_t m = 0;m < k;m++){
                    printf("%d",k);
                }
                printf("\n");
            }
            for(int32_t k = amp-1;k > 0;k--){
                for(int32_t m = 0;m < k;m++){
                    printf("%d",k);
                }
                printf("\n");
            }
            if(j != fre - 1 || i != time - 1){
                printf("\n");
            }
        }
        
    }
    return 0;
}