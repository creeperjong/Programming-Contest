#include <bits/stdc++.h>
using namespace std;

bool cmp(const pair<string, int>& a, const pair<string, int>& b){
    return a.second < b.second;
}

int main(){

    int n;
    
    while(cin >> n && n != 0){
        unordered_map<string, int> cnt;
        while(n--){
            string idx;
            int input[5];

            for(int i = 0;i < 5;i++) cin >> input[i];
            sort(input, input + 5);

            for(int i = 0;i < 5;i++) idx += to_string(input[i]);
            ++cnt[idx];
        }
        
        unordered_map<string, int>::iterator it;
        int ans = 0;
        int maxVal = max_element(cnt.begin(), cnt.end(), cmp)->second;

        for(it = cnt.begin();it != cnt.end();it++){
            if(it->second == maxVal) ++ans;
        }

        cout << ans * maxVal << endl;
    }


}