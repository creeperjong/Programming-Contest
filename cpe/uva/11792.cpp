#include <bits/stdc++.h>

using namespace std;

int tc,n,s;
int d[10005];
vector<int> adjs[10005];

bool check(){
    int tmp = -1;
    for(int i = 1;i <= n;i++){
        if(d[i]){
            if(tmp == -1) tmp = d[i];
            else if(tmp != d[i]) return false;
        }
    }
    return true;
}

int main(){

    scanf("%d", &tc);
    while(tc--){
        printf("%d\n", tc);
        scanf("%d %d", &n, &s);
        memset(d, 0, sizeof(d));
        for(int i = 1;i <= n;i++) adjs[i].clear();
        for(int i = 0;i < s;i++){
            int pre = -1, tmp;
            while(scanf("%d", &tmp) && tmp){
                if(pre != -1){
                    bool flag = false;
                    for(int adj : adjs[tmp]){
                        if(adj == pre){
                            flag = true;
                            pre = tmp;
                            break;
                        }
                    }
                    if(flag) continue;
                    adjs[tmp].push_back(pre), adjs[pre].push_back(tmp);
                    ++d[tmp], ++d[pre];
                }
                pre = tmp;
            }
        }
        queue<int> q;
        int mi = 0x3f3f3f3f;
        int ccnt = 10;
        while(!check() && ccnt--){
            for(int i = 1;i <= n;i++) printf("%d ", d[i]);
            printf("\n");
            mi = 0x3f3f3f3f;
            for(int i = 1;i <= n;i++){
                if(d[i]) mi = min(mi, d[i]);
            }
            for(int i = 1;i <= n;i++){
                if(mi == d[i]){
                    q.push(i);
                    printf("%d ", i);
                }
            }
            printf("\n");
            while(!q.empty()){
                int now = q.front(); q.pop();
                d[now] -= mi;
                if(d[now] < 0) d[now] = 0;
                for(int adj : adjs[now]){
                    if(d[adj]) --d[adj];
                }
            }
        }
        for(int i = 1;i <= n;i++){
            if(d[i]){
                printf("Krochanska is in: %d\n", i);
                break;
            }
        }
    }

    return 0;
}