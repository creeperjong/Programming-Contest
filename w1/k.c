#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

int32_t fibo(int32_t n);

int32_t fibo(int32_t n){
    double a = 0;
    double b = 0;
    a = (1+sqrt(5))/2;
    b = (1-sqrt(5))/2;

    return (sqrt(5) / 5) * (pow(a,n)-pow(b,n));
}

int main(){

    int32_t num = 0;
    int32_t dec = 0;
    char ans[40] = "";
    int32_t tmp = 0;
    int32_t isStart = 0;

    scanf("%d",&num);

    for(int32_t i = 0;i < num;i++){
        scanf("%d",&dec);
        tmp = dec;

        for(int32_t j = 40;j > 1;j--){
            if(dec >= fibo(j)){
                dec -= fibo(j);
                ans[j-2] = '1';
                isStart = 1;
            }else if(isStart){
                ans[j-2] = '0';
            }
        }
        printf("%d = ",tmp);
        for(int32_t j = 39;j >= 0;j--){
            if(ans[j] != '\0'){
                printf("%c",ans[j]);
            }
        }
        printf(" (fib)\n");

        memset(ans,'\0',40);
        isStart = 0;
    }

    return 0;
}