#include <bits/stdc++.h>
#define MAXLEN (200 + 5)
#define pd(x) printf("%d\n", x)
#define sd(x) scanf("%d", &x)
#define nl printf("\n")
#define ll long long
#define pii pair<int, int>

using namespace std;

int n,l,s,e;
int vis[MAXLEN] = {0};
bool ans = true;

void dfs(int st, vector<int>* adjList){
    for(int i : adjList[st]){
        if(!vis[i]){
            vis[i] = (vis[st] == 1) ? 2 : 1;
            dfs(i, adjList);
        }
        else{
            if(vis[i] == vis[st]) ans = false;
        }
    }
}

int main(){
    
    while(cin >> n && n != 0){
        vector<int> adjList[MAXLEN];
        memset(vis, 0, sizeof(vis));
        ans = true;

        sd(l);
        while(l--){
            sd(s), sd(e);
            adjList[s].push_back(e);
            adjList[e].push_back(s);
        }

        vis[0] = 1;
        dfs(0, adjList);

        if(ans) printf("BICOLORABLE.\n");
        else printf("NOT BICOLORABLE.\n");
    }
    
    return 0;
}