#include <iostream>
#include <cstring>

using namespace std;

bool isChecked[27]; // a ~ z

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N; cin >> N;
	int result = 0;

	for (int i = 0; i < N; i++)
	{
		string input;
		cin >> input;

		bool isGroupWord = true;
		memset(isChecked, 0, sizeof(isChecked));

		int prev = input[0] - 'a';
		isChecked[prev] = true;

		for (int j = 1; j < input.size(); j++)
		{
			int cur = input[j] - 'a';
			if (!isChecked[cur])
				isChecked[cur] = true;
			else 
			{
				if (cur != prev)
				{
					isGroupWord = false;
					break;
				}
			}

			prev = cur;
		}

		if (isGroupWord)
			result++;
	}

	cout << result;

	return 0;
}