#include <iostream>

using namespace std;

int Tile[501][501];
int maxSum = 0;
int n, m;

void Calc_2x2() // 정사각
{
	// 2x2 기준으로 배치
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < m - 1; j++)
		{
			int sum = Tile[i][j] + Tile[i][j + 1] + Tile[i + 1][j] + Tile[i+1][j + 1];
			maxSum = max(maxSum, sum);
		}
	}
}
                                               
// 3x2 모양으로!
void Calc_3x2() // L , ㄱㄴ, ㅏ
{
	
	for (int i = 0; i < n - 2; i++)
	{
		for (int j = 0; j < m - 1; j++)
		{
			int sumAll = Tile[i][j] + Tile[i][j+1] + Tile[i+1][j] + Tile[i+1][j+1] + Tile[i+2][j] + Tile[i+2][j+1];

			// L 
			maxSum = max(maxSum, sumAll - (Tile[i][j + 1] + Tile[i + 1][j + 1]));
			maxSum = max(maxSum, sumAll - (Tile[i+1][j + 1] + Tile[i + 2][j + 1]));
			maxSum = max(maxSum, sumAll - (Tile[i][j] + Tile[i + 1][j]));
			maxSum = max(maxSum, sumAll - (Tile[i+1][j] + Tile[i + 2][j]));

			// ㄱㄴ 세운모양
			maxSum = max(maxSum, sumAll - (Tile[i][j] + Tile[i + 2][j + 1]));
			maxSum = max(maxSum, sumAll - (Tile[i][j + 1] + Tile[i + 2][j]));

			// ㅏ, ㅓ 모양
			maxSum = max(maxSum, sumAll - (Tile[i][j + 1] + Tile[i + 2][j + 1]));
			maxSum = max(maxSum, sumAll - (Tile[i][j] + Tile[i + 2][j]));
		}
	}
}

// 2x3 모양으로!
void Calc_2x3() // ㄴ , ㄱㄴ, ㅜ
{
	// ㄴ
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < m - 2; j++)
		{
			int sumAll = Tile[i][j] + Tile[i][j+1] + Tile[i][j+2] + Tile[i+1][j] + Tile[i+1][j+1] + Tile[i+1][j+2];

			maxSum = max(maxSum, sumAll - (Tile[i][j] + Tile[i][j + 1]));
			maxSum = max(maxSum, sumAll - (Tile[i][j + 1] + Tile[i][j + 2]));
			maxSum = max(maxSum, sumAll - (Tile[i + 1][j] + Tile[i + 1][j+1]));
			maxSum = max(maxSum, sumAll - (Tile[i+1][j+1] + Tile[i + 1][j+2]));

			// ㄱㄴ 누운모양
			maxSum = max(maxSum, sumAll - (Tile[i][j] + Tile[i + 1][j + 2]));
			maxSum = max(maxSum, sumAll - (Tile[i+1][j] + Tile[i][j+2]));

			// ㅗ, ㅜ 모양
			maxSum = max(maxSum, sumAll - (Tile[i][j] + Tile[i][j + 2]));
			maxSum = max(maxSum, sumAll - (Tile[i+1][j] + Tile[i + 1][j+2]));
		}
	}
}

void Calc_4x1() // ㅣ 모양
{
	for (int i = 0; i < n - 3; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int sumAll = Tile[i][j] + Tile[i+1][j] + Tile[i+2][j] + Tile[i+3][j];
			maxSum = max(maxSum, sumAll);
		}
	}
}
void Calc_1x4() // ㅡ 모양
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m - 3; j++)
		{
			int sumAll = Tile[i][j] + Tile[i][j+1] + Tile[i][j+2] + Tile[i][j+3];
			maxSum = max(maxSum, sumAll);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> Tile[i][j];
		}
	}
	Calc_1x4();
	Calc_4x1();
	Calc_2x2();
	Calc_2x3();
	Calc_3x2();
	
	cout << maxSum;

	return 0;
}