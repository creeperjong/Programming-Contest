#include <bits/stdc++.h>
#define MAXLEN (200 + 5)
#define pd(x) printf("%d\n", x)
#define sd(x) scanf("%d", &x)
#define nl printf("\n")
#define ll long long
#define pii pair<int, int>

using namespace std;

struct node {
    int v[3],d;
    node(int _a,int _b,int _c, int _d){v[0] = _a, v[1] = _b, v[2] = _c, d = _d;}
    bool operator < (const node& rhs) const{
        return d > rhs.d;
    }
};

int t,pour,d,cp[3];

int main(){
    
    sd(t);
    while(t--){

        int ans[MAXLEN];
        memset(ans, 0x3f, sizeof(ans));
        bool vis[MAXLEN][MAXLEN] = {0};
        priority_queue<node> q;

        sd(cp[0]),sd(cp[1]),sd(cp[2]),sd(d);

        q.push(node(0, 0, cp[2], 0));
        vis[0][0] = true;

        while(!q.empty()){
            node now = q.top();
            q.pop();

            for(int i = 0;i < 3;i++) ans[now.v[i]] = min(ans[now.v[i]], ans[now.v[i]]);
            
            if(ans[d] != 0x3f3f3f3f) break;

            for(int i = 0;i < 3;i++){
                for(int j = 0;j < 3;j++){
                    if(i == j || now.v[i] == 0 || now.v[j] == cp[j]) continue;
                    pour = min(cp[j] - now.v[j], now.v[i]);

                    node newNode = node(now.v[0], now.v[1], now.v[2], now.d + pour);
                    newNode.v[i] = now.v[i] - pour, newNode.v[j] = now.v[j] + pour;

                    if(!vis[newNode.v[0]][newNode.v[1]]){
                        vis[newNode.v[0]][newNode.v[1]] = true;
                        q.push(newNode);
                    }
                }
            }
        }

        for(int i = d;i >= 0;--i){
            if(ans[i] != 0x3f3f3f3f){
                printf("%d %d\n", ans[i], i);
                break;
            }
        }

    }
    
    return 0;
}