#include <bits/stdc++.h>

using namespace std;

int main(){

    int n,m;

    while(cin >> n){
        unordered_map<string, int> mp;
        string s;
        for(int i = 0;i < n;++i){
            cin >> s;
            mp[s] = 0;
        }
        cin >> m;
        int inc;
        while(m--){
            int rank = 1;
            for(int i = 0;i < n;++i){
                cin >> inc >> s;
                mp[s] += inc;
            }
            int now = mp["memory"];
            for(auto& p : mp){
                if(p.second > now) ++rank;
            }
            cout << rank << endl;
        }
    }

    return 0;
}