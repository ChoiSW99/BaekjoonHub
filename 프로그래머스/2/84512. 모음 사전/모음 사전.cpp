#include <string>
#include <vector>

using namespace std;

string AEIOU = "AEIOU";

void DFS(int& answer, string& now, string& target, int& cnt)
{
    if(answer != -1)
        return;
    
    cnt++;
    
    if(now == target)
    {
        answer = cnt;
        return;
    }
    
    if(now.size() == 5)
        return;
    
    for(char c : AEIOU)
    {
        now.push_back(c);
        DFS(answer, now, target, cnt);
        now.pop_back();
    }
}

int solution(string word) {
    string now = "";
    int answer = -1;
    int cnt = -1;
    
    DFS(answer, now, word, cnt);
    return answer;
}

// AAAAE ) A A~ AA~ 

