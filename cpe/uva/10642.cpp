#include <bits/stdc++.h>
#define MAXLEN (1000000000 + 5)
#define pd(x) printf("%d\n", x)
#define sd(x) scanf("%d", &x)
#define nl printf("\n")
#define ll long long
#define pii pair<int, int>

using namespace std;


int main(){
    
    int tc,x1,y1,x2,y2,l1,l2,d1,d2;
    sd(tc);
    for(int t = 1;t <= tc;t++){
        int ans = 0;
        sd(x1), sd(y1), sd(x2), sd(y2);
        l1 = x1 + y1, l2 = x2 + y2;
        if(l1 == l2){
            printf("Case %d: %d\n", t, y1 - y2);
            continue;
        }
        else{
            for(int i = l1 + 1;i < l2;i++) ans += i + 1;
            d1 = l1 - x1, d2 = l2 - y2;
            printf("Case %d: %d\n",t , d1 + d2 + ans + 1); 
        }
    }
    
    return 0;
}