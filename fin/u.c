#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

int32_t record[4] = {0};

int32_t cmp(int32_t idx);

int32_t cmp(int32_t idx){
    return  ((record[idx] >= record[0]) && (record[idx] >= record[1]) && (record[idx] >= record[2]) && (record[idx] >= record[3]));
}

int main(){

    int32_t cases = 0;
    int32_t row = 0;
    int32_t col = 0;
    int32_t ans = 0;
    char** DNA = NULL;

    scanf("%d",&cases);

    while(cases--){
        scanf("%d %d",&row,&col);

        DNA = (char**)malloc(sizeof(char*) * row);
        for(int32_t i = 0;i < row;i++){
            DNA[i] = (char*)malloc(sizeof(char) * (col + 1));
            
        }

        for(int32_t i = 0;i < row;i++) scanf("%s",DNA[i]);

        for(int32_t i = 0;i < col;i++){
            for(int32_t j = 0;j < row;j++){
                if(DNA[j][i] == 'A') record[0]++;
                else if (DNA[j][i] == 'C') record[1]++;
                else if (DNA[j][i] == 'G') record[2]++;
                else if (DNA[j][i] == 'T') record[3]++;
            }

            // printf("%d %d %d %d\n",record[0],record[1],record[2],record[3]);

            if(cmp(0)){
                printf("A");
                ans += record[0];
            }else if(cmp(1)){
                printf("C");
                ans += record[1];
            }else if(cmp(2)){
                printf("G");
                ans += record[2];
            }else if(cmp(3)){
                printf("T");
                ans += record[3];
            }

            memset(record,0,sizeof(record));
        }

        printf("\n%d\n",row * col - ans);
        ans = 0;

        for(int32_t i = 0;i < row;i++) free(DNA[i]);
        free(DNA);
    }

    return 0;
}