#include <bits/stdc++.h>
#define MAXLEN (100 + 5)
#define pd(x) printf("%d\n", x)
#define sd(x) scanf("%d", &x)
#define nl printf("\n")
#define ll long long
#define pii pair<int, int>

using namespace std;

int n,s,p,q,ans,ma=-1,cs=0,dis[MAXLEN] = {0};
vector<int> adjs[MAXLEN];

int main(){
    
    while(cin >> n && n != 0){
        for(int i = 0;i <= n;i++) adjs[i].clear();
        memset(dis, 0, sizeof(dis));
        ma = -1;
        sd(s);
        while(cin >> p >> q && (p != 0 || q != 0)){
            auto idx = lower_bound(adjs[p].begin(), adjs[p].end(), q);
            if(idx == adjs[p].end()) adjs[p].push_back(q);
            else adjs[p].insert(idx, q);
        }
        
        queue<int> q;
        q.push(s);
        dis[s] = 0;
        while(!q.empty()){
            int now = q.front(); q.pop();
            for(int adj : adjs[now]){
                if(dis[adj] < dis[now] + 1){
                    dis[adj] = dis[now] + 1;
                    q.push(adj);
                }
            }
        }
        for(int i = 1;i <= n;i++){
            if(ma < dis[i]){
                ma = dis[i];
                ans = i;
            }
        }
        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n", ++cs, s, ma, ans);
    }
    
    return 0;
}