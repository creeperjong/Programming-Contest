#include <bits/stdc++.h>
#define MAXLEN (100 + 5)
#define pd(x) printf("%d\n", x)
#define sd(x) scanf("%d", &x)
#define nl printf("\n")
#define ll long long
#define pii pair<int, int>

using namespace std;

struct edge {
    pii point;
    double dis;
    edge(pii _point, double _dis){point = _point;dis = _dis;}
    bool operator<(const edge _b) const{
        return dis > _b.dis;
    }
};

int t,n,s[MAXLEN];
double x,y,ans=0;
vector<pair<double,double>> pt;

double findDis(pair<double, double> p1, pair<double, double> p2){
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
        pt.clear();
        ans = 0;
        sd(n);
        for(int i = 0;i < n;i++){
            scanf("%lf %lf", &x, &y);
            pt.push_back({x,y});
        }
        priority_queue<edge> pq;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                if(i == j) continue;
                pq.push(edge({i,j}, findDis(pt[i], pt[j])));
            }
        }
        for(int i = 0;i < n;i++) s[i] = i;
        while(!pq.empty()){
            edge now = pq.top();
            pq.pop();
            bool res = Union(now.point.first, now.point.second);
            if(res) ans += now.dis;
        }
        printf("%.2lf\n",ans);
        if(t) printf("\n");
    }
    
    return 0;
}