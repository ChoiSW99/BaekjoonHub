#include <bits/stdc++.h>
using namespace std;

int Matrix[7][7];
int Output[7][3];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T;

	for (int t = 1; t <= T; t++)
	{
		int N; cin >> N;
		for (int r = 0; r < N; r++)
			for (int c = 0; c < N; c++)
				cin >> Matrix[r][c];

		// 90 
		// output 0열에
		for (int c = 0; c < N; c++)
		{
			int num = 0;
			for (int r = N - 1; r >= 0; r--)
			{
				num *= 10;
				num += Matrix[r][c];
			}
			Output[c][0] = num;
		}

		// 180
		// output 1열에
		{
			for (int r = N - 1; r >= 0; r--)
			{
				int num = 0;
				for (int c = N - 1; c >= 0; c--)
				{
					num *= 10;
					num += Matrix[r][c];
				}
				Output[(N - 1) - r][1] = num;
			}

			// 270
			// output 2열에
			for (int c = N - 1; c >= 0; c--)
			{
				int num = 0;
				for (int r = 0; r < N; r++)
				{
					num *= 10;
					num += Matrix[r][c];
				}
				Output[(N - 1) - c][2] = num;
			}

			cout << "#" << t << '\n';
			for (int r = 0; r < N; r++)
			{
				for (int c = 0; c < 3; c++)
				{
					int len = 1;
					for (int l = 1; l < N; l++)
						len *= 10;
					int num = Output[r][c];
					while (num < len)
					{
						cout << 0;
						len /= 10;
					}
					cout << Output[r][c] << " ";
				}
				cout << '\n';
			}
		}
	}
	return 0;
}