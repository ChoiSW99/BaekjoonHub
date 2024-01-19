#define _CRT_SECURE_NO_WARNINGS
#include <sstream>
#include <vector>
#include <iostream>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

// https://www.acmicpc.net/problem/1525 퍼즐

string ANSWER = "123456780";

int main()
{
	//freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// 오름차순
	queue<pair<string, int>> open;
	set<string> closed;

	string current;
	char number;

	int x = 1;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			cin >> number;
			current.push_back(number);
		}
	int dx[4] = {0, 0, -1, 1};
	int dy[4] = {1, -1, 0, 0};

	open.emplace(current, 0);
	closed.insert(current);

	while (!open.empty())
	{
		auto cur = open.front();
		open.pop();
		
		if (cur.first == ANSWER)
		{
			cout << cur.second;
			return 0;
		}

		int idx = cur.first.find('0');

		for (int i = 0; i < 4; i++)
		{
			int x = idx % 3;
			int y = idx / 3;
			x += dx[i];
			y += dy[i];

			if (x > 2 || x < 0 || y > 2 || y < 0)
				continue;

			string next = cur.first;
			swap(next[idx], next[x+3*y]);

			if (closed.find(next) == closed.end())
			{
				open.emplace(next, cur.second + 1);
				closed.insert(next);
			}
		}
	}
	cout << -1;
	return 0;
}