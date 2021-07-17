#include <bits/stdc++.h>
using namespace std;

int main(){

    int totalCase;
    scanf("%d", &totalCase);
    getchar();
    while(totalCase--){
        string str;
        vector<char> stk;
        bool ans = true;

        getline(cin, str);
        for(char i : str){
            if(i == '(') stk.push_back(')');
            else if(i == '[') stk.push_back(']');
            else{
                if(!stk.empty() && stk.back() == i) stk.pop_back();
                else{
                    ans = false;
                    break;
                }
            }
        }
        if(ans && stk.empty()) printf("Yes\n");
        else printf("No\n");
    }

    return 0;
}