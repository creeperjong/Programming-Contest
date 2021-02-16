#include <stdio.h>
#include <stdint.h>

int main(){

    int32_t cases = 0;
    int32_t times = 0;
    int32_t count = 0;
    int32_t now = 0;

    char c = 0;
    char alphabet = 0;
    char ans[201] = "";

    scanf("%d",&cases);
    c = getchar();

    for(int32_t i = 0;i < cases;i++){
        
        do{
            c = getchar();

            if((c >= 'A' && c <= 'Z') || c == '\n'){
                if(alphabet != 0){
                    for(int32_t j = now;j < now + count;j++){
                        ans[j] = alphabet;
                    }
                    now += count;
                }

                alphabet = c;
                count = 0;
            }else{
                count = count * 10 + c - '0';
            }


        }while(c != '\n');
        
        printf("Case %d: %s\n",++times,ans);
        alphabet = 0;
        for(int32_t j = 0;j < now;j++){
            ans[j] = 0;
        }
        now = 0;
    }

    return 0;
}