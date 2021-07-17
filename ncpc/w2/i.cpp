#include <bits/stdc++.h>
#define MAXLEN 1000 + 5
#define pii pair<int, int>
using namespace std;

struct node{
    pii pos;
    int val;
    node(pii _pos, int _val) : pos(_pos), val(_val){}
};

int n, m, req;
int year[100005] = {0};
const int dirR[] = {1 ,-1, 0, 0};
const int dirC[] = {0 , 0, 1, -1};
vector<int> res;
vector<node> islandArr;
pii s[MAXLEN][MAXLEN];

bool cmp(const node& a, const node& b){
    return a.val < b.val;
}

void init(){
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++) s[i][j] = {-1, -1};
    }
    res.clear();
    islandArr.clear();
}

pii find(pii x){
    if(x.first == -1 || x.second == -1) return x;
    if(x == s[x.first][x.second]) return x;
    else return s[x.first][x.second] = find(s[x.first][x.second]);
}

void Union(pii x, pii y, int& ans){
    pii fx = find(x);
    pii fy = find(y);
    if(fx.first != fy.first || fx.second != fy.second) s[fx.first][fx.second] = fy, --ans;
}

int main(){

    int totalCase;
    scanf("%d", &totalCase);
    while(totalCase--){
        scanf("%d %d", &n, &m);
        init();
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                int p;
                scanf("%d", &p);
                islandArr.push_back(node({i ,j}, p));
            }
        }
        sort(islandArr.begin(), islandArr.end(), cmp);
        
        scanf("%d", &req);
        for(int i = 0;i < req;i++) scanf("%d", &year[i]);
        
        int preAns = 0;
        for(int i = req - 1;i >= 0;i--){
            int ans = preAns;
            while(!islandArr.empty() && islandArr.back().val > year[i]){
                node now = islandArr.back();
                islandArr.pop_back();

                s[now.pos.first][now.pos.second] = now.pos;
                ++ans;
                for(int j = 0;j < 4;j++){
                    int adjR = now.pos.first + dirR[j], adjC = now.pos.second + dirC[j];
                    if(adjR >= 0 && adjR < n && adjC >= 0 && adjC < m && s[adjR][adjC].first != -1 && s[adjR][adjC].second != -1){
                        Union(now.pos, {adjR, adjC}, ans);
                        //printf("%d %d union %d %d\n", now.pos.first, now.pos.second, adjR, adjC);
                    }
                    //printf("%d %d ans: %d\n", now.pos.first, now.pos.second, ans);
                }
            }
            res.push_back(ans);
            preAns = ans;
        }

        for(int i = res.size() - 1;i >= 0;i--){
            printf("%d ", res[i]);
        }
        printf("\n");

    }

    return 0;
}