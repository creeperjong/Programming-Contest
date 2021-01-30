#include <stdio.h>
#include <stdint.h>

int main(){

    char c;

    c = getchar();

    while(c != EOF){
        if(c == '\n'){
            printf("\n");
        }else{
            printf("%c",c - 7);
        }
        c = getchar();
    }

    return 0;
}