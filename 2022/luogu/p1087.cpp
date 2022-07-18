#include <bits/stdc++.h>
#define MAXLEN 2000 + 5

using namespace std;

int sum[MAXLEN];

void dfs(int l, int r){
    if(l == r) return;
    if(r - l == 1){
        if(sum[r] - sum[l]) cout << 'I';
        else cout << 'B';
        return;
    }
    int mid = (l + r) / 2;
    dfs(l, mid);
    dfs(mid, r);
    if(sum[r] - sum[l] == r - l) cout << 'I';
    else if(sum[r] - sum[l]) cout << 'F';
    else cout << 'B';
}

int main(){

    int n;
    cin >> n;
    getchar();    
    for(int i = 0;i < (1 << n);++i){
        char c;
        cin >> c;
        sum[i+1] += sum[i] + c - '0'; 
    }
    dfs(0, (1 << n));
    cout << '\n';

    return 0;
}