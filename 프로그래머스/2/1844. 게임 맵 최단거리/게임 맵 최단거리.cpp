#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> pii;

// 상하좌우
int dr[4] = { +1, -1, 0, 0 };
int dc[4] = { 0, 0, -1, +1 };

// BFS
void BFS(vector<vector<int>>& maps)
{
    queue<pii> que;
    que.emplace(0, 0);

    while (!que.empty())
    {
        pii now = que.front();
        que.pop();

        for (int idx = 0; idx < 4; idx++)
        {
            int next_Row = now.first + dr[idx];
            int next_Col = now.second + dc[idx];

            if (next_Row < 0 || maps.size() - 1 < next_Row)
                continue;

            if (next_Col < 0 || maps[0].size() - 1 < next_Col)
                continue;

            if (maps[next_Row][next_Col] == 0 || maps[next_Row][next_Col] != 1)
                continue;

            maps[next_Row][next_Col] = maps[now.first][now.second] + 1;
            que.emplace(next_Row, next_Col);

            if (next_Row == maps.size() - 1 && next_Col == maps[0].size() - 1)
                return;
        }
    }
}

int solution(vector<vector<int>> maps)
{
    int answer = -1;
    BFS(maps);
    if (maps[maps.size() - 1][maps[0].size() - 1] > 1)
        answer = maps[maps.size() - 1][maps[0].size() - 1];
    return answer;
}
