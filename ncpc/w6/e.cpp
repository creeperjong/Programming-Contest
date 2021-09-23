#include <bits/stdc++.h>
#define MAXLEN (1000 + 5)
#define pd(x) printf("%d\n", x)
#define sd(x) scanf("%d", &x)
#define nl printf("\n")
#define ll long long
#define pii pair<int, int>

using namespace std;

int n,k,t[6],tmp=0,dis[MAXLEN];
vector<int> Floor[6];
bool vis[MAXLEN];
char c;

void dijkstra(int idx, vector<pii>* adjs){
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for(int i = 1;i <= n;i++){
        if(Floor[i][0] % 100 == 0){
            dis[100 * i] = 0;
            pq.push({0, 100 * i});
        }
    }
    while(!pq.empty()){
        pii now = pq.top(); pq.pop();
        //pd(now.second);
        if(vis[now.second]) continue;
        vis[now.second] = true;
        for(pii adj : adjs[now.second]){
            if(adj.second + dis[now.second] < dis[adj.first]){
                dis[adj.first] = adj.second + dis[now.second];
                //printf("dis %d: %d\n", adj.first, dis[adj.first]);
                if(vis[adj.first]) continue;
                pq.push({dis[adj.first], adj.first});
            }
        }
    }
}

int main(){
    
    while(cin >> n >>k){
        vector<pii> adjs[MAXLEN];
        for(int i = 1;i <= n;i++) sd(t[i]);
        getchar();
        for(int i = 1;i <= n;i++){
            Floor[i].clear();
            while((c = getchar()) != '\n'){
                if(c == ' '){
                    Floor[i].push_back(tmp + i * 100);
                    tmp = 0;           
                }
                else tmp = tmp * 10 + c - '0';
            }
            Floor[i].push_back(tmp + i * 100);
            tmp = 0; 
        }
        // for(int i = 1;i <= n;i++){
        //     for(int j : Floor[i]) printf("%d ", j);
        //     nl;
        // }
        for(int i = 1;i <= n;i++){
            for(int j = 0;j < Floor[i].size() - 1;j++){
                adjs[Floor[i][j]].push_back({Floor[i][j+1], (Floor[i][j+1] - Floor[i][j]) * t[i]});
                adjs[Floor[i][j+1]].push_back({Floor[i][j], (Floor[i][j+1] - Floor[i][j]) * t[i]});
            }
        }
        for(int i = 1;i <= n;i++){
            for(int j = i + 1;j <= n;j++){
                for(int k = 0;k < Floor[i].size();k++){
                    for(int m = 0;m < Floor[j].size();m++){
                        if(Floor[i][k] % 100 == Floor[j][m] % 100){
                            adjs[Floor[i][k]].push_back({Floor[j][m], 60});
                            adjs[Floor[j][m]].push_back({Floor[i][k], 60});
                        }
                    }
                }
            }
        }
        dijkstra(0, adjs);
        int mi = 0x3f3f3f3f;
        for(int i = 1;i <= n;i++){
            mi = min(mi, dis[i * 100 + k]);
        }
        if(mi == 0x3f3f3f3f) printf("IMPOSSIBLE\n");
        else pd(mi);
    }

    return 0;
}