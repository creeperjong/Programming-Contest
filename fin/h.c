#include <stdio.h>
#include <stdint.h>

int main(){

    int32_t now = 0;
    int32_t first = 0;
    int32_t second = 0;
    int32_t third = 0;
    int32_t ans = 0;

    do{
        scanf("%d %d %d %d",&now,&first,&second,&third);


        if(now != 0 || first != 0 || second != 0 || third != 0){

            ans = 720;

            if(now < first) ans += (now + 40 - first) * 9;
            else ans += (now - first) * 9;

            now = first;

            ans += 360;

            if(now > second) ans += (second + 40 - now) * 9;
            else ans += (second - now) * 9;

            now = second;

            if(now < third) ans += (now + 40 - third) * 9;
            else ans += (now - third) * 9;

            printf("%d\n",ans);
        }



    }while(now != 0 || first != 0 || second != 0 || third != 0);

    return 0;
}