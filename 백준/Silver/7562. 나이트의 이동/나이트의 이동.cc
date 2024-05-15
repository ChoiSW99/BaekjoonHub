#include <bits/stdc++.h>
using namespace std;

int Board[301][301];
bool Visited[301][301];

int dr[8] = {-2, -1, +1, +2, +2, +1, -1, -2};
int dc[8] = {+1, +2, +2, +1, -1, -2, -2, -1};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc; cin >> tc;
	for (int t = 0; t < tc; t++)
	{
		memset(Board, 0, sizeof(Board));
		memset(Visited, 0, sizeof(Visited));

		int l; cin >> l;
		queue<pair<int, int>> que;
		int startRow, startCol;
		cin >> startRow >> startCol;
		que.emplace(startRow, startCol); 
		Visited[startRow][startCol] = 1;
		
		int goalRow, goalCol; 
		cin >> goalRow >> goalCol;

		while (!que.empty())
		{
			auto now = que.front(); que.pop();
			int row = now.first;
			int col = now.second;
			if (row == goalRow && col == goalCol)
			{
				cout << Board[row][col] << '\n';
				break;
			}

			for (int i = 0; i < 8; i++)
			{
				int nextR = row + dr[i];
				int nextC = col + dc[i];
				if (nextR < 0 || nextR >= l || nextC < 0 || nextC >= l)
					continue;
				if (Visited[nextR][nextC])
					continue;
				Board[nextR][nextC] = Board[row][col] + 1;
				Visited[nextR][nextC] = 1;
				que.emplace(nextR, nextC);
			}
		}
	}
	return 0;
}