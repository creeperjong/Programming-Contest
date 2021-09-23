#include <bits/stdc++.h>
#define MAXLEN (30 + 5)
#define pd(x) printf("%d\n", x)
#define sd(x) scanf("%d", &x)
#define nl printf("\n")
#define ll long long
#define pii pair<int, int>

using namespace std;

int tc,n,m,s,money,u,v,w,cost[MAXLEN],vis;
vector<pii> adjs[MAXLEN];

void dfs(int now, int par, int m){
    m += cost[now];
    for(pii adj : adjs[now]){
        if(m >= adj.second && adj.first != par) dfs(adj.first, now, m - adj.second);
    }
}

int main(){
    
    sd(tc);
    while(tc--){
        scanf("%d %d %d", &n, &s, &money);
        vis = n - 1;
        scanf("%d", &m);
        while(m--){
            scanf("%d %d %d", &u, &v, &w);
            adjs[u].push_back({v, w});
            adjs[v].push_back({u, w});
        }
        scanf("%d", &m);
        while(m--){
            scanf("%d %d", &u, &w);
            cost[u] = w;
        }
        dfs(s, 0, money);
    }
    
    return 0;
}