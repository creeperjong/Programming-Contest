#include <stdio.h>
#include <stdint.h>

int main(){
    int32_t v = 0;
    int32_t t = 0;

    while(1){
        scanf("%d %d",&v,&t);
        printf("%d\n",v * t * 2);
    }

    return 0;
}