#include <stdio.h>
#include <stdint.h>

int32_t GCD(int32_t i,int32_t j);

int32_t GCD(int32_t i,int32_t j){
    while(j != 0 && i != 0){
        j = j % i;
        if(j != 0){
            i = i % j;
        }
    }
    return i+j;
}

int main(){

    int32_t n = 0;
    int32_t G = 0;

    scanf("%d",&n);

    while(n != 0){
        G = 0;
        for(int32_t i = 1;i < n;i++){
            for(int32_t j = i + 1;j <= n;j++){
                G += GCD(i,j);
            }
        }
        printf("%d\n",G);

        scanf("%d",&n);
    }

    return 0;
}