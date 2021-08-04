#include <bits/stdc++.h>
#define MAXLEN (40000 + 5)
#define pd(x) printf("%d\n", x)
#define sd(x) scanf("%d", &x)
#define nl printf("\n")
#define ll long long
#define pii pair<int, int>

using namespace std;

int t,n,arr[105],sum=0;
ll dp[MAXLEN];

int main(){
    
    sd(t);
    while(t--){
        getchar();
        memset(dp, 0, sizeof(dp));
        sum = 0;
        sd(n);
        for(int i = 0;i < n;i++) sd(arr[i]), sum += arr[i];
        dp[0] = 1;
        for(int i = 0;i < n;i++){
            for(int j = sum;j >= arr[i];j--){
                dp[j] |= (dp[j - arr[i]] << 1);
            }
        }

        ll maxi = INT_MAX, mini = INT_MIN;
        int mid = (n + 1) >> 1;
        for(int i = 0;i < sum + 1;i++){
            for(int j = 1;j < mid + 1;j++){
                if(dp[i] & (1LL << j) && abs(j * 2 - n) <= 1 && maxi - mini > abs(sum - i * 2)){
                    maxi = max(sum - i, i);
                    mini = min(sum - i, i);
                }
            }
        }
        printf("%lld %lld\n", mini, maxi);
        if(t) nl;
    }
    
    return 0;
}