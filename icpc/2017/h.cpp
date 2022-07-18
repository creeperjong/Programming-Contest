#include <bits/stdc++.h>
#define MAXLEN (1100000 + 5)
#define pd(x) printf("%d\n", x)
#define sd(x) scanf("%d", &x)
#define nl printf("\n")
#define ll long long
#define pii pair<int, int>

using namespace std;

int tc,n,ans;
bool p[MAXLEN];
unordered_set<int> se;

void jianbiao(){
    for(int i = 2;i < MAXLEN;i++) p[i] = true;
    for(int i = 2;i <= sqrt(MAXLEN);i++){
        if(p[i]){
            for(int j = 2;i * j < MAXLEN;j++) p[i * j] = false; 
        }
    } 
}

void dfs(int x, int layer, unordered_map<int, int> mp){
    for(pii i : mp){
        if(i.second && se.count(x)){

        }
    }
}

int main(){
    
    sd(tc);
    jianbiao();
    while(tc--){
        ans = 0;
        unordered_map<int, int> mp;
        se.clear();
        sd(n);
        for(int i = 2;i <= sqrt(n);i++){
            if(p[i]){
                int cnt = 0,tmp = i;
                while(!(n % tmp)) tmp *= i, ++cnt;
                mp[i] = cnt;
            }
        }
        dfs(1, 0, mp);
    }
    
    return 0;
}