#include <bits/stdc++.h>

using namespace std;

int Flavor[21];
int Calorie[21];

int dp[21][10001]; // dp[i][j] : i번까지 고려했고 최대칼로리 j일 때의 맛의 최대합

// j>= Calorie[i] 일 때, 
// (i번째 넣는 것과 안넣는 것 비교하기)
// dp[i][j] = dp[i-1][j-Calorie[i]] + v[i]  vs  dp[i-1][j]

// j < Calorie[i] 일 때,
// (이전 상태 유지)
// dp[i][j] = dp[i-1][j]; 

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	//freopen("input.txt", "r", stdin);
	int T; cin >> T;
	for (int t = 1; t <= T; t++)
	{
		memset(dp, 0, sizeof(dp));

		int N, L;
		cin >> N >> L; // 재료개수, 최대칼로리
		for (int n = 1; n <= N; n++)
			cin >> Flavor[n] >> Calorie[n];

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= L; j++)
			{
				if (j >= Calorie[i])
					dp[i][j] = max(dp[i - 1][j - Calorie[i]] + Flavor[i], dp[i - 1][j]);
				else
					dp[i][j] = dp[i - 1][j];
			}
		}

		cout << "#" << t << " " << dp[N][L] << '\n';
	}
	return 0;
}