#include <bits/stdc++.h>
#define MAXLEN (10000 + 5)
#define pd(x) printf("%d\n", x)
#define sd(x) scanf("%d", &x)
#define nl printf("\n")
#define ll long long
#define pii pair<int, int>

using namespace std;

int n,arr[MAXLEN],lis[MAXLEN],dp1[MAXLEN],dp2[MAXLEN],lislen = 1,ldslen = 1,ans = -1;

int findlisPos(int a){
    return distance(lis, lower_bound(lis, lis + lislen, a));
}

int main(){
    
    while(cin >> n){
        lislen = 1, ldslen = 1, ans = -1;
        memset(dp1, 0, sizeof(dp1));
        memset(dp2, 0, sizeof(dp2));
        for(int i = 0;i < n;i++) sd(arr[i]);
        memset(lis, 0, sizeof(lis));
        lis[0] = arr[0], dp1[0] = 1, lislen = 1;
        for(int i = 1;i < n;i++){
            int lispos = findlisPos(arr[i]);
            lis[lispos] = arr[i];
            dp1[i] = lispos + 1;
            if(lispos == lislen) ++lislen;
        }
        memset(lis, 0, sizeof(lis));
        lis[0] = arr[n-1], dp2[n-1] = 1, lislen = 1;
        for(int i = n - 2;i >= 0;i--){
            int lispos = findlisPos(arr[i]);
            lis[lispos] = arr[i];
            dp2[i] = lispos + 1;
            if(lispos == lislen) ++lislen;
        }
        // for(int i = 0;i < n;i++) printf("%d ", dp1[i]);
        // nl;
        // for(int i = 0;i < n;i++) printf("%d ", dp2[i]);
        // nl;
        for(int i = 0;i < n;i++){
            ans = max(ans, min(dp1[i],dp2[i]) * 2 - 1);
        }
        pd(ans);
    }
    
    
    return 0;
}