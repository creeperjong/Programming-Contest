#include <bits/stdc++.h>
#define MAXLEN (20000 + 5)
#define pd(x) printf("%d\n", x)
#define sd(x) scanf("%d", &x)
#define nl printf("\n")
#define ll long long
#define pii pair<int, int>

using namespace std;

int t,h,w,n,row,col;
string mp[25],str1,str2;

int main(){
    
    sd(t);
    for(int k = 1;k <= t;k++){
        str1.clear(), str2.clear();
        sd(h), sd(w);
        for(int i = 0;i < h;i++) cin >> mp[i];
        sd(n), sd(row), sd(col);
        getchar();
        --row, --col;
        str1.push_back(mp[row][col]);
        for(int i = 0;i < n;i++){
            char c = getchar();
            if(c == 'N') str1.push_back(mp[--row][col]);
            if(c == 'E') str1.push_back(mp[row][++col]);
            if(c == 'S') str1.push_back(mp[++row][col]);
            if(c == 'W') str1.push_back(mp[row][--col]);
        }
        sd(n), sd(row), sd(col);
        getchar();
        --row, --col;
        str2.push_back(mp[row][col]);
        for(int i = 0;i < n;i++){
            char c = getchar();
            if(c == 'N') str2.push_back(mp[--row][col]);
            if(c == 'E') str2.push_back(mp[row][++col]);
            if(c == 'S') str2.push_back(mp[++row][col]);
            if(c == 'W') str2.push_back(mp[row][--col]);
        }

        unordered_map<char, vector<int>> rec;
        vector<int> tmp;
        vector<int> dp;
        int len = 0;

        for(int i = 0;i < str1.length();i++){
            if(rec.count(str1[i]) == 0) rec[str1[i]].push_back(-1);
        }
        for(int i = 0;i < str2.length();i++){
            if(rec.count(str2[i]) != 0) rec[str2[i]].push_back(i);
        }
        for(int i = 0;i < str1.length();i++){
            if(rec[str1[i]].size() > 1){
                for(int j = rec[str1[i]].size() - 1;j > 0;j--){
                    tmp.push_back(rec[str1[i]][j]);
                }
            }
        }

        if(!tmp.empty()) dp.push_back(tmp[0]), ++len;
        for(int i = 1;i < tmp.size();i++){
            int pos = distance(dp.begin(), lower_bound(dp.begin(), dp.end(), tmp[i]));
            if(pos == len) dp.push_back(tmp[i]), ++len;
            else dp[pos] = tmp[i];
        }

        printf("Case %d: %ld %ld\n",k,str1.length() - len, str2.length() - len);
    }
    
    return 0;
}