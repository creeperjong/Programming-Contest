#include <bits/stdc++.h>
#define MAXLEN (1000 + 5)
#define pd(x) printf("%d\n", x)
#define sd(x) scanf("%d", &x)
#define nl printf("\n")
#define ll long long
#define pii pair<int, int>

using namespace std;

struct sub {
    int price;
    vector<int> ct;
} subntw[10];

struct edge {
    pii pos;
    int dis;
    edge(pii _pos, int _dis){pos = _pos; dis = _dis;}
    bool operator<(const edge _b) const{
        return dis > _b.dis;
    }
};

int t,n,q,ctn,c,x,y,s[MAXLEN];
vector<pii> city;

int findDis(pii p1, pii p2){
    return (p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second);
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
        city.clear(), city.push_back({-1,-1});
        
        priority_queue<edge> pqTmp;
        int ans = 0x3f3f3f3f;

        sd(n), sd(q);
        for(int i = 0;i < q;i++){
            subntw[i].ct.clear();
            sd(ctn), sd(subntw[i].price);
            for(int j = 0;j < ctn;j++){
                sd(c);
                subntw[i].ct.push_back(c);
            }
        }
        
        for(int i = 0;i < n;i++){
            sd(x), sd(y);
            city.push_back({x,y});
        }

        for(int i = 1;i <= n;i++){
            for(int j = i + 1;j <= n;j++){
                pqTmp.push(edge({i, j}, findDis(city[i], city[j])));
            }
        }

        for(int choice = 0;choice < (1 << q);choice++){
            priority_queue<edge> pq(pqTmp);
            int sum = 0;
            for(int j = 1;j <= n;j++) s[j] = j;

            for(int j = 0;j < q;j++){
                unsigned int mask = (1 << j);
                if(choice & mask){
                    for(int k : subntw[j].ct) Union(subntw[j].ct[0], k);
                    sum += subntw[j].price;
                }
            }

            while(!pq.empty()){
                edge now = pq.top();
                pq.pop();
                bool res = Union(now.pos.first, now.pos.second);
                if(res) sum += now.dis;
            }
            ans = min(ans, sum);
        }
        printf("%d\n%c",ans,t ? '\n' : 0);
    }
    
    return 0;
}