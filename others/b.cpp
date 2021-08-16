#include <bits/stdc++.h>
#define MAXLEN (1000000000 + 5)
#define pd(x) printf("%d\n", x)
#define sd(x) scanf("%d", &x)
#define nl printf("\n")
#define ll long long
#define pii pair<int, int>

using namespace std;

int a,odd=0,even=0,cnt=1;

int main(){
    
    sd(a);
    while(a != 0){
        int tmp = a % 10;
        if(cnt & 1) odd += tmp;
        else even += tmp;
        
        ++cnt;
        a /= 10;
    }

    pd(abs(odd - even));
    
    return 0;
}