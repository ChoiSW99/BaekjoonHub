#include <bits/stdc++.h>

using namespace std;

int sticker[2][100005];
int dp[2][100005];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int tc;
	cin >> tc;
	for (int t = 0; t < tc; t++)
	{
		int n;
		cin >> n;

		for (int r = 0; r < 2; r++)
		{
			for (int c = 0; c < n; c++)
			{
				cin >> sticker[r][c];
			}
		}

		dp[0][0] = sticker[0][0];
		dp[1][0] = sticker[1][0];

		dp[0][1] = max(dp[0][0], dp[1][0] + sticker[0][1]);
		dp[1][1] = max(dp[1][0], dp[0][0] + sticker[1][1]);

		for (int i = 2; i < n; i++)
		{
			dp[0][i] = max( dp[0][i - 1], (dp[1][i - 1] + sticker[0][i]) );
			dp[1][i] = max( dp[1][i - 1], (dp[0][i - 1] + sticker[1][i]) );
		}

		cout << max(dp[0][n-1], dp[1][n-1]) << '\n';
		// 50 10 100
		// 30 50 70

		// dp[0][i] = (dp[0][i-2] + sticker[1][i-1] + sticker[0][i]) vs (dp[1][i-2] + sticker[0][i])
		// dp[1][i] = (dp[1][i-2] + sticker[0][i-1] + sticker[1][i]) vs (dp[0][i-2] + sticker[1][i])
	}

	return 0;
}