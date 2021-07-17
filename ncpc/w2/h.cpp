#include <bits/stdc++.h>
#define MAXLEN 100000 + 5
using namespace std;

int s[MAXLEN];
int cnt[MAXLEN];
int sum[MAXLEN];
int id[MAXLEN];
int fake;

int find(int x){
    if(s[x] == x) return x;
    else return s[x] = find(s[x]);
}

void union_s(int x, int y){
    int fx = find(x);
    int fy = find(y);
    if(fx != fy){
        s[fx] = fy;
        sum[fy] += sum[fx];
        cnt[fy] += cnt[fx];
    }
}

void move(int x, int y){
    int fx = find(id[x]);
    int fy = find(id[y]);
    if(fx != fy){
        sum[fx] -= x;
        --cnt[fx];
        ++fake;
        id[x] = fake;
        s[fake] = fake;
        cnt[fake] = 1;
        sum[fake] = x;
        union_s(id[x], id[y]);
    }
}

int main(){

    int n, m, choice, p, q;
    while(cin >> n >> m){
        fake = n;
        for(int i = 1;i <= n;i++){
            sum[i] = id [i] = s[i] = i;
            cnt[i] = 1;
        }
        for(int i = 0;i < m;i++){
            scanf("%d", &choice);
            if(choice == 1){
                scanf("%d %d", &p, &q);
                union_s(id[p] ,id[q]);
            }
            if(choice == 2){
                scanf("%d %d", &p, &q);
                move(p, q);
            }
            if(choice == 3){
                scanf("%d", &p);
                int fx = find(id[p]);
                printf("%d %d\n", cnt[fx], sum[fx]);
            }
            // for(int i = 1;i <= n;i++) cout << s[i] << " ";
            // cout << endl;
        }
    }

    return 0;
}