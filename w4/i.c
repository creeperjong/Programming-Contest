#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


typedef struct link{
    int32_t val;
    struct link* next;
} node;

int32_t happy(int32_t n);

int32_t happy(int32_t n){

    int32_t ans = 0;

    while(n != 0){
        ans += (n % 10)*(n % 10);
        n /= 10;
    }

    return ans;
}


int main(){

    int32_t cases = 0;
    int32_t times = 0;
    int32_t n = 0;
    int32_t isUnhappy = 0;
    int32_t tmpn = 0;

    node* head = NULL;
    node* now = NULL;
    node* pre = NULL;

    scanf("%d",&cases);

    for(int32_t i = 0;i < cases;i++){
        scanf("%d",&n);
        tmpn = n;

        head = (node*)malloc(sizeof(node));
        head->val = n;
        head->next = NULL;
        pre = head;
        
        while(1){
            n = happy(n);

            if(n == 1) break;

            now = head;
            while(now != NULL){
                if(now->val == n){
                    isUnhappy = 1;
                    break;
                }
                now = now->next;
            }
            
            if(isUnhappy) break;

            now = (node*)malloc(sizeof(node));
            now->val = n;
            now->next = NULL;
            pre->next = now;
            pre = now;
        }

        printf("Case #%d: ",++times);

        if(isUnhappy){
            printf("%d is an Unhappy number.\n",tmpn);
        }else{
            printf("%d is a Happy number.\n",tmpn);
        }

        isUnhappy = 0;

        now = head;
        while(now != NULL){
            pre = now;
            now = now->next;
            free(pre);
        }
    }

    return 0;
}