#include <bits/stdc++.h>
#define MAXLEN (1000000000 + 5)
#define pd(x) printf("%d\n", x)
#define sd(x) scanf("%d", &x)
#define nl printf("\n")
#define ll long long
#define pii pair<int, int>

using namespace std;

int a,b,ans;

int main(){
    
    cin >> a >> b >> ans;

    if((bool)(a & b) == ans) printf("AND\n");
    if((bool)(a | b) == ans) printf("OR\n");
    if((bool)(a ^ b) == ans) printf("XOR\n");
    
    return 0;
}