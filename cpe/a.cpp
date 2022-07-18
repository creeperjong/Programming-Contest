#include <bits/stdc++.h>
#define MAXLEN (1000000000 + 5)
#define pd(x) printf("%d\n", x)
#define sd(x) scanf("%d", &x)
#define nl printf("\n")
#define ll long long
#define pii pair<int, int>

using namespace std;

int n, m, tmp;

int main(){
    
    while(~scanf("%d %d", &n, &m) && n && m){
        unordered_set<int> m1, m2;
        vector<int> arr1, arr2;
        int cnt1 = 0, cnt2 = 0;
        for(int i = 0;i < n;i++){
            scanf("%d", &tmp);
            arr1.push_back(tmp);
            if(!m1.count(tmp)) m1.insert(tmp), ++cnt1;
        }
        for(int i = 0;i < m;i++){
            scanf("%d", &tmp);
            arr2.push_back(tmp);
            if(!m2.count(tmp)) m2.insert(tmp), ++cnt2;
        }
        m2.clear();
        int ans = min(cnt1, cnt2);
        for(int i = 0;i < m;i++){
            if(m2.count(arr2[i])) continue;
            if(m1.count(arr2[i])) --ans;
            m2.insert(arr2[i]);
        }
        printf("%d\n", ans);
    }
    
    return 0;
}