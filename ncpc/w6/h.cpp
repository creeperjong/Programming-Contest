#include <bits/stdc++.h>
#define MAXLEN (100 + 5)
#define pd(x) printf("%d\n", x)
#define sd(x) scanf("%d", &x)
#define nl printf("\n")
#define ll long long
#define pii pair<int, int>

using namespace std;

int n,m,u,v,t[MAXLEN],fp[MAXLEN],fn[MAXLEN],tp[MAXLEN],tn[MAXLEN],ans=-1,cnt=0;
string ori, modi;
bool vis[(1 << 20) + 5];

void dijkstra(int id){
    memset(vis, 0, sizeof(vis));
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, id});

    while(!pq.empty()){
        pii now = pq.top(); pq.pop();
        if(!now.second){
            ans = now.first;
            break;
        }
        if(vis[now.second]) continue;
        vis[now.second] = true;
        for(int i = 1;i <= m;i++){
            if(((fp[i] & now.second) == fp[i]) && ((~now.second & fn[i]) == fn[i])){
                int adj = (now.second | tp[i]) & (~tn[i]);
                if(vis[adj]) continue;
                pq.push({now.first + t[i], adj});
            }
        }
    }
}

int main(){
    
    while(cin >> n >> m && (n != 0 || m != 0)){
        ans = -1;
        for(int i = 1;i <= m;i++){
            cin >> t[i] >> ori >> modi;
            fp[i] = fn[i] = tp[i] = tn[i] = 0;
            for(int j = 0;j < n;j++){
                if(ori[j] == '+') fp[i] |= (1 << j);
                if(ori[j] == '-') fn[i] |= (1 << j);
                if(modi[j] == '+') tp[i] |= (1 << j);
                if(modi[j] == '-') tn[i] |= (1 << j);
            }
        }
        dijkstra((1 << n) - 1);
        printf("Product %d\n", ++cnt);
        if(ans != -1) printf("Fastest sequence takes %d seconds.\n", ans);
        else printf("Bugs cannot be fixed.\n");
        nl;
    }

    
    return 0;
}