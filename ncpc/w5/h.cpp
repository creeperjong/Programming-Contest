#include <bits/stdc++.h>
#define MAXLEN (100000 + 5)
#define pd(x) printf("%d\n", x)
#define sd(x) scanf("%d", &x)
#define nl printf("\n")
#define ll long long
#define pii pair<int, int>

using namespace std;

struct edge {
    pii pos;
    int len;
    edge(pii _pos, int _len){pos = _pos; len = _len;}
    bool operator<(const edge _b) const{
        return len > _b.len;
    }
};

int t,n,m,a,b,w,ans=0x3f3f3f3f,s[MAXLEN];

int find(int x){
    if(x == s[x]) return x;
    else return s[x] = find(s[x]);
}

bool Union(int x, int y){
    int fx = find(x);
    int fy = find(y);
    if(fx != fy){
        s[fx] = fy;
        return true;
    }
    return false;
}

int main(){
    
    while(cin >> n >> m && (n != 0 || m != 0)){
        priority_queue<edge> pq;
        ans = 0x3f3f3f3f;

        for(int i = 0;i < m;i++){
            sd(a), sd(b), sd(w);
            pq.push(edge({a,b}, w));
        }
        for(int i = 0;i < m;i++){
            priority_queue<edge> pqTmp(pq);
            int cnt = n,ma=-1,mi;
            for(int j = 1;j <= n;j++) s[j] = j;

            for(int j = 0;j < i;j++) pqTmp.pop();
            mi = pqTmp.top().len;
            //printf("mi: %d\n", mi);
            while(!pqTmp.empty()){
                edge now = pqTmp.top();
                pqTmp.pop();
                //printf("now: %d\n",now.len);
                ma = max(ma, now.len);
                bool res = Union(now.pos.first, now.pos.second);
                if(res) --cnt;
                //printf("cnt: %d\n", cnt);
                if(cnt == 1) break;
            }

            if(cnt == 1){
                ans = min(ans, ma - mi);
                //printf("ans: %d\n",ans);
                continue;
            }
            else break;
        }
        if(ans == 0x3f3f3f3f) pd(-1);
        else pd(ans);
    }
    
    return 0;
}