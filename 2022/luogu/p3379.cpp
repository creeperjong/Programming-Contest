#include <bits/stdc++.h>

using namespace std;

constexpr int MAXLEN = 5e5 + 5;

vector<int> adjs[MAXLEN];
int fa[MAXLEN][32], dep[MAXLEN];

void dfs(int root, int pa){
    fa[root][0] = pa;
    dep[root] = dep[pa] + 1;
    for(int i = 1;i <= 31;++i){
        fa[root][i] = fa[fa[root][i-1]][i-1];
    }
    for(int adj : adjs[root]){
        if(adj == pa) continue;
        dfs(adj, root);
    }
}

int lca(int x, int y){
    if(dep[x] > dep[y]) swap(x, y);
    int diff = dep[y] - dep[x];
    for(int i = 0;diff;++i, diff >>= 1){
        if(diff&1) y = fa[y][i];
    }
    if(y == x) return y;
    for(int i = 31;i >= 0 ;--i){
        if(fa[x][i] != fa[y][i]){
            x = fa[x][i];
            y = fa[y][i];
        }
    }
    return fa[x][0];
}

int main(){

    int n,m,s;
    cin >> n >> m >> s;
    for(int i = 1;i < n;++i){
        int a, b;
        cin >> a >> b;
        adjs[a].push_back(b);
        adjs[b].push_back(a);
    }
    dfs(s, 0);
    while(m--){
        int a,b;
        cin >> a >> b;
        cout << lca(a, b) << endl;
    }

    return 0;
}