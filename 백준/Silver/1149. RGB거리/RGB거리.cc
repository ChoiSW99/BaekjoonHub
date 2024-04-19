/*
https://www.acmicpc.net/problem/1149
*/

#include <bits/stdc++.h>

using namespace std;

int cost[1001][3];
int dp[1001][3];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> cost[i][0] >> cost[i][1] >> cost[i][2];

	dp[1][0] = cost[1][0];
	dp[1][1] = cost[1][1];
	dp[1][2] = cost[1][2];

	for (int i = 2; i <= N; i++)
	{
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];

	}
	cout << min({ dp[N][0],dp[N][1],dp[N][2] });

	return 0;
}
/*
26        40        83
89,132    86, 143   83,97

*/