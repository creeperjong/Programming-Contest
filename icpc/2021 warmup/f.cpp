#include <bits/stdc++.h>
#define MAXLEN (1000000000 + 5)
#define pd(x) printf("%d\n", x)
#define sd(x) scanf("%d", &x)
#define nl printf("\n")
#define ll long long
#define pii pair<int, int>

using namespace std;

struct tr {
    int x,y,z;
    bool operator<(const tr& b) const{
        if(x == b.x){
            if(y == b.y){
                if(z == b.z) return false;
                else return z < b.z;
            }
            else return y < b.y;
        }
        else return x < b.x;
    }
    bool operator==(const tr& b) const{
        return x == b.x && y == b.y && z == b.z;
    }
    tr(int _x, int _y, int _z): x(_x), y(_y), z(_z){}
};

int m,n,s,w,x,y,z;
vector<tr> arr;

void gen(){
    int g = s;
    for(int i = 0;i < n;i++){
        x = (g / 7) % 100 + 1;
        y = (g / 700) % 100 + 1;
        z = (g / 70000) % 100 + 1;
        if(g % 2 == 0) g /= 2;
        else g = (g / 2) ^ w;
        arr.push_back(tr(x,y,z));
    }
}

double solver(int i, int j){
    tr a = arr[i], b = arr[j];
    int x1 = a.x, y1 = a.y, z1 = a.z;
    int x2 = b.x, y2 = b.y, z2 = b.z;
    return abs((x1 * x2 + y1 * y2 + z1 * z2) * 1.0) / sqrt(1.0 * x1 * x1 + y1 * y1 + z1 * z1) / sqrt(1.0 * x2 * x2 + y2 * y2 + z2 * z2);
}

bool cmp(pii a, pii b){
    return arr[a.first] == arr[b.first] ? (arr[a.second] < arr[b.second]) : (arr[a.first] < arr[b.first]);
}

int main(){
    
    while(scanf("%d %d %d %d", &m, &n, &s, &w) && (m || n || s || w)){
        arr.clear();
        for(int i = 0;i < m;i++){
            scanf("%d %d %d", &x, &y, &z);
            arr.push_back(tr(x,y,z));
        }
        gen();
        double tmp,ma = -2;
        pii rec;
        for(int i = 0;i < m+n;i++){
            printf("%d %d %.10lf\n",i, i, tmp);
            for(int j = i + 1;j < m+n;j++){
                tmp = solver(i, j);
                
                if(abs(tmp - 1.0) > 1e-8){
                    if(tmp > ma){
                        ma = tmp;
                        rec = make_pair(i ,j);
                    }
                    else if(abs(tmp - ma) < 1e-8 && cmp({i, j}, rec)){
                        ma = tmp;
                        rec = make_pair(i, j);
                    }
                }
            }
        }
        int i = rec.first, j = rec.second;
        printf("%d %d %d %d %d %d\n", arr[i].x, arr[i].y, arr[i].z, arr[j].x, arr[j].y, arr[j].z);
    }
    
    return 0;
}