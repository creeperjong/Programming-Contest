#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(){

    int32_t round = 0;
    int32_t count = 0;
    int32_t row = 0;
    int32_t col = 0;
    char** map = NULL;

    do{
        scanf("%d %d",&row,&col);

        if(row != 0 && col != 0){
            map = (char**)malloc(sizeof(char*) * row);
            
            for(int32_t i = 0;i < row;i++){
                map[i] = (char*)malloc(sizeof(char) * col);
            }

            for(int32_t i = 0;i < row;i++){
                scanf("%s",map[i]);
            }

            for(int32_t i = 0;i < row;i++){
                for(int32_t j = 0;j < col;j++){
                    if(map[i][j] == '.'){
                        for(int32_t m = -1;m <= 1;m++){
                            for(int32_t n = -1;n <= 1;n++){
                                if(i + m > row - 1 || i + m < 0 || j + n > col - 1 || j + n < 0){
                                    continue;
                                }else{
                                    if(map[i+m][j+n] == '*'){
                                        count++;
                                    }
                                }
                            }
                        }
                        map[i][j] = count + '0';
                        count = 0;
                    }
                }
            }
            
            if(round != 0) printf("\n");
            printf("Field #%d:\n",++round);
            for(int32_t i = 0;i < row;i++){
                printf("%s\n",map[i]);
            }
        }
        
    }while(row != 0 && col != 0);

    return 0;
}