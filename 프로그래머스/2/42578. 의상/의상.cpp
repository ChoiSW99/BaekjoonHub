#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    
    unordered_map<string, int> m;
    for(vector<string> cloth : clothes){
        m[cloth[1]]++;
    }
    
    // ''각 의상종류 + 1'로 모두 곱한 후 '아무것도 안 입는 1가지 경우 빼기'
    answer = 1;
    for(auto x : m){
        answer *= (x.second+1);
    }
    answer--;
    
    return answer;
}