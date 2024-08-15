#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;
// 0은 빈 칸, 1은 벽, 2는 바이러스가

int N, M;
int Map[9][9];

vector<pair<int, int>> emptyAreas;
vector<pair<int, int>> virusAreas;

int dr[4] = { 0, 0, -1, 1 };
int dc[4] = { -1, 1, 0, 0 };

bool visited[9][9];

int cntSpreadVirus() {
	int result = 0;

	memset(visited, false, sizeof(visited));

	queue<pair<int, int>> que;
	for (pair<int, int> virus : virusAreas) {
		que.push(make_pair(virus.first, virus.second));
		visited[virus.first][virus.second] = true;
	}

	while (!que.empty()) {
		int r = que.front().first;
		int c = que.front().second;
		que.pop();

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];

			if (nr < 0 || nr >= N || nc < 0 || nc >= M)
				continue;
			if (visited[nr][nc])
				continue;

			if (Map[nr][nc] == 0) {
				que.push(make_pair(nr, nc));
				visited[nr][nc] = true;
				result++;
			}
		}
	}

	return result;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int result = -1;
	int cntEmptyAreas = 0;
	
	//freopen("input.txt", "r", stdin);
	
	cin >> N >> M;
	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			int x;
			cin >> x;
			Map[n][m] = x;

			if (x == 0) {
				emptyAreas.push_back({ n, m });
				cntEmptyAreas++;
			}
			else if (x == 2)
				virusAreas.push_back({ n, m });
		}
	}

	int s = emptyAreas.size();

	// 3곳 선택하여 벽 세우기
	for (int i = 0; i < s; i++) {
		for (int j = i + 1; j < s; j++) {
			for (int k = j + 1; k < s; k++) {
				pair<int, int> w1 = emptyAreas[i];
				pair<int, int> w2 = emptyAreas[j];
				pair<int, int> w3 = emptyAreas[k];
				Map[w1.first][w1.second] = 1;
				Map[w2.first][w2.second] = 1;
				Map[w3.first][w3.second] = 1;
				
				result = max(result, (cntEmptyAreas - 3 - cntSpreadVirus()));

				Map[w1.first][w1.second] = 0;
				Map[w2.first][w2.second] = 0;
				Map[w3.first][w3.second] = 0;
			}
		}
	}

	cout << result;
	
	return 0;
}