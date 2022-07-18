#include <bits/stdc++.h>
#define MAXLEN (300 + 5)
#define pd(x) printf("%d\n", x)
#define sd(x) scanf("%d", &x)
#define nl printf("\n")
#define ll long long
#define pii pair<int, int>

using namespace std;

int ma,tc,n,u,v,w,sum[MAXLEN],vis[MAXLEN];
vector<pii> adjs[MAXLEN];

void dfs(int x, int t, int s){
    vis[x] = t,sum[x] = s;
    for(pii adj : adjs[x]){
        if(!vis[adj.first]) dfs(adj.first, t+1, s + adj.second);
        else{
            if(vis[x] - vis[adj.first] == 2) ma = max(ma, sum[x] - sum[adj.first] + adj.second);
        }
    }
    vis[x] = sum[x] = 0; 
}

int main(){
    
    sd(tc);
    while(tc--){
        ma = 0xc0c0c0c0;
        memset(sum, 0, sizeof(sum));
        memset(vis, 0, sizeof(vis));
        sd(n);
        for(int i = 0;i < n;i++) adjs[i].clear();
        for(int i = 0;i < n * (n - 1) / 2;i++){
            sd(u), sd(v), sd(w);
            adjs[u].push_back({v,w});
            adjs[v].push_back({u,w});
        }
        dfs(1, 1, 0);
        pd(ma);
    }
    
    return 0;
}