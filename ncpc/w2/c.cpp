#include <bits/stdc++.h>
using namespace std;

int main(){

    int totalCase;
    scanf("%d", &totalCase);
    while(totalCase--){
        int n,my, time = 0;
        deque<pair<int, bool>> q;

        cin >> n >> my;
        for(int i = 0;i < n;i++){
            int tmp;
            scanf("%d", &tmp);
            if(my == i) q.push_back({tmp, true});
            else q.push_back({tmp, false});
        }

        while(!q.empty()){
            pair<int, bool> now = q.front();
            q.pop_front();

            bool continueFlag = false;
            for(int i = 0;i < q.size();i++){
                if(now.first < q[i].first){
                    q.push_back(now);
                    continueFlag = true;
                    break;
                }
            }
            if(continueFlag) continue;

            if(now.second){
                printf("%d\n", ++time);
                break;
            }
            else ++time;
        }
    }

    return 0;

}