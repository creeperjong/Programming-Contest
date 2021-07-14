#include <bits/stdc++.h>
using namespace std;

int se[26] = {0};
int so[26] = {0};

int main(){

    string ori, enc;
    while(cin >> enc >> ori){
        
        memset(se, 0, sizeof(se));
        memset(so, 0, sizeof(so));

        for(char i : enc) ++se[i - 'A'];
        for(char i : ori) ++so[i - 'A'];
        
        sort(se, se+26);
        sort(so, so+26);
        
        bool ans = true;
        for(int i = 0;i < 26;i++){
            if(se[i] != so[i]){
                ans = false;
                break;
            }
        }

        //for(int i = 0;i < 26;i++) cout << se[i] << so[i] << endl;

        if(ans) cout << "YES\n";
        else cout << "NO\n";
    }
    
    return 0;
}