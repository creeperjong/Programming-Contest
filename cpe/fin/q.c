#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

int main(){

    char input[8] = "";
    char output[7] = "";
    int32_t origin_base = 0;
    int32_t expo = 0;
    int32_t tenBase = 0;
    int32_t convert_base = 0;

    while(scanf("%s %d %d",input,&origin_base,&convert_base) != EOF){
        for(int32_t i = strlen(input) - 1;i >= 0;i--){
            
            if(input[i] >= 'A' && input[i] <= 'F') tenBase += (input[i] - 'A' + 10) * pow(origin_base,expo++);
            else tenBase += (input[i] - '0') * pow(origin_base,expo++);

        }

        for(int32_t i = 0;i < 7 && tenBase != 0;i++){
            output[i] = tenBase % convert_base + '0';
            if(output[i] > '9') output[i] = output[i] - '9' - 1 + 'A';
            tenBase /= convert_base;
        }

        if(tenBase != 0) printf("  ERROR\n");
        else{
            for(int32_t i = 6;i >= 0;i--){
                if(strlen(output) == 0){
                    printf("%7d",0);
                    break;
                }
                else if(output[i] == 0 && i >= strlen(output)) printf(" ");
                else printf("%c",output[i]);
            }
            printf("\n");
        }

        expo = 0;
        tenBase = 0;
        memset(output,0,sizeof(output));
    }

    return 0;
}