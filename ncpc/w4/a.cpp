#include <bits/stdc++.h>
#define MAXLEN (1000 + 5)
#define pd(x) printf("%d\n", x)
#define sd(x) scanf("%d", &x)
#define nl printf("\n")
#define ll long long
#define pii pair<int, int>

using namespace std;

int t,n,g,sum=0,w[MAXLEN],maxW=0;
pii obj[MAXLEN];

int main(){
    
    sd(t);
    while(t--){
        sum = 0;
        int dp[MAXLEN][MAXLEN] = {0};
        sd(n);
        for(int i = 1;i <= n;i++) sd(obj[i].first), sd(obj[i].second);
        sd(g);
        for(int i = 1;i <= g;i++){
            sd(w[i]);
            maxW = max(maxW, w[i]);
        }
        for(int j = 1;j <= n;j++){
            for(int k = 1;k <= maxW;k++){
                if(k >= obj[j].second) dp[j][k] = max(dp[j-1][k], dp[j-1][k-obj[j].second] + obj[j].first);
                else dp[j][k] = dp[j-1][k];
            }
        }
        for(int i = 1;i <= g;i++) sum += dp[n][w[i]];
        pd(sum);
    }
    
    return 0;
}