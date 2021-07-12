#include <stdio.h>
#include <stdint.h>
#include <string.h>

int main(){
    char c = 0;
    char sentence[100][100];
    int32_t row = 0;
    int32_t col = 0;
    int32_t maxRow = 0;
    int32_t maxCol = 0;

    memset(sentence,0,sizeof(sentence));

    do{
        c = getchar();

        if(c != EOF){
            if(c == '\n'){
                row++;
                col = 0;
            }else{
                sentence[row][col] = c;
                col++;
                if(row > maxRow) maxRow = row;
                if(col > maxCol) maxCol = col;
            }
        }
    }while(c != EOF);

    for(int32_t i = 0;i < maxCol;i++){
        for(int32_t j = maxRow;j >= 0;j--){
            if(sentence[j][i] != 0){
                printf("%c",sentence[j][i]);
            }else{
                printf(" ");
            }
            if(j == 0) printf("\n");
        }
    }

    // for(int32_t i = 0;i < 100;i++){
    //     for(int32_t j = 0;j < 100;j++){
    //         printf("%c",sentence[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("\n");

    return 0;
}