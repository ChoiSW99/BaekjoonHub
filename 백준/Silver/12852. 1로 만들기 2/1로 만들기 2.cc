/*
https://www.acmicpc.net/problem/12852
*/

#include <bits/stdc++.h>

using namespace std;

/*
1 -> 2, 3 -> 

dp[100001][2]
dp[2][0]은 2를 최소로 만들기 전 숫자
dp[2][1]은 2를 만들때까지 연산 횟수 ( 최소가 되어야함 )

*/

int dp[1000001][2];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	
	for (int i = 2; i <= N; i++)
	{
		dp[i][0] = i - 1;
		dp[i][1] = dp[i - 1][1] + 1;
		if (i % 2 == 0)
		{
			if (dp[i][1] > dp[i / 2][1] + 1)
			{
				dp[i][0] = i / 2;
				dp[i][1] = dp[i / 2][1] + 1;
			}
		}
		if (i % 3 == 0)
		{
			if (dp[i][1] > dp[i / 3][1] + 1)
			{
				dp[i][0] = i / 3;
				dp[i][1] = dp[i / 3][1] + 1;
			}
		}
	}

	cout << dp[N][1] << '\n';

	int cur = N;
	cout << cur << " ";
	while (cur > 1)
	{
		cur = dp[cur][0];
		cout << cur << " ";
	}

	return 0;
}

// 10 9 3 1
// 10 5 4 2 1