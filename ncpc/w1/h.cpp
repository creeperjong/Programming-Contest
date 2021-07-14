#include <bits/stdc++.h>
using namespace std;

bool cmp(const pair<int, double> a, const pair<int, double> b){
    return a.second > b.second;
}

int main(){

    int totalCase;
    bool isFirst = true;
    cin >> totalCase;
    while(totalCase--){
        getchar();
        int n;
        pair<int, double> arr[1005];
        cin >> n;
        for(int i = 1;i <= n;i++){
            int day, fine;
            cin >> day >> fine;
            arr[i].first = i;
            arr[i].second = (double)fine / day;
        }

        //for(int i = 1;i <= n;i++) cout << arr[i].first << " " << arr[i].second << endl;

        stable_sort(arr + 1, arr + 1 + n, cmp);

        if(!isFirst) cout << endl;
        else isFirst = false;
        cout << arr[1].first;
        for(int i = 2;i <= n;i++) cout << " " << arr[i].first;
        cout << endl; 
    }

    return 0;
}