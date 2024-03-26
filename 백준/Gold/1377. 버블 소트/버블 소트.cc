//#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	int N;
	cin >> N;

	int input;
	vector<pair<int, int>> A;
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		A.emplace_back(input, i);
	}

	sort(A.begin(), A.end());

	int result = 0;
	for (int i = 0; i < N; i++)
	{
		// 정렬 후 인덱스 i
		// 정렬 전 인덱스 A[i].second
		// 왼쪽으로 최대로 옮겨간 것! 
		result = max(result, A[i].second - i);
	}
	cout << result + 1;
	/*bool changed = false;

	for (int i = 1; i < N+1; i++)
	{
		changed = false;
		for (int j = 1; j < N-i; j++)
		{
			if (A[j] > A[j + 1])
			{
				changed = true;
				swap(A[j], A[j + 1]);
			}
		}

		if (changed == false)
		{
			cout << i << endl;
			break;
		}
	}*/

	return 0;
}