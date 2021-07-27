#include <bits/stdc++.h>
#define MAXLEN (13 + 5)
#define pd(x) printf("%d\n", x)
#define sd(x) scanf("%d", &x)
#define nl printf("\n")
#define ll long long
#define pii pair<int, int>

using namespace std;

vector<int> ans;
int k,arr[MAXLEN] = {0}, isFirst = 1;

void dfs(int n, int layer){
    if(layer == 6){
        for(int i = 0;i < ans.size()-1;i++) printf("%d ", ans[i]);
        pd(ans[ans.size()-1]);
        return;
    }
    for(int i = n;i < k;i++){
        ans.push_back(arr[i]);
        dfs(i+1,layer+1);
        ans.pop_back();
    }
}

int main(){
    
    while(cin >> k && k != 0){
        for(int i = 0;i < k;i++) sd(arr[i]);
        if(isFirst) isFirst = 0;
        else printf("\n");
        dfs(0, 0);
    }
    
    return 0;
}