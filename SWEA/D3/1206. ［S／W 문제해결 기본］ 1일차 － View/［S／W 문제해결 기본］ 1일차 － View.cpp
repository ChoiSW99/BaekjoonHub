#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc = 10;
	for(int t=1; t<=tc; t++)
	{
		int n; // 건물수
		cin >> n;

		int result = 0;

		deque<int> deq;

		for (int c = 0; c < n; c++)
		{
			int h;
			cin >> h;
			deq.emplace_back(h);

			if (c < 4)
				continue;

			auto iter = deq.begin();
			int canSee = *(iter + 2) - max({*iter, *(iter+1), *(iter+3), *(iter+4)});
			if (canSee > 0)
				result += canSee;

			deq.pop_front();
		}
		cout << "#" << t<< " " << result << '\n';
	}
	return 0;
}