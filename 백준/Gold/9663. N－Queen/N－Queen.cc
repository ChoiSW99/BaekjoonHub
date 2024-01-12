#include <bits/stdc++.h>

using namespace std;

const int MAX = 15;
int N = 0;
int result = 0;
int board[MAX] = { -1, };

bool isPromising(int row)
{
	for (int r = 0; r < row; r++)
	{
		// 세로
		if (board[r] == board[row])
			return false;
		// 대각
		if (row - r == abs(board[row] - board[r]))
			return false;
	}
	return true;
}

void N_Queens(int row)
{
	if (row == N) {
		result++;
		return;
	}

	for (int col = 0; col < N; col++)
	{
		board[row] = col;
		
		if (isPromising(row))
			N_Queens(row + 1);
	}

	
}

int main()
{
	ios_base::sync_with_stdio(false);

	cin >> N;

	N_Queens(0);
	cout << result;
}