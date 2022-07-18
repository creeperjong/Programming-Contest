#include <bits/stdc++.h>
using namespace std;

int main(){

    int n,tmp;
    while(cin >> n && n){
        vector<int> arr;
        unordered_map<int, vector<pair<int, int>>> mp;
        for(int i = 0;i < n;++i){
            cin >> tmp;
            arr.push_back(tmp);
        }
        for(int i = 0;i < n;++i){
            for(int j = i+1;j < n;++j){
                mp[arr[i]+arr[j]].push_back({i, j});
            }
        }
        int ans = 0xc0c0c0c0;
        for(int i = 0;i < n;++i){
            for(int j = 0;j < n;++j){
                if(i == j) continue;
                int rhs = arr[i] - arr[j];
                if(mp.count(rhs)){
                    if(mp[rhs].size() > 1) ans = max(ans, arr[i]);
                    else{
                        auto p = mp[rhs][0];
                        if(p.first != i && p.second != i && p.first != j && p.second != j){
                            ans = max(ans, arr[i]);
                        }
                    }
                }
            }
        }
        if(ans != 0xc0c0c0c0) cout << ans << endl;
        else cout << "no solution\n";
    }

    return 0;
}