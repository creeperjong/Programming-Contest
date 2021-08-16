#include <bits/stdc++.h>
#define MAXLEN (1000 + 5)
#define pd(x) printf("%d\n", x)
#define sd(x) scanf("%d", &x)
#define nl printf("\n")
#define ll long long
#define pii pair<int, int>

using namespace std;

int n,a,b,gcdNum,ma=-1,ans=0;
vector<pii> rec;
bool vis[MAXLEN] = {0},flag = false;

int gcd(int a, int b){
    if(b) while((a%=b) && (b%=a));
    return a + b;
}

int main(){
    
    sd(n);
    for(int i = 0;i < n;i++){
        sd(a), sd(b);
        gcdNum = gcd(gcdNum, gcd(a, b));
        rec.push_back({a,b});
    }
    for(auto itv : rec){
        int s = itv.first / gcdNum;
        int e = itv.second / gcdNum;
        ma = max(ma, e);
        for(int i = s;i <= e;i++) vis[i] = true;
    }
    for(int i = 0;i <= ma;i++){
        if(vis[i]){
            if(!flag) flag = true;
            else ++ans;
        }
        else{
            if(flag) flag = false;
        }
    }
    pd(ans * gcdNum);
    
    return 0;
}