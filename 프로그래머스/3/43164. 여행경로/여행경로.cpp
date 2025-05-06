#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

/*
    DFS를 돈다
    
    
    map<string, vector<string>> path;
    
    vector<string>는 오름차순을 한다.
    
*/

bool DFS(map<string, vector<pair<string, bool>>>& path, string cur, int toPick, vector<string>& answer)
{
    if(toPick == 0)
    {
        return true;
        /*if(answer.size() == path.size()) // 모든 경로를 뽑았을 때만 return true
            return true;
        
        return false;*/
    }
        
    // 현재 공항에서 모든 갈 수 있는 곳에 대해,
    for(pair<string, bool>& p : path[cur])
    {
        if(p.second == true) // 이미 방문
            continue;
        
        answer.push_back(p.first); // 다음 공항
        p.second = true;
        
        bool found = DFS(path, p.first, toPick-1, answer);
        if(found) 
            return true;
        
        answer.pop_back();
        p.second = false;
    }
    
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    
    int toPick = tickets.size(); // 골라야할 티켓 수
    
    map<string, vector<pair<string, bool>>> path;
    
    for(vector<string>& t : tickets)
    {
        path[t[0]].push_back({t[1], false});
    }
    
    for (auto& p : path)
    {
        auto& v = p.second;
        // 오름차순 정렬
        sort(v.begin(), v.end(), less<>());
    }
    
    string cur = "ICN";
    answer.push_back(cur);
    
    DFS(path, cur, toPick, answer);
    
    
    return answer;
}