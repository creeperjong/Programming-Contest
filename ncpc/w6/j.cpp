#include <bits/stdc++.h>
#define MAXLEN (1000 + 5)
#define pd(x) printf("%d\n", x)
#define sd(x) scanf("%d", &x)
#define nl printf("\n")
#define ll long long
#define pii pair<int, int>

using namespace std;

int n,m,a,b,w,dis[MAXLEN],dp[MAXLEN];
vector<pii> adjs[MAXLEN];
bool vis[MAXLEN];

void dijkstra(){
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    dis[2] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 2});
    while(!pq.empty()){
        pii now = pq.top(); pq.pop();
        if(vis[now.second]) continue;
        vis[now.second] = true;
        for(pii adj : adjs[now.second]){
            if((adj.second + dis[now.second]) <  dis[adj.first]){
                dis[adj.first] = adj.second + dis[now.second];
                if(!vis[adj.first]) pq.push({dis[adj.first], adj.first});
            }
        }
    }
    memset(vis, 0, sizeof(vis));
    queue<int> q;
    q.push(1);
    vis[1] = true;
    while(!q.empty()){
        int now = q.front(); q.pop();
        for(pii& adj : adjs[now]){
            if(dis[now] <= dis[adj.first]) adj.second = -1;
            if(!vis[adj.first]){
                vis[adj.first] = true;
                q.push(adj.first);
            }
        }
    }
}

int dfs(int id){

    if(~dp[id]) return dp[id];
    if(id == 2) return dp[id] = 1;
    int ans = 0;
    for(pii adj : adjs[id]){
        if(adj.second != -1) ans += dfs(adj.first);
    }

    return dp[id] = ans;
}

int main(){
    
    while(cin >> n && n){
        sd(m);
        for(int i = 1;i <= n;i++) adjs[i].clear();
        for(int i = 0;i < m;i++){
            sd(a), sd(b), sd(w);
            adjs[a].push_back({b,w});
            adjs[b].push_back({a,w});
        }
        dijkstra();
        memset(dp, -1, sizeof(dp));
        pd(dfs(1));
        for(int i = 1;i <= n;i++) printf("%d ", dp[i]);
        nl;
    }
    
    return 0;
}