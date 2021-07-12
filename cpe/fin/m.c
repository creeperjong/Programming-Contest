#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct m{
    char name[15];
    uint64_t fre;
} medicine;

uint64_t GCD(uint64_t a,uint64_t b);

uint64_t GCD(uint64_t a,uint64_t b){
    while((a %= b) && (b %= a));
    return a + b;
}

int main(){

    uint64_t cases = 0;
    uint64_t n = 0;
    uint64_t k = 0;
    uint64_t unit = 0;
    uint64_t day  = 0;
    uint64_t count = 0;
    uint64_t isStop = 0;
    medicine* list = NULL;
    medicine* prescr = NULL;

    scanf("%ld",&cases);

    while(cases--){
        scanf("%ld %ld",&n,&k);

        prescr = (medicine*)malloc(sizeof(medicine) * n);

        for(uint64_t i = 0;i < n;i++) scanf("%s %ld",prescr[i].name,&prescr[i].fre);

        unit = prescr[0].fre;
        for(uint64_t i = 1;i < n;i++) unit = GCD(unit,prescr[i].fre);

        while(day += unit){
            for(uint64_t i = 0;i < n;i++){
                if(day % prescr[i].fre == 0){
                    printf("%ld %s\n",day,prescr[i].name);
                    count++;
                    if(count == k){
                        isStop = 1;
                        break;
                    }
                }
            }

            if(isStop) break;
        }

        day = 0;
        unit = 0;
        count = 0;
        isStop = 0;
    }

    return 0;
}