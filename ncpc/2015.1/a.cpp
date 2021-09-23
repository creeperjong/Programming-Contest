#include <bits/stdc++.h>
#define MAXLEN (100000 + 5)
#define pd(x) printf("%d\n", x)
#define sd(x) scanf("%d", &x)
#define nl printf("\n")
#define ll long long
#define pii pair<int, int>

using namespace std;

int tc,n,num;
string s;
vector<int> arr;
unordered_map<int, int> L;

int main(){
    
    sd(tc);
    getchar();
    while(tc--){
        L.clear();
        arr.clear();
        getline(cin, s);
        stringstream ss(s);
        while(ss >> num) arr.push_back(num);
        for(int i = 0;i < arr.size();i++){
            L[arr[i]] = i + 1;
        }
        ll ans = 0;
        for(auto x : L) ans += x.second;
        cout << ans << endl;
    }
    
    return 0;
}