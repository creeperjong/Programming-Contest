#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

int main(){

    int32_t l = 0;
    int32_t n = 0;
    int32_t len = 0;
    int32_t isIrregular = 0;
    char volca[20] = "";
    char** singular = NULL;
    char** plural = NULL;

    while(scanf("%d %d",&l,&n) != EOF){

        singular = (char**)malloc(sizeof(char*) * l);
        plural = (char**)malloc(sizeof(char*) * l);
        for(int32_t i = 0;i < l;i++){
            singular[i] = (char*)malloc(sizeof(char) * 20);
            plural[i] = (char*)malloc(sizeof(char) * 20);
            memset(singular[i],0,sizeof(singular[i]));
            memset(plural[i],0,sizeof(plural[i]));
        }


        for(int32_t i = 0;i < l;i++){
            scanf("%s %s",singular[i],plural[i]);
        }

        for(int32_t i = 0;i < n;i++){
            scanf("%s",volca);
            len = strlen(volca);

            for(int32_t j = 0;j < l;j++){
                if(strncmp(singular[j],volca,20) == 0){
                    printf("%s\n",plural[j]);
                    isIrregular = 1;
                }
            }
        
            if(!isIrregular){
                if(volca[len - 1] == 'y' && (volca[len - 2] != 'a' && volca[len - 2] != 'e' && volca[len - 2] != 'i' && volca[len - 2] != 'o' && volca[len - 2] != 'u')){
                    volca[len - 1] = 'i';
                    volca[len] = 'e';
                    volca[len + 1] = 's';
                    volca[len + 2] = 0;
                    printf("%s\n",volca);
                }else if(volca[len - 1] == 'o'){
                    volca[len] = 'e';
                    volca[len + 1] = 's';
                    volca[len + 2] = 0;
                    printf("%s\n",volca);
                }else if(volca[len - 1] == 's'){
                    volca[len] = 'e';
                    volca[len + 1] = 's';
                    volca[len + 2] = 0;
                    printf("%s\n",volca);
                }else if(volca[len - 1] == 'x'){
                    volca[len] = 'e';
                    volca[len + 1] = 's';
                    volca[len + 2] = 0;
                    printf("%s\n",volca);
                }else if(volca[len - 2] == 's' && volca[len - 1] == 'h'){
                    volca[len] = 'e';
                    volca[len + 1] = 's';
                    volca[len + 2] = 0;
                    printf("%s\n",volca);
                }else if(volca[len - 2] == 'c' && volca[len - 1] == 'h'){
                    volca[len] = 'e';
                    volca[len + 1] = 's';
                    volca[len + 2] = 0;
                    printf("%s\n",volca);
                }else{
                    volca[len] = 's';
                    volca[len + 1] = 0;
                    printf("%s\n",volca);
                }
            }
            isIrregular = 0;
        }

        for(int32_t i = 0;i < l;i++){
            free(singular[i]);
            free(plural[i]);
        }
        free(singular);
        free(plural);
    }

    return 0;
}