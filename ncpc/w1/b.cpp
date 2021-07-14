#include <bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while(cin >> n && n != 0){
        vector<int> arr;
        for(int i = 0;i < n;i++){
            int input;
            cin >> input;
            arr.push_back(input);
        }
        sort(arr.begin(), arr.end());
        cout << arr[0];
        for(int i = 1;i < n;i++) cout << " " << arr[i];
        cout << endl;
    }

    return 0;
}