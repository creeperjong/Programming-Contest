#include <bits/stdc++.h>
using namespace std;

int main(){

    string sen;
    string name;
    while(cin >> sen && sen != "END"){
        for(int i = 1;i < sen.length();++i){
            if(sen[i] == '"') break;
            name.push_back(sen[i]);
        }
        
    }

    return 0;
}