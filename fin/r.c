#include <stdio.h>
#include <stdint.h>

int main(){

    char c = 0;
    int32_t x = 0;
    int32_t next = 0;
    int32_t ans = 0;
    int32_t tmp = 0;

    while(scanf("%d",&x) != EOF){
        c = getchar();

        do{
            c = getchar();

            if(c != '\n'){
                if(c == '-' || (c >= '0' && c <= '9')){
                    ungetc(c,stdin);
                    scanf("%d",&tmp);
                    ans = ans * x + next;
                    next = next * x + tmp;
                }
            }else{
                printf("%d\n",ans);

                tmp = 0;
                ans = 0;
                next = 0;
            }

        }while(c != '\n');
    }
    return 0;
}