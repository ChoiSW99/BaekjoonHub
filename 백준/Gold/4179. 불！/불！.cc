#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

char maze[1001][1001];
int  dist[1001][1001]; // 0 ...

int dr[4] = { 1,0,-1,0 };
int dc[4] = { 0,1,0,-1 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int R, C;
	cin >> R >> C;
	cin.ignore();

	// 불 먼저 번져보고 (BFS 돌리기)
	// 다음으로, 지훈이 이동 확인
	// 불이 간 것보다 지훈이의 이동수가 작을 때만 고려!
	queue<pii> fireQue;
	queue<pii> jihoonQue;

	for (int r = 0; r < R; r++)
	{
		cin >> maze[r];
		for (int c=0; c<C; c++)
		{
			if (maze[r][c] == 'F')
			{
				fireQue.emplace(r, c);
				dist[r][c] = 1;
			}
		}
	}

	while (!fireQue.empty())
	{
		pii now = fireQue.front();
		fireQue.pop();

		for (int i = 0; i < 4; i++)
		{
			int nRow = now.first + dr[i];
			int nCol = now.second + dc[i];

			if (nRow < 0 || nRow >= R || nCol < 0 || nCol >= C)
				continue;
			if (maze[nRow][nCol] == '#')
				continue;
			if (dist[nRow][nCol] != 0)
				continue;

			fireQue.push({ nRow, nCol });
			dist[nRow][nCol] = dist[now.first][now.second] + 1;
		}
	}

	// Jihoon
	for (int r = 0; r < R; r++)
	{
		for (int c = 0; c < C; c++)
		{
			if (maze[r][c] == 'J')
			{
				jihoonQue.emplace(r, c);
				dist[r][c] = 1;
			}
		}
	}

	while (!jihoonQue.empty())
	{
		pii now = jihoonQue.front();
		jihoonQue.pop();
		if (now.first == 0 || now.first == R - 1 || now.second == 0 || now.second == C - 1)
		{
			cout << dist[now.first][now.second];
			return 0;
		}

		for (int i = 0; i < 4; i++)
		{
			int nRow = now.first + dr[i];
			int nCol = now.second + dc[i];

			if (nRow < 0 || nRow >= R || nCol < 0 || nCol >= C)
				continue;
			if (maze[nRow][nCol] == '#')
				continue;

			// 불의 이동거리보다 크거나같음
			if (dist[nRow][nCol] != 0 && dist[now.first][now.second] + 1 >= dist[nRow][nCol])
				continue;

			jihoonQue.push({ nRow, nCol });
			dist[nRow][nCol] = dist[now.first][now.second] + 1;
		}
	}

	cout << "IMPOSSIBLE";
}
