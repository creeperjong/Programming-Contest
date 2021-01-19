#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


int main(){
    int32_t a = 0;
    int32_t b = 0;
    int32_t* cardA = NULL;
    int32_t* cardB = NULL;
    int32_t ab = 0;
    int32_t ba = 0;

    scanf("%d %d",&a,&b);

    while(a != 0 || b != 0){

        if(a == 0 || b == 0){
            printf("0\n");
            scanf("%d %d",&a,&b);
            continue;
        }

        cardA = (int32_t*)malloc(a * sizeof(int32_t));
        cardB = (int32_t*)malloc(b * sizeof(int32_t));

        for(int32_t i = 0;i < a;i++){
            scanf("%d",&cardA[i]);
        }
        for(int32_t i = 0;i < b;i++){
            scanf("%d",&cardB[i]);
        }

        for(int32_t i = 0;i < a;i++){
            if(cardA[i] == cardA[i-1]){
                continue;
            }
            for(int32_t j = 0;j < b;j++){
                if(cardA[i] == cardB[j]){
                    break;
                }
                if(j == b-1){
                    ab++;
                }
            }
        }

        for(int32_t i = 0;i < b;i++){
            if(cardB[i] == cardB[i-1]){
                continue;
            }
            for(int32_t j = 0;j < a;j++){
                if(cardB[i] == cardA[j]){
                    break;
                }
                if(j == a-1){
                    ba++;
                }
            }
        }

        if(ab > ba){
            printf("%d\n",ba);
        }else{
            printf("%d\n",ab);
        }
        ab = 0;
        ba = 0;
        free(cardA);
        free(cardB);
        scanf("%d %d",&a,&b);
    }
    return 0;
}