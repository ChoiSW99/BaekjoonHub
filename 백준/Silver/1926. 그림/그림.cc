#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	bool board[502][502];

	int dr[4] = { 1, 0, -1, 0 };
	int dc[4] = { 0, 1, 0, -1 };

	int cnt = 0;
	int maxArea = 0;

	int n, m;
	cin >> n >> m;

	for (int r = 0; r < n; r++)
		for (int c = 0; c < m; c++)
			cin >> board[r][c];

	queue<pair<int, int>> que;

	for (int r = 0; r < n; r++)
	{
		for (int c = 0; c < m; c++)
		{
			if (board[r][c] == 0)
				continue;

			que.push({ r,c });
			board[r][c] = 0;
			int area = 1;
			cnt++;

			while (!que.empty())
			{
				pair<int, int> now = que.front(); 
				que.pop();

				for (int i = 0; i < 4; i++)
				{
					int row = now.first + dr[i];
					int col = now.second + dc[i];
					if (row<0 || row > n-1 || col <0 || col > m-1)
						continue;
					if (board[row][col] == 0)
						continue;

					que.push({ row, col });
					board[row][col] = 0;
					area++;
				}
			}
			if (maxArea < area)
				maxArea = area;
		}
	}
	cout << cnt << '\n' << maxArea;
	return 0;
}