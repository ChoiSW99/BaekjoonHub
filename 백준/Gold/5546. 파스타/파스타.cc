//#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

// https://www.acmicpc.net/problem/5546

int dp[101][4][3]; // i(0~100)일에 j(0~3)파스타를 먹었을 때 k(0~2)번 연속으로 먹는 경우의 수

int main()
{
	//freopen("input.txt", "r", stdin);

	int n, k;
	cin >> n >> k;

	unordered_map<int, int> day_pasta;

	int day, pasta;
	for (int i = 0; i < k; i++)
	{
		cin >> day >> pasta;
		day_pasta[day] = pasta;
	}

	// 첫날
	if (day_pasta.find(1) != day_pasta.end()) // 파스타 정해진 날
		dp[1][day_pasta[1]][1] = 1;
	else
	{
		dp[1][1][1] = 1;
		dp[1][2][1] = 1;
		dp[1][3][1] = 1;
	}

	for (int i = 2; i <= n; i++)
	{
		if (day_pasta.find(i) != day_pasta.end()) // i번째 날은 파스타 day_pasta[i]로 정해진 날
		{
			for (int j = 1; j <= 3; j++)
			{
				if(j != day_pasta[i])
					dp[i][day_pasta[i]][1] += (dp[i - 1][j][1] + dp[i - 1][j][2]) % 10000;
			}

			dp[i][day_pasta[i]][2] += dp[i - 1][day_pasta[i]][1] % 10000;
		}
		else 
		{
			for (int j = 1; j <= 3; j++)
			{
				for (int jj = 1; jj <= 3; jj++)
				{
					if (j != jj)
						dp[i][j][1] += ( dp[i - 1][jj][1] + dp[i - 1][jj][2] ) % 10000;

				}
				dp[i][j][2] += dp[i - 1][j][1] % 10000;
			}

			/*
			dp[i][1][1] += ( dp[i - 1][2][1] + dp[i - 1][2][2] );
			dp[i][1][1] += ( dp[i - 1][3][1] + dp[i - 1][3][2] );

			dp[i][1][2] += dp[i - 1][1][1];

			
			dp[i][2][1] += (dp[i - 1][1][1] + dp[i - 1][1][2] + dp[i - 1][3][1] + dp[i - 1][3][2]);

			dp[i][2][2] += dp[i - 1][2][1];

			
			dp[i][3][1] += (dp[i - 1][1][1] + dp[i - 1][1][2] + dp[i - 1][2][1] + dp[i - 1][2][2]);

			dp[i][3][2] += dp[i - 1][3][1];
			*/

		}
	}
	int result = 0;
	for (int j = 1; j <= 3; j++)
	{
		for (int k = 1; k <= 2; k++)
		{
			//cout << dp[n][j][k] << '\n';
			result += dp[n][j][k] % 10000;
		}
	}
	cout << result % 10000;
}
