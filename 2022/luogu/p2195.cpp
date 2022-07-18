#include <bits/stdc++.h>

using namespace std;

constexpr int MAXLEN = 3e5 + 5;

vector<int> adjs[MAXLEN];
int djs[MAXLEN];

int par(int x){
    return x == djs[x] ? x : djs[x] = par(djs[x]);
}

int main(){

    int n,m,q,u,v,opt,x,y;
    cin >> n >> m >> q;
    iota(djs, djs + n + 1, 0);
    for(int i = 0;i < m;++i){
        cin >> u >> v;
        adjs[u].push_back(v);
        adjs[v].push_back(u);
        int pu = par(u), pv = par(v);
        djs[pu] = pv;
    }


    while(q--){
        cin >> opt;
        if(opt == 1){

        }
        else{
            
        }
    }

    return 0;
}