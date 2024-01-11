#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

// https://school.programmers.co.kr/learn/courses/30/lessons/118669

#define MAX 50001
#define INF 1e9

using namespace std;

typedef pair<int, int> pii;

vector<vector<pii>> graph(MAX); // { from, to, intensity }
vector<int> intensity(MAX);
vector<bool> summit(MAX);

void dijkstra(vector<int>& gates, priority_queue<pii, vector<pii>, greater<pii>>& answers)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for (auto& g : gates) // 입구가 여러개인데, 이 입구들에서 동시에! 돌려야함
    {
        pq.emplace(0, g); // { intensity, node }
        intensity[g] = 0;
    }

    while (!pq.empty())
    {
        int nowIntensity = pq.top().first;
        int nowNode = pq.top().second;
        pq.pop();
        
        if (nowIntensity > intensity[nowNode])
            continue;

        if (summit[nowNode])
        {
            answers.push({nowIntensity, nowNode});
            continue;
        }
        
        for (const pii& n : graph[nowNode])
        {
            int nextNode = n.first;
            int nextIntensity = n.second;

            // 탐색 조건
            if (intensity[nextNode] == -1 || max(nowIntensity, nextIntensity) < intensity[nextNode]) // 미방문 or 더 강도 낮은 길
            {
                intensity[nextNode] = max(nowIntensity, nextIntensity);
                pq.emplace(intensity[nextNode], nextNode);
            }
        }
    }
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer; // [산봉우리의 번호, intensity의 최솟값] 
    priority_queue<pii, vector<pii>, greater<pii>> answers;

    fill(intensity.begin(), intensity.end(), -1);
    fill(summit.begin(), summit.end(), false);

    for (const auto& s : summits)
        summit[s] = true;

    for (const auto& e : paths) // & 또는 const auto& 로 해줘야 불필요한 복사 안생김
    {
        graph[e[0]].push_back({ e[1], e[2]});
        graph[e[1]].push_back({ e[0], e[2]});
    }
    dijkstra(gates, answers);
    answer = { answers.top().second, answers.top().first};

    return answer; // intensity 제일 낮은 것 중 제일 낮은 봉우리
}