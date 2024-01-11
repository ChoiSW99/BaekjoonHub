#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

// 도넛과 막대 그래프
// https://school.programmers.co.kr/learn/courses/30/lessons/258711

#define MAX 1000001
// #define INF 1e9

using namespace std;

typedef pair<int, int> pii;

bool visited[MAX] = { false, };

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer;
    int createdVertex = -1; // 생성한 정점의 번호
    int donut = 0;
    int stick = 0;
    int eight = 0;

    vector<vector<int>> graph(MAX); // 단방향
    vector<int> indegree(MAX);
    vector<int> outdegree(MAX);
    int shapesNum = 0; // 전체 도형 개수

    for (auto& e : edges)
    {
        visited[e[0]] = true;
        visited[e[1]] = true;

        graph[e[0]].push_back(e[1]); 
        outdegree[e[0]]++;
        indegree[e[1]]++;
    }

    // 생성한 정점의 번호 찾기
    for (int idx = 1; idx < MAX; idx++)
    {
        if (!visited[idx])
            continue;

        if (indegree[idx] == 0 && outdegree[idx] >= 2) // 시작지점에서 이어주기만 함 && 모형그래프는 2개 이상
        {
            createdVertex = idx;
            break;
        }
    }

    shapesNum = graph[createdVertex].size();

    // 생성한 정점과 각 도형그래프들 간의 edge 끊어주기
    for (auto& e : graph[createdVertex])
        indegree[e]--;
    graph[createdVertex].clear();
    outdegree[createdVertex] = 0;


    // 막대 도형 or 8자 도형 찾기
    for (int idx = 1; idx < MAX; idx++)
    {
        if (idx == createdVertex)
            continue;

        if (!visited[idx])
            continue;

        // 막대도형
        if (indegree[idx] == 0 && outdegree[idx] <= 1)
        {
            stick++;
            continue;
        }

        // 8자 도형
        if (indegree[idx] == 2 && indegree[idx] == outdegree[idx])
        {
            eight++;
            continue;
        }
    }

    donut = shapesNum - stick - eight;
    answer = { createdVertex, donut, stick, eight };
    return answer;
}