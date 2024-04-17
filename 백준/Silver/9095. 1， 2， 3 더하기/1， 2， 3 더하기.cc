/*
https://www.acmicpc.net/problem/11652
*/

#include <bits/stdc++.h>

using namespace std;

int DP[11];

// DP[k] = DP[k-1]+DP[k-2]+DP[k-3]
// DP[k+4] = DP[k+3] + DP[k+2] + DP[k+1]

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	DP[1] = 1;
	DP[2] = 2;
	DP[3] = 4; // 1 1 1 , 1 2, 3, 2 1

	for (int i = 4; i <= 10; i++)
	{
		DP[i] = DP[i - 1] + DP[i - 2] + DP[i - 3];
	}

	int tc;
	cin >> tc;
	for (int t = 0; t < tc; t++)
	{
		int N;
		cin >> N;

		cout << DP[N] << '\n';
	}
	
	return 0;
}
