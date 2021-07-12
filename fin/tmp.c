#include <stdio.h>
#include <stdint.h>
#include <string.h>

int64_t myPower(int64_t x,int64_t expo);

int64_t myPower(int64_t x,int64_t expo){
    int64_t ans = 1;

    for(int32_t i = 0;i < expo;i++){
        ans *= x;
    }

    if(x == 0 && expo == 0) return 0;
    else return ans;
}


int main(){

    int64_t x = 0;
    int64_t count = 0;
    int64_t ans = 0;
    int64_t coef = 0;
    int64_t len = 0;
    int64_t isNum = 0;
    char poly[200] = "";
    char gbg = 0;

    while(scanf("%ld",&x) != EOF){
        gbg = getchar();
        fgets(poly,200,stdin);
        len = strlen(poly);
        poly[len - 1] = ' ';
        
        // for(int32_t i = 0;i < len;i++) printf("%d ",poly[i]);
        // printf("\n");

        for(int32_t i = 0;i < len;i++){
            //printf("loop %d:\n",i);
            if(poly[i] == ' ') count++;
            else{
                if(poly[i] >= '0' && poly[i] <= '9'){
                    poly[i] -= '0';
                }else if(poly[i] == '-'){
                    poly[i + 1] = 0 - (poly[i + 1] - '0');
                    poly[i] = ' ';
                }
            }
        }

        count--;

        // for(int32_t i = 0;i < len;i++) printf("%d ",poly[i]);
        // printf("\n");


        for(int32_t i = 0;i < len;i++){
            //printf("%d:\n",poly[i]);
            if(poly[i] != ' '){
                // printf("Upper\n");
                if(coef < 0) coef = coef * 10 - poly[i];
                else coef = coef * 10 + poly[i];
                isNum = 1;
                // printf("coef: %ld\n",coef);
            }else{
                // printf("Lower\n");
                if(count != 0 && isNum == 1) ans += coef * count * myPower(x,--count);
                coef = 0;
                isNum = 0;
                // printf("ans: %ld\n",ans);
            }
        }
        
        printf("%ld\n",ans);

        count = 0;
        ans = 0;
        coef = 0;
        isNum = 0;
        memset(poly,0,sizeof(poly));
    }

    return 0;
}