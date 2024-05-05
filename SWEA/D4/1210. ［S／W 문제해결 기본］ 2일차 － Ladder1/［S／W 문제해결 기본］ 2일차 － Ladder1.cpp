#include <bits/stdc++.h>
using namespace std;

int Ladder[100][100];
bool Visited[100][100];

// 왼쪽 오른쪽 위쪽
int dr[3] = {0, 0, -1};
int dc[3] = {-1, +1, 0};
// 도착지점에서 거꾸로 올라가는 식으로 찾기!
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T = 10;
	for(int t = 1; t<=T; t++)
	{
		memset(Visited, 0, sizeof(Visited));
		cin >> t;
		queue<pair<int, int>> que;

		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < 100; j++)
				cin >> Ladder[i][j];
			if (i == 99)
			{
				for (int j = 0; j < 100; j++)
				{
					if (Ladder[i][j] == 2)
					{
						que.emplace(i, j);
						Visited[i][j] = true;
						break;
					}
				}
			}
		}
		while (true)
		{
			auto cur = que.front(); que.pop();
			int row = cur.first;
			int col = cur.second;
			if (row == 0)
			{
				cout << "#" << t << " " << col << '\n';
				break;
			}

			// 왼쪽->오른쪽->위쪽
			for (int n = 0; n < 3; n++)
			{
				int nextRow = row + dr[n];
				int nextCol = col + dc[n];
				if (nextRow < 0 || nextRow >= 100 || nextCol < 0 || nextCol >= 100)
					continue;
				if (!Visited[nextRow][nextCol] && Ladder[nextRow][nextCol] == 1)
				{
					que.emplace(nextRow, nextCol);
					Visited[nextRow][nextCol] = true;
					break;
				}
			}
		}
	}
	return 0;
}