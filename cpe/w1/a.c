#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(){
    int32_t time = 0;
    int32_t a = 0;
    int32_t b = 0;
    int32_t ans = 0;

    scanf("%d",&time);

    for(int32_t i = 0;i < time;i++){
        ans = 0;
        scanf("%d",&a);
        scanf("%d",&b);
        for(int32_t j = a;j <= b;j++){
            if(j % 2 == 1){
                ans += j;
            }
        }
        printf("Case %d: %d\n",i+1,ans);
    }

    return 0;
}