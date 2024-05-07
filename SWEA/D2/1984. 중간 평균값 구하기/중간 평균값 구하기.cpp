#include <bits/stdc++.h>
using namespace std;

int Input[10];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T;

	for (int t = 1; t <= T; t++)
	{
		for (int i = 0; i < 10; i++)
			cin >> Input[i];
		sort(begin(Input), end(Input)); // default는 less<>(), 오름차순
		float sum = 0.0f;
		for (int i = 1; i < 9; i++)
			sum += Input[i];
		cout << "#" << t <<" " << round(sum/8) << '\n';
	}
	return 0;
}