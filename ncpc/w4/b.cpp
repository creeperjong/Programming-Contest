#include <bits/stdc++.h>
#define MAXLEN (30000 + 5)
#define pd(x) printf("%d\n", x)
#define sd(x) scanf("%d", &x)
#define nl printf("\n")
#define ll unsigned long long
#define pii pair<int, int>

using namespace std;

int n,price[6] = {0,1,5,10,25,50};

int main(){
    
    while(cin >> n){
        ll dp[6][MAXLEN] = {0};

        for(int i = 1;i <= 5;i++){
            dp[i][0] = 1;
            for(int j = 1;j <= n;j++){
                if(j - price[i] >= 0) dp[i][j] = dp[i-1][j] + dp[i][j-price[i]];
                else dp[i][j] = dp[i-1][j];
            }
        }
        // for(int i = 0;i < 6;i++){
        //     for(int j = 0;j <= n;j++){
        //         printf("%d ",dp[i][j]);
        //     }
        //     nl;
        // }

        if(dp[5][n] != 1) printf("There are %lld ways to produce %d cents change.\n", dp[5][n],n);
        else printf("There is only 1 way to produce %d cents change.\n", n);
    }
    
    return 0;
}