#include <bits/stdc++.h>
#define MAXLEN (20 + 5)
#define pd(x) printf("%d\n", x)
#define sd(x) scanf("%lf", &x)
#define nl printf("\n")
#define ll long long
#define pii pair<int, int>

using namespace std;

struct exchange {
    int rec;
    double val;
} dp[MAXLEN][MAXLEN][MAXLEN];

int dim;

void print(int k, int i, int j){
    if(k == 1){
        printf("%d %d", i, j);
        return;
    }
    print(k-1, i, dp[k][i][j].rec);
    printf(" %d", j);
}

int main(){
    
    while(cin >> dim){
        memset(dp, 0, sizeof(dp));
        for(int i = 1;i <= dim;i++){
            for(int j = 1;j <= dim;j++){
                if(i == j) dp[1][i][j].val = 1.0;
                else sd(dp[1][i][j].val);
                dp[1][i][j].rec = 0;
            }
        }

        int ans = -1, ansK = 0;
        bool flag = false;
        for(int k = 2;k <= dim;k++){
            for(int i = 1;i <= dim;i++){
                for(int j = 1;j <= dim;j++){
                    for(int m = 1;m <= dim;m++){
                        double newEx = dp[k-1][i][m].val * dp[1][m][j].val;
                        if(newEx > dp[k][i][j].val){
                            dp[k][i][j].val = newEx;
                            dp[k][i][j].rec = m;
                        }
                    }
                }
                if(dp[k][i][i].val > 1.01){
                    ans = i, ansK = k, flag = true;
                    break;
                }
            }
            if(flag) break;
        }

        // for(int k = 1;k <= dim;k++){
        //     for(int i = 1;i <= dim;i++){
        //         for(int j = 1;j <= dim;j++) printf("%lf(%d) ", dp[k][i][j].val,dp[k][i][j].rec);
        //         nl;
        //     }
        //     nl;
        // }

        // printf("ans: %d, ansK: %d\n", ans, ansK);

        if(ans == -1) printf("no arbitrage sequence exists");
        else print(ansK, ans, ans);
        nl;
 
    }
    
    return 0;
}