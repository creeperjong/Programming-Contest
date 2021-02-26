#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char** avail = NULL;
    int32_t* avail_d = NULL;
    int32_t state = 0;
    char subject[20] = "";
    int32_t cases = 0;
    int32_t time = 0;
    int32_t n = 0;
    int32_t d = 0;

    scanf("%d",&cases);

    while(cases--){
        scanf("%d",&n);

        avail = (char**)malloc(sizeof(char*) * n);
        avail_d = (int32_t*)malloc(sizeof(int32_t) * n);
        for(int32_t i = 0;i < n;i++){
            avail[i] = (char*)malloc(sizeof(char) * 20);
        }

        for(int32_t i = 0;i < n;i++){
            scanf("%s %d",avail[i],&avail_d[i]);
        }

        scanf("%d %s",&d,subject);

        for(int32_t i = 0;i < n;i++){
            if(strncmp(avail[i],subject,20) == 0){
                if(avail_d[i] <= d){
                    state = 1;
                }else if(avail_d[i] <= d + 5){
                    state = 2;
                }else{
                    state = 3;
                }
                break;
            }else{
                if(i == n - 1) state = 3;
            }
        }

        printf("Case %d: ",++time);

        if(state == 1){
            printf("Yesss\n");
        }else if(state == 2){
            printf("Late\n");
        }else{
            printf("Do your own homework!\n");
        }


    }

    return 0;
}