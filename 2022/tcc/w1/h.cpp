#include <bits/stdc++.h>
using namespace std;

constexpr int MAXLEN = 1e5 + 5;
set<int> neq[MAXLEN];
int pa[MAXLEN];
int n,x,y,e,cnt=0;

int parent(int u){
    return u == pa[u] ? u : pa[u] = parent(pa[u]);
}
void init(){
    iota(pa, pa+n+1, 0);
    for(int i = 1;i <= n;++i){
        neq[i].clear();
    }
    cnt = 0;
}

int main(){

    vector<int> ans;
    while(~scanf("%d", &n)){
        init();
        for(int tc = 0;tc < n;++tc){
            scanf("%d %d %d", &x, &y, &e);
            int px = parent(x), py = parent(y);
            ++cnt;
            if(e){
                if(px == py) continue;
                if(neq[px].count(py)){
                    ans.push_back(cnt);
                    init();
                }
                else{
                    pa[px] = py;
                    for(int i : neq[px]){
                        neq[py].insert(i);
                        neq[i].erase(px);
                        neq[i].insert(py);
                    }
                }
            }
            else{
                if(px == py){
                    ans.push_back(cnt);
                    init();
                }
                else{
                    neq[px].insert(py);
                    neq[py].insert(px);
                }
            }
        }
        printf("%d\n", (int)ans.size());
        for(int i : ans){
            printf("%d\n", i);
        }
    }

    return 0;
}