#include <bits/stdc++.h>
using namespace std;

bool cmp(const pair<char, char> a, const pair<char, char> b){
    int a_val = 0, b_val = 0;
    if(a.first == 'C') a_val += 0;
    if(a.first == 'D') a_val += 13;
    if(a.first == 'S') a_val += 26;
    if(a.first == 'H') a_val += 39;
    if(b.first == 'C') b_val += 0;
    if(b.first == 'D') b_val += 13;
    if(b.first == 'S') b_val += 26;
    if(b.first == 'H') b_val += 39;

    pair<char, char> tmpA = a, tmpB = b;
    if(a.second == 'T') tmpA.second = '9' + 1;
    if(a.second == 'J') tmpA.second = '9' + 2;
    if(a.second == 'Q') tmpA.second = '9' + 3;
    if(a.second == 'K') tmpA.second = '9' + 4;
    if(a.second == 'A') tmpA.second = '9' + 5;
    if(b.second == 'T') tmpB.second = '9' + 1;
    if(b.second == 'J') tmpB.second = '9' + 2;
    if(b.second == 'Q') tmpB.second = '9' + 3;
    if(b.second == 'K') tmpB.second = '9' + 4;
    if(b.second == 'A') tmpB.second = '9' + 5;

    a_val += tmpA.second - '1';
    b_val += tmpB.second - '1';
    //cout << a.first << a.second << ',' << b.first << b.second << ':' << a_val << " " << b_val << endl;
    return a_val < b_val;

}

int main(){

    char s;
    while(cin >> s && s != '#'){
        string input;
        string deck;
        vector<pair<char, char>> player[4];
        
        cin >> deck >> input;
        deck += input;

        int idx = 0;
        if(s == 'N') idx = 0;
        if(s == 'E') idx = 1;
        if(s == 'S') idx = 2;
        if(s == 'W') idx = 3;

        for(int i = 0;i < deck.length();i += 2){
            if(++idx == 4) idx = 0;
            
            pair<char, char> dist;
            dist.first = deck[i], dist.second = deck[i+1];

            player[idx].push_back(dist);
        }

        idx = 2;
        for(int i = 0;i < 4;i++){
            sort(player[idx].begin(), player[idx].end(), cmp);
            if(idx == 0) cout << "N:";
            if(idx == 1) cout << "E:";
            if(idx == 2) cout << "S:";
            if(idx == 3) cout << "W:";
            for(pair<char, char> j : player[idx]){
                cout << " " << j.first << j.second;
            }
            cout << endl;
            if(++idx == 4) idx = 0;
        }
    }

    return 0;
}