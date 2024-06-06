#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int Lab[9][9];
bool Visited[9][9];
int N, M;
int dr[4] = { 0,0,-1,+1 };
int dc[4] = { -1,+1, 0, 0 };

vector<pair<int, int>> safeArea; // 안전구역 위치들
vector<pair<int, int>> virus; // 바이러스 위치들

int BFS()
{
	int virusAreaCnt = 0; // 바이러스가 퍼진 안전영역 크기 합
	queue<pair<int, int>> que;
	for (pair<int, int> v : virus)
	{
		que.push({v.first, v.second});
		Visited[v.first][v.second] = true;
	}

	while (!que.empty())
	{
		pair<int, int> v = que.front();
		que.pop();

		for (int i = 0; i < 4; i++)
		{
			int nr = v.first + dr[i];
			int nc = v.second + dc[i];

			if (nr < 0 || nc < 0 || nr >= N || nc >= M) continue;

			if (Lab[nr][nc] != 0) continue;

			if (Visited[nr][nc]) continue;

			virusAreaCnt++;
			que.push({ nr,nc });
			Visited[nr][nc] = true;
		}
	}
	return virusAreaCnt;
}

// 0은 빈 칸, 1은 벽, 2는 바이러스
// 바이러스가 최소로 퍼지는 경우를 구해야한다.
// (초기 안전영역 크기) - (최소로 퍼진 경우의 바이러스 구역들 크기 합)
// 
// 바이러스 구역은 BFS나 DFS로 구하기 !
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	int safetyArea = 0;

	int minOccupiedArea = 100; // 안전구역 중, 바이러스가 차지한 최소 영역

	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < M; c++)
		{
			int x; cin >> x;
			Lab[r][c] = x;
			if (x == 0)
			{
				safeArea.emplace_back(r, c);
				safetyArea++;
			}
			else if (x == 2)
				virus.emplace_back(r, c);
		}
	}

	for (int i = 0; i < safeArea.size(); i++)
	{
		for (int j = 0; j < i; j++)
		{
			for (int k = 0; k < j; k++)
			{
				memset(Visited, false, sizeof(Visited));
				pair<int, int> s1 = safeArea[i];
				pair<int, int> s2 = safeArea[j];
				pair<int, int> s3 = safeArea[k];
				Lab[s1.first][s1.second] = 1;
				Lab[s2.first][s2.second] = 1;
				Lab[s3.first][s3.second] = 1;

				int areaCnt = BFS();
				minOccupiedArea = min(minOccupiedArea, areaCnt);

				Lab[s1.first][s1.second] = 0;
				Lab[s2.first][s2.second] = 0;
				Lab[s3.first][s3.second] = 0;
			}
		}
	}
	safetyArea -= 3; // 벽 3개
	cout << safetyArea - minOccupiedArea;

	return 0;
}