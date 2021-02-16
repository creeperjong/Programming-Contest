#include <stdio.h>
#include <stdint.h>

int64_t reverse(int64_t input);

int64_t reverse(int64_t input){
    
    int64_t ans = 0;
    
    while(input != 0){
        ans = ans * 10 + input % 10;
        input /= 10;
    }

    return ans;
}

int main(){

    int32_t cases = 0;
    int64_t input = 0;
    int32_t times = 0;

    scanf("%d",&cases);

    for(int32_t i = 0;i < cases;i++){
        scanf("%ld",&input);

        do{
            input += reverse(input);
            times++;
        }while(input != reverse(input));

        printf("%d %ld\n",times,input);
        times = 0;
    }

    return 0;
}