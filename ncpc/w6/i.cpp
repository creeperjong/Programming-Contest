#include <bits/stdc++.h>
#define MAXLEN (500 + 5)
#define pd(x) printf("%d\n", x)
#define sd(x) scanf("%d", &x)
#define nl printf("\n")
#define ll long long
#define pii pair<int, int>
#define psi pair<sta, int>

using namespace std;

struct sta {
    int id;
    int num;
    sta(int _id, int _num){num=_num,id=_id;}
};

int n,s,e,m,x,y,z,k,par[MAXLEN],dis[MAXLEN],ans=0x3f3f3f3f,change = 0;
vector<psi> adjs[MAXLEN];
vector<int> route;
bool vis[MAXLEN], isFirst = true;
pii com[1005];

void dijkstra(int choice){
    int tmp = 0;
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    memset(par, 0, sizeof(par));
    dis[s] = 0, par[s] = -1;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, s});
    while(!pq.empty()){
        pii now = pq.top(); pq.pop();
        if(vis[now.second]) continue;
        vis[now.second] = true;
        for(psi adj : adjs[now.second]){
            if(adj.first.num == choice || adj.first.num == -1){
                if(adj.second + dis[now.second] < dis[adj.first.id]){
                    dis[adj.first.id] = adj.second + dis[now.second];
                    par[adj.first.id] = now.second;
                    if(adj.first.num == choice) tmp = now.second;
                    if(!vis[adj.first.id]) pq.push({dis[adj.first.id], adj.first.id});
                }
            }
        }
    }
    if(ans > dis[e]){
        ans = dis[e];
        change = tmp;
        route.clear();
        int now = e;
        route.push_back(e);
        while(now != s){
            route.push_back(par[now]);
            now = par[now];
        }
    }
}

int main(){
    
    while(cin >> n >> s >> e){
        change = 0, ans = 0x3f3f3f3f;
        sd(m);
        for(int i = 1;i <= n;i++) adjs[i].clear();
        for(int i = 0;i < m;i++){
            sd(x), sd(y), sd(z);
            adjs[x].push_back({sta(y, -1), z});
            adjs[y].push_back({sta(x, -1), z});
        }
        sd(k);
        for(int i = 1;i <= k;i++){
            sd(x), sd(y), sd(z);
            com[i] = {x, y};
            adjs[x].push_back({sta(y, i), z});
            adjs[y].push_back({sta(x, i), z});
        }
        for(int i = 0;i <= k;i++) dijkstra(i);
        if(isFirst) isFirst = false;
        else nl;
        for(int i = route.size() - 1;i >= 0;i--) printf("%d%c", route[i], (i) ? ' ' : '\n');
        if(change) pd(change);
        else printf("Ticket Not Used\n");
        pd(ans);
    }
    
    return 0;
}