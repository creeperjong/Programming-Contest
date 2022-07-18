#include <bits/stdc++.h>
#define MAXLEN (1000000000 + 5)
#define pd(x) printf("%lld\n", x)
#define sd(x) scanf("%lld", &x)
#define nl printf("\n")
#define ll long long
#define pii pair<int, int>

using namespace std;

ll n,tc;

int main(){
    
    sd(tc);
    while(tc--){
        sd(n);
        pd(n * (n+1) ^ (n+1));
    }
    
    return 0;
}