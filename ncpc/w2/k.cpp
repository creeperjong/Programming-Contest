#include <bits/stdc++.h>
#define pii pair<int, int>
#define umspii unordered_multimap<string, pii>
using namespace std;

int main(){

    int n, m;
    while(cin >> n >> m){
        getchar();
        
        unordered_multimap<string, pii> mp[m];
        set<pii> s[m];
        string sen;
        int r1, r2, c1, c2;

        for(int i = 0;i < n;++i){
            getline(cin ,sen);
            string word;
            int cnt = 0;

            for(int j = 0;j < sen.length();++j){
                if(sen[j] == ',' || j == sen.length() - 1){
                    if(j == sen.length() - 1) word.push_back(sen[j]);
                    umspii::iterator it = mp[cnt].find(word);
                    if(it != mp[cnt].end()){
                        pair<umspii::iterator, umspii::iterator> tmp = mp[cnt].equal_range(it->first);
                        for(umspii::iterator it = tmp.first;it != tmp.second;it++){
                            pii pos = {it->second.first, i};
                            //cout << cnt << " " << pos.first << " " << pos.second << endl;
                            // cout << sen[j] <<  endl;
                            s[cnt].insert(pos);
                        }
                    }
                    mp[cnt].insert({word ,{i, cnt}});
                    ++cnt;
                    word.clear();
                }
                else word.push_back(sen[j]);
            }
        }

        // for(int i = 0;i < m;i++){
        //     set<pii>::iterator it = s[i].begin();
        //     for(;it != s[i].end();it++){
        //         cout << it->first << " " << it->second << endl;
        //     }
        // }

        set<pii> res;
        for(int i = 0;i < m - 1;i++){
            for(int j = i + 1;j < m;j++){
                //cout << i << " " << j << endl;
                set_intersection(s[i].begin(), s[i].end(), s[j].begin(), s[j].end(), inserter(res, res.begin()));
                //cout << "test\n";
                if(!res.empty()){
                    printf("NO\n%d %d\n%d %d\n", res.begin()->first+1, res.begin()->second+1, i+1, j+1);
                    break;
                }
            }
            if(!res.empty()) break;
        }
        if(res.empty()) printf("YES\n");
    }

    return 0;
}