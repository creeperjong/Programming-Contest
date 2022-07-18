#include <bits/stdc++.h>

using namespace std;

int main(){

    bool hasAns = true;
    int input, l = 1, r = 10;
    string s;
    while(cin >> input && input){
        getchar();
        getline(cin ,s);
        if(s[4] == 'h'){
            if(input <= l) hasAns = false;
            else r = min(r, input-1);
        }
        else if(s[4] == 'l'){
            if(input >= r) hasAns = false;
            else l = max(l, input+1);
        }
        else{
            if(input < l || input > r) hasAns = false;

            if(hasAns) cout << "Stan may be honest\n";
            else cout << "Stan is dishonest\n";
            l = 1, r = 10, hasAns = true;
        }
    }

}