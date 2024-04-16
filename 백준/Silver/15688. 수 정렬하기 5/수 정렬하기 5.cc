// https://www.acmicpc.net/problem/2751
// stable sort : 앞의 배열과 뒤의 배열에서 현재 가리키는 값이 같을 때, 앞의 원소를 먼저 넣어주는 것
// merge sort는 stable sort임. 
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
		counting[1000000-n]++; // -1,000,000 이면 2,000,000에 저장 // +1,000,000 이면 0에 저장
	}
	for (int i = 2000000; i >= 0; i--)
	{
		while (counting[i] > 0)
		{
			counting[i]--;
			cout << 1000000-i << '\n';
		}
	}
}
