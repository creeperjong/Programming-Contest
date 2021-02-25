#include <stdio.h>
#include <stdint.h>

int main(){
    
    int32_t n = 0;
    int32_t c = 0;
    int32_t middle = 0;
    int32_t index = 1;
    int32_t isPrime = 1;
    int32_t start = 0;
    int32_t end = 0;
    int32_t count = 0;
    int32_t prime[200] = {0};

    prime[0] = 1;

    for(int32_t i = 2;i <= 1000;i++){
        for(int32_t j = 2;j < i;j++){
            if(i % j == 0){
                isPrime = 0;
            }
        }
        if(isPrime){
            prime[index++] = i;
        }
        isPrime = 1;
    }

    while(scanf("%d %d",&n,&c) != EOF){
        while(prime[count] <= n && prime[count] != 0){
            count++;
        }

        if(count % 2 == 0){ //even
            middle = c * 2;
        }else{  //odd
            middle = c * 2 - 1;
        }

        printf("%d %d:",n,c);

        if(middle >= count){
            for(int32_t i = 0;i < count;i++){
                printf(" %d",prime[i]);
            }
            printf("\n\n");
        }else{
            start = (count - middle) / 2;
            end = start + middle;

            for(int32_t i = start;i < end;i++){
                printf(" %d",prime[i]);
            }
            printf("\n\n");
        }

        count = 0;
    }

    // for(int32_t i = 0;i < index;i++){
    //     printf("%d ",prime[i]);
    // }
    // printf("\n");


    return 0;
}