#include <bits/stdc++.h>
using namespace std;

int main(){

    int totalCase;
    cin >> totalCase;
    while(totalCase--){
        int num;
        multiset<int> addr;

        cin >> num;
        for(int i = 0;i < num;i++){
            int input;
            cin >> input;
            addr.insert(input);
        }

        multiset<int>::iterator it = addr.begin();
        for(int i = 0;i < (num - 1) / 2;i++) it++;
        int house = *it;
        int ans = 0;

        for(it = addr.begin();it != addr.end();it++){
            ans += abs(*it - house);
        }
        cout << ans << endl;
    }

    return 0;
}