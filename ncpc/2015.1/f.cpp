#include <bits/stdc++.h>
#define MAXLEN (100 + 5)
#define pd(x) printf("%d\n", x)
#define sd(x) scanf("%d", &x)
#define nl printf("\n")
#define ll long long
#define pii pair<int, int>

using namespace std;

struct _sz {
    int n,id;
} sz[MAXLEN];

int tc,v,e,u,v,del,arr[MAXLEN];
vector<int> adjs[MAXLEN];

bool cmp(int &a, int &b){
    return a > b;
}

int main(){
    
    scanf("%d", &tc);
    while(tc--){
        del = 0;
        memset(sz, 0, sizeof(sz));
        scanf("%d %d", &v, &e);
        for(int i = 0;i < e;i++){
            scanf("%d %d", &u, &v);
            --u, --v;
            adjs[u].push_back(v);
            adjs[v].push_back(u);
            ++arr[u], ++arr[v];
        }
        while(del < e){
            for(int i = 0;i < v - del;i++) sz[i].id = i, sz[i].n = arr[i];
            sort(sz, sz + v - del, cmp);
            int now = sz[0].id;
            
        }
    }
    
    return 0;
}