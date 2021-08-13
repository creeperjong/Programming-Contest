#include <bits/stdc++.h>
#define MAXLEN (1000 + 5)
#define pd(x) printf("%d\n", x)
#define sd(x) scanf("%d", &x)
#define nl printf("\n")
#define ll long long
#define pii pair<int, int>

using namespace std;

struct edge {
    pii pos;
    int w;
    edge(pii _pos, int _w){pos = _pos; w = _w;}
    bool operator<(const edge _b) const{
        return w > _b.w;
    }
};

int t,n,m,k,a,b,c,ans=0,s[MAXLEN];

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
    
    sd(t);
    for(int ti = 1;ti <= t;ti++){
        sd(n);
        priority_queue<edge> pq;
        for(int i = 0;i <= n;i++) s[i] = i;
        ans = 0;

        sd(m), sd(k);
        for(int i = 0;i < k;i++){
            sd(a);
            Union(0, a);
            pq.push(edge({0,a}, 0));
        }
        for(int i = 0;i < m;i++){
            sd(a), sd(b), sd(c);
            pq.push(edge({a,b}, c));
        }

        printf("Case #%d: ", ti);
        while(!pq.empty()){
            edge now = pq.top();
            pq.pop();
            bool res = Union(now.pos.first, now.pos.second);
            if(res) ans += now.w;
        }
        pd(ans);
    }
    
    return 0;
}