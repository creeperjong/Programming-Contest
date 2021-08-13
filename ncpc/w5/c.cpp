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
    int len;
    edge(pii _pos, int _len){pos = _pos; len = _len;}
    bool operator<(const edge _b) const{
        return len > _b.len;
    }
};

int t,n,d,s[MAXLEN];

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
        for(int i = 0;i < n;i++) s[i] = i;

        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                scanf("%d,",&d);
                if(d && j <= i) pq.push(edge({i, j}, d));
            }
        }
        printf("Case %d:\n", ti);
        while(!pq.empty()){
            edge now = pq.top();
            pq.pop();
            bool res = Union(now.pos.first, now.pos.second);
            if(now.pos.first > now.pos.second) swap(now.pos.first, now.pos.second);
            if(res) printf("%c-%c %d\n", now.pos.first + 'A', now.pos.second + 'A', now.len);
        }
    }
    
    return 0;
}