#include <bits/stdc++.h>
#define MAXLEN (20000 + 5)
#define pd(x) printf("%d\n", x)
#define sd(x) scanf("%d", &x)
#define nl printf("\n")
#define ll long long
#define pii pair<int, int>

using namespace std;

int tc,n,m,s,t,a,b,w,dis[MAXLEN];
vector<pii> adjs[MAXLEN];
bool vis[MAXLEN] = {0};

void dijkstra(int s){
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    dis[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0,s});
    while(!pq.empty()){
        pii now = pq.top(); pq.pop();
        if(vis[now.second]) continue;
        vis[now.second] = true;
        for(pii adj : adjs[now.second]){
            if(dis[now.second] + adj.second < dis[adj.first]){
                dis[adj.first] = dis[now.second] + adj.second;
                if(vis[adj.first]) continue;
                pq.push({dis[adj.first], adj.first});
            }
        }
    }
}

int main(){
    
    sd(tc);
    for(int tcc = 1;tcc <= tc;++tcc){
        sd(n), sd(m), sd(s), sd(t);
        for(int i = 0;i <= n;i++) adjs[i].clear();
        for(int i = 0;i < m;i++){
            sd(a), sd(b), sd(w);
            adjs[a].push_back({b,w});
            adjs[b].push_back({a,w});
        }
        dijkstra(s);
        printf("Case #%d: ",tcc);
        if(dis[t] == 0x3f3f3f3f) printf("unreachable\n");
        else pd(dis[t]);
    }
    
    return 0;
}