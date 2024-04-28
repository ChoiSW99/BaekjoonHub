// https://www.acmicpc.net/problem/11723
//#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int state; // 32-bit

void Calc(string op)
{
	if (op == "all")
		state = 0xfffff; // 16진수이므로 하나당 4비트기에 f는 5개
	else if (op == "empty")
		state = 0;
	else
	{
		int x; 
		cin >> x;
		x -= 1;
		if (op == "add")
			state |= (1 << x);
		else if (op == "remove")
			state &= (~(1 << x));
		else if (op == "check")
			cout << ((state >> x) & 1) << '\n';
		else if (op == "toggle")
			state ^= (1 << x);
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