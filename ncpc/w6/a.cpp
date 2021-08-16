#include <bits/stdc++.h>
#define MAXLEN (1000 + 5)
#define pd(x) printf("%d\n", x)
#define sd(x) scanf("%d", &x)
#define nl printf("\n")
#define ll long long
#define pii pair<int, int>
#define pipii pair<int, pii>

using namespace std;

int t,n,m,arr[MAXLEN][MAXLEN],dis[MAXLEN][MAXLEN];
const int dx[] = {1,-1,0,0};
const int dy[] = {0,0,1,-1};
bool vis[MAXLEN][MAXLEN] = {0};

void dijkstra(int x, int y){
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    dis[x][y] = arr[x][y];
    priority_queue<pipii, vector<pipii>, greater<pipii>> q; 
    q.push({dis[x][y], {x, y}});
    while(!q.empty()){
        pipii now = q.top(); q.pop();
        if(vis[now.second.first][now.second.second]) continue;
        vis[now.second.first][now.second.second] = true;

        for(int i = 0;i < 4;i++){
            int nx = now.second.first + dx[i], ny = now.second.second + dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                if(now.first + arr[nx][ny] < dis[nx][ny]){
                    dis[nx][ny] = now.first + arr[nx][ny];
                    if(vis[nx][ny]) continue;
                    q.push({dis[nx][ny], {nx, ny}});
                }
            }
        }
    }
}

int main(){
    
    sd(t);
    while(t--){
        sd(n), sd(m);
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++) sd(arr[i][j]);
        }
        dijkstra(0, 0);
        // for(int i = 0;i < n;i++){
        //     for(int j = 0;j < m;j++) sd(dis[i][j]);
        //     nl;
        // }
        pd(dis[n-1][m-1]);
    }
    
    return 0;
}