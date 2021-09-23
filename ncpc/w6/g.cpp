#include <bits/stdc++.h>
#define MAXLEN (100 + 5)
#define pd(x) printf("%d\n", x)
#define sd(x) scanf("%d", &x)
#define nl printf("\n")
#define ll long long
#define pii pair<int, int>

using namespace std;

int c,s,q,u,v,w,st,e,dp[MAXLEN][MAXLEN][MAXLEN],caseCnt=0;

void floyd(){
    for(int k = 1;k <= c;k++){
        for(int i = 1;i <= c;i++){
            for(int j = 1;j <= c;j++){
                dp[k][i][j] = min(dp[k-1][i][j], max(dp[k-1][i][k], dp[k-1][k][j]));
            }
        }
    }
}

int main(){
    
    while(cin >> c >> s >> q && (c != 0 || s != 0 || q != 0)){
        memset(dp, 0x3f, sizeof(dp));
        for(int i = 0;i < s;i++){
            sd(u), sd(v), sd(w);
            dp[0][u][v] = w;
            dp[0][v][u] = w;
        }
        for(int i = 1;i <= c;i++) dp[0][i][i] = 0;
        floyd();
        if(caseCnt) nl;
        printf("Case #%d\n", ++caseCnt);
        for(int i = 0;i < q;i++){
            sd(st), sd(e);
            if(dp[c][st][e] == 0x3f3f3f3f) printf("no path\n");
            else pd(dp[c][st][e]);
        }
    }
    
    return 0;
}