#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(){
    int32_t h1 = 0;
    int32_t m1 = 0;
    int32_t h2 = 0;
    int32_t m2 = 0;

    scanf("%d %d %d %d",&h1,&m1,&h2,&m2);

    while(h1!=0 || h2!=0 || m1!=0 || m2!=0){

        if(h2 > h1){
            printf("%d\n",(h2-h1)*60+(m2-m1));
        }else if(h2 == h1){
            if(m2 >= m1){
                printf("%d\n",m2-m1);
            }else{
                printf("%d\n",1440 - m1 + m2);
            }
        }else if(h2 < h1){
            h2 += 24;
            printf("%d\n",(h2-h1)*60+(m2-m1));
        }
        scanf("%d %d %d %d",&h1,&m1,&h2,&m2);
    }

    return 0;
}