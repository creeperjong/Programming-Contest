#include <bits/stdc++.h>
#define MAXLEN (10000 + 5)
#define pd(x) printf("%d\n", x)
#define sd(x) scanf("%d", &x)
#define nl printf("\n")
#define ll long long
#define pii pair<int, int>

using namespace std;

int n,s,e,ans = 0;
vector<int> adjList[MAXLEN];

int dfs(int now){
    if(adjList[now].empty()) return 0;
    int d1 = 0,d2 = 0;
    for(int adj : adjList[now]){
        int w = dfs(adj) + 1;
        if(w > d1) d2 = d1, d1 = w;
        else if(w > d2) d2 = w;
    }
    ans = max(ans, d1 + d2);
    return max(d1, d2);
}

int main(){
    
    sd(n);
    for(int i = 0;i < n-1;i++){
        sd(s), sd(e);
        adjList[s].push_back(e);
    }
    dfs(1);
    pd(ans);
    
    return 0;
}