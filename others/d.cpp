#include <bits/stdc++.h>
#define MAXLEN (100 + 5)
#define pd(x) printf("%d\n", x)
#define sd(x) scanf("%d", &x)
#define nl printf("\n")
#define ll long long
#define pii pair<int, int>

using namespace std;

int n,arr[MAXLEN],s[MAXLEN],cnt;

void init(){
    for(int i = 0;i < n;i++) s[i] = i;
}

int find(int x){
    if(x == s[x]) return x;
    else return s[x] = find(s[x]);
}

bool Union(int a, int b){
    int fa = find(a);
    int fb = find(b);
    if(fa != fb){
        s[fa] = fb;
        return true;
    }
    return false;
}

int main(){
    
    cin >> n;
    init();
    cnt = n;
    for(int i = 0;i < n;i++){
        sd(arr[i]);
        bool res = Union(i, arr[i]);
        if(res) --cnt;
    }
    pd(cnt);
    
    return 0;
}