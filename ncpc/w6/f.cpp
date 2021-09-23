#include <bits/stdc++.h>
#define MAXLEN (100 + 5)
#define pd(x) printf("%d\n", x)
#define sd(x) scanf("%d", &x)
#define nl printf("\n")
#define ll long long
#define pii pair<int, int>

using namespace std;

int u,v,ma=-1,caseCnt=0,cnt=0;
int dp[MAXLEN][MAXLEN][MAXLEN];
double ans = 0;

void floyd(){
    for(int k = 1;k <= ma;k++){
        for(int i = 1;i <= ma;i++){
            for(int j = 1;j <= ma;j++){
                dp[k][i][j] = min(dp[k-1][i][j], dp[k-1][i][k] + dp[k-1][k][j]);
                if(k == ma && dp[k][i][j] != 0x3f3f3f3f && dp[k][i][j] != 0) ans += dp[k][i][j], ++cnt;
            }
        }
    }
}

int main(){
    
    while(cin >> u >> v && (u != 0 || v != 0)){
        memset(dp, 0x3f, sizeof(dp));
        ans = 0,cnt = 0,ma = -1;
        dp[0][u][v] = 1;
        ma = max(ma, max(u ,v));
        while(cin >> u >> v && (u != 0 || v != 0)) dp[0][u][v] = 1, ma = max(ma, max(u,v));
        for(int i = 1;i <= ma;i++) dp[0][i][i] = 0;

        floyd();
        // for(int i = 1;i <= ma;i++){
        //     for(int j = 1;j <= ma;j++) printf("%d ", dp[ma][i][j]);
        //     nl;
        // }
        printf("Case %d: average length between pages = %.3lf clicks\n", ++caseCnt, ans / cnt);
    }
    
    return 0;
}