#include <bits/stdc++.h>
#define MAXLEN (1000000000 + 5)
#define pd(x) printf("%d\n", x)
#define sd(x) scanf("%d", &x)
#define ll long long
#define pii pair<int, int>

using namespace std;

int n,num,to,totalCase = 0,dp[25][25][25] = {0},s,e;

void floyd(){
    for(int k = 1;k <= 20;k++){
        for(int i = 1;i <= 20;i++){
            for(int j = 1;j <= 20;j++){
                dp[k][i][j] = min(dp[k-1][i][j], dp[k-1][i][k] + dp[k-1][k][j]);
            }
        }
    }
}

int main(){
    
    while(cin >> num){
        memset(dp, 0x3f, sizeof(dp));
        while(num--){
            sd(to);
            dp[0][1][to] = 1, dp[0][to][1] = 1;
        }
        for(int i = 2;i <= 19;i++){
            sd(num);
            while(num--){
                sd(to);
                dp[0][i][to] = 1, dp[0][to][i] = 1;
            }
        }

        floyd();

        sd(n);
        printf("Test Set #%d\n", ++totalCase);
        for(int i = 0;i < n;i++){
            sd(s), sd(e);
            printf("%2d to %2d: %d\n", s, e, dp[20][s][e]);
        }
        printf("\n");
    }
    
    return 0;
}