#include <bits/stdc++.h>
#define MAXLEN (1000000000 + 5)
#define pd(x) printf("%d\n", x)
#define sd(x) scanf("%d", &x)
#define nl printf("\n")
#define ll long long
#define pii pair<int, int>

using namespace std;

int tc, input; 

int main(){
    
    scanf("%d", &tc);
    while(tc--){
        scanf("%d", &input);
        int digit = 0, tmp, ans = 0;
        tmp = input;
        while(tmp) tmp /= 10, ++digit;
        for(int i = input - 9 * digit;i < input;i++){
            int sum = i;
            tmp = i;
            while(tmp) sum += tmp % 10, tmp /= 10;
            if(sum == input){
                printf("%d\n", i);
                break;
            }
            if(i == input - 1) printf("0\n");
        }
    }
    
    return 0;
}