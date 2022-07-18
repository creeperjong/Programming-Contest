#include <bits/stdc++.h>
#define MAXLEN (500 + 5)
#define pd(x) printf("%d\n", x)
#define sd(x) scanf("%d", &x)
#define nl printf("\n")
#define ll long long
#define pii pair<int, int>

using namespace std;

int tc,n,m,ans;
bitset<MAXLEN> arr[20];

int bitcnt(bitset<MAXLEN> bm){
    int ans = 0;
    for(int i = 0;i < MAXLEN;i++) bm[i] ? ++ans : 0;
    return ans;
}

void dfs(int x, int cnt, bitset<MAXLEN> now){
    if(x == m){
        int res = bitcnt(now);
        if(res == n) ans = min(ans, cnt);
        return;
    }
    dfs(x+1, cnt, now);
    dfs(x+1, cnt+1, now | arr[x]);
}

int main(){
    
    sd(tc);
    while(tc--){
        ans = 0x3f3f3f3f;
        memset(arr, 0, sizeof(arr));
        sd(n), sd(m);
        for(int i = 0;i < m;i++){
            getchar();
            for(int j = 0;j < n;j++){
                char c = getchar();
                arr[i] <<= 1;
                if(c == '1') arr[i] |= bitset<MAXLEN>(1);
            }
        }
        dfs(0, 0, bitset<MAXLEN>());
        //for(int i = 0;i < m;i++) cout << arr[i] << endl;
        if(ans != 0x3f3f3f3f) printf("%d\n", ans);
        else printf("-1\n");
    }
    
    return 0;
}