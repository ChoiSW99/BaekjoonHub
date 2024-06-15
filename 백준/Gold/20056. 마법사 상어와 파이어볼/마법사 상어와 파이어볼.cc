#include<iostream>
#include<queue>
#include<tuple>
#include<cstring>

using namespace std;

int N, M, K; // NxN 격자, M 파이어볼수, K번 이동 명령

queue<tuple<int, int, int>> Grid[51][51]; // 1번 행은 N번과 연결되어 있고, 1번 열은 N번 열과 연결되어 있다.
int Count[51][51]; // 몇개의 파이어볼이 있는지
int tempCount[51][51];

// 방향
int dr[8] = { -1, -1, 0, 1, 1,1,0,-1 };
int dc[8] = { 0,1,1,1,0,-1,-1,-1 };

// 이동 명령
void Move()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (tempCount[i][j] == 0)
				continue;
			for (int c = 0; c < tempCount[i][j]; c++)
			{
				auto g = Grid[i][j].front();
				Grid[i][j].pop();

				int m = get<0>(g);
				int s = get<1>(g);
				int d = get<2>(g);

				int nextRow = i + s * dr[d];
				if (nextRow < 1)
				{
					nextRow = N - abs(nextRow) % N;
				}
				else if (nextRow > N)
				{
					if ((nextRow % N) == 0)
						nextRow = N;
					else
						nextRow %= N;
				}

				int nextCol = j + s * dc[d];
				if (nextCol < 1)
				{
					nextCol = N - abs(nextCol) % N;
				}
				else if (nextCol > N)
				{
					if ((nextCol % N) == 0)
						nextCol = N;
					else
						nextCol %= N;
				}

				Grid[nextRow][nextCol].push({ m,s,d });
				Count[nextRow][nextCol]++;
			}
		}
	}
}

// 분열 명령
void Act()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			// 2개 이상이면 분열
			if (Count[i][j] >= 2)
			{
				int newM = 0; // 질량
				int newS = 0; // 속력
				bool isAllOdd = true; // 모두 홀수인지
				bool isAllEven = true; // 모두 짝수인지

				int cnt = Grid[i][j].size();
				while (!Grid[i][j].empty())
				{
					auto g = Grid[i][j].front();
					Grid[i][j].pop();

					newM += get<0>(g);
					newS += get<1>(g);
					int d = get<2>(g);

					if (d % 2 == 0)
					{
						isAllOdd &= false;
						isAllEven &= true;
					}
					else
					{
						isAllOdd &= true;
						isAllEven &= false;
					}
				}

				newM /= 5;
				// 질량이 0인 파이어볼은 소멸되어 없어진다.
				if (newM == 0)
				{
					Count[i][j] = 0;
					continue;
				}

				newS /= cnt;

				// 모두 홀수이거나 모두 짝수이면
				if (isAllEven || isAllOdd)
				{
					Grid[i][j].push({ newM, newS, 0 });
					Grid[i][j].push({ newM, newS, 2 });
					Grid[i][j].push({ newM, newS, 4 });
					Grid[i][j].push({ newM, newS, 6 });
					Count[i][j] = 4;
				}
				else
				{
					Grid[i][j].push({ newM, newS, 1 });
					Grid[i][j].push({ newM, newS, 3 });
					Grid[i][j].push({ newM, newS, 5 });
					Grid[i][j].push({ newM, newS, 7 });
					Count[i][j] = 4;
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> K;

	for (int i = 0; i < M; i++)
	{
		int r, c, m, s, d;
		cin >> r >> c >> m >> s >> d;
		Grid[r][c].push({ m,s,d }); // { 질량은 m, 속력은 s, 방향은 d }
		Count[r][c]++;
	}

	while (K-- > 0)
	{
		memset(tempCount, 0, sizeof(tempCount));

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				tempCount[i][j] = Count[i][j];
				Count[i][j] = 0;
			}
		}

		Move();
		Act();
	}

	int mSum = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (Count[i][j] == 0)
				continue;

			while (!Grid[i][j].empty())
			{
				auto g = Grid[i][j].front();
				Grid[i][j].pop();

				mSum += get<0>(g);
			}
		}
	}
	cout << mSum;
	return 0;
}