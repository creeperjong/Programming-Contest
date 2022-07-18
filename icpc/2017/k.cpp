#include <bits/stdc++.h>
#define MAXLEN (25 + 5)
#define pd(x) printf("%d\n", x)
#define sd(x) scanf("%d", &x)
#define nl printf("\n")
#define ll long long
#define pii pair<int, int>

using namespace std;

int tc,n,m,u,v,vis[MAXLEN];
vector<int> adjs[MAXLEN];

bool dfs(int x){
    if(x == n) return true;
    for(int i = 1;i <= 3;i++){
        vis[x] = i;
        bool flag = false;
        for(int adj : adjs[x]){
            if(adj < x && vis[x] == vis[adj]){
                flag = true;
                break;
            }
        }
        if(flag) continue;
        else if(dfs(x+1)) return true;
    }
    return false; 
}

int main(){
    
    sd(tc);
    while(tc--){
        sd(n), sd(m);
        for(int i = 0;i < n;i++) adjs[i].clear();
        memset(vis, 0, sizeof(vis));
        while(m--){
            sd(u), sd(v);
            adjs[u].push_back(v), adjs[v].push_back(u);
        }
        if(dfs(0)) printf("Y\n");
        else printf("N\n");
    }
    
    return 0;
}