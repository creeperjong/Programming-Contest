#include <bits/stdc++.h>
#define MAXLEN (50 + 5)
#define pd(x) printf("%d\n", x)
#define sd(x) scanf("%d", &x)
#define nl printf("\n")
#define ll long long
#define pii pair<int, int>

using namespace std;

int l,n,arr[MAXLEN],mini[MAXLEN][MAXLEN];

int dp(int s, int e){
    if(mini[s][e] != 0x3f3f3f3f) return mini[s][e];
    if(s + 1 == e) return mini[s][e] = 0;
    int res = 0x3f3f3f3f;
    for(int i = s + 1;i < e;i++){
        res = min(res, dp(s,i) + dp(i,e));
    }
    return mini[s][e] = res + arr[e] - arr[s];
}

int main(){
    
    while(cin >> l && l != 0){
        memset(mini, 0x3f, sizeof(mini));
        sd(n);
        for(int i = 1;i <= n;i++) sd(arr[i]);
        arr[0] = 0, arr[n+1] = l;
        printf("The minimum cutting is %d.\n", dp(0, n + 1));
    }
    
    return 0;
}