#include <bits/stdc++.h>
#define MAXLEN (100 + 5)
#define pd(x) printf("%d\n", x)
#define sd(x) scanf("%d", &x)
#define ll long long
#define pii pair<int, int>

using namespace std;

int m,n,cnt = 0;
const int dirR[] = {-1, 1, 0, 0, -1, -1, 1, 1};
const int dirC[] = {0, 0, -1, 1, -1, 1, -1, 1};
char field[MAXLEN][MAXLEN];
bool vis[MAXLEN][MAXLEN] = {0};

void visit(int r, int c){
    if(vis[r][c]) return;
    vis[r][c] = true;
    for(int i = 0;i < 8;i++){
        if(r+dirR[i] >= 0 && r+dirR[i] < m && c+dirC[i] >= 0 && c+dirC[i] < n){
            if(field[r+dirR[i]][c+dirC[i]] == '@' && !vis[r+dirR[i]][c+dirC[i]]){
                visit(r + dirR[i], c + dirC[i]);
            }
        }
    }
}

int main(){
    
    while(cin >> m >> n && (m != 0 || n != 0)){
        getchar();
        memset(vis, 0, sizeof(vis)), cnt = 0;
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++) scanf("%c", &field[i][j]);
            getchar();
        }
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(field[i][j] == '@' && !vis[i][j]){
                    //printf("%d %d\n", i, j);
                    ++cnt;
                    visit(i ,j);
                }
            }
        }
        pd(cnt);
        // for(int i = 0;i < m;i++){
        //     for(int j = 0;j < n;j++){
        //         printf("%c ", field[i][j]);
        //     }
        //     printf("\n");
        // }
        // printf("\n");
    }
    
    return 0;
}