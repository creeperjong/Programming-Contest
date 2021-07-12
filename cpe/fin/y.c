#include <stdio.h>
#include <stdint.h>
#include <math.h>

int main(){
    int32_t player = 0;
    int32_t q = 0;
    int32_t cases =  0;
    double ans = 0;
    double p = 0;

    scanf("%d",&cases);

    while(cases--){
        scanf("%d %lf %d",&player,&p,&q);
        if(p == 0) printf("0.0000\n");
        else{
        ans = p * pow(1 - p,q - 1) / (1 - pow(1 - p,player));
        printf("%.4lf\n",ans);
        }
    }

    return 0;
}