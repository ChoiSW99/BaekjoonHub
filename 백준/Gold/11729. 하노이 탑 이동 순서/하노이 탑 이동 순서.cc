#include <bits/stdc++.h>

using namespace std;

// 원판 n개를 기둥a -> 기둥b로 옮기는 방법을 출력하는 함수
int result = 0;
stringstream resultStr;
void func(int a, int b, int n)
{
	if (n == 0)
		return;
	func(a, 6 - a - b, n - 1);
	resultStr << a << ' ' << b << '\n';
	result++;
	func(6 - a - b, b, n - 1);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N; 
	cin >> N;

	func(1, 3, N);
	cout << result << '\n' << resultStr.str();
}
