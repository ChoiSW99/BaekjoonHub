/*
https://www.acmicpc.net/problem/11652
*/

#include <bits/stdc++.h>

using namespace std;

int DP[1000001];

// DP[k] = min(DP[k/3], DP[k/2], DP[k-1])

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	fill(begin(DP), end(DP), 1000001);

	int N;
	cin >> N;

	DP[1] = 0;

	for (int i = 2; i <= N; i++)
	{
		if (i % 3 == 0)
			DP[i] = min(DP[i], DP[i/3] + 1);
		if (i % 2 == 0)
			DP[i] = min(DP[i], DP[i/2] + 1);
		DP[i] = min(DP[i], DP[i-1] + 1);
	}
	cout << DP[N];
	return 0;
}
