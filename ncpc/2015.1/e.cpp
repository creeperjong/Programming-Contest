#include <bits/stdc++.h>
#define MAXLEN (1000000 + 5)
#define pd(x) printf("%d\n", x)
#define sd(x) scanf("%d", &x)
#define nl printf("\n")
#define ll long long
#define pii pair<int, int>

using namespace std;

int m,n,v[MAXLEN];  
bool dp[MAXLEN];

int main(){
    
    while(scanf("%d", &m) && m){
        memset(dp, 0, sizeof(dp));
        scanf("%d", &n);
        dp[0] = true;
        for(int i = 0;i < n;i++) scanf("%d", &v[i]);
        for(int i = 0;i < n;i++){
            for(int j = m;j - v[i] >= 0;j--){
                dp[j] |= dp[j - v[i]];
            }
        }
        for(int i = m;i >= 0;i--){
            if(dp[i]){
                printf("%d\n", i);
                break;
            }
        }
    }
    
    return 0;
}