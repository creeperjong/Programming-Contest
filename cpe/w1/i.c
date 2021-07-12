#include <stdio.h>
#include <stdint.h>

int main(){
    int32_t num = 0;
    int32_t s1 = 0;
    int32_t s2 = 0;
    int32_t s3 = 0;
    int32_t s4 = 0;

    scanf("%d",&num);

    for(int32_t i = 0;i < num;i++){
        scanf("%d %d %d %d",&s1,&s2,&s3,&s4);
        
        if(s1 == s2 && s2 == s3 && s3 == s4){
            printf("square\n");
        }else if((s1 == s2 && s3 == s4) || (s1 == s3 && s2 == s4) || (s1 == s4) && (s2 == s3)){
            printf("rectangle\n");
        }else if((s1 + s2 + s3 > s4) && (s1 + s2 + s4 > s3) && (s1 + s3 + s4 > s2) && (s2 + s3 + s4 > s1)){
            printf("quadrangle\n");
        }else{
            printf("banana\n");
        }
    }

    return 0;
}