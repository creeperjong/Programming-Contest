#include <stdio.h>
#include <stdint.h>
#include <math.h>

int main(){

    int64_t n = 0;
    int64_t m = 0;
    int64_t tmp = 0;
    int32_t isBoring = 0;

    while(scanf("%ld %ld",&n,&m) != EOF){
        tmp = n;

        if(m == 0 || n == 1 || m > n){
            printf("Boring!\n");
        }else{ 
            while(tmp != 1){
                if(tmp % m != 0){
                    isBoring = 1;
                    break;
                }
                tmp /= m;
            }
            
            if(isBoring){
                printf("Boring!\n");
            }else{
                while(n != 1){
                    printf("%ld ",n);
                    n /= m;
                }
                printf("1\n");
            }
        }
        isBoring = 0;
    }

    return 0;
}