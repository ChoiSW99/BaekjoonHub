#include <bits/stdc++.h>
using namespace std;

int Input[10];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T;

	for (int t = 1; t <= T; t++)
	{
		int N; cin >> N; // N명의 학생
		int K; cin >> K; // K번째학생
		int interval = N / 10;

		vector<pair<int, int>> v; // {점수, 학생번호}
		for (int s = 1; s <= N; s++)
		{
			int a, b, c; 
			cin >> a >> b >> c; // 중간, 기말, 과제
			v.emplace_back(a * 35 + b * 45 + c * 20, s);
		}
		sort(v.begin(), v.end(), greater<>()); // 내림차순 (시작이 greater)

		for (int i = 0; i < N; i++)
		{
			int s = v[i].second;

			if (s == K)
			{
				if(i < interval)
					cout << "#" << t << " A+" << '\n';
				else if (i < interval*2)
					cout << "#" << t << " A0" << '\n';
				else if (i < interval*3)
					cout << "#" << t << " A-" << '\n';
				else if (i < interval*4)
					cout << "#" << t << " B+" << '\n';
				else if (i < interval*5)
					cout << "#" << t << " B0" << '\n';
				else if (i < interval*6)
					cout << "#" << t << " B-" << '\n';
				else if (i < interval*7)
					cout << "#" << t << " C+" << '\n';
				else if (i < interval*8)
					cout << "#" << t << " C0" << '\n';
				else if (i < interval*9)
					cout << "#" << t << " C-" << '\n';
				else
					cout << "#" << t << " D0" << '\n';
				break;
			}
		}
	}
	return 0;
}