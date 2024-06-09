#include <iostream>
#include <deque>
#include <cstring>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T;
	for (int t = 0; t < T; t++)
	{
		string p; cin >> p; // 함수 p
		int n; cin >> n; // 개수
		string s; cin >> s;

		deque<int> deq;

		int num = 0;

		for (char c : s)
		{
			if (c == '[')
				continue;
			else if (c == ',' || c == ']')
			{
				if (num != 0)
				{
					deq.push_back(num);
					num = 0;
				}
			}
			else // 숫자
			{
				num *= 10;
				num += (c - '0');
			}
		}

		bool isReversed = false;
		bool stop = false;

		for (auto _p : p)
		{
			if (_p == 'R')
			{
				isReversed = !isReversed;
			}
			else if (_p == 'D')
			{
				if (deq.empty())
				{
					cout << "error" << '\n';
					stop = true;
					break;
				}
				else
				{
					if (!isReversed)
						deq.pop_front();
					else
						deq.pop_back();
				}
			}
		}
		
		if (stop)
			continue;

		cout << "[";
		int deqCnt = deq.size();
		if (!isReversed)
		{
			for (int i = 0; i < deqCnt; i++)
			{
				cout << deq[i];
				if (i != deqCnt - 1)
					cout << ",";
			}
		}
		else
		{
			for (int i = deqCnt-1; i >= 0; i--)
			{
				cout << deq[i];
				if (i != 0)
					cout << ",";
			}
		}
		cout << "]" << "\n";
	}

	return 0;
}