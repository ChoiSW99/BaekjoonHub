/*
https://www.acmicpc.net/problem/7785
*/

#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	unordered_set<string> s;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string name, el;
		cin >> name >> el;
		if (el == "enter")
		{
			s.insert(name);
		}
		else 
		{
			s.erase(name);
		}
	}

	vector<string> v(s.begin(), s.end());
	sort(v.begin(), v.end(), greater<>());
	for (auto s : v)
		cout << s << '\n';
}
