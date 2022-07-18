#include <bits/stdc++.h>
#define MAXLEN (1000 + 5)
#define pd(x) printf("%d\n", x)
#define sd(x) scanf("%d", &x)
#define nl printf("\n")
#define ll long long
#define pii pair<int, int>

using namespace std;

int tc,n,tmp;

int main(){
    
    sd(tc);
    while(tc--){
        int ans = 0;
        priority_queue<int, vector<int>, greater<int> > pq;
        sd(n);
        while(n--) sd(tmp), pq.push(tmp);
        while(pq.size() > 1){
            int top1 = pq.top(); pq.pop();
            int top2 = pq.top(); pq.pop();
            ans += top1 + top2, pq.push(top1 + top2);
        }
        pd(ans);
    }
    
    return 0;
}