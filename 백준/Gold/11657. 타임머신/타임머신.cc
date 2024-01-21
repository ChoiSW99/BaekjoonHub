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

	vector<vector<pii>> graph(n+1);
	vector<long long> dist(n + 1, INF);

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		graph[a].push_back({b,c});
	}

	dist[1] = 0;
	// n-1번 반복
	for (int r = 0; r < n - 1; r++)
	{
		for (int st = 1; st < n + 1; st++)
		{
			for (pii n : graph[st]) // 출발st, 도착n.first, 걸리는시간n.second
			{
				// 방문 안한 도시
				// 걸리는시간n.second가 음수면 갱신되기 때문에 continue로 넘겨줘야함.
				// if(INF - 1 < INF) 
				if (dist[st] == INF)
					continue;

				if (dist[st] + n.second < dist[n.first])
					dist[n.first] = dist[st] + n.second;
			}
		}
	}

	// 마지막
	for (int st = 1; st < n + 1; st++)
	{
		for (pii n : graph[st]) // 출발st, 도착n.first, 걸리는시간n.second
		{
			// 방문 안한 도시
			if (dist[st] == INF)
				continue;

			if (dist[st] + n.second < dist[n.first])
			{
				cout << -1;
				return 0;
			}
		}
	}

	// 음의 사이클 있으면 -1 만 출력
	// 없으면 2~n도시까지의 cost 출력. 이 때, cost값이 INF면 -1
	for (int idx = 2; idx < n+1; idx++)
	{
		if (dist[idx] == INF)
			cout << -1 << '\n';
		else
			cout << dist[idx] << '\n';
	}
	return 0;
}