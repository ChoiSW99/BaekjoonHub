#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int DP[301][2] = {0,}; // [계단번호][연속오르기]
int SCORE[301] = { 0, };
// https://www.acmicpc.net/problem/2579 계단오르기

int main()
{
	//freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N; // 계단 개수
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int score;
		cin >> score;
		SCORE[i+1] = score;
	}
	DP[1][0] = SCORE[1];
	DP[2][0] = SCORE[2];
	DP[2][1] = DP[1][0] + SCORE[2];

	for (int i = 3; i <= N; i++)
	{
		DP[i][0] = max(DP[i - 2][0], DP[i - 2][1]) + SCORE[i];
		DP[i][1] = DP[i - 1][0] + SCORE[i];
	}

	cout << max(DP[N][0], DP[N][1]);
}