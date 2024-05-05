#include <bits/stdc++.h>
using namespace std;

char Word[8][8];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int T = 10;

	for(int t = 1; t<=T; t++)
	{
		int L; cin >> L;

		for (int i = 0; i < 8; i++)
		{
			string input; cin >> input;
			for (int j = 0; j < 8; j++)
				Word[i][j] = input[j];
		}
		
		int cnt = 0;
		// 가로
		for (int r = 0; r < 8; r++)
		{
			for (int c = 0; c < 8 - L + 1; c++)
			{
				// 회문 확인
				bool isPalindrome = true;
				for (int p = 0; p < L / 2; p++)
				{
					if (Word[r][c + p] != Word[r][c + (L - 1) - p])
					{
						isPalindrome = false;
						break;
					}
				}

				if (isPalindrome) cnt++;
			}
		}
		// 세로
		for (int c = 0; c < 8; c++)
		{
			for (int r = 0; r < 8 - L + 1; r++)
			{
				// 회문 확인
				bool isPalindrome = true;
				for (int p = 0; p < L / 2; p++)
				{
					if (Word[r+p][c] != Word[r + (L - 1) - p][c])
					{
						isPalindrome = false;
						break;
					}
				}

				if (isPalindrome) cnt++;
			}
		}
		cout << "#" << t << " " << cnt << '\n';
	}
	return 0;
}