#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);

	string input;
	cin >> input;
	int zero = 0;
	int one = 0;

	int current = -1;
	
	
	for (int idx = 0; idx < input.length(); idx++)
	{
		if (input[idx] - '0' != current)
		{
			if (input[idx] - '0' == 0)
			{
				current = 0;
				zero++;
			}
			else {
				current = 1;
				one++;
			}
		}
	}
	cout << min(one, zero);
}