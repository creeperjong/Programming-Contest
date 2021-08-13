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

int n,x,y,s[MAXLEN],cnt=0;
double ans;
vector<pair<double,double>> pt;

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
    
    while(cin >> n && n != 0){
        priority_queue<edge> pq;
        pt.clear();
        ans = 0;

        for(int i = 0;i < n;i++){
            scanf("%d %d", &x, &y);
            pt.push_back({x,y});;
        }
        for(int i = 0;i < n;i++){
            for(int j = i + 1;j < n;j++){
                pq.push(edge({i,j}, findDis(pt[i], pt[j])));
            }
        }
        for(int i = 0;i < n;i++) s[i] = i;
        while(!pq.empty()){
            edge now = pq.top();
            ans = now.dis;
            pq.pop();
            bool res = Union(now.point.first, now.point.second);
            if(res){
                if(find(0) == find(1)) break;
            }
        }

        printf("Scenario #%d\n",++cnt);
        printf("Frog Distance = %.3lf\n\n",ans);
    }
    
    return 0;
}