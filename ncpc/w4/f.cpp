#include <bits/stdc++.h>
#define MAXLEN (30 + 5)
#define pd(x) printf("%d\n", x)
#define sd(x) scanf("%d", &x)
#define nl printf("\n")
#define ll long long
#define pii pair<int, int>

using namespace std;

struct _box {
    int id;
    vector<int> box;
    bool operator<(const _box &b) const{
        for(int i = 0;i < box.size();i++){
            if(box[i] >= b.box[i]) return false;
        }
        return true;
    }
} boxSeq[MAXLEN];

int num,dim;
vector<int> adjList[MAXLEN];

bool cmp(const _box a, const _box b){
    for(int i = 0;i < dim;i++){
        if(a.box[i] > b.box[i]) return 0;
        else if(a.box[i] < b.box[i]) return 1;
    }
    return 0;
}

void print(int* pre, int idx){
    if(pre[idx] == 0){
        printf("%d", boxSeq[idx].id);
        return;
    }

    print(pre, pre[idx]);
    printf(" %d", boxSeq[idx].id);
}

int main(){
    
    while(cin >> num >> dim){
        int dp[MAXLEN] = {0};
        int pre[MAXLEN] = {0};
        memset(boxSeq, 0, sizeof(boxSeq));
        for(int i = 1;i <= num;i++){
            for(int j = 0;j < dim;j++){
                int tmp;
                sd(tmp);
                boxSeq[i].box.push_back(tmp);  
            }
            boxSeq[i].id = i;
            sort(boxSeq[i].box.begin(), boxSeq[i].box.end());
            dp[i] = 1;
        }
        sort(boxSeq + 1, boxSeq + num + 1, cmp);

        int ansMax = 0, ansIdx = 0;
        for(int i = 1;i <= num;i++){
            for(int j = i - 1;j > 0;j--){
                if(boxSeq[j] < boxSeq[i] && dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                    pre[i] = j;
                }
            }
            if(ansMax < dp[i]){
                ansMax = dp[i];
                ansIdx = i;
            }
        }

        pd(ansMax);
        print(pre, ansIdx);
        nl;
    }
    
    return 0;
}