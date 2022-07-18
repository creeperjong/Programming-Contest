#include <iostream>
#define MAXLEN 150000+5

using namespace std;


class Node {
public:
    Node() = default;
    Node(int val_): val(val_), prev(NULL), next(NULL){}
    int val;
    Node* prev;
    Node* next;
};

void read(int &x){
	char ch = getchar();x = 0;
	for (; ch < '0' || ch > '9'; ch = getchar());
	for (; ch >='0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
}

int main(){

    int n, q;
    while(~scanf("%d %d", &n, &q)){
        Node* head[MAXLEN] = {0};
        Node* tail[MAXLEN] = {0};
        for(int i = 1;i <= n;++i){
            head[i] = new Node();
            tail[i] = new Node();
            head[i]->next = tail[i];
            tail[i]->prev = head[i];
        }
        while(q--){
            int opt;
            read(opt);
            switch(opt){
                case 1:{
                    int u, w, val;
                    read(u);
                    read(w);
                    read(val);
                    Node* newNode = new Node(val);
                    if(w){
                        newNode->prev = tail[u]->prev;
                        newNode->next = tail[u];
                    }
                    else{
                        newNode->prev = head[u];
                        newNode->next = head[u]->next;
                    }
                    newNode->prev->next = newNode;
                    newNode->next->prev = newNode;
                    break;
                }
                case 2:{
                    int u,w;
                    read(u);
                    read(w);
                    Node* del;
                    Node* now = head[u];
                    
                    if(w) del = tail[u]->prev;
                    else del = head[u]->next;
                    if(del->val){ 
                        printf("%d\n", del->val);
                        del->prev->next = del->next;
                        del->next->prev = del->prev;
                    }
                    else printf("-1\n");
                    break;
                }
                case 3:{
                    int u,v,w;
                    read(u);
                    read(v);
                    read(w);
                    if(head[v]->next == tail[v]) break;
                    if(w){
                        Node* now = head[v]->next;
                        while(now->val){
                            swap(now->prev, now->next);
                            now = now->prev;
                        }
                        swap(head[v]->next, tail[v]->prev);
                        tail[v]->prev->next = tail[v];
                        head[v]->next->prev = head[v];
                    }
                    
                    tail[u]->prev->next = head[v]->next;
                    head[v]->next->prev = tail[u]->prev;
                    tail[u]->prev = tail[v]->prev;
                    tail[v]->prev->next = tail[u];
                    head[v]->next = tail[v], tail[v]->prev = head[v];
                    break;
                }
            }
        }
    }

    return 0;
}