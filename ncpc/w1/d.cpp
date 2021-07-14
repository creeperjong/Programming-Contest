#include <bits/stdc++.h>
using namespace std;

int main(){

    int x;
    int l = 1;
    int r = 10;
    bool honest = true;
    while(cin >> x && x != 0){
        string mes;
        cin >> mes >> mes;

        if(mes[0] == 'h'){
            if(x <= r) r = x - 1;
        }
        else if(mes[0] == 'l'){
            if(x >= l) l = x + 1;
        }
        else{
            if(x < l || x > r) honest = false;

            if(honest) cout << "Stan may be honest\n";
            else cout << "Stan is dishonest\n";
            l = 1;
            r = 10;
            honest = true;
        }
        
        if(l > r) honest = false;
    }

    return 0;
}