#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define pii pair<int, int>

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    vector<vector<pii>> graph(101);
    
    for(auto& c : costs)
    {
        graph[c[0]].push_back({c[2],c[1]}); // {비용, 다음노드}
        graph[c[1]].push_back({c[2],c[0]});
    }
    
    // {cost, next}
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<bool> visited(101, false);
    
    // 0번 섬에서 시작
    pq.push({0, 0});
    answer = 0;
    
    while(!pq.empty())
    {
        pii now = pq.top(); pq.pop();
        int cost = now.first;
        int node = now.second;
        
        // 현재지점의 방문여부
        if(visited[node]) 
            continue;
        visited[node] = true;
        answer += cost;
        
        for(pii e : graph[node])
        {
            int nextCost = e.first;
            int nextNode = e.second;
            if(visited[nextNode])
                continue;
            pq.push({nextCost, nextNode});
        }
    }
    
    return answer;
}