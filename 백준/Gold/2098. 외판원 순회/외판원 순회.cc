#define _CRT_SECURE_NO_WARNINGS
#include <sstream>
#include <vector>
#include <iostream>

using namespace std;

// https://www.acmicpc.net/problem/2098 외판원 순회

int N; // 도시의 수
const int INF = 1e9;
int start = 0;
vector<vector<int>> dp;
vector<vector<int>> dist;

// Top-down 방식
int DFS_TSP(int cur, int visited)
{
	// ( 종료조건 )
	// 다 돈 후, 마지막으로 시작지점으로 돌아갈 때
	if (visited == (1 << start))
	{
		if(dist[cur][start] == 0)
			return INF;
		return dist[cur][start];
	}

	// 이미 방문한 지점
	if (dp[cur][visited] != -1)
		return dp[cur][visited];

	dp[cur][visited] = INF;

	for (int i = 0; i < N; i++)
	{
		// 없는 길
		if (dist[cur][i] == 0)
			continue;

		if ( i == cur) // i == start ||
			continue;

		// 방문해야할 곳이 아닐 때
		if ((visited & (1 << i)) == 0)
			continue;

		// cur 시작하여 visited (비트마스킹 집합)를 다 방문한 후, 0번 지점으로 복귀하는 최소경로
		dp[cur][visited] = min(dp[cur][visited], dist[cur][i] + DFS_TSP(i, visited - (1 << i)) );
	}
	return dp[cur][visited];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	cin.ignore();
	dp.assign(N, vector<int>((1<< N), -1));
	dist.assign(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++)
	{
		string str, token;
		getline(cin, str);
		stringstream ss(str);
		for (int j = 0; j < N; j++)
		{
			ss >> token;
			dist[i][j] = stoi(token);
		}
	}

	cout << DFS_TSP(start, (1 << N) - 1); // 0번시작, 1111 
}