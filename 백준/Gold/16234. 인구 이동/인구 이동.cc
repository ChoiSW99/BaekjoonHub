#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int Ground[51][51];

bool Visited[51][51]; // 공유하는 나라들 평균계산 고려됐는지
int dr[4] = { 0,0,-1,+1 };
int dc[4] = { -1,+1, 0, 0 };

int N, L, R; // NxN 크기땅 , L명이상 R명이하

bool CheckOccured()
{
	bool hasOccured = false;
	memset(Visited, false, sizeof(Visited));
	// 한번 BFS 돌았을 때, Visited[r][c] = true처리가 된 것들끼리는
	// 국경선 공유하는 것임.

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (Visited[i][j])
				continue;

			queue<pair<int, int>> que;
			que.push({ i,j });
			Visited[i][j] = true;

			vector<pair<int, int>> shares; // 국경선을 공유하는 나라들
			shares.push_back({ i,j });

			while (!que.empty())
			{
				int nowR = que.front().first;
				int nowC = que.front().second;
				que.pop();

				for (int i = 0; i < 4; i++)
				{
					int nextR = nowR + dr[i];
					int nextC = nowC + dc[i];

					if (nextR < 0 || nextR >= N || nextC < 0 || nextC >= N)
						continue;

					if (Visited[nextR][nextC])
						continue;

					int diff = abs(Ground[nowR][nowC] - Ground[nextR][nextC]);
					if (L <= diff && diff <= R)
					{
						que.push({ nextR, nextC });
						shares.push_back({ nextR, nextC });
						Visited[nextR][nextC] = true;
					}
				}
			}

			int sharedCnt = shares.size();
			if (sharedCnt > 1)
			{
				int sum = 0;

				for (auto& s : shares)
					sum += Ground[s.first][s.second];
				
				int avg = sum / sharedCnt;

				for (auto& s : shares)
					Ground[s.first][s.second] = avg;

				hasOccured = true;
			}
		}
	}
	return hasOccured;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> L >> R;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> Ground[i][j];
		}
	}

	int days = 0;
	while (true)
	{
		bool hasOccured = CheckOccured();
		if (hasOccured)
			days++;
		else
			break;
	}
	cout << days;

	return 0;
}