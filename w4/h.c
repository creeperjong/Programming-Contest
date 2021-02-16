#include <stdio.h>
#include <stdint.h>
#include <string.h>

int main(){

    int32_t step = 0;
    int32_t tmp = 0;
    char n[] = "north";
    char e[] = "east";
    char s[] = "south";
    char w[] = "west";
    char choice[10] = "";

    do{
        int32_t die[3][3] = {{0,2,0},
                            {3,1,4},
                            {0,5,0}};
        int32_t bottom = 6;
        scanf("%d",&step);

        if(step != 0){
            for(int32_t i = 0;i < step;i++){
                scanf("%s",choice);

                if(strcmp(choice,n) == 0){
                    tmp = die[0][1];
                    die[0][1] = die[1][1];
                    die[1][1] = die[2][1];
                    die[2][1] = bottom;
                    bottom = tmp;
                }

                if(strcmp(choice,e) == 0){
                    tmp = die[1][2];
                    die[1][2] = die[1][1];
                    die[1][1] = die[1][0];
                    die[1][0] = bottom;
                    bottom = tmp;
                }

                if(strcmp(choice,s) == 0){
                    tmp = die[2][1];
                    die[2][1] = die[1][1];
                    die[1][1] = die[0][1];
                    die[0][1] = bottom;
                    bottom = tmp;
                }

                if(strcmp(choice,w) == 0){
                    tmp = die[1][0];
                    die[1][0] = die[1][1];
                    die[1][1] = die[1][2];
                    die[1][2] = bottom;
                    bottom = tmp;
                }
            }
        printf("%d\n",die[1][1]);
        }



    }while(step != 0);
    

    return 0;
}