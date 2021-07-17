#include <bits/stdc++.h>
using namespace std;

pair<int, int> table[26];

int main(){

    int totalCase;
    scanf("%d", &totalCase);

    while(totalCase--){
        char name;
        int r,c;
        cin >> name >> r >> c;
        table[name - 'A'] = {r,c};
    }

    string input;

    while(cin >> input){
        vector<pair<int, int>> stk;
        int ans = 0;

        for(char i : input){
            if(i == '(') stk.push_back({-1, -1});
            else if(i == ')'){
                pair<int, int> s = stk.back();
                stk.pop_back();
                pair<int, int> f = stk.back();
                stk.pop_back();
                stk.pop_back();
                
                if(f.second != s.first){
                    ans = -1;
                    break;
                }
                else{
                    ans += f.first * f.second * s.second;
                    stk.push_back({f.first, s.second});
                }
            }
            else stk.push_back(table[i - 'A']);
        }

        if(ans == -1) printf("error\n");
        else printf("%d\n", ans);
    }

    return 0;
}