#include <stdio.h>
#include <stdint.h>

int main(){

    int32_t cases = 0;
    int32_t init = 0;
    int32_t found = 0;
    int32_t need = 0;
    int32_t drink = 0;
    int32_t buf = 0;

    scanf("%d",&cases);

    for(int32_t i = 0;i < cases;i++){
        scanf("%d %d %d",&init,&found,&need);

        buf = init + found;

        while(buf >= need){
            drink += buf / need;
            buf = buf % need + buf / need;
        }

        printf("%d\n",drink);

        drink = 0;
    }

    return 0;
}