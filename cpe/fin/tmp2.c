#include <stdio.h>
#include <stdint.h>

int main(){

    char c = 0;
    int32_t x = 0;
    int32_t next = 0;
    int32_t ans = 0;
    int32_t tmp = 0;
    int32_t isNegative = 0;

    while(scanf("%d",&x) != EOF){
        c = getchar();

        do{
            c= getchar();

            if(c != EOF){
                if(c != '\n'){
                    if(c == ' '){
                        ans = ans * x + next;
                        next = next * x + tmp;
                        isNegative = 0;
                    }else{
                        if(c == '-'){
                            isNegative = 1;
                        }else{
                            if(isNegative) tmp = tmp * 10 - c + '0';
                            else tmp = tmp * 10 + c - '0';
                        }
                    }
                }else{
                    printf("%d\n",ans);

                    isNegative = 0;
                    tmp = 0;
                    ans = 0;
                    next = 0;
                }
            }

        }while(c != EOF);
    }
    return 0;
}