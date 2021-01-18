#include <stdio.h>
#include <stdint.h>

int32_t f(int32_t input);

int32_t f(int32_t input){
    
    int32_t ans = 0;
    
    if(input / 10 == 0){
        return input;
    }else{
        while(input != 0){
            ans += input % 10;
            input /= 10;
        }
        return f(ans);
    }
}

int main(){
    int32_t input = 0;

    scanf("%d",&input);
    
    while(input != 0){
        input = f(input);
        printf("%d\n",input);
        scanf("%d",&input);
    }
    return 0;
}