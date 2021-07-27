#include <bits/stdc++.h>
#define MAXLEN (1000 + 5)
#define pd(x) printf("%d\n", x)
#define sd(x) scanf("%d", &x)
#define nl printf("\n")
#define ll long long
#define pii pair<int, int>

using namespace std;

int totalCase,n,rd[26],cd[26],checkSet[26];
bool exist[26],visit[MAXLEN];
string word[MAXLEN];
vector<pair<int, int>> e;
vector<string> ans;

void init(){
    memset(rd, 0, sizeof(rd));
    memset(cd, 0, sizeof(cd));
    memset(checkSet, 0, sizeof(checkSet));
    memset(exist, 0, sizeof(exist));
    memset(visit, 0, sizeof(visit));
    e.clear(), ans.clear();
}

int findSet(int x){
    if(x == checkSet[x]) return x;
    else return checkSet[x] = findSet(checkSet[x]);
}

bool check(){
    for(int i = 0;i < 26;i++){
        if(exist[i]) checkSet[i] = i;
        else checkSet[i] = -1;
    }

    for(auto i : e){
        int fa = findSet(i.first);
        int fb = findSet(i.second);
        if(fa != fb) checkSet[fa] = fb;
    }

    int cnt = 0;
    for(int i = 0;i < 26;i++){
        if(checkSet[i] == i) cnt++;
    }
    
    if(cnt == 1) return true;
    else return false;
}

void dfs(int x, int n){
    for(int i = 0;i < n;i++){
        if(word[i][0] - 'a' == x && !visit[i]){
            visit[i] = true;
            dfs(word[i][word[i].length() - 1] - 'a' , n);
            ans.push_back(word[i]);
        }
    }
}

int main(){

    sd(totalCase);
    
    while(totalCase--){
        init();
        cin >> n;
        for(int i = 0;i < n;i++){
            cin >> word[i];
            int First = word[i][0] - 'a';
            int Second = word[i][word[i].length()-1] - 'a';
            exist[First] = true, exist[Second] = true;
            e.push_back({First, Second}), e.push_back({Second, First});
            ++cd[First], ++rd[Second];
        }
        sort(word, word + n);

        int cnt = 0;
        int start = -1;
        bool flag = false;
        for(int i = 0;i < 26;i++){
            if(exist[i]){
                if(abs(cd[i] - rd[i]) >= 1){
                    ++cnt;
                    if(abs(cd[i] - rd[i] > 1)){
                        cout << "***\n";
                        flag = true;
                        break;
                    }
                    else if(cd[i] - rd[i] == 1) start = i;
                }
            }
        }
        if(flag) continue;

        if((cnt != 0 && cnt != 2) || !check()){
            cout << "***\n";
            continue;
        }

        if(cnt == 0){
            for(int i = 0;i < 26;i++){
                if(exist[i]) dfs(i, n);
            }
        }else dfs(start ,n);

        cout << ans[ans.size()-1];
        for(int i = ans.size() - 2;i >= 0;i--){
            cout << '.' << ans[i];
        }
        cout << endl;
    }

    return 0;
}