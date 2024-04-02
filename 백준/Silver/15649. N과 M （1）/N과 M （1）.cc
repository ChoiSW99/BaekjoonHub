#include <bits/stdc++.h>

using namespace std;
int N, M;
bool isUsed[9];
int arr[9]; // arr[idx] 는 idx번째로 뽑은 수를 저장한다.

void Sol(int depth)
{
	if (depth > M)
	{
		for (int i=1; i<= M; i++)
			cout << arr[i] << " ";
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; i++)
	{
		if ( !isUsed[i] )
		{
			arr[depth] = i;
			isUsed[i] = true;
			Sol(depth + 1);
			isUsed[i] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	vector<int> nums;

	int depth = 1;

	Sol(depth);
}
