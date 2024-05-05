#include <bits/stdc++.h>
using namespace std;

bool Queen[10][10]; 
int cnt;
int N;

void Sol(int row)
{
	if (row == N)
	{
		cnt++;
		return;
	}

	for (int col = 0; col < N; col++)
	{
		bool can = true;
		for (int r = row-1, dc = 1; r >= 0; r--, dc++)
		{
			// 위쪽에 이미 놓여있는지
			if (Queen[r][col] == 1)
			{
				can = false;
				break;
			}
			// 대각에 이미 놓여있는지
			if (col - dc >= 0)
			{
				if (Queen[r][col - dc] == 1)
				{
					can = false;
					break;
				}
			}
			if (col + dc < N)
			{
				if (Queen[r][col + dc] == 1)
				{
					can = false;
					break;
				}
			}
		}

		if (can)
		{
			Queen[row][col] = 1;
			Sol(row + 1);
			Queen[row][col] = 0;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T;

	for(int t = 1; t<=T; t++)
	{
		memset(Queen, 0, sizeof(Queen)); // 0 초기화
		cnt = 0;
		cin >> N;

		for (int col = 0; col < N; col++)
		{
			Queen[0][col] = 1;
			Sol(1);
			Queen[0][col] = 0;
		}

		cout << "#" << t << " " << cnt << '\n';
	}
	return 0;
}