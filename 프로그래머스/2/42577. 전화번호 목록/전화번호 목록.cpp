#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    unordered_set<string> s;
    for(int i=0; i<phone_book.size(); i++){
        s.insert(phone_book[i]);
    }

    // 모든 전화번호에 대해 1~n 만큼 잘라서 확인
    for(int i=0; i<phone_book.size(); i++){
        for(int j=0; j<phone_book[i].length()-1; j++){
            if(s.find(phone_book[i].substr(0, j+1)) != s.end()){
                answer = false;
                break;
            }
        }
        
        if(answer == false)
            break;
    }
    return answer;
}