#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(){

    int64_t ans = 0;
    int64_t need = 0;
    int64_t now = 0;
    int32_t people = 0;

    do{
        scanf("%d",&people);

        if(people != 0){
            for(int32_t  i = 0 ;i < people;i++){
                scanf("%ld",&now);
                ans += abs(need);
                need += now;
                //printf("%ld %ld %ld\n",ans,need,now);
            }

            printf("%ld\n",ans);
            ans = 0;
            need = 0;
        }
            
    }while(people != 0);

    return 0;
}
