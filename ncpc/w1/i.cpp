#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, d, r;
    while(cin >> n >> d >> r && (n  || d  || r )){
        int morning[n], evening[n], ans = 0;
        for(int i = 0;i < n;i++) cin >> morning[i];
        for(int i = 0;i < n;i++) cin >> evening[i];
        sort(morning, morning + n);
        sort(evening, evening + n);
        for(int i = 0;i < n;i++){
            int dis = morning[i] + evening[n - 1 - i];
            ans += (dis > d) ? (dis - d) * r : 0;
        }
        cout << ans << endl;
    }
    return 0;
}