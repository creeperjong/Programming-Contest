#include <stdio.h>
#include <stdint.h>
#include <string.h>

int32_t add_digit(int32_t input);

int32_t add_digit(int32_t input){
    int32_t ans = 0;

    while(input){
        ans += input % 10;
        input /= 10;
    }

    return ans;
}

int main(){

    char n[1000] = "";
    int32_t result = 0;
    int32_t tmp = 0;
    int32_t depth = 1;
    
    do{
        scanf("%s",n);

        if(n[0] != '0' || strlen(n) != 1){
            if(strlen(n) == 1) result = n[0] - '0';
            else{
                for(int32_t i = 0;i < strlen(n);i++) result += n[i] - '0';

                while(result >= 10){
                    tmp = result;
                    result = add_digit(tmp);
                    depth++;
                }
            }

            if(result == 9) printf("%s is a multiple of 9 and has 9-degree %d.\n",n,depth);
            else printf("%s is not a multiple of 9.\n",n);

            depth = 1;
            result = 0;
        }


    }while(n[0] != '0' || strlen(n) != 1);

    return 0;
}