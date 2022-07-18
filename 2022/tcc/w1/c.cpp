#include <bits/stdc++.h>

using namespace std;

constexpr int MAXLEN = 1e3+5;

int djs[MAXLEN];

int parent(int x){
    return x == djs[x] ? x : djs[x] = parent(djs[x]);
}

int main(){

    int n,m;
    while(scanf("%d", &n) && n){
        scanf("%d", &m);
        iota(djs, djs+n+1, 0);
        for(int i = 0;i < m;++i){
            int u,v;
            scanf("%d %d", &u, &v);
            djs[parent(u)] = parent(v);
        }
        int ans = 0;
        for(int i = 1;i <= n;++i){
            if(djs[i] == i) ++ans;
        }
        if(ans) printf("%d\n", ans - 1);
        else printf("0\n");
    }

    return 0;
}