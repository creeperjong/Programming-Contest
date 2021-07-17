#include <bits/stdc++.h>
using namespace std;

int find(int x, int* s){
    if(x == s[x]) return x;
    else return s[x] = find(s[x], s);
}

int main(){

    int n, m, cnt = 0;
    while(cin >> n >> m && (n != 0 || m != 0)){
        int s[n + 1], a, b, ans = 0;
        for(int i = 1;i <= n;i++) s[i] = i;
        for(int i = 0;i < m;i++){
            scanf("%d %d", &a, &b);
            int fa = find(a, s);
            int fb = find(b, s);
            if(fa != fb) s[fa] = fb;
        }
        for(int i = 1;i <= n;i++){
            if(s[i] == i) ++ans;
        }
        printf("Case %d: %d\n", ++cnt, ans);
    }

    return 0;
}