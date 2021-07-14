#include <bits/stdc++.h>
using namespace std;

bool cmp(const pair<double, double> a, const pair<double, double> b){
    return (a.first != b.first) ? (a.first < b.first) : (a.second < b.second);
}

// 19 5 27 cause inf loop

int main(){

    int n, l, w;
    while(cin >> n >> l >> w){
        vector<pair<double, double>> sprayer;
        for(int i = 0;i < n;i++){
            double pos, rad;
            double le, re;
            cin >> pos >> rad;
            if(rad * 2 <= w) continue;
            le = pos - sqrt(rad * rad - (w / 2.0) * (w / 2.0));
            re = pos + sqrt(rad * rad - (w / 2.0) * (w / 2.0));
            sprayer.push_back({le, re});
        }
        //for(auto i : sprayer) cout << i.first << " " << i.second << endl;
        sort(sprayer.begin(), sprayer.end(), cmp);
        //for(auto i : sprayer) cout << i.first << " " << i.second << endl;


        int nowIdx = -1;
        double nowR = 0;
        int cnt = 0;

        while(nowR < l){
            //cout << nowIdx << endl;
            double maxR = INT_MIN;
            int maxIdx = -1;

            for(int i = nowIdx + 1;i < sprayer.size() && sprayer[i].first <= nowR;i++){
                if(maxR < sprayer[i].second){
                    maxR = sprayer[i].second;
                    maxIdx = i;
                }
            }
            if(maxIdx == nowIdx || maxIdx == -1){
                cnt = -1;
                break;
            }
            nowIdx = maxIdx;
            nowR = maxR;
            ++cnt;
        }
        if(cnt == 0) cout << -1 << endl;
        else cout << cnt << endl;
    }

    return 0;
}