#include <bits/stdc++.h>

using namespace std;

int cave[126][126];
bool visited[126][126];

int dr[4] = {0, 0, -1, +1};
int dc[4] = {-1, +1, 0, 0};

using tiii = tuple<int, int, int>;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int tc = 0;
	while (true)
	{
		++tc;
		memset(cave, 0, sizeof(cave));
		memset(visited, 0, sizeof(visited));

		int N; cin >> N;
		if (N == 0) break;

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> cave[i][j];

		priority_queue< tiii, vector<tiii>, greater<tiii>> pq;
		pq.emplace(cave[0][0], 0, 0);
		visited[0][0] = 1;
		
		while (!pq.empty())
		{
			auto now = pq.top(); pq.pop();
			int weight = get<0>(now);
			int row = get<1>(now);
			int col = get<2>(now);
			if (row == N - 1 && col == N - 1)
			{
				cout << "Problem " << tc << ": " << weight << '\n';
				break;
			}
			for (int i = 0; i < 4; i++)
			{
				int nextR = row + dr[i];
				int nextC = col + dc[i];

				if (nextR < 0 || nextR >= N || nextC < 0 || nextC >= N)
					continue;
				if (visited[nextR][nextC])
					continue;
				pq.emplace(weight + cave[nextR][nextC], nextR, nextC);
				visited[nextR][nextC] = 1;
			}
		}
	}
}