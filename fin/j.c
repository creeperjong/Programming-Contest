#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(){

    int32_t ascii[128] = {0};
    int32_t count = 0;
    int32_t fre_idx = 0;
    int32_t isFirst = 1;
    char c = 0;
    int32_t** fre = NULL;
    int32_t* tmp = NULL;

    do{
        c = getchar();

        if(c != EOF){
            if(c != '\n'){
                if(ascii[c] == 0) count++;
                ascii[c]++;
            }else{
                fre = (int32_t**)malloc(sizeof(int32_t*) * count);
                for(int32_t i = 0;i < count;i++){
                    fre[i] = (int32_t*)malloc(sizeof(int32_t) * 2);
                }

                for(int32_t i = 32;i < 128;i++){
                    if(ascii[i] != 0){
                        fre[fre_idx][0] = i;
                        fre[fre_idx][1] = ascii[i];

                        fre_idx++;
                    }
                }

                if(!isFirst) printf("\n");

                for(int32_t i = 0;i < count;i++){
                    for(int32_t j = i + 1;j < count;j++){
                        if(fre[i][1] > fre[j][1]){
                            tmp = fre[i];
                            fre[i] = fre[j];
                            fre[j] = tmp;
                        }else if(fre[i][1] == fre[j][1]){
                            if(fre[i][0] < fre[j][0]){
                                tmp = fre[i];
                                fre[i] = fre[j];
                                fre[j] = tmp;
                            }
                        }
                    }
                    printf("%d %d\n",fre[i][0],fre[i][1]);
                }

                count = 0;
                fre_idx = 0;
                isFirst = 0;

                for(int32_t i = 0;i < 128;i++) ascii[i] = 0;
            }
        }

        
    }while(c != EOF);

    return 0;
}