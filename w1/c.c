#include <stdio.h>
#include <stdint.h>

int main(){
    int32_t v = 0;
    int32_t t = 0;

    while(scanf("%d %d",&v,&t) != EOF){
        printf("%d\n",v * t * 2);
    }

    return 0;
}