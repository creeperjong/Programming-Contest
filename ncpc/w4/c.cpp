#include <bits/stdc++.h>
#define MAXLEN (1000 + 5)
#define pd(x) printf("%d\n", x)
#define sd(x) scanf("%d", &x)
#define nl printf("\n")
#define ll long long
#define pii pair<int, int>

using namespace std;

string a,b;

int main(){
    
    while(getline(cin,a) && getline(cin,b)){
        int dp[MAXLEN][MAXLEN] = {0};
        for(int i = 1;i <= a.length();i++){
            for(int j = 1;j <= b.length();j++){
                if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        pd(dp[a.length()][b.length()]);
    }
    
    return 0;
}