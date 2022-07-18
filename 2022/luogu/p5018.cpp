#include <bits/stdc++.h>

using namespace std;

constexpr int MAXLEN = 1e6+5;

int tw[MAXLEN];
int tl[MAXLEN];
int tr[MAXLEN];
int ans;

int dfs(int l, int r){
    if(!l || !r){
        if(l == r) return 1;
        return 0;
    }
    int wl = dfs(tr[l], tl[r]);
    int wr = dfs(tl[l], tr[r]);
    if(tw[l] == tw[r]){
        if(wl == wr){
            ans = max(ans, wl+1);
            return wl + 1;
        }
        else{
            ans = max(ans, max(wl, wr));
            return 0;
        }
    }
    return 0; 
}

int main(){

    int n;
    cin >> n;
    for(int i = 1;i <= n;++i) cin >> tw[i];
    for(int i = 1;i <= n;++i){
        int l, r;
        cin >> l >> r;
        if(~l) tl[i] = l;
        if(~r) tr[i] = r;
    }
    dfs(tl[1], tr[1]);
    cout << ans+1 << endl;


    return 0;
}