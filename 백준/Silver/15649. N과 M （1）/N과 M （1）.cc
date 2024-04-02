#include <bits/stdc++.h>

using namespace std;

void Sol(vector<int>& nums, int N, int depth, int maxDepth)
{
	if (depth > maxDepth)
	{
		for (int n : nums)
			cout << n << " ";
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; i++)
	{
		bool has = false;
		for(int n : nums)
			if (n == i)
			{
				has = true;
				break;
			}
		if (has == false)
		{
			nums.push_back(i);
			Sol(nums, N, depth + 1, maxDepth);
			nums.pop_back();
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M; 
	cin >> N >> M;

	vector<int> nums;

	int depth = 1;

	Sol(nums, N, depth, M);
}
