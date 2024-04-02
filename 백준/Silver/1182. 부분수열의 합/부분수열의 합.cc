#include <bits/stdc++.h>

using namespace std;

int input[21]; // input[idx] 는 idx번째 입력값
int sum = 0;

int N;
int S;
int cnt = 0;

void Sol(int idx)
{
	if (idx >= N)
	{
		if (sum == S)
			cnt++;
		return;
	}
	
	sum += input[idx];
	Sol(idx + 1);
	sum -= input[idx];
	Sol(idx + 1);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> S;
	for (int i = 0; i < N; i++)
		cin >> input[i];

	Sol(0);

	if (S == 0 && cnt > 0)
		cnt--;
	cout << cnt;
}
