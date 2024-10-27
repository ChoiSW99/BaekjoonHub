#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

// 우선 트리를 만들고, wires의 각 요소에 대해
// 하나씩 제거 후, 제거된 wire의 v1과 v2를 루트노드로하여
// 트리의 자식 수를 세고, 뺀 후 절댓값을 씌운다.
// 
// wires.size() < 100
// 최대 99번 x 2개의 루트노드에 대한 DFS

int DFS(int rootNode, vector<vector<int>>& graph, vector<bool>& visited)
{
    int cnt = 0;
    
    stack<int> st;
    
    st.push(rootNode);
    visited[rootNode] = true;

    while(!st.empty()){
        int node = st.top();
        st.pop();
        cnt++;

        for(int child : graph[node])
        {
            if(visited[child])
                continue;
            visited[child] = true;
            st.push(child);
        }
    }
    
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 1e9;
    
    vector<bool> visited(101, false);
    vector<vector<int>> graph(101);
    for(vector<int> wire : wires)
    {
        graph[wire[0]].push_back(wire[1]);
        graph[wire[1]].push_back(wire[0]);
    }
    
    
    for(vector<int> wire : wires)
    {
        fill(visited.begin(), visited.end(), false);
        
        visited[wire[0]] = true; // 연결 끊었음
        visited[wire[1]] = true; // 연결 끊었음
        
        int cnt1 = DFS(wire[0], graph, visited);
        int cnt2 = DFS(wire[1], graph, visited);
        answer = min(answer, abs(cnt1-cnt2));
    }
    
    return answer;
}