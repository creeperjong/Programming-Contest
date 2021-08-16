#include <bits/stdc++.h>
#define MAXLEN (1000 + 5)
#define pd(x) printf("%d\n", x)
#define sd(x) scanf("%d", &x)
#define nl printf("\n")
#define ll long long
#define pii pair<int, int>

using namespace std;

int t,n,m,x,y,w,dis[MAXLEN];
vector<pii> adjs[MAXLEN];

int main(){
    
    sd(t);
    while(t--){
        sd(n), sd(m);
        memset(dis, 0x3f, sizeof(dis));
        dis[0] = 0;
        for(int i = 0;i < n;i++) adjs[i].clear();
        for(int i = 0;i < m;i++){
            sd(x), sd(y), sd(w);
            adjs[x].push_back({y,w});
        }
        for(int i = 0;i < n - 1;i++){
            for(int j = 0;j < n;j++){
                for(pii k : adjs[j]){
                    if(dis[j] + k.second < dis[k.first]){
                        dis[k.first] = dis[j] + k.second;
                    }
                }
            }
        }
        bool flag = false;
        for(int j = 0;j < n;j++){
            for(pii k : adjs[j]){
                if(dis[j] + k.second < dis[k.first]){
                    printf("possible\n");
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }
        if(flag) continue;
        printf("not possible\n");
    }
    
    return 0;
}