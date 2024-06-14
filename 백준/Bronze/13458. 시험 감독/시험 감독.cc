#include <iostream>

using namespace std;

int people[1000005];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> people[i];
	int b, c;
	cin >> b >> c;

	long long result = 0;
	for (int i = 0; i < n; i++)
		people[i] -= b; // 총 감독관
	result += n;

	for (int i = 0; i < n; i++)
	{
		if (people[i] > 0)
		{
			if ((people[i] % c) == 0)
				result += people[i] / c;
			else
				result += (people[i] / c) + 1;
		}
	}

	cout << result;
	return 0;
}