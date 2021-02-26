#include <stdio.h>
#include <stdint.h>
#include <string.h>

int main(){

    int32_t cases = 0;
    int32_t base = 0;
    int32_t len = 0;
    char input[80] = "";

    scanf("%d",&cases);

    while(cases--){
        scanf("%s",input);

        for(int32_t i = 1;i <= strlen(input);i++){
            if(strlen(input) % i == 0){
                //printf("%d\n",i);
                for(int32_t j = 0;j < strlen(input);j++){
                    //printf("%d %d\n",base,j);
                    if(input[base] == input[j]){
                        base++;
                        //printf("base++\n");
                    }else{
                        base = 0;
                        break;
                    }

                    if(base == i){
                        base = 0;
                        //printf("hi\n");
                    }

                    if(j == strlen(input) - 1){
                        len = i;
                    }
                }
                if(len != 0) break;
            }
        }

        printf("%d\n",len);

        if(cases) printf("\n");

        len = 0;
        base = 0;
    }
    
    return 0;
}