#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void dfs(int64_t layer,int64_t s,int64_t n,int64_t* arr,int64_t* visited,int64_t* arragement);

void dfs(int64_t layer,int64_t s,int64_t n,int64_t* arr,int64_t* visited,int64_t* arragement){
    if(layer == 6){
        for(int64_t i = 0;i < 5;i++) printf("%ld ",arragement[i]);
        printf("%ld\n",arragement[5]);
    }else{
        for(int64_t i = s;i < n;i++){
            if(visited[i]) continue;
            else{
                visited[i] = 1;
                arragement[layer] = arr[i];
                dfs(layer + 1,i+1,n,arr,visited,arragement);
                visited[i] = 0; 
            }
        }
    }
}

int main(){

    int64_t n = 0;
    int64_t isFirst = 0;

    do{
        int64_t* arr = NULL;
        int64_t* visited = NULL;
        int64_t arragement[6] = {0};

        scanf("%ld",&n);

        if(n != 0){
            arr = (int64_t*)malloc(sizeof(int64_t) * n);
            visited = (int64_t*)malloc(sizeof(int64_t) * n);

            for(int64_t i = 0;i < n;i++){
                scanf("%ld",&arr[i]);
                visited[i] = 0;
            }

            if(isFirst++) printf("\n");
            dfs(0,0,n,arr,visited,arragement);

            free(visited);
            free(arr);
        }

    }while(n != 0);

    return 0;
}