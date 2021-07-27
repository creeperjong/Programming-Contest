#include <bits/stdc++.h>
#define MAXLEN (10 + 5)
#define pd(x) printf("%d\n", x)
#define sd(x) scanf("%d", &x)
#define nl printf("\n")
#define ll long long
#define pii pair<int, int>

using namespace std;

int totalCase,n,rd[MAXLEN] = {0},sum[MAXLEN] = {0},num = 10;
bool vis[MAXLEN] = {0};
vector<int> adjList[MAXLEN];
string str;

void init(){
    num = 10;
    memset(rd, 0, sizeof(rd));
    memset(sum, 0 ,sizeof(sum));
    memset(vis, 0, sizeof(vis));
    for(int i = 0;i < MAXLEN;i++) adjList[i].clear();
}

int main(){
    
    sd(totalCase);
    while(totalCase--){

        init();

        sd(n);
        cin >> str;
        int cnt = 0;
        for(int i = 1;i <= n;i++){
            for(int j = i;j <= n;j++){
                if(str[cnt] == '+') adjList[j].push_back(i-1), ++rd[i-1];
                if(str[cnt] == '-') adjList[i-1].push_back(j), ++rd[j];
                ++cnt;
            }
        }
        
        queue<int> q;
        for(int i = 0;i <= n;i++){
            if(rd[i] == 0) q.push(i), vis[i] = true, sum[i] = num;
        }
        --num;
        while(!q.empty()){
            int now = q.front(), flag = 0;
            q.pop();

            for(int adj : adjList[now]){
                if(!vis[adj]){
                    --rd[adj];
                    if(!rd[adj]) q.push(adj), sum[adj] = num, vis[adj] = true, flag = 1;
                }
            }

            if(flag) --num;
        }
        // for(int i = 0;i <= n;i++) printf("%d ", sum[i]);
        // nl;

        printf("%d", sum[1] - sum[0]);
        for(int i = 2;i <= n;i++) printf(" %d", sum[i] - sum[i-1]);
        nl;
    }
    
    return 0;
}