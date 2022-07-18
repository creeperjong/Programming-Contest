#include <bits/stdc++.h>

using namespace std;
constexpr int MAXLEN = 1e5 + 5;

vector<int> adjs[MAXLEN];
int d[MAXLEN];

int main(){

    int n,k;
    cin >> n >> k;
    for(int i = 0;i < n-1;++i){
        int u, v;
        cin >> u >> v;
        adjs[u].push_back(v);
        adjs[v].push_back(u);
        ++d[u], ++d[v];
    }
    k = n - k;
    queue<int> q;
    for(int i = 0;i <= n;++i){
        if(d[i] == 1) q.push(i);
    }
    int ans = 1;
    while(!q.empty()){
        int num = q.size();
        while(num--){
            int now = q.front(); q.pop();
            --k;
            if(!k) goto result;
            for(int adj : adjs[now]){
                --d[adj];
                if(d[adj] == 1) q.push(adj);
            }
        }
        ++ans;
    }
    result:
    cout << ans << endl;


    return 0;
}