#include <bits/stdc++.h>

using namespace std;

int Count[101];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	for(int t=1; t<=tc; t++)
	{
		memset(Count, 0, sizeof(Count));

		int mostFrequent = 0;

		int score;
		cin >> score;

		for (int i = 0; i < 1000; i++)
		{
			cin >> score;
			Count[score]++;

			if (Count[mostFrequent] < Count[score])
				mostFrequent = score;
			else if (Count[mostFrequent] == Count[score])
				mostFrequent = max(mostFrequent, score);
		}

		cout << "#" << t<< " " << mostFrequent << '\n';
	}
	return 0;
}