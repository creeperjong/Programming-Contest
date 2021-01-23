#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

int main(){
    char time[5] = "";
    double ang = 0;
    
    scanf("%s",time);
    while(time[0] != '0' || time[2] != '0' || time[3] != '0'){
        if(time[1] == ':'){
            time[4] = time[3];
            time[3] = time[2];
            time[2] = time[1];
            time[1] = time[0];
            time[0] = '0';
        }

        ang = (time[0] - '0') * 300 + (time[1] - '0') * 30;

        ang += (time[3] - '0') * 5 + (time[4] - '0') * 0.5;

        ang -= (time[3] - '0') * 60 + (time[4] - '0') * 6;

        ang = fabs(ang);

        if(ang > 180){
            ang = 360.0 - ang;
        }

        printf("%.3lf\n",ang);
        scanf("%s",time);
    }
    return 0;
}