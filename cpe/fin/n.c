#include <stdio.h>
#include <stdint.h>

int main(){

    int32_t guess = 0;
    int32_t impossible[11] = {0};
    char response[10] = "";

    do{
        scanf("%d",&guess);

        if(guess != 0){
            scanf("%s %s",response,response);

            if(response[0] == 'h'){
                for(int32_t i = guess;i < 11;i++) impossible[i] = 1;
            }else if(response[0] == 'l'){
                for(int32_t i = 0;i <= guess;i++) impossible[i] = 1;
            }else{
                if(impossible[guess] == 0) printf("Stan may be honest\n");
                else printf("Stan is dishonest\n");

                for(int32_t i = 0;i < 11;i++) impossible[i] = 0;
            }
        }

    }while(guess != 0);

    return 0;
}