#include <iostream>
#include <vector>
#include <utility>

using namespace std;

typedef pair<int, int> pii;
const int INF = 1e9; // 1,000,000,000

int main()
{

	int n, m; // 도시개수n, 버스개수m

	cin >> n >> m;

	vector<vector<int>> dist(n+1, vector<int>(n+1, INF));

	int start, end, cost;
	for (int idx = 0; idx < m; idx++)
	{
		cin >> start >> end >> cost;
		if (dist[start][end] > cost)
			dist[start][end] = cost;
	}

	for (int mid = 1; mid <= n; mid++)
	{
		for (int st = 1; st <= n; st++)
		{
			for (int end = 1; end <= n; end++)
			{
				
				if (dist[st][end] > dist[st][mid] + dist[mid][end])
					dist[st][end] = dist[st][mid] + dist[mid][end];
			}
		}
	}

	for (int st = 1; st <= n; st++)
	{
		for (int end = 1; end <= n; end++)
		{
			if (st== end || dist[st][end] == INF)
				cout << 0 << ' ';
			else
				cout << dist[st][end] << ' ';
		}
		cout << '\n';
	}
		
}