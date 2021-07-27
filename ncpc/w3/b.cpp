#include <bits/stdc++.h>
#define MAXLEN (1000 + 5)
#define pd(x) printf("%d\n", x)
#define sd(x) scanf("%d", &x)
#define ll long long
#define pii pair<int, int>

using namespace std;

int totalCase,p,n,s,e,ans[MAXLEN] = {0};
bool adjMtx[MAXLEN][MAXLEN] = {0};
queue<int> q;

int main(){
    
    sd(totalCase);
    while(totalCase--){

        memset(adjMtx, 0, sizeof(adjMtx));
        memset(ans, 0, sizeof(ans));

        getchar();
        sd(p), sd(n);
        while(n--){
            sd(s), sd(e);
            adjMtx[s][e] = true, adjMtx[e][s] = true;
        }
 
        q.push(0);
        ans[0] = 0;

        while(!q.empty()){
            int now = q.front();
            q.pop();

            for(int i = 0;i < p;i++){
                if(adjMtx[now][i] && ans[i] == 0 && i != 0) q.push(i), ans[i] = ans[now] + 1;
            }
        }
        for(int i = 1;i < p;i++) pd(ans[i]);
        if(totalCase) printf("\n");
    }
    
    return 0;
}