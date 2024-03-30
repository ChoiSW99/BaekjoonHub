#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int board[101][101];
	bool visited[101][101];
	memset(visited, false, sizeof(visited));

	int N, M;
	cin >> N >> M;
	cin.ignore();

	for (int i = 0; i < N; i++)
	{
		string input;
		cin >> input;
		for (int j = 0; j < M; j++)
		{
			board[i][j] = input[j] - '0';
		}
	}

	int dr[4] = { 1, 0, -1, 0 };
	int dc[4] = { 0, 1, 0, -1 };

	queue<pair<int, int>> que;
	que.push({ 0, 0 });
	visited[0][0] = true;

	while (!que.empty())
	{
		pair<int, int> now = que.front(); 
		que.pop();
		if (now.first == N - 1 && now.second == M - 1)
		{
			cout << board[N - 1][M - 1];
			return 0;
		}

		for (int i = 0; i < 4; i++)
		{
			int nextR = now.first + dr[i];
			int nextC = now.second + dc[i];

			if (nextR < 0 || nextR >= N || nextC < 0 || nextC >= M)
				continue;

			if (board[nextR][nextC] == 0)
				continue;

			if (visited[nextR][nextC] == true)
				continue;

			que.push({ nextR, nextC });
			visited[nextR][nextC] = true;
			board[nextR][nextC] = board[now.first][now.second] + 1;
		}
	}

	return 0;
}
