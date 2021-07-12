#include <stdio.h>
#include <stdint.h>
#include <string.h>

int main(){

    int32_t cases = 0;
    int32_t input = 0;
    int32_t tmp = 0;
    int32_t sum = 0;
    int32_t ans[100001];

    scanf("%d",&cases);
    memset(ans,0,sizeof(ans));

    for(int32_t i = 1;i <= 100001;i++){
        sum = i;
        tmp = i;
        while(tmp != 0){
            sum += tmp % 10;
            tmp /= 10;
        }
        if(sum < 100001){
            if(ans[sum] == 0 || ans[sum] > i){
                ans[sum] = i;
            }
        }
    }

    for(int32_t i = 0;i < cases;i++){
        
        scanf("%d",&input);

        printf("%d\n",ans[input]);
    }

    return 0;
}