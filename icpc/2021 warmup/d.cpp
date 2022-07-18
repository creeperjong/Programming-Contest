#include <bits/stdc++.h>
#define MAXLEN (1000000000 + 5)
#define pd(x) printf("%d\n", x)
#define sd(x) scanf("%d", &x)
#define nl printf("\n")
#define ll long long
#define pii pair<int, int>

using namespace std;

int H,h,m,s;
vector<pii> opt;

int gcd(int a, int b){
    if(b){
        while((a %= b) && (b %= a));
    }
    return a + b;
}

void makeopt(){
    int nn = 3600 * h + 60 * m - 60 * m * H;
    int dd = H - 1, GCD;
    if(nn >= 0){
        GCD = gcd(nn, dd);
        nn /= GCD, dd /= GCD;
    }
    int n,d;
    for(int i = 0;i < 3;i++){
        if(i == 0) n = 3600 * (h - H) + 60 * m * (H + 1);
        if(i == 1) n = 3600 * h + 60 * m * (H + 1);
        if(i == 2) n = 3600 * (h + H) + 60 * m * (H + 1);
        d = 119 * H - 1;
        if(n >= 0){
            GCD = gcd(n, d);
            n /= GCD, d /= GCD;
        }
        else continue;
        if((n != nn || d != dd) && n / d < 60) opt.push_back({n,d});
    }
    int tmpm = m, tmph = h;
    m += 1, h = (h + (m / 60)) % H, m %= 60;
    nn = 3600 * h + 60 * m - 60 * m * H;
    dd = H - 1;
    if(nn >= 0){
        GCD = gcd(nn, dd);
        nn /= GCD, dd /= GCD;
    }
    for(int i = 0;i < 3;i++){
        if(i == 0) n = 3600 * (h - H) + 60 * m * (H + 1);
        if(i == 1) n = 3600 * h + 60 * m * (H + 1);
        if(i == 2) n = 3600 * (h + H) + 60 * m  * (H + 1);
        d = 119 * H - 1;
        if(n >= 0){
            GCD = gcd(n, d);
            n /= GCD, d /= GCD;
        }
        else continue;
        if((n != nn || d != dd) && n / d < 60){
            opt.push_back({n,d});
            h = tmph, m = tmpm;
            break;
        }
    }
}

int main(){
    
    while(scanf("%d %d %d %d", &H, &h, &m, &s) && (H || h || m || s)){
        opt.clear();
        makeopt();
        for(int i = 0;i < opt.size();i++){
            if(i == opt.size() - 1){
                m += 1, h = (h + (m / 60)) % H, m %= 60;
                printf("%d %d %d %d\n", h, m , opt[i].first, opt[i].second);
            }
            else{
                if(opt[i].first / opt[i].second >= s){
                    printf("%d %d %d %d\n", h, m, opt[i].first, opt[i].second);
                    break;
                }
            }
        }
    }   
    
    return 0;
}