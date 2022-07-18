#include <bits/stdc++.h>
#define MAXLEN (1000000000 + 5)
#define pd(x) printf("%d\n", x)
#define sd(x) scanf("%d", &x)
#define nl printf("\n")
#define ll long long
#define pii pair<int, int>

using namespace std;

int n;

int main(){
    
    unordered_map<string, int> mp;
    unordered_set<string> se;
    string s1,s2;
    scanf("%d", &n);
    while(n--){
        cin >> s1;
        getline(cin, s2);
        if(se.count(s1 + s2)) continue;
        se.insert(s1 + s2);
        if(mp.count(s1)) ++mp[s1];
        else mp[s1] = 1;
    }
    vector<pair<string, int>> arr;
    for(auto it = mp.begin();it != mp.end();++it){
        arr.push_back({it->first, it->second});
    }
    sort(arr.begin(), arr.end());
    for(auto p : arr){
        cout << p.first << " " << p.second << "\n";
    }
    
    return 0;
}