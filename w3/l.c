#include <stdio.h>
#include <stdint.h>
#include <string.h>

void count(int32_t* previous,int32_t* next,int32_t* ans,int32_t* tmp);

void count(int32_t* previous,int32_t* next,int32_t* ans,int32_t* tmp){
    for(int32_t i = 0;i < 10;i++){
        tmp[i] = next[i];
        next[i] -= previous[i];
        if(next[i] == -1){
            next[i] = 0;
        }
        ans[i] += next[i];
        previous[i] = tmp[i];
    }
}

int main(){

    int32_t cases = 0;
    int32_t previous[10] = {0};
    int32_t ans[10] = {0};
    int32_t tmp[10] = {0};
    char c;

    scanf("%d",&cases);

    c = getchar();
    for(int32_t i = 0;i < cases;i++){
        c = getchar();
        while(c != '\n'){
            if(c == 'c'){
                int32_t next[10] = {0,1,1,1,0,0,1,1,1,1};
                count(previous,next,ans,tmp);
            }
            if(c == 'd'){
                int32_t next[10] = {0,1,1,1,0,0,1,1,1,0};
                count(previous,next,ans,tmp);
            }
            if(c == 'e'){
                int32_t next[10] = {0,1,1,1,0,0,1,1,0,0};
                count(previous,next,ans,tmp);
            }
            if(c == 'f'){
                int32_t next[10] = {0,1,1,1,0,0,1,0,0,0};
                count(previous,next,ans,tmp);
            }
            if(c == 'g'){
                int32_t next[10] = {0,1,1,1,0,0,0,0,0,0};
                count(previous,next,ans,tmp);
            }
            if(c == 'a'){
                int32_t next[10] = {0,1,1,0,0,0,0,0,0,0};
                count(previous,next,ans,tmp);
            }
            if(c == 'b'){
                int32_t next[10] = {0,1,0,0,0,0,0,0,0,0};
                count(previous,next,ans,tmp);
            }
            if(c == 'C'){
                int32_t next[10] = {0,0,1,0,0,0,0,0,0,0};
                count(previous,next,ans,tmp);
            }
            if(c == 'D'){
                int32_t next[10] = {1,1,1,1,0,0,1,1,1,0};
                count(previous,next,ans,tmp);
            }
            if(c == 'E'){
                int32_t next[10] = {1,1,1,1,0,0,1,1,0,0};
                count(previous,next,ans,tmp);
            }
            if(c == 'F'){
                int32_t next[10] = {1,1,1,1,0,0,1,0,0,0};
                count(previous,next,ans,tmp);
            }
            if(c == 'G'){
                int32_t next[10] = {1,1,1,1,0,0,0,0,0,0};
                count(previous,next,ans,tmp);
            }
            if(c == 'A'){
                int32_t next[10] = {1,1,1,0,0,0,0,0,0,0};
                count(previous,next,ans,tmp);
            }
            if(c == 'B'){
                int32_t next[10] = {1,1,0,0,0,0,0,0,0,0};
                count(previous,next,ans,tmp);
            }

            c = getchar();
        }

        for(int32_t i = 0;i < 9;i++){
            printf("%d ",ans[i]);
        }
        printf("%d\n",ans[9]);

        memset(ans,0,sizeof(ans));
        memset(previous,0,sizeof(previous));
    }

    return 0;
}