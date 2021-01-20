#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int32_t check(int64_t** mat,int64_t** sym,int32_t dim);

int32_t check(int64_t** mat,int64_t** sym,int32_t dim){

    int16_t isSym = 1;
    int32_t isPos = 1;

    for(int32_t i = 0;i < dim;i++){
        for(int32_t j = 0;j < dim;j++){
            if(mat[i][j] != sym[i][j]){
                isSym = 0;
            }
            if(mat[i][j] < 0){
                isPos = 0;
            }
        }
    }

    return isPos && isSym;
    
}

int main(){

    int32_t cases = 0;
    int32_t dim = 0;
    char garbage = 0;
    int64_t** mat = NULL;
    int64_t** sym = NULL;

    scanf("%d",&cases);

    for(int32_t i = 0;i < cases;i++){
        scanf("%c%c%c%c%d",&garbage,&garbage,&garbage,&garbage,&dim);


        mat = (int64_t**)malloc(dim * sizeof(int64_t*));
        for(int32_t j = 0;j < dim;j++){
            mat[j] = (int64_t*)malloc(dim * sizeof(int64_t));
        }

        sym = (int64_t**)malloc(dim * sizeof(int64_t*));
        for(int32_t j = 0;j < dim;j++){
            sym[j] = (int64_t*)malloc(dim * sizeof(int64_t));
        }

        for(int32_t j = 0;j < dim;j++){
            for(int32_t k = 0;k < dim;k++){
                scanf("%ld",&mat[j][k]);
            }
        }

        //spin

        for(int32_t j = 0;j < dim;j++){
            for(int32_t k = 0;k < dim;k++){
                sym[j][k] = mat[dim - 1 - j][dim - 1 - k];
            }
        }

        if(check(mat,sym,dim)){
            printf("Test #%d: Symmetric.\n",i+1);
        }else{
            printf("Test #%d: Non-symmetric.\n",i+1);
        }

        //

        for(int32_t j = 0;j < dim;j++){
            free(mat[j]);
        }
        free(mat);

        for(int32_t j = 0;j < dim;j++){
            free(sym[j]);
        }
        free(sym);
    }

    return 0;
}