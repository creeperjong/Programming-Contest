#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

unordered_map<int, int> record;

int main(){

    int times;
    string str;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    while(cin >> str && str[0] != '#'){
        int ins, per;
        scanf("%d %d", &ins, &per);
        record[ins] = per;
        q.push({per, ins});

    }
    scanf("%d", &times);

    int nowtime = 0;
    while(times--){
        pii now = q.top();
        q.pop();
        printf("%d\n", now.second);
        q.push({now.first + record[now.second], now.second});
        //cout << now.first << " " << now.second << endl;
    }

    return 0;
}