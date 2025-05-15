#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int dp[101][100001];

// dp[i번째까지 고려][최대 담을 수 있는 무게] = 최대 가치합

int w[101];
int v[101];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
		cin >> w[i] >> v[i];

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			// i번째 넣을 수 있으면
			if (w[i] <= j)
				dp[i][j] = max(dp[i - 1][j-w[i]] + v[i], dp[i-1][j]);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	cout << dp[n][k];
	return 0;
}