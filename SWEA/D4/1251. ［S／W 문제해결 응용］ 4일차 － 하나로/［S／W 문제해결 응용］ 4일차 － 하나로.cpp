#include <bits/stdc++.h>

using namespace std;

int X[1000001];
int Y[1000001];

long long Dist[1001][1001]; // 모든 섬들 간의 거리
bool visited[1001];

long long GetDist(int p1, int p2)
{
	long long x = X[p1] - X[p2];
	long long y = Y[p1] - Y[p2];
	return x * x + y * y;
}

using plli = pair<long long, int>;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T; cin >> T;
	int N;
	double E;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> X[i];
		for (int i = 0; i < N; i++)
			cin >> Y[i];
		cin >> E; // 세율

		for(int i=0; i<N; i++)
			fill(Dist[i], Dist[i]+N, LLONG_MAX);

		memset(visited, 0, sizeof(visited));

		for (int st = 0; st < N; st++)
			for (int end = 0; end < N; end++)
					Dist[st][end] = GetDist(st, end);
		long long result = 0L;
		int visitedCnt = 0;

		// { 거리, 섬번호} // 섬번호까지의 거리
		priority_queue<plli, vector<plli>, greater<plli>> pq;
		pq.emplace(0, 0);

		while (!pq.empty())
		{
			plli p = pq.top(); pq.pop();
			if (visited[p.second]) continue;
			result += p.first;
			visited[p.second] = true;
			visitedCnt++;

			if (visitedCnt == N)
				break;

			for (int dest = 0; dest < N; dest++)
			{
				if (visited[dest])	continue;
				pq.emplace(Dist[p.second][dest], dest);
			}
		}
		cout << "#" << tc << " " << (long long)(round(E * result)) << '\n';
	}
}
