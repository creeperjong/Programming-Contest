#include <bits/stdc++.h>
using namespace std;

long long cnt = 0;

void mergesort(vector<int>& arr, int l, int r){
    if(l >= r) return;
    int mid = (l + r) / 2;
    mergesort(arr, l, mid);
    mergesort(arr, mid+1, r);
    
    int lidx = l, ridx = mid + 1, tmpidx = 0;
    vector<int> tmp(r - l + 1);
    while(lidx <= mid && ridx <= r){
        if(arr[lidx] <= arr[ridx]){
            tmp[tmpidx++] = arr[lidx++];
            cnt += ridx - (mid + 1);
        }
        else tmp[tmpidx++] = arr[ridx++];
    }

    while(lidx <= mid){
        tmp[tmpidx++] = arr[lidx++];
        cnt += r - mid;
    }
    while(ridx <= r) tmp[tmpidx++] = arr[ridx++];
    for(int i = 0;i < tmp.size();i++) arr[l + i] = tmp[i];
}

int main(){

    int n;

    while(cin >> n && n != 0){
        cnt = 0;
        vector<int> arr;
        while(n--){
            int input;
            cin >> input;
            arr.push_back(input);
        }
    
        mergesort(arr, 0, arr.size()-1);
    
        cout << cnt << endl;
    }


    return 0;
}