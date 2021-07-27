#include <bits/stdc++.h>
#define MAXLEN (100 + 5)
#define pd(x) printf("%d\n", x)
#define sd(x) scanf("%d", &x)
#define ll long long
#define pii pair<int, int>

using namespace std;

int n,m,s,e;
bool vis[MAXLEN] = {0};
vector<int> ans;

void dfs(int s, vector<int>* adjList){
    vis[s] = true;
    for(int i : adjList[s]){
        if(!vis[i]) dfs(i, adjList);
    }
    ans.push_back(s);
}

int main(){
    
    while(cin >> n >> m && (n != 0 || m != 0)){
        vector<int> adjList[MAXLEN];
        memset(vis, 0, sizeof(vis));
        ans.clear();
        while(m--){
            sd(s), sd(e);
            adjList[s].push_back(e);
        }
        for(int i = 1;i <= n;i++){
            if(!vis[i]) dfs(i, adjList);
        }
        for(int i = ans.size() - 1;i >= 0;i--) printf("%d ", ans[i]);
        printf("\n");
    }

    
    return 0;
}