#include <bits/stdc++.h>
using namespace std;

int main(){

    int l,n,m,s,k,tmp,tc = 0;
    while(cin >> l >> n >> m){
        cout << "Case " << ++tc << ":\n";
        vector<int> a, b, c;
        vector<int> sum;
        for(int i = 0;i < l;++i){
            cin >> tmp;
            a.push_back(tmp);
        }
        for(int i = 0;i < n;++i){
            cin >> tmp;
            b.push_back(tmp);
        }
        for(int i = 0;i < m;++i){
            cin >> tmp;
            c.push_back(tmp);
        }
        for(int i = 0;i < l;++i){
            for(int j = 0;j < n;++j) sum.push_back(a[i] + b[j]);
        }
        sort(sum.begin(), sum.end());
        cin >> s;
        while(s--){
            cin >> k;
            bool ans = false;
            for(int i = 0;i < m;++i){
                int t = k-c[i];
                if(*lower_bound(sum.begin(), sum.end(), t) == t){
                    ans = true;
                    break;
                }
            }
            if(ans) cout << "YES\n";
            else cout << "NO\n";
        }
    }

    return 0;
}