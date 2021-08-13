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

int t,n,r,c1,c2,d,sum=0,ans=0,s[MAXLEN];

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
    while(t--){
        sd(n), sd(r);
        priority_queue<edge> pq;
        for(int i = 0;i < n;i++) s[i] = i;
        ans = 0, sum = 0;

        for(int i = 0;i < r;i++){
            sd(c1), sd(c2), sd(d);
            pq.push(edge({c1,c2}, d));
            sum += d;
        }
        while(!pq.empty()){
            edge now = pq.top();
            pq.pop();
            bool res = Union(now.pos.first, now.pos.second);
            if(res) ans += now.len;
        }
        pd(sum-ans);
    }
    
    return 0;
}