#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

// https://www.acmicpc.net/problem/4485 녹색 옷 입은 애가 젤다지?

int main()
{
	//freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int tc = 1;
	int size;

	int dr[4] = { 1, -1, 0, 0 };
	int dc[4] = { 0, 0, -1, 1 };

	while (true)
	{
		cin >> size;

		if (size == 0)
			return 0;

		vector<vector<int>> cave(size, vector<int>(size, 0));
		vector<vector<int>> cost(size, vector<int>(size, 1e9));

		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				cin >> cave[i][j];

		queue<pair<int,int>> que;
		que.emplace(0,0);
		cost[0][0] = cave[0][0];

		while (!que.empty())
		{
			pair<int, int> cur = que.front();
			que.pop();

			for (int idx = 0; idx < 4; idx++)
			{
				int nextRow = cur.first + dr[idx];
				int nextCol = cur.second + dc[idx];

				if (0 <= nextRow && nextRow < size && 0 <= nextCol && nextCol < size)
				{
					if (cost[cur.first][cur.second] + cave[nextRow][nextCol] < cost[nextRow][nextCol])
					{
						cost[nextRow][nextCol] = cost[cur.first][cur.second] + cave[nextRow][nextCol];
						que.emplace(nextRow, nextCol);
					}
				}
			}
		}
		cout << "Problem " << tc << ": " << cost[size - 1][size - 1] << '\n';

		tc++;
	}

	return 0;
}
