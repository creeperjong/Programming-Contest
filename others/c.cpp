#include <bits/stdc++.h>
#define MAXLEN (100 + 5)
#define pd(x) printf("%d\n", x)
#define sd(x) scanf("%d", &x)
#define nl printf("\n")
#define ll long long
#define pii pair<int, int>

using namespace std;

int arr[MAXLEN],n,c=-1,d=-1;
bool flag = false;

int main(){
    
    sd(n);
    for(int i = 0;i < n;i++) sd(arr[i]);

    sort(arr, arr + n);

    for(int i = 0;i < n;i++){
        if(arr[i] >= 60){
            if(i == 0){
                flag = true;
                break;
            }
            c = arr[i-1];
            d = arr[i];
            break;
        }
    }
    if(c != -1 || d != -1){
        printf("%d %d\n", c, d);
    }
    else{
        if(flag) printf("best case\n");
        else printf("worst case\n");
    }
    
    return 0;
}