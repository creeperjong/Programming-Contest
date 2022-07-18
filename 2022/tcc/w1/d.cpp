#include <bits/stdc++.h>

using namespace std;

int main(){

    int n,k;
    while(~scanf("%d %d", &n, &k)){
        char c;
        priority_queue<int, vector<int>, greater<int>> pq;
        while(n--){
            getchar();
            c = getchar();
            if(c == 'I'){
                int x;
                scanf("%d", &x);
                if(pq.size() == k){
                    int now = pq.top();
                    if(x > now){
                        pq.pop();
                        pq.push(x);
                    }
                }
                else pq.push(x);
            }
            else printf("%d\n", pq.top());
        }
    }

    return 0;
}