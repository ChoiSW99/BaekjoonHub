/*
https://www.acmicpc.net/problem/2579
*/

#include <bits/stdc++.h>

using namespace std;

int dp[2][305]; // [연속한칸][계단번호]
int stair[305]; // 계단 점수

// dp[0][x] = max(dp[0][x-2]+stair[x], dp[1][x-2]+stair[x]) 
// dp[1][x] = dp[0][x-1]+stair[x]

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> stair[i];

	dp[0][1] = stair[1];

	dp[0][2] = stair[2];
	dp[1][2] = stair[1]+ stair[2];


	for (int i = 3; i <= N; i++)
	{
		dp[0][i] = max(dp[0][i - 2] + stair[i], dp[1][i - 2] + stair[i]);
		dp[1][i] = dp[0][i - 1] + stair[i];
	}
	cout << max(dp[0][N], dp[1][N]);

	return 0;
}
