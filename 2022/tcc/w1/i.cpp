#include <bits/stdc++.h>
#define MAXLEN 150000+5
using namespace std;

class Guest {
public:
    int pri = 0;
    int val = 0;
    char name[205] = {0};
    bool operator< (const Guest& rhs) const{
        return val == rhs.val ? pri > rhs.pri : val < rhs.val;
    }
};

Guest arr[MAXLEN];
int ans[MAXLEN];
pair<int, int> rule[MAXLEN];

int main(){

    int tc,n,m,q,v,t,p;
    scanf("%d", &tc);
    while(tc--){
        int ansCnt = 0;
        memset(ans, 0, sizeof(ans));
        scanf("%d %d %d", &n, &m, &q);
        for(int i = 0;i < n;++i){
            scanf("%s %d", arr[i].name, &arr[i].val);
            arr[i].pri = i;
        }
        priority_queue<Guest> pq;
        int now = 0;
        for(int i = 0;i < m;++i){
            scanf("%d %d", &t, &p);
            rule[i] = {t, p};
        }
        sort(rule, rule+m);
        for(int i = 0;i < m;++i){
            t = rule[i].first, p = rule[i].second;
            for(;now < t;++now) pq.push(arr[now]);
            while(p-- && !pq.empty()){
                Guest cur = pq.top(); pq.pop();
                ans[ansCnt++] = cur.pri;
            }
        }
        for(;now < n;++now) pq.push(arr[now]);
        while(!pq.empty()){
            Guest cur = pq.top(); pq.pop();
            ans[ansCnt++] = cur.pri;
        }
        while(q--){
            scanf("%d", &now);
            printf("%s", arr[ans[now-1]].name);
            if(q) printf(" ");
            else printf("\n");
        }

    }

    return 0;
}