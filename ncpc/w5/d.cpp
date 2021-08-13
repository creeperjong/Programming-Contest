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
    double len;
    edge(pii _pos, double _len){pos = _pos; len = _len;}
    bool operator<(const edge _b) const{
        return len > _b.len;
    }
};

int t,ss,p,x,y,s[MAXLEN];

double findDis(pii p1, pii p2){
    return sqrt((p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second));
}

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
        sd(ss), sd(p);
        priority_queue<edge> pq;
        vector<pii> pt;
        vector<double> ans;
        for(int i = 0;i < p;i++) s[i] = i;

        for(int i = 0;i < p;i++){
            sd(x), sd(y);
            pt.push_back({x,y});
        }
        for(int i = 0;i < p;i++){
            for(int j = i + 1;j < p;j++){
                pq.push(edge({i,j}, findDis(pt[i], pt[j])));
            }
        }
        while(!pq.empty()){
            edge now = pq.top();
            pq.pop();
            bool res = Union(now.pos.first, now.pos.second);
            if(res) ans.push_back(now.len);
        }
        printf("%.2lf\n", ans[ans.size() - ss]);
    }
    
    return 0;
}