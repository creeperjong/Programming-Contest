#include <bits/stdc++.h>
#define MAXLEN 2000000
using namespace std;

bool visited[MAXLEN] = {0};

int find(int x, int* s){
    if(x == s[x]) return x;
    else return s[x] = find(s[x], s);
}

int main(){

    int s[MAXLEN] = {0};
    int from, to, cnt = 0;
    bool isTree = true;
    for(int i = 0;i < MAXLEN;i++) s[i] = i;
    while(cin >> from >> to && (from >= 0 || to >= 0 )){
        if(from == 0 && to == 0){
            if(isTree){
                int rt = 0;
                for(int i = 0;i < MAXLEN;i++){
                    if(visited[i] && find(i, s) == i){
                        if(rt == 1)
                        isTree = false;
                        break;
                    }
                    ++rt;
                }
            }
            if(isTree) cout << "Case " << ++cnt << " is a tree.\n";
            else cout << "Case " << ++cnt << " is not a tree.\n";
            isTree = true;
            for(int i = 0;i < MAXLEN;i++) s[i] = i;
            continue;
        }
        if(!isTree) continue;

        visited[from] = visited[to] = true;
        int fa = find(from, s), fb = find(to, s);
        if(fa != fb) s[fb] = fa;
        else isTree = false;

    }

    return 0;
}