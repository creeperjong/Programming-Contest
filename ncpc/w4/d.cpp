#include <bits/stdc++.h>
#define MAXLEN (100 + 5)
#define pd(x) printf("%d\n", x)
#define sd(x) scanf("%d", &x)
#define nl printf("\n")
#define ll long long
#define pii pair<int, int>

using namespace std;

int n,m;

int main(){
    
    while(scanf("%d %d", &n, &m) && (n != 0 || m != 0)){
        ll dp[MAXLEN][MAXLEN] = {0};
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                if(i == j || j == 0) dp[i][j] = 1;
                else dp[i][j] = dp[i-1][j] * i / (i - j);
            }
        }
        printf("%d things taken %d at a time is %lld exactly.\n",n,m,dp[n][m]);
    }
    
    return 0;
}