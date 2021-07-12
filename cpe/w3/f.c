#include <stdio.h>
#include <stdint.h>

int main(){

    int64_t input = 0;
    int64_t last = 0;
    int64_t ans = 0;

    while(scanf("%ld",&input) != EOF){
        last = (1 + input) * ((input - 1) / 2 + 1) / 2 * 2 - 1;
        ans = last * 3 - 6;
        printf("%ld\n",ans);
    }

    return 0;
}