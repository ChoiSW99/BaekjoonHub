#include <bits/stdc++.h>

using namespace std;

// https://www.acmicpc.net/problem/23256

int Full_DP[1000001];
int NotFull_DP[1000001];

const int divisor = 1000000007;

int Calc(int num, int m)
{
	int result = 0;
	for (int i = 0; i < m; i++)
	{
		result = (result + num) % divisor;
	}
	return result;
}

int main()
{
	int t,n;
	cin >> t;
	vector<int> nums;


	for (int i=0; i < t; i++)
	{
		cin >> n;
		nums.push_back(n);
	}
	int maxN = *max_element(nums.begin(), nums.end());

	Full_DP[1] = 7;
	NotFull_DP[1] = 3;
	for (int i = 2; i <= maxN; i++)
	{
		Full_DP[i] = (Calc(Full_DP[i - 1], 3) + Calc(NotFull_DP[i - 1], 4)) % divisor; // (Full_DP[i - 1] % divisor * 3 + NotFull_DP[i - 1] * 4) % divisor;
		NotFull_DP[i] = (Full_DP[i - 1] + Calc(NotFull_DP[i - 1], 2)) % divisor;

//		Full_DP[i] = (Full_DP[i - 1] % divisor * 3 + NotFull_DP[i - 1] * 4) % divisor;
//		NotFull_DP[i] = (Full_DP[i - 1] + NotFull_DP[i - 1] * 2) % divisor;
	}
	
	for (int n : nums)
		cout << Full_DP[n] % divisor << '\n';

	return 0;
}

