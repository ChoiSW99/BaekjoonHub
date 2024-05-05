#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

bool Puzzle[17][17];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	for(int t = 1; t<=T; t++)
	{
		bool isPalindrome = true;

		string input;
		cin >> input;
		int len = input.length();
		for (int i = 0; i < len / 2; i++)
		{
			if (input[i] != input[(len - 1) - i])
			{
				isPalindrome = false;
				break;
			}
		}
		cout << "#" << t << " " << isPalindrome << '\n';
	}
	return 0;
}