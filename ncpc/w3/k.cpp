#include <bits/stdc++.h>
#define MAXLEN (2000 + 5)
#define pd(x) printf("%d\n", x)
#define sd(x) scanf("%d", &x)
#define nl printf("\n")
#define ll long long
#define pii pair<int, int>

using namespace std;

struct edge {
    int x;
    int y;
} e[MAXLEN];

int x,y,z,du[50],start,maxE,maxV;
bool vis[MAXLEN];
vector<int> ans;

void init(){
    maxE = 0, maxV = 0;
    memset(vis, 0, sizeof(vis));
    memset(du, 0, sizeof(du));
    memset(e, 0, sizeof(e));
    ans.clear();
}

void dfs(int now){
    for(int i = 1;i <= maxE;i++){
        if((e[i].x == now || e[i].y == now) && !vis[i]){
            vis[i] = true;
            dfs(e[i].x == now ? e[i].y : e[i].x);
            ans.push_back(i);
        }
    }
}

int main(){
    
    while(cin >> x >> y && (x != 0 || y != 0)){

        init();

        cin >> z;
        e[z] = {x, y}, ++du[x], ++du[y];
        start = min(x, y), maxE = max(maxE, z), maxV = max(maxV, max(x, y));
        while(cin >> x >> y && (x != 0 || y != 0)){
            cin >> z;
            e[z] = {x, y}, ++du[x], ++du[y];
            maxE = max(maxE, z), maxV = max(maxV, max(x, y));
        }
        bool flag = false;
        for(int i = 1;i <= maxV;i++){
            if(du[i] % 2 != 0){
                printf("Round trip does not exist.\n\n");
                flag = true;
                break;
            }
        }
        if(flag) continue;

        dfs(start);
        printf("%d", ans[ans.size()-1]);
        for(int i = ans.size() - 2;i >= 0;i--) printf(" %d", ans[i]);
        nl;nl;
    }
    
    return 0;
}