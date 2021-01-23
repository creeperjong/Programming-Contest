#include <stdio.h>
#include <stdint.h>
#include <string.h>

int main(){

    int32_t cases = 0;
    int32_t num = 0;
    int32_t abc[26] = {0};
    int32_t cool = 0;
    int32_t isRepeat = 0;
    int32_t nonZero = 0;
    char c;

    while(scanf("%d",&num) != EOF){
        cases++;
        c = getchar();
        for(int32_t i = 0;i < num;i++){
            c = getchar();
            
            while(c != '\n'){
                abc[c - 'a']++;
                c = getchar();
            }

            // for(int32_t j = 0;j < 26;j++){
            //     printf("%d ",abc[j]);
            // }
            // printf("\n");

            for(int32_t j = 0;j < 26;j++){
                if(abc[j] != 0){
                    nonZero++;
                }
                for(int32_t k = j + 1;k < 26;k++){
                    if(abc[j] == abc[k] && abc[j] != 0){
                        isRepeat = 1;
                    }
                }
            }

            if(!isRepeat && nonZero > 1){
                cool++;
            }

            isRepeat = 0;
            nonZero = 0;

            memset(abc,0,26 * sizeof(int32_t));
        }

        printf("Case %d: %d\n",cases,cool);
        cool = 0;
    }
    return 0;
}