#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin >> t;
    string s;
    getchar();
    while(t--){
        char c;
        string tmp;
        while((c = getchar()) != '\n'){
            if(c == ' '){
                reverse(tmp.begin(), tmp.end());
                cout << tmp << ' ';
                tmp.clear();
            }
            else tmp += c;
        }
        reverse(tmp.begin(), tmp.end());
        cout << tmp << endl;
    }

    return 0;
}