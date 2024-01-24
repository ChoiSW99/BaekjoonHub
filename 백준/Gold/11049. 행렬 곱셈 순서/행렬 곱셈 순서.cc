//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int Mat[501][2];
int dp[501][501]; // dp[a][b] 행렬a부터 b까지의 필요한 곱셈 연산 횟수의 최솟값
int N; // 행렬 개수
const int INF = INT_MAX;

// Divide & Conquer
int DP(int start, int end)
{
	if (start == end)
		return dp[start][end] = 0;

	if (dp[start][end] != INF)
		return dp[start][end];

	for (int mid = start; mid < end; mid++)
	{
		int left = DP(start, mid);
		int right = DP(mid+1, end);
		int temp = left + right + Mat[start][0] * Mat[mid][1] * Mat[end][1];
		dp[start][end] = min(dp[start][end], temp);
	}
	return dp[start][end];
}
                                                                                                                          
int main()
{
	//freopen("input.txt", "r", stdin);
	fill(&Mat[0][0], &Mat[0][0] + 501 * 2, -1);
	fill(&dp[0][0], &dp[0][0] + 501 * 501, INF);
	cin >> N;

	int r, c;
	for (int i = 0; i < N; i++)
	{
		cin >> r >> c;
		Mat[i][0] = r;
		Mat[i][1] = c;
	}
	cout << DP(0, N-1);
}