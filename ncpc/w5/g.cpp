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

int t,n,m,a,x,y,c,ans,sum=0,s[MAXLEN];

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
        sd(n), sd(m), sd(a);
        ans = n,sum = 0;
        priority_queue<edge> pq;
        for(int i = 1;i <= n;i++) s[i] = i;

        for(int i = 0;i < m;i++){
            sd(x), sd(y), sd(c);
            pq.push(edge({x,y}, c));
        }
        while(!pq.empty()){
            edge now = pq.top();
            pq.pop();
            if(now.len >= a) break;
            bool res = Union(now.pos.first, now.pos.second);
            if(res) --ans, sum += now.len;
        }
        sum += ans * a;
        printf("Case #%d: %d %d\n", ti, sum, ans);
    }
    
    return 0;
}