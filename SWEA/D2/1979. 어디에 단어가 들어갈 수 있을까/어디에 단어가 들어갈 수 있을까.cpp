#include <bits/stdc++.h>
using namespace std;

bool Puzzle[17][17];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	for(int t=1; t<=T; t++)
	{
		memset(Puzzle, 0, sizeof(Puzzle));
		int N, K;
		cin >> N >> K; // 퍼즐길이N 단어길이K
		int result = 0;

		for (int r = 1; r < N+1; r++)
		{
			for (int c = 1; c < N+1; c++)
			{
				cin >> Puzzle[r][c];
			}
		}

		// 가로 탐색
		for (int r = 1; r < N+1; r++)
		{
			for (int c = 0; c < N-K+1; c++) // 0 1 2
			{
				bool find = true;
				// K+2개씩 확인. 01110 인지
				for (int k = 0; k < K+2; k++)
				{
					if (k == 0 || k == K+1)
					{
						if (Puzzle[r][c + k] == true)
						{
							find = false;
							break;
						}
					}
					else
					{
						if (Puzzle[r][c + k] == false)
						{
							find = false;
							break;
						}
					}
				}

				if (find)
				{
					//cout << "r=" << r << ", c=" << c << '\n';
					result++;
					c += K; // K+1만큼만 넘어가야함. !주의! for문에서 c++이므로 여기서 K+1이 아닌 K만 늘려주기!
				}
			}
		}

		// 세로 탐색
		for (int c = 1; c < N+1; c++)
		{
			for (int r = 0; r < N - K + 1; r++) // 0 1 2
			{
				bool find = true;
				// K+1개씩 확인. 1110 인지!
				for (int k = 0; k < K + 2; k++)
				{
					if (k == 0 || k == K + 1)
					{
						if (Puzzle[r + k][c] == true)
						{
							find = false;
							break; 
						}
					}
					else
					{
						if (Puzzle[r + k][c] == false)
						{
							find = false;
							break;
						}
					}
				}

				if (find)
				{
					//cout << "c=" << c << ", r=" << r << '\n';

					result++; 
					r += K; // K+1만큼만 넘어가야함. !주의! for문에서 r++이므로 여기서 K+1이 아닌 K만 늘려주기!
				}
			}
		}


		cout << "#" << t<< " " << result << '\n';
	}
	return 0;
}