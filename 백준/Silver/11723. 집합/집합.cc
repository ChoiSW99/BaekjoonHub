// https://www.acmicpc.net/problem/11723
//#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

bool SET[21];

void Calc(string op)
{
	if (op == "all")
		for (int i = 0; i < 21; i++)
			SET[i] = true;
	else if (op == "empty")
		for (int i = 0; i < 21; i++)
			SET[i] = false;
	else
	{
		int x; 
		cin >> x;
		if (op == "add")
			SET[x] = true;
		else if (op == "remove")
			SET[x] = false;
		else if (op == "check")
			cout << SET[x] << '\n';
		else if (op == "toggle")
			SET[x] = !SET[x];
	}
	
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string op;
		cin >> op;
		Calc(op);
	}

	return 0;
}