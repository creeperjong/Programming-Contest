#include <bits/stdc++.h>
using namespace std;

int r,c;
char draw[255][255];

int main(){

    char choice = 0;
    while(cin >> choice && choice != 'X'){
        switch(choice){
            case 'I':
                memset(draw, 0, sizeof(draw));
                cin >> c >> r;
                for(int i = 0;i < r;i++){
                    for(int j = 0;j < c;j++) draw[i][j] = 'O';
                }
                break;
            case 'C':
                memset(draw, 0, sizeof(draw));
                for(int i = 0;i < r;i++){
                    for(int j = 0;j < c;j++) draw[i][j] = 'O';
                }
                break;
            case 'L':{
                int x, y;
                char color;
                cin >> x >> y >> color;
                draw[y-1][x-1] = color;
                break;
            }
            case 'V':{
                int x, y1, y2, tmp;
                char color;
                cin >> x >> y1 >> y2 >> color;
                if(y1 > y2){
                    tmp = y1;
                    y1 = y2;
                    y2 = tmp;
                }
                for(int i = y1-1;i <= y2-1;i++) draw[i][x-1] = color;
                break;
            }
            case 'H':{
                int x1, x2, y, tmp;
                char color;
                cin >> x1 >> x2 >> y >> color;
                if(x1 > x2){
                    tmp = x1;
                    x1 = x2;
                    x2 = tmp;
                }
                for(int i = x1-1;i <= x2-1;i++) draw[y-1][i] = color;
                break;
            }
            case 'K':{
                int x1, x2, y1, y2, tmp;
                char color;
                cin >> x1 >> y1 >> x2 >> y2 >> color;
                if(x1 > x2){
                    tmp = x1;
                    x1 = x2;
                    x2 = tmp;
                }
                if(y1 > y2){
                    tmp = y1;
                    y1 = y2;
                    y2 = tmp;
                }
                for(int i = y1-1;i <= y2-1;i++){
                    for(int j = x1-1;j <= x2-1;j++) draw[i][j] = color;
                }
                break;
            }
            case 'F':{
                int x, y;
                char color;
                cin >> x >> y >> color;
                
                queue<pair<int, int>> q;
                bool visited[r][c];
                char cl = draw[y-1][x-1];

                memset(visited, 0, sizeof(visited));
                q.push({x,y});
                visited[y-1][x-1] = true;
                while(!q.empty()){
                    pair<int, int> now = q.front();
                    q.pop();
                    draw[now.second-1][now.first-1] = color;
                    //cout << "test\n";
                    if(now.first - 1 > 0 && draw[now.second-1][now.first-2] == cl && !visited[now.second-1][now.first-2]){
                        visited[now.second-1][now.first-2] = true;
                        q.push({now.first-1, now.second});
                    }
                    if(now.first + 1 <= c && draw[now.second-1][now.first] == cl && !visited[now.second-1][now.first]){
                        visited[now.second-1][now.first] = true;
                        q.push({now.first+1, now.second});
                    }
                    if(now.second - 1 > 0 && draw[now.second-2][now.first-1] == cl && !visited[now.second-2][now.first-1]){
                        visited[now.second-2][now.first-1] = true;
                        q.push({now.first, now.second-1});
                    }
                    if(now.second + 1 <= r && draw[now.second][now.first-1] == cl && !visited[now.second][now.first-1]){
                        visited[now.second][now.first-1] = true;
                        q.push({now.first, now.second+1});
                    }
                }
                break;
            }
            case 'S':{
                string name;
                cin >> name;
                cout << name << endl;
                for(int i = 0;i < r;i++){
                    for(int j = 0;j < c;j++) cout << draw[i][j];
                    cout << endl;
                }
                break;
            }
            default:
                char c;
                while((c = getchar()) != '\n');
                continue;
        }
    }

    return 0;
}