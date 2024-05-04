#include <bits/stdc++.h>

using namespace std;

using tii = tuple<int, int, int>;

int Map[100][100];
bool Visited[100][100];

int dr[4] = {+1, -1,  0,  0};
int dc[4] = { 0,  0, -1, +1 };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;

    for (int t = 1; t <= T; t++)
    {
        memset(Visited, 0, sizeof(Visited));
        int N; cin >> N;
        string input;
        for (int i = 0; i < N; i++)
        {
            cin >> input;
            for (int j = 0; j < N; j++)
                Map[i][j] = input[j] - '0';
        }

        priority_queue<tii, vector<tii>, greater<tii>> pq; // cost, row, col // 오름차순
        pq.emplace(0, 0, 0);
        Visited[0][0] = true;

        while (!pq.empty())
        {
            auto& cur = pq.top(); 
            int cost = get<0>(cur);
            int row = get<1>(cur);
            int col = get<2>(cur);
            pq.pop();
            if (row == N - 1 && col == N - 1)
            {
                cout << "#" << t << " " << cost << '\n';
                break;
            }

            for(int i=0; i<4; i++)
            {
                int nextRow = row + dr[i];
                int nextCol = col + dc[i];
                if (0 > nextRow || nextRow >= N || 0 > nextCol || nextCol >= N)
                    continue;

                if (Visited[nextRow][nextCol])
                    continue;

                pq.emplace(cost + Map[nextRow][nextCol], nextRow, nextCol);
                Visited[nextRow][nextCol] = true;
            }
        }
    }
}
