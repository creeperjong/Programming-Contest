#include <bits/stdc++.h>
using namespace std;


int main(){

    int totalCase;
    while(cin >> totalCase){
        stack<int> s;
        queue<int> q;
        priority_queue<int> p;
        bool S = true, Q = true, P = true;

        while(totalCase--){
            int ins, num;
            scanf("%d %d", &ins, &num);
            if(ins == 1){
                s.push(num);
                q.push(num);
                p.push(num);
            }
            if(ins == 2){
                int spop = (s.empty()) ? -1 : s.top();
                int qpop = (q.empty()) ? -1 : q.front();
                int ppop = (p.empty()) ? -1 : p.top();
                if(!s.empty()) s.pop();
                if(!q.empty()) q.pop();
                if(!p.empty()) p.pop();
                if(spop != num) S = false;
                if(qpop != num) Q = false;
                if(ppop != num) P = false;
            }
        }

        int cnt = 0;
        if(S) ++cnt;
        if(Q) ++cnt;
        if(P) ++cnt;
        if(cnt){
            if(cnt == 1){
                if(S) printf("stack\n");
                if(Q) printf("queue\n");
                if(P) printf("priority queue\n");
            }
            else printf("not sure\n");
        }
        else printf("impossible\n");
    }

    return 0;
}