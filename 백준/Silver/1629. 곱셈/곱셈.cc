#include <bits/stdc++.h>

using namespace std;

long long POW(int A, int B, int C)
{
	if (B == 1) return A % C;
	long long val = POW(A, B / 2, C);
	val = val * val % C;
	if (B % 2 == 0)
		return val;
	else
		return val * A % C;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int A, B, C;
	cin >> A >> B >> C;
	cout << POW(A, B, C);
}

//
// 10^11 % 12
// ( 10^5 * 10^5 * 10 ) % 12
// ( (10^2 * 10^2 * 10 ) * (10 ^ 2 * 10 ^ 2 * 10) * 10) % 12
// ((((10 ^ 1 * 10 ^ 1) % 12) * ((10 ^ 1 * 10 ^ 1) % 12) * 10) * (((10 ^ 1 * 10 ^ 1) % 12) * ((10 ^ 1 * 10 ^ 1) % 12) * 10) * 10) % 12
// 
// ...
// 10 ^ 2 ==> ( ( 10^1 * 10^1 )% 12 )