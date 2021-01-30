#include <stdio.h>
#include <stdint.h>
#include <string.h>

int main(){

    int32_t plate[6][2];
    int32_t isPossible = 1;
    int32_t tmp1 = 0;
    int32_t tmp2 = 0;
    memset(plate,0,sizeof(plate));

    while(scanf("%d %d",&plate[0][0],&plate[0][1]) != EOF){

        if(plate[0][0] < plate[0][1]){
            tmp1 = plate[0][0];
            plate[0][0] = plate[0][1];
            plate[0][1] = tmp1;
        }

       for(int32_t i = 1;i <= 5;i++){
           scanf("%d %d",&plate[i][0],&plate[i][1]);
           if(plate[i][0] < plate[i][1]){
               tmp1 = plate[i][0];
               plate[i][0] = plate[i][1];
               plate[i][1] = tmp1;
           }
       }

        for(int32_t i = 0;i < 5;i++){
            for(int32_t j = i + 1;j < 6;j++){
                if(plate[i][0] < plate[j][0]){
                    tmp1 = plate[i][0];
                    tmp2 = plate[i][1];
                    plate[i][0] = plate[j][0];
                    plate[i][1] = plate[j][1];
                    plate[j][0] = tmp1;
                    plate[j][1] = tmp2;
                }
            }
        }

        for(int32_t i = 0;i < 5;i++){
            for(int32_t j = i + 1;j < 6;j++){
                if(plate[i][1] < plate[j][1] && plate[i][0] == plate[j][0]){
                    tmp1 = plate[i][0];
                    tmp2 = plate[i][1];
                    plate[i][0] = plate[j][0];
                    plate[i][1] = plate[j][1];
                    plate[j][0] = tmp1;
                    plate[j][1] = tmp2;
                }
            }
        }

        // for(int32_t i = 0;i < 6;i++){
        //     for(int32_t j = 0;j < 2;j++){
        //         printf("%d ",plate[i][j]);
        //     }
        //     printf("\n");
        // }

        for(int32_t i = 0;i < 6;i = i + 2){
            if(plate[i][0] != plate[i+1][0]){
                isPossible = 0;
            }else if(plate[i][1] != plate[i+1][1]){
                isPossible = 0;
            }
        }

        if(plate[0][0] != plate[2][0] || plate[0][1] != plate[4][0] || plate[2][1] != plate[4][1]){
            isPossible = 0;
        }

        if(isPossible){
            printf("POSSIBLE\n");
        }else{
            printf("IMPOSSIBLE\n");
        }

        isPossible = 1;
        memset(plate,0,sizeof(plate));
    }

    return 0;
}