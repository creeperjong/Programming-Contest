#include <bits/stdc++.h>
using namespace std;

int main(){
    string input;
    vector<string> record;

    while(getline(cin ,input) && input[0] != '0'){
        string word;
        for(int i = 0;i < input.size();i++){
            word.clear();
            if(isalpha(input[i])){
                while(isalpha(input[i])){
                    word.push_back(input[i]);
                    i++;
                }
                record.push_back(word);
                cout << word;
                --i;
            }
            else if(isdigit(input[i])){
                int num = 0;
                string keyword;
                while(isdigit(input[i])){
                    num = num * 10 + input[i] - '0';
                    ++i;
                }
                keyword = record[record.size() - num];
                record.erase(record.end() - num);
                record.push_back(keyword);
                cout << keyword;
                --i;
            }
            else printf("%c", input[i]);
        }
        printf("\n");
    }

    return 0;
}