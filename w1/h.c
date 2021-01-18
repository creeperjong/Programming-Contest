#include <stdio.h>
#include <stdint.h>

int main(){
    int32_t point = 0;
    int32_t originX = 0;
    int32_t originY = 0;
    int32_t pX = 0;
    int32_t pY = 0;

    scanf("%d",&point);

    while(point!=0){
        scanf("%d %d",&originX,&originY);
        for(int32_t i = 0;i < point;i++){
            scanf("%d %d",&pX,&pY);
            if(pX > originX){
                if(pY > originY){
                    printf("NE\n");
                }else if(pY < originY){
                    printf("SE\n");
                }else{
                    printf("divisa\n");    
                }
            }else if(pX < originX){
                if(pY > originY){
                    printf("NO\n");
                }else if(pY < originY){
                    printf("SO\n");
                }else{
                    printf("divisa\n");    
                }
            }else{
                printf("divisa\n");
            }
        }
        scanf("%d",&point);
    }
    return 0;
}