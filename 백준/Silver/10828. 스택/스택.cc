#include <iostream>

using namespace std;

int arr[10001];
int cur = 0;

int main()
{
	int N; cin >> N;
	string op;
	int num;

	for (int i = 0; i < N; i++)
	{
		cin >> op;
		if (op == "push")
		{
			cin >> num;
			arr[cur] = num;
			cur++;
		}
		else if (op == "pop")
		{
			if (cur == 0) // 비어있음
				cout << -1 << "\n";
			else
			{
				cur--;
				cout << arr[cur] << "\n";
			}
		}
		else if (op == "size")
		{
			cout << cur << "\n";
		}
		else if (op == "empty")
		{
			if (cur == 0)
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
		}
		else if (op == "top")
		{
			if (cur == 0) // 비어있음
				cout << -1 << "\n";
			else
			{
				cur--;
				cout << arr[cur] << "\n";
				cur++;
			}
		}
	}
}