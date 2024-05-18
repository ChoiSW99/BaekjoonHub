#include <bits/stdc++.h>

using namespace std;

int path1[100];
int path2[100];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int tc = 1; tc <= 10; tc++)
	{
		cin >> tc; 
		int l; cin >> l;
		// 연결 안됨   : -1
		// 이미 지나감 : 0
		memset(path1, -1, sizeof(path1));
		memset(path2, -1, sizeof(path2));
		for (int i = 0; i < l; i++)
		{
			int from; int to;
			cin >> from >> to;
			if (path1[from] == -1)
				path1[from] = to;
			else
				path2[from] = to;
		}
		bool found = false;
		queue<int> que;
		que.push(0);
		while (!que.empty())
		{
			int now = que.front(); que.pop();
			if (now == 99)
			{
				found = true;
				break;
			}

			if (path1[now] > 0) {
				que.push(path1[now]);
				path1[now] = 0;
			}

			if (path2[now] > 0) {
				que.push(path2[now]);
				path2[now] = 0;
			}
		}

		cout << "#" << tc << " " << found << '\n';
	}
}
