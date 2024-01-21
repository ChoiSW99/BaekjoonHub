#include <bits/stdc++.h>

#define INF 1e9
using namespace std;

// https://www.acmicpc.net/problem/11657 타임머신
typedef pair<int, int> pii;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	int a, b, c;
	cin >> n >> m;

	vector<vector<pii>> graph(n + 1);
	vector<int> visited(n+1, 0); // 노드 방문 횟수
	vector<bool> isInQueue(n + 1, 0);

	vector<long long> dist(n + 1, INF); 

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		graph[a].push_back({b,c}); // a도시 ==(c시간)==> b도시
	}

	queue<int> que;
	que.push(1);
	isInQueue[1] = true;
	dist[1] = 0;

	while (!que.empty())
	{
		int now = que.front();
		que.pop();
		isInQueue[now] = false;
		visited[now]++;

		// 음의 싸이클 여부 체크
		if (visited[now] == n)
		{
			cout << -1;
			return 0;
		}

		for (pii next : graph[now])
		{
			int to = next.first;
			int cost = next.second;

			if (dist[now] + cost < dist[to])
			{
				dist[to] = dist[now] + cost;

				if (isInQueue[to] == false) // 큐에 없으면
				{
					isInQueue[to] = true;
					que.push(to);
				}
			}
		}
	}

	for (int idx = 2; idx <= n; idx++)
	{
		if (dist[idx] == INF)
			cout << -1 << '\n';
		else
			cout << dist[idx] << '\n';
	}

	return 0;
}