#include <bits/stdc++.h>
#define MAXLEN (100 + 5)
#define pd(x) printf("%d\n", x)
#define sd(x) scanf("%d", &x)
#define nl printf("\n")
#define ll long long
#define pii pair<int, int>

using namespace std;

int n,t,to,ansVal = INT_MIN,ans,cnt;
bool vis[MAXLEN] = {0};

void dfs(int now, vector<int>* adjList){
    ++cnt;
    vis[now] = true;
    for(int i : adjList[now]){
        if(!vis[i]) dfs(i, adjList);
    }
}

int main(){
    
    while(cin >> n && n != 0){
        vector<int> adjList[MAXLEN];
        ansVal = INT_MIN;

        for(int i = 1;i <= n;i++){
            sd(t);
            while(t--) sd(to), adjList[i].push_back(to);
        }
        for(int i = 1;i <= n;i++){
            cnt = -1;
            memset(vis, 0, sizeof(vis));

            dfs(i, adjList);
            if(cnt > ansVal){
                ansVal = cnt;
                ans = i;
            }
        }
        pd(ans);
    }
    
    return 0;
}