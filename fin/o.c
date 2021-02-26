#include <stdio.h>
#include <stdint.h>

int32_t situation = 1;

void print(int64_t input,int32_t type);

void print(int64_t input,int32_t type){
    int32_t kuti = 0;
    int32_t lakh = 0;
    int32_t hajar = 0;
    int32_t shata = 0;

    kuti = input / 10000000;
    input %= 10000000;
    if(kuti != 0){
        printf(" %d kuti",kuti);
    }else{
        if(type == 2 && situation == 1) printf(" kuti");
    }

    lakh = input / 100000;
    input %= 100000;
    if(lakh != 0) printf(" %d lakh",lakh);

    hajar = input / 1000;
    input %= 1000;
    if(hajar != 0) printf(" %d hajar",hajar);

    shata = input / 100;
    input %= 100;
    if(shata != 0) printf(" %d shata",shata);

    if(input != 0) printf(" %ld",input);


    return;
}

int main(){

    int64_t input = 0;
    int32_t times = 0;

    while(scanf("%ld",&input) != EOF){


        printf("%4d.",++times);

        if(input == 0) printf(" 0\n");
        else{

            if(input / 1000000000 * 100 == 0) situation = 2;
            
            print(input / 1000000000 * 100,1);

            input %= 1000000000;

            print(input,2);

            printf("\n");
            situation = 1;
        }

    }

    return 0;
}