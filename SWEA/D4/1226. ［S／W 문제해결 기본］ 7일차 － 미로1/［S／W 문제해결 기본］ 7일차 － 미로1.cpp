#include <bits/stdc++.h>

using namespace std;

int maze[16][16];
bool visited[16][16];

int dr[4] = { -1, +1, 0, 0 };
int dc[4] = { 0, 0, -1, +1 };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 10;

    for (int t = 1; t <= T; t++)
    {
        cin >> t;
        memset(visited, 0, sizeof(visited));
        queue<pair<int, int>> que;
        for (int i = 0; i < 16; i++)
            for (int j = 0; j < 16; j++)
            {
                char c; cin >> c;
                maze[i][j] = c - '0';
                if (maze[i][j] == 2)
                {
                    que.emplace(i, j);
                    visited[i][j] = true;
                }
            }
        bool can = false;
        while (!que.empty())
        {
            auto now = que.front(); que.pop();
            if (maze[now.first][now.second] == 3)
            {
                can = true; 
                break;
            }

            for (int i = 0; i < 4; i++)
            {
                int nextRow = now.first + dr[i];
                int nextCol = now.second + dc[i];
                if (nextRow < 0 || nextRow > 15 || nextCol < 0 || nextCol > 15)
                    continue;
                if (visited[nextRow][nextCol])
                    continue;
                if (maze[nextRow][nextCol] == 0 || maze[nextRow][nextCol] == 3)
                {
                    que.emplace(nextRow, nextCol);
                    visited[nextRow][nextCol] = true;
                }
            }
        }
       cout << "#" << t << " " << can << '\n';
    }
}
