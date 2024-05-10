#include <bits/stdc++.h>
using namespace std;

int A[20];
int B[20];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T;

	for (int t = 1; t <= T; t++)
	{
		int N;  cin >> N; 
		int M;  cin >> M; 
		for (int i = 0; i < N; i++)
			cin >> A[i];
		for (int i = 0; i < M; i++)
			cin >> B[i];
		vector<int> x;

		if (N <= M)
		{
			for (int s = 0; s < M - N + 1; s++)
			{
				int num = 0;
				for (int l = 0; l < N; l++)
					num += A[l] * B[s + l];
				x.push_back(num);
			}
		}
		else
		{
			for (int s = 0; s < N - M + 1; s++)
			{
				int num = 0;
				for (int l = 0; l < M; l++)
					num += A[s+l] * B[l];
				x.push_back(num);
			}
		}
		cout << "#" << t << " " << *max_element(x.begin(), x.end()) << '\n';
	}
	return 0;
}