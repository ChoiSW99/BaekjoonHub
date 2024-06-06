#include <iostream>

using namespace std;

bool isNotSelfNumber[10001];

int Calc(int number)
{
	int result = number;
	while (number > 0)
	{
		result += number % 10;
		number /= 10;
	}
	return result;
}

int main()
{
	for (int n = 1; n < 10001; n++)
	{
		int x = Calc(n);
		if (x > 10000) continue;

		isNotSelfNumber[x] = true;
	}

	int cnt = 0;
	for (int n = 1; n < 10001; n++)
	{
		if (isNotSelfNumber[n]) continue;
		cout << n << '\n';
	}

	return 0;
}