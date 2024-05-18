#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int Board[4][4];
int dr[4] = { 0, 0, -1, +1 };
int dc[4] = { -1, +1, 0,  0 };

set<int> s;

bool IsValidArea(int r, int c)
{
	if (r < 0 || r > 3 || c < 0 || c > 3)
		return false;
	return true;
}

void Check(int n, int r, int c, int depth)
{
	if (depth == 6)
	{
		s.insert(n);
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int nextR = r + dr[i];
		int nextC = c + dc[i];
		if (IsValidArea(nextR, nextC))
		{
			int nextNum = n*10 + Board[nextR][nextC];
			Check(nextNum, nextR, nextC, depth + 1);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				cin >> Board[i][j];
		
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				Check(Board[i][j], i, j, 0); // 0번째의 숫자는 Board[i][j]
			}
		}

		cout << "#" << tc << " " << s.size() << '\n';
		s.clear();
	}
}

