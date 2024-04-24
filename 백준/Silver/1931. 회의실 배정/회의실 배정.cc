/*
https://www.acmicpc.net/problem/1931
*/

#include <bits/stdc++.h>

using namespace std;

using pll = pair<int, int>;

bool comp(pll& p1, pll& p2)
{
	if (p1.second != p2.second) 
		return (p1.second < p2.second);
	return p1.first < p2.first;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	vector<pll> inputs;
	int s, e;
	for (int i = 0; i < N; i++)
	{
		cin >> s >> e;
		inputs.emplace_back(s,e);
	}

	sort(inputs.begin(), inputs.end(), comp);

	int answer = 0;
	pll cur = { -1,-1 };

	for (int i = 0; i < N; i++) 
	{
		pll next = inputs[i];
		if (next.first < cur.second)
			continue;

		cur = next;
		answer++;
	}
	cout << answer;

	return 0;
}

/*
 ----
   ---
-------
     ---

*/
