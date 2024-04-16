/*
https://www.acmicpc.net/problem/15688
counting sort
*/

#include <bits/stdc++.h>

using namespace std;

int counting[2000002];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n;
		counting[n+1000000]++; // -1,000,000 이면 2,000,000에 저장 // +1,000,000 이면 0에 저장
	}
	for (int i = 0; i <= 2000001; i++)
	{
		while (counting[i] > 0)
		{
			counting[i]--;
			cout << i-1000000 << '\n';
		}
	}
}
