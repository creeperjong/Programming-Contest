#include <bits/stdc++.h>

using namespace std;

int main(){

    pair<int, int> rec[26];
    int t;
    cin >> t;
    while(t--){
        char al;
        int r, c;
        cin >> al >> r >> c;
        rec[al-'A'] = {r, c};
    }
    string s;
    while(cin >> s){
        vector<pair<int, int>> stk;
        int ans = 0;
        for(char c : s){
            if(c == '(') stk.push_back({-1, -1});
            else if(c == ')'){
                pair<int, int> m2 = stk.back();
                stk.pop_back();
                pair<int, int> m1 = stk.back();
                stk.pop_back();
                stk.pop_back();
                if(m1.second != m2.first){
                    ans = -1;
                    break;
                }
                ans += m1.first * m2.first * m2.second;
                stk.push_back({m1.first, m2.second});
            }
            else stk.push_back(rec[c - 'A']);
        }
        if(~ans) printf("%d\n", ans);
        else printf("error\n");
    }

    return 0;
}