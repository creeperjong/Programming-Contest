#include <bits/stdc++.h>
using namespace std;

int main(){

    map<string, int> shelf;
    unordered_map<string, string> authorOf;
    shelf.clear();
    authorOf.clear();
    string sen;
    string name;
    string author;
    int returnNum = 0;

    while(getline(cin, sen) && sen != "END"){
        name.clear();
        author.clear();
        int i;
        for(i = 1;i < sen.length();++i){
            if(sen[i] == '"') break;
            name.push_back(sen[i]);
        }
        for(i += 5;i < sen.length();++i){
            author.push_back(sen[i]);   
        }
        shelf[author + "\t" + name] = 1;
        authorOf[name] = author;
    }
    while(getline(cin, sen) && sen != "END"){
        if(sen == "SHELVE"){
            if(returnNum == 0){
                printf("END\n");
                continue;
            }
            map<string, int>::iterator it = shelf.begin();
            map<string, int>::iterator pre = shelf.end();

            for(;it != shelf.end();++it){
                if(it->second == 1) pre = it;
                else if(it->second == 3){
                    if(pre == shelf.end()) cout << "Put \"" << it->first.substr(it->first.find("\t")+1) << "\" first\n";
                    else cout << "Put \"" << it->first.substr(it->first.find("\t")+1) << "\" after \"" << pre->first.substr(pre->first.find("\t")+1) << "\"\n";
                    it->second = 1;
                    --returnNum;
                    pre = it;
                }
            }
            printf("END\n");
        }
        else{
            name.clear();
            for(int i = 8;i < sen.length();++i){
                if(sen[i] == '"') break;
                name.push_back(sen[i]);
            }
            
            string key = authorOf[name] + "\t" + name;
            if(sen[0] == 'B' && shelf[key] == 1) shelf[key] = 2;
            else if(sen[0] == 'R' && shelf[key] == 2) shelf[key] = 3, ++returnNum;
        }
    }

    return 0;
}