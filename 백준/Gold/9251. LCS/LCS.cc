#include <iostream>

using namespace std;

int DP[1001][1001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s1, s2;
	cin >> s1 >> s2;

/*
	    C A P C A K
	  0 0 0 0 0 0 0 
	A 0
	C 0
	A 0
	Y 0
	K 0
	P 0
*/

	for (int i = 0; i < s1.size(); i++)
	{
		for (int j = 0; j < s2.size(); j++)
		{
			if (s1[i] == s2[j])
			{
				// 같다면, s1[i]와 s2[j]를 둘다 제외하고 고려해야함.
				// 그렇기에, s1[i-1]까지와 s2[j-1]까지 고려한 것에 + 1
				DP[i + 1][j + 1] = DP[i][j] + 1; // 즉, 왼쪽위 대각 + 1
			}
			else
			{
				// 다르면, 이전 것들 중 최대값으로 해야함.
				// 왼쪽이나 위쪽이 최대이므로
				// 왼쪽 vs 위쪽
				int bigger = max(DP[i + 1][j], DP[i][j + 1]);
				DP[i + 1][j + 1] = bigger; 
			}
		}
	}
/*
		C A P C A K
	  0 0 0 0 0 0 0 
	A 0 0 1 1 1 1 1
	C 0 1 1 1 2 2 2
	A 0 1 2 2 2 3 3
	Y 0 1 2 2 2 3 3
	K 0 1 2 2 2 3 4
	P 0 1 2 3 3 3 4
*/
	cout << DP[s1.size()][s2.size()];
	return 0;
}