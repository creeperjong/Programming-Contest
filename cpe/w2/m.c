#include <stdio.h>
#include <stdint.h>

int main(){
    int32_t cases = 0;
    int64_t n = 0;
    int64_t m = 0;

    scanf("%d",&cases);

    for(int32_t i = 0;i < cases;i++){

        scanf("%ld %ld",&n,&m);

        printf("%ld\n",(m-1+m-n) * n / 2);
    }
    return 0;
}