#include <stdio.h>
#include <stdint.h>
#include <math.h>

int main(){

    int32_t input = 0;
    int32_t tmp = 0;
    int32_t rev = 0;
    int32_t digit = 0;
    int32_t isPrime = 1;
    int32_t isEmp = 1;

    while(scanf("%d",&input) != EOF){

        tmp = input;

        while(tmp != 0){
            tmp /= 10;
            digit++;
        }

        tmp = input;

        for(int32_t i = 0;i < digit;i++){
            rev += (tmp % 10) * pow(10,digit - 1 - i);
            tmp /= 10;
        }
        for(int32_t i = 2;i <= sqrt(input);i++){
            if(input % i == 0){
                isPrime = 0;
            }
        }
        for(int32_t i = 2;i <= sqrt(rev);i++){
            if(rev % i == 0){
                isEmp = 0;
            }
        }
        
        printf("%d ",input);
        
        if(!isPrime){
            printf("is not prime.\n");
        }else{
            if(isEmp && input != rev){
                printf("is emirp.\n");
            }else{
                printf("is prime.\n");
            }
        }

        rev = 0;
        isPrime = 1;
        isEmp = 1;
        digit = 0;
    }
    return 0;
}