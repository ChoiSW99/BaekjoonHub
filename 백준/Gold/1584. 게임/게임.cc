//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <tuple>
#include <memory.h>

using namespace std;

// 안전0 위험1 죽음2
int MAP[501][501];
int VISITED[501][501];

// 상하좌우
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

typedef tuple<int, int, int> tiii;

void SetMapValue(int x1, int y1, int x2, int y2, int value)
{
	for (int startX = min(x1, x2); startX <= max(x1, x2); startX++)
	{
		for (int startY = min(y1, y2); startY <= max(y1, y2); startY++)
		{
			MAP[startX][startY] = value;
		}
	}
}

int Heuristic(int x, int y)
{
	return (1000 - x - y);
}

int main()
{
	//freopen("input.txt", "r", stdin);
	memset(MAP, 0, sizeof(MAP));
	memset(VISITED, -1, sizeof(VISITED));

	int N; // 위험구역 수
	int M; // 죽음구역 수

	cin >> N;
	int x1, y1, x2, y2;
	for (int idx = 0; idx < N; idx++)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		SetMapValue(x1, y1, x2, y2, 1);
	}
	cin >> M;
	for (int idx = 0; idx < M; idx++)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		SetMapValue(x1, y1, x2, y2, 2);
	}

	priority_queue<tiii, vector<tiii>, greater<tiii>> pq; // f, row,col
	pq.emplace(0,0,0);
	VISITED[0][0] = 0;

	while (!pq.empty())
	{
		tiii cur = pq.top();
		pq.pop();

		// int f = get<0>(cur);
		int row = get<1>(cur);
		int col = get<2>(cur);
		//cout << row << ' ' << col << '\n';

		for (int idx = 0; idx < 4; idx++)
		{
			int nextRow = row + dr[idx];
			int nextCol = col + dc[idx];

			// MAP 범위 밖
			if (nextRow < 0 || nextRow > 500 || nextCol < 0 || nextCol > 500)
				continue;

			// 죽음 구역
			if (MAP[nextRow][nextCol] == 2)
				continue;

			// 이미 방문
			if(VISITED[nextRow][nextCol] != -1)
				continue;


			VISITED[nextRow][nextCol] = VISITED[row][col] + MAP[nextRow][nextCol]; 
			pq.emplace(1000*(VISITED[nextRow][nextCol])+Heuristic(nextRow, nextCol), nextRow, nextCol);

			if (nextRow == 500 && nextCol == 500)
			{
				cout << VISITED[nextRow][nextCol];
				return 0;
			}
		}
	}
	cout << -1;
	return 0;
}