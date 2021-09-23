#include <bits/stdc++.h>
#define MAXLEN (10000 + 5)
#define pd(x) printf("%d\n", x)
#define sd(x) scanf("%d", &x)
#define nl printf("\n")
#define ll long long
#define pii pair<int, int>

using namespace std;

struct sc {
    int a,b,c,id;
    bool operator<(sc bb) const {
        return (a == bb.a) ? b > bb.b : a > bb.a;
    }
    sc(): a(0), b(0), c(0){}
} score[MAXLEN];

int tc,n,s,k,m,a,b,tmp,q,rk[MAXLEN];

int main(){
    
    scanf("%d", &tc);
    while(tc--){
        memset(score, 0, sizeof(score));
        scanf("%d %d %d %d %d %d", &n, &s, &k, &m, &a, &b);
        for(int i = 0;i < n;i++){
            score[i].id = i;
            for(int j = 0;j < k;j++){
                scanf("%d", &tmp);
                if(tmp >= a) ++score[i].a;
                else if(tmp >= b) ++score[i].b;
                else ++score[i].c; 
            }
        }
        sort(score, score + n);
        int nowR = 0, pre = 0;
        rk[score[0].id] = 0;
        for(int i = 1;i < n;i++){
            if(score[i].a == score[pre].a && score[i].b == score[pre].b) rk[score[i].id] = rk[score[pre].id], ++nowR;
            else rk[score[i].id] = ++nowR, pre = i;
        }
        while(s--){
            scanf("%d", &q);
            printf("%d%c", rk[q-1], s ? ' ' : '\n');
        }
    }
    
    return 0;
}